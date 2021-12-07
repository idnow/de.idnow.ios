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
        settings.companyID = "svenvideo"
        settings.environment = .test
        return settings
    }
    
    func initialize(ident: String) {
        self.controller = IDnowController.init(settings: settings(ident: ident))
    }
    
    func start() {
        self.controller.initialize(completionBlock: {(success, error, canceledByUser) -> Void in
            self.controller.startIdentification(from: ViewUtils.rootController(), withCompletionBlock: {(success, error, canceledByUser) -> Void in
                
            })
        })
    }
}
