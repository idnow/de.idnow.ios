//
//  ContentView.swift
//  IDnow
//
//  Created by Aare Undo on 02.12.2021.
//

import SwiftUI
import IDnowSDK

struct ContentView: View {

    @State private var ident: String = ""
    @State private var error: String? = ""
    
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
            TextField("Enter your Ident-ID here", text: $ident)
                .padding()
                .padding()
                .multilineTextAlignment(.center)
                .onSubmit {
                    self.onConfirm()
                }
            HStack {
                Spacer()
                Button("CONFIRM") {
                    self.onConfirm()
                }
                Spacer()
            }
            
        }).alert(isPresented: .constant($error.wrappedValue != nil)) {
            Alert(title: Text("Error"), message: Text($error.wrappedValue!), dismissButton: .cancel())
        }
        
    }
    
    func onConfirm() {
        Task.init(priority: .background, operation: {
            IDnowService.instance.initialize(ident: $ident.wrappedValue)
            let result = await IDnowService.instance.start()
            if (result != nil) {
                $error.wrappedValue = result
            }
        })
    }
}

