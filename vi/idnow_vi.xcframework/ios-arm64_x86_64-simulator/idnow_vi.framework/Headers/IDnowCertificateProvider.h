//
//  IDnowCertificateProvider.h
//  idnow-sdk
//
//  Created by Holger Kretzschmar on 28/12/2016.
//  Copyright © 2016 IDnow GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  classes that implement this interface are used to provide custom mTLS certificates
 *  used by the network connections.
 *  
 *  In order to use custom certificates please subclass IDnowCertificateProvider and add
 *  an instance of your new class to the IDnowSettings:
 *
 *  IDnowSettings.certificateProvider = >>YOUR_SUBCLASS<<
 */
@interface IDnowCertificateProvider : NSObject

/**
 *  subclasses need to implement this function in a way that it returns SecIdentityRef with certificate and private key
 *  either from keychain or from .p12 file
 *
 *
 *  @return SecIdentityRef with certificate and private key
 */
- (SecIdentityRef)provideCertificateIdentity;

/**
 *  subclasses need to implement this function in a way that it returns the raw bytes containing the SHA256 fingerprint
 *  of the used server certificates
 *
 *  @return raw bytes of the SHA256 fingerprint
 */
- (NSArray<NSData*>*)provideServerFingerPrintByteStreams;

/**
 *  subclasses need to implement this function in a way that it returns the raw bytes
 *  of the used server certificates
 *
 *  @return raw bytes of the server certificates
 */
- (NSArray<NSData*>*)provideServerCertificateByteStreams;

/**
 *  these bool flags configure which features the underlying network connection uses
 */
- (BOOL)featureCertificate;  // DEFAULT: true
- (BOOL)featureFingerPrint;  // DEFAULT: true
- (BOOL)featureServerCert;   // DEFAULT: true

@end
