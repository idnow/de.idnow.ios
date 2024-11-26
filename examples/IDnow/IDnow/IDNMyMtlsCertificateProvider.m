//
//  IDNDefaultCertificateProvider.m
//  IDnow
//
//  Created by Holger Kretzschmar on 28/12/2016.
//  Copyright © 2016 IDnow GmbH. All rights reserved.
//

#import "IDNMyMtlsCertificateProvider.h"

static NSString* TEST_SERVER_FINGERPRINT = @"90:5A:42:E5:A5:42:C3:9A:C9:FF:1E:F5:78:29:CB:F8:29:9B:C2:A0:4E:06:C6:B1:E7:3F:EE:F4:7B:D7:DE:AF";
static NSString* STAGING1_SERVER_FINGERPRINT = @"A3:8E:02:5C:B4:17:FA:2A:6D:A2:4F:BF:BF:2D:19:0C:52:E3:65:28:DC:4D:C7:61:18:E1:31:F1:44:BA:C8:06";

@interface IDNMyMtlsCertificateProvider()

@property (nonatomic, strong) NSMutableArray *serverCerts;

- (NSMutableData*)readBytesFromFile:(NSString*)fileName;

@end

@implementation IDNMyMtlsCertificateProvider

- (instancetype)init {
    self = [super init];
    if (self != nil) {
        self.serverCerts = [NSMutableArray array];
        [self loadServerCerts];
        
        self.clientCertFileName = self.availableClientCertificateFileNames.firstObject;
    }
    
    return self;
}

- (SecIdentityRef)provideCertificateIdentity {
    NSMutableData* data = [self readBytesFromFile:self.clientCertFileName];
    return [[self class] loadIdentityFromP12:data password:@"YOUR_PASSWORD"];
}

- (NSArray<NSData*>*)provideServerFingerPrintByteStreams
{
    NSMutableArray<NSData *>* data = [NSMutableArray new];
    for (NSString *fingerprint in @[STAGING1_SERVER_FINGERPRINT]) {
        [data addObject:[self dataFromHex:fingerprint]];
    }

    return data;
}

- (NSArray<NSData *> *)provideServerCertificateByteStreams {
    return self.serverCerts;
}

#pragma mark - Helpers

- (NSArray<NSString*> *)pathesForServerCerts {
    return [[NSBundle mainBundle] pathsForResourcesOfType:@"cer" inDirectory:@"server_certs"];
}

- (NSArray<NSString *> *)availableClientCertificateFileNames {
    return [[NSBundle mainBundle] pathsForResourcesOfType:@"p12" inDirectory:@"client_certs"];
}

- (NSMutableData*)readBytesFromFile:(NSString*)filePath
{
    NSFileManager* manager = [NSFileManager defaultManager];
    NSMutableData* data = nil;
    if ([manager fileExistsAtPath:filePath]) {
        data = [[NSMutableData alloc] initWithContentsOfFile:filePath];
    }
    
    return data;
}

- (NSData *)dataFromHex:(NSString *)hex {
    NSMutableData *result = [[NSMutableData alloc] init];
    NSString *sourceHex = [hex stringByReplacingOccurrencesOfString:@":" withString:@""];
    char currentByte[3] = {'\0','\0','\0'};
    for (int i = 0; i < [sourceHex length] / 2; i++) {
        currentByte[0] = [sourceHex characterAtIndex:i*2];
        currentByte[1] = [sourceHex characterAtIndex:i*2+1];
        char wholeByte = strtol(currentByte, NULL, 16);
        [result appendBytes:&wholeByte length:1];
    }
    
    return result;
}

- (void)loadServerCerts {
    NSArray* serverCertFileNames = [self pathesForServerCerts];
    
    [serverCertFileNames enumerateObjectsUsingBlock:^(NSString *fileName, NSUInteger idx, BOOL * _Nonnull stop) {
        NSData *data = [self readBytesFromFile:fileName];
        [self.serverCerts addObject:data];
    }];
}

#pragma mark - Loading cert identity

+ (SecIdentityRef)loadIdentityFromP12:(NSData *)p12Data password:(NSString *)password {
    const void *keys[] = { kSecImportExportPassphrase };
    const void *values[] = { (__bridge CFStringRef)password };
    CFDictionaryRef optionsDictionary = CFDictionaryCreate(NULL, keys, values, 1, NULL, NULL);
    CFArrayRef p12Items;
    OSStatus status = SecPKCS12Import((__bridge CFDataRef) p12Data, optionsDictionary, &p12Items);
    if (status != errSecSuccess) {
        return NULL;
    }
    
    CFDictionaryRef identityDict = CFArrayGetValueAtIndex(p12Items, 0);
    SecIdentityRef identityApp = (SecIdentityRef) CFDictionaryGetValue(identityDict, kSecImportItemIdentity);
    
    CFRetain(identityApp);
    CFRelease(optionsDictionary);
    CFRelease(p12Items);
    
    return identityApp;
}

+ (SecIdentityRef)loadIdentityFromKeychainWithTag:(NSString *)tag {
    NSDictionary *query = @{
        (id)kSecClass: (id)kSecClassIdentity,
        (id)kSecAttrLabel: tag,
        (id)kSecReturnRef: @YES,
    };

    SecIdentityRef identity = NULL;
    OSStatus status = SecItemCopyMatching((__bridge CFDictionaryRef)query, (CFTypeRef *)&identity);
    if (status != errSecSuccess) {
        return NULL;
    }
    
    return identity;
}

@end
