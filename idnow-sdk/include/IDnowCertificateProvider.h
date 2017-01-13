//
//  IDnowCertificateProvider.h
//  idnow-sdk
//
//  Created by Holger Kretzschmar on 28/12/2016.
//  Copyright © 2016 IDnow GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  classes that implement this interface are used to provide custom DTLS certificates
 *  used by the WebRTC connection.
 *  
 *  In order to use custom certificates please subclass IDnowCertificateProvider and add
 *  an instance of your new class to the IDnowSettings:
 *
 *  IDnowSettings.certificateProvider = >>YOUR_SUBCLASS<<
 */
@interface IDnowCertificateProvider : NSObject

/**
 *  subclasses need to implement this function in a way that it returns a DER encoded byte stream
 *  representing the private key.
 *
 *  openssl command to convert from PEM to DER: openssl rsa -outform der -in yourkey.pem -out yourkey.der
 *
 *  @return DER encoded private key
 */
- (NSMutableData*)providePrivateKeyBytestream;

/**
 *  subclasses need to implement this function in a way that it returns a DER encoded byte stream
 *  representing the x509/ASN.1 certificate.
 *
 *  openssl command to convert form PEM to DER: openssl x509 -outform der -in yourcertificate.pem -out yourcertificate.der
 *
 *  @return DER encoded x509/ASN.1 certificate
 */
- (NSMutableData*)provideCertificateBytestream;

@end
