//
//  ContentView.swift
//  IDnow
//
//  Created by Aare Undo on 02.12.2021.
//

import SwiftUI
import IDnowSDK

struct ContentView: View {

    @State private var email: String = ""

    var body: some View {
        VStack(alignment: .leading, spacing: 0, content: {
            HStack {
                Spacer()
                Image("logo-main")
                Spacer()
            }.padding()
            Text("Please enter and confirm your Ident-ID to start the idenfitcation process")
                .padding()
                .multilineTextAlignment(.center)
            TextField("User name (email address)", text: $email)
                .padding()
                .padding()
                .multilineTextAlignment(.center)
                .onSubmit {
                    print("submit")
                }
            HStack {
                Spacer()
                Button("CONFIRM") {
                    print("confirm")
                    
                    let settings = IDnowSettings(companyID: "svenvideo")
                    settings.transactionToken = "TST-EVBZS"
                    settings.environment = .test
                    
                    let windows = UIApplication.shared.windows[0].rootViewController!
                    
                    let controller = IDnowController.init(settings: settings)
                    
                    controller.initialize(completionBlock: {(success, error, canceledByUser) -> Void in
                        controller.startIdentification(from: windows, withCompletionBlock: {(success, error, canceledByUser) -> Void in
                            
                        })
                    })
                }
                Spacer()
            }
            
        })
    }
}

