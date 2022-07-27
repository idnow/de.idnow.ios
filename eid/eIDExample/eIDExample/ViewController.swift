//
//  ViewController.swift
//  eIDExample
//
//  Created by Phu Nguyen on 4/17/20.
//  Copyright © 2020 The Vis. All rights reserved.
//

import UIKit
import idnow_eid

class ViewController: UIViewController {
    @IBOutlet weak var textField: UITextField!
    
    private var eidRouter: IDN_eIDRouter!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func launchIdent(_ sender: Any) {
        guard let token = textField.text, !token.isEmpty else { // input token validate
            return
        }
        eidRouter = IDN_eIDRouter(
            withControlller: self,
            token: token,            
            completion: { [unowned self] (support, error) in
                if support {
                    self.eidRouter.present { (identSuccess, continueVideoIdent, error) in
                        if continueVideoIdent {
                            print("LOG: - Continue video identification")
                        } else {
                            print("LOG: - Identification finished \(identSuccess ? "Successfully" : "Failed")")
                            if !identSuccess {
                                print("LOG: - Ident failed with reason \(String(describing: error))")
                            }
                        }
                    }
                } else {
                    print("LOG: - Device not support nfc ")
                }
        })
    }
    
}

