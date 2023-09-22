//
//  IDnowService.swift
//  IDnow
//
//  Created by Aare Undo on 02.12.2021.
//

import Foundation
import idnow_vi

class IDnowService {
    static let instance = IDnowService()
    
    var controller: IDnowController!
    
    private init() {}
    
    private func settings(ident: String) -> IDnowSettings {
        let settings = IDnowSettings()
        settings.transactionToken = ident
        settings.ignoreCompanyID = true
        return settings
    }
    
    func initialize(ident: String) {
        self.controller = IDnowController.init(settings: settings(ident: ident))
    }
    
    func start(viewController: UIViewController?) async -> String? {
        
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
                guard let viewController = viewController else {
                    return continuation.resume(returning: "Failed")
                }
                self.controller.startIdentification(from: viewController, withCompletionBlock: {(success, error, canceledByUser) -> Void in
                    
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
