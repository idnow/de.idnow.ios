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
    
    func settings() -> IDnowSettings {
        let settings = IDnowSettings(companyID: "svenvideo")
        settings.transactionToken = "TST-EVBZS"
        settings.environment = .test
        return settings
    }
    
    func initialize() {
        self.controller = IDnowController.init(settings: settings())
    }
    
    func start() {
        self.controller.initialize(completionBlock: {(success, error, canceledByUser) -> Void in
            self.controller.startIdentification(from: ViewUtils.rootController(), withCompletionBlock: {(success, error, canceledByUser) -> Void in
                
            })
        })
    }
}
