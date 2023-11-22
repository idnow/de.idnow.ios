//
//  IDNDefaultCertificateProvider.m
//  IDnow
//
//  Created by Holger Kretzschmar on 28/12/2016.
//  Copyright © 2016 IDnow GmbH. All rights reserved.
//

#import "IDNMyMtlsCertificateProvider.h"

static NSString* CLIENT_IDENTITY_FILENAME = @"client_cert.p12";
static NSString* TEST_SERVER_FINGERPRINT =
    @"90:3A:43:09:E3:34:6E:8F:EE:DA:03:11:5E:03:12:E0:3D:10:3D:19:67:40:70:A5:39:54:F5:75:CF:80:99:66";

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
    }
    
    return self;
}

- (SecIdentityRef)provideCertificateIdentity {
    NSMutableData* data = [self readBytesFromFile:[self pathForClientCert:CLIENT_IDENTITY_FILENAME]];
    return [[self class] loadIdentityFromP12:data password:@"unbreakablePassword"];
}

- (NSArray<NSData*>*)provideServerFingerPrintByteStreams
{
    NSData* data = [self dataFromHex:TEST_SERVER_FINGERPRINT];
    return @[data];
}

- (BOOL)verifyServerCertificate:(NSData*)serverCertificate {
    NSUInteger matchIndex = [self.serverCerts indexOfObjectPassingTest:^BOOL(NSData *obj, NSUInteger idx, BOOL * _Nonnull stop) {
        *stop = [serverCertificate isEqualToData:obj];
        return *stop;
    }];
    
    return matchIndex != NSNotFound;
}

#pragma mark - Helpers

- (NSString *)pathForClientCert:(NSString *)certFileName {
    NSString *relPath = [@"client_cert" stringByAppendingPathComponent:certFileName];
    return [[NSBundle mainBundle] pathForResource:relPath ofType:@""];
}

- (NSArray<NSString*> *)pathesForServerCerts {
    return [[NSBundle mainBundle] pathsForResourcesOfType:@"cer" inDirectory:@"server_certs"];
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
