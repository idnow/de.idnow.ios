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
                    IDnowService.instance.initialize(ident: $ident.wrappedValue)
                    IDnowService.instance.start()
                }
            HStack {
                Spacer()
                Button("CONFIRM") {
                    IDnowService.instance.initialize(ident: $ident.wrappedValue)
                    IDnowService.instance.start()
                }
                Spacer()
            }
            
        })
    }
}

