//
//  IDnowSettings.h
//  IDnow
//
//  Created by Matthias Redlin on 19.03.15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Possible server environments for executing an identification
 */
typedef NS_ENUM (NSInteger, IDnowEnvironment)
{
    /**
     *  Server environment not defined
     */
    IDnowEnvironmentNotDefined,
    /**
     *  Dev server environment
     */
    IDnowEnvironmentDev,
    /**
     *  Test server environment
     */
    IDnowEnvironmentTest,
    /**
     *  Test server environment
     */
    IDnowEnvironmentTest1,
    /**
     *  Test server environment
     */
    IDnowEnvironmentTest2,
    /**
     *  Test server environment
     */
    IDnowEnvironmentTest3,
    /**
     *  Live server environment
     */
    IDnowEnvironmentLive,
    /**
     *  Custom server environment
     */
    IDnowEnvironmentCustom
};

/**
 *  The type of connection used to get events from the backend
 */
typedef NS_ENUM (NSInteger, IDnowConnectionType)
{
    /**
     *  Use websockets using SocketRocket (default)
     */
    IDnowConnectionTypeWebsocket,
    /**
     *  Use long polling
     */
    IDnowConnectionTypeLongPolling
};

/**
 *  This class is used to instantiate an instance of IDnowController.
 *  It lets you customize the identification process.
 *  At least a transactionToken and a companyID have to be set before calling [IDnowController initialize].
 *  You can also explicitly set the environment, which describes on which server the identificaton will be executed.
 */
@interface IDnowSettings : NSObject

/**
 *  Creates an instance of IDnowSettings taking a company identifier into account.
 *
 *  @param companyID The company identifier provided by IDnow.
 *
 *  @return An IDnowSettings instance.
 */
+ (instancetype) settingsWithCompanyID: (NSString *) companyID;

/**
 *  Creates an instance of IDnowSettings taking a company identifier and a transaction token into account.
 *
 *  @param companyID The company identifier provided by IDnow.
 *
 *	@param transactionToken A token used for instantiating a photo or video identification.
 *
 *  @return An IDnowSettings instance.
 */
+ (instancetype) settingsWithCompanyID: (NSString *) companyID transactionToken: (NSString *) transactionToken;

/**
 *  A token that will be used for instantiating a photo or video identification.
 */
@property (nullable, strong, nonatomic) NSString *transactionToken;

/**
 *  The company id provided by IDnow.
 */
@property (nullable, strong, nonatomic) NSString *companyID;

/**
 *  Optional: The environment that should be used for the identification (DEV, TEST, LIVE, Custom)
 *  The default value is `IDnowEnvironmentNotDefined`. 
 *  Then the used environment is based on the prefix of the transaction token (DEV -> DEV, TST -> Test, TS1 -> Test1, TS2 -> Test2, TS3 -> Test3, else -> Live).
 *  You can use the special IDnowEnvironmentCustom to define a custom IDnow installation. If this is done, you need to set the apiHost and websocketHost.
 */
@property (assign, nonatomic) IDnowEnvironment environment;

/**
 *  If set to `false`, the Error-Success-Screen provided by the SDK will not be shown.
 *  The default value of this property is `true`.
 */
@property (assign, nonatomic) BOOL showErrorSuccessScreen;

/**
 *  If set to `false`, the video overview check screen will not be shown before starting a video identification.
 *  The default value of this property is `true`.
 */
@property (assign, nonatomic) BOOL showVideoOverviewCheck;

/**
 *  If set to `true`, the UI for the identification will always be displayed modal. 
 *  By default the value of this property is `false` and the identification UI 
 *  will be pushed on an existing navigation controller if possible.
 */
@property (assign, nonatomic) BOOL forceModalPresentation;

/**
 *  If set to `true`, the SDK will accept invalid (e.g. self signed certificates).
 *  Please note that iOS might still reject the certs if you dont also set
 *  NSAllowsArbitraryLoads in NSAppTransportSecurity and also NSTemporaryExceptionAllowsInsecureHTTPLoads
 *  in NSExceptionDomains for your domains
 */
@property (assign, nonatomic) BOOL allowInvalidCertificates;

/**
 *  The target server url for REST calls if custom server is used
 */
@property (nullable, strong, nonatomic) NSString *apiHost;

/**
 *  The target server url for websocket calls if custom server is used
 */
@property (nullable, strong, nonatomic) NSString *websocketHost;

/**
 *  The target server url for video rest calls if custom server is used
 */
@property (nullable, strong, nonatomic) NSString *videoHost;

/**
 *  The target server for stun calls if custom server is used
 */
@property (nullable, strong, nonatomic) NSString *stunHost;

/**
 *  The target port for stun calls if custom server is used
 */
@property (assign, nonatomic) NSInteger stunPort;

/**
 *  The connection type to use to talk the backend
 */
@property (assign, nonatomic) IDnowConnectionType connectionType;

@end

NS_ASSUME_NONNULL_END