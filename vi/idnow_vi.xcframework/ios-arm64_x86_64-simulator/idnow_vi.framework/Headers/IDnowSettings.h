//
//  IDnowSettings.h
//  IDnow
//
//  Created by Matthias Redlin on 19.03.15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDNLogClient.h"


NS_ASSUME_NONNULL_BEGIN

// -----------------------------------------------------------------------------------
//									Enumerations
// -----------------------------------------------------------------------------------

typedef NS_ENUM(NSInteger, IDnowEnvironment);

/**
 * forward declaration of the certificate provider interface
 */
@class IDnowCertificateProvider;
@class IDnowDtlsCertificateProvider;
@class IDnowSettings;

#ifndef IDNowSettings_h
#define IDNowSettings_h

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
     *  Dev0 server environment
     */
    IDnowEnvironmentDev0,
    /**
     *  Dev1 server environment
     */
    IDnowEnvironmentDev1,
    /**
     *  Dev2 server environment
     */
    IDnowEnvironmentDev2,
    /**
     *  Dev3 server environment
     */
    IDnowEnvironmentDev3,
    /**
     *  Dev4 server environment
     */
    IDnowEnvironmentDev4,
    /**
      *  Dev5 server environment
      */
     IDnowEnvironmentDev5,
    /**
      *  Dev6 server environment
      */
     IDnowEnvironmentDev6,
    /**
      *  Dev7 server environment
      */
     IDnowEnvironmentDev7,
    /**
      *  Dev8 server environment
      */
     IDnowEnvironmentDev8,
    /**
      *  Dev9 server environment
      */
     IDnowEnvironmentDev9,
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
     *  Staging server environment
     */
    IDnowEnvironmentStag1,
    /**
     *  Live server environment
     */
    IDnowEnvironmentLive,
    /**
     *  Intrum server environment
     */
    IDnowEnvironmentIntrum,
    /**
     *  Intrum test server environment
     */
    IDnowEnvironmentIntrumTest,
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

// -----------------------------------------------------------------------------------
//                                    Initialization
// -----------------------------------------------------------------------------------

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
 *    @param transactionToken A token used for instantiating a photo or video identification.
 *
 *  @return An IDnowSettings instance.
 */
+ (instancetype) settingsWithCompanyID: (NSString *) companyID transactionToken: (NSString *) transactionToken;



// -----------------------------------------------------------------------------------
//                                    Basic Properties
// -----------------------------------------------------------------------------------

/**
 *  A token that will be used for instantiating a photo or video identification.
 */
@property (nullable, strong, nonatomic) NSString *transactionToken;

/**
 *  The company id provided by IDnow.
 */
@property (nullable, strong, nonatomic) NSString *companyID;

// -----------------------------------------------------------------------------------
//                                    Extended Properties (optional)
// -----------------------------------------------------------------------------------

/**
 *  If this is set to YES the ident token will be visible on the check screen page
 *  as well. The default value of this property is `NO`.
 */
@property (assign, nonatomic) BOOL showIdentTokenOnCheckScreen;

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
 * If set to `YES`, a failed / canceled / finished identification will be forced to display the result screen.
 */
@property (assign, nonatomic) BOOL forceErrorSuccessScreen;

/**
 * Specifies the presentation style for the modal ident viewcontroller.
 * E.g. Can be set to `UIModalPresentationCurrentContext` to allow presenting ident view controller within a popover on an iPad.
 */
@property (assign, nonatomic) UIModalPresentationStyle modalPresentationStyle;

/**
 * Sets a certificate provider for custom DTLS certificates used by the WebRTC connection.
 * The certificate provider can be used to provide a custom DTLS certificate (featureCertificate == YES) and/or to check the
 * SHA fingerprint of the server certificate (featureFingerprint == YES)
 */
@property (strong, nullable, nonatomic) IDnowCertificateProvider* certificateProvider;

@property (strong, nullable, nonatomic) IDnowDtlsCertificateProvider* dtlsCertificateProvider;

@property (strong, nullable, nonatomic)IDnowDtlsCertificateProvider* dtlsUDPCertificateProvider;

/**
 * The device token is needed to uniquely identify the device. Its used to send push notifications.
 */
@property (strong, nullable, nonatomic)NSString* pushDeviceToken;

/**
 * If you use Sentry with your app, set sentryDSN to https://login:secret@<sentry-fqdn>/<project>
 */
@property (strong, nullable, nonatomic)NSString* sentryDSN;
 /* The name the resulting app should use in the UINavigation bar
 */
@property (strong, nullable, nonatomic)NSString* productName;

/**
 *  If true the first api request will take the token instead of the companyid into account.
 */
@property (assign, nonatomic) BOOL ignoreCompanyID;

/**
 * The current logger instance that implement IDNLogClient interface.
 * Responsible for log events to a External logger
 */
@property (strong, nonatomic) id<IDNLogClient> externalLogger;

/**
 * Waiting screen
 * Paging time interval
 * 10s by default, equal with animated video duration
 */
@property (assign, nonatomic) double automaticPagingTimeInterval;

// -----------------------------------------------------------------------------------
//                                    Localization
// -----------------------------------------------------------------------------------

/**
 * This sets the user interface language. Allowed values are: en (English), de (German), fr (French),
 * es (Spanish), it (Italian), pt (Portugese), et (Estonian), hr (Croatian), hu (Hungarian), ka (Georgian), ko(Korean), lt(Lithuanian), lv (Latvian), nl (Dutch), pl (Polish),  ru (Russian), zh (Chinese).
 */
@property (nullable, strong, nonatomic) NSString* userInterfaceLanguage;

// -----------------------------------------------------------------------------------
//                                    Server Properties (optional)
// -----------------------------------------------------------------------------------

/**
 *  Optional: The environment that should be used for the identification (DEV, TEST, LIVE, Custom)
 *  The default value is `IDnowEnvironmentNotDefined`.
 *  Then the used environment is based on the prefix of the transaction token (DEV -> DEV, TST -> Test, TS1 -> Test1, TS2 -> Test2, TS3 -> Test3, else -> Live).
 *  You can use the special IDnowEnvironmentCustom to define a custom IDnow installation. If this is done, you need to set the apiHost and websocketHost.
 */
@property (assign, nonatomic) IDnowEnvironment environment;

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

// -----------------------------------------------------------------------------------
//                                    Unified Ident (optional)
// -----------------------------------------------------------------------------------

/**
 *  The sdk is a part of Unified Ident
 */
@property (assign, nonatomic) BOOL isUnifiedIdent;

/**
 *  should show Unified Ident popup
 */
@property (assign, nonatomic) BOOL showUnifiedIdentPopUp;

/**
 *  token should be shown within ErrorSuccessScreen
 *  by default transactionToken will be shown
 */
@property (nullable, strong, nonatomic) NSString *finishScreenToken;

/**
 *  User forced to quit ident flow from Unified ident prompt
 */
@property (assign, nonatomic) BOOL userForcedToQuit;

@end



#endif /* IDNowSettings_h */

NS_ASSUME_NONNULL_END
