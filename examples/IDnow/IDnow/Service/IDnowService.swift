//
//  IDnowService.swift
//  IDnow
//
//  Created by Aare Undo on 02.12.2021.
//

import Foundation
import IDnowSDK

class IDnowService {
    static let instance = IDnowService()
    
    var controller: IDnowController!
    
    private init() {}
    
    private func settings(ident: String) -> IDnowSettings {
        let settings = IDnowSettings()
        settings.transactionToken = ident
        settings.environment = .test
        settings.ignoreCompanyID = true
        return settings
    }
    
    func initialize(ident: String) {
        self.controller = IDnowController.init(settings: settings(ident: ident))
    }
    
    func start() async -> String? {
        
        return await withCheckedContinuation{ continuation in
            
            self.controller.initialize(completionBlock: {(success, error, canceledByUser) -> Void in
                if (error != nil) {
                    let message = error?.localizedDescription;
                    continuation.resume(returning: message)
                    return
                }
                
                if (canceledByUser) {
                    continuation.resume(returning: "You cancelled the identification process. That's it")
                    return
                }
                
                self.controller.startIdentification(from: ViewUtils.rootController(), withCompletionBlock: {(success, error, canceledByUser) -> Void in
                    
                    if (error != nil) {
                        continuation.resume(returning: error?.localizedDescription)
                        return
                    }
                    
                    if (canceledByUser) {
                        continuation.resume(returning: "You cancelled the identification process. That's it")
                        return
                    }
                    
                    continuation.resume(returning: nil)
                    
                })
            })
            
        }
    }
}
