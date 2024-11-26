//
//  IDNDefaultCertificateProvider.h
//  IDnow
//
//  Created by Holger Kretzschmar on 28/12/2016.
//  Copyright © 2016 IDnow GmbH. All rights reserved.
//

#import "IDnowCertificateProvider.h"

@interface IDNMyMtlsCertificateProvider : IDnowCertificateProvider

@property (nonatomic, strong) NSString *clientCertFileName;

- (SecIdentityRef)provideCertificateIdentity;
- (NSArray<NSData*>*)provideServerFingerPrintByteStreams;

- (NSArray<NSData *> *)provideServerCertificateByteStreams;

- (NSArray<NSString *> *)availableClientCertificateFileNames;

@end
