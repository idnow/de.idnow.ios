//
//  ContentView.swift
//  spm-example-idnow
//
//  Created by Phu Nguyen on 5/10/23.
//

import SwiftUI
import idnow_vi

struct ContentView: View {
    @State private var ident: String = ""
    @State private var error: String? = nil
    
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
            Alert(title: Text("Error"), message: Text($error.wrappedValue!), dismissButton: .default(Text("Close"), action: {
                $error.wrappedValue = nil
            }))
        }
        
    }
    
    func rootController() async -> UIViewController? {
        return await MainActor.run {
            if let windowScene = UIApplication.shared.connectedScenes.first as? UIWindowScene {
                return windowScene.windows.first?.rootViewController
            }
            return nil
        }
    }
    
    func onConfirm() {
        
        Task.init(priority: .background, operation: {
            let controller = await rootController()
            IDnowService.instance.initialize(ident: $ident.wrappedValue)
            let result = await IDnowService.instance.start(viewController: controller)
            if (result != nil) {
                $error.wrappedValue = result
            }
        })
    }
    
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
