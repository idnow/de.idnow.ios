# IDnowSDK

## Table of Contents

- [Requirements](#requirements)
- [Supported Versions](#supported-versions)
- [Compatibility, End of Support, End of Life](#compatibility-end-of-support-end-of-life)
- [Installation](#installation)
  - [CocoaPods](#cocoapods)
  - [Manually](#manually)
  - [Static XCFramework](#Static-XCFramework)
  - [Dynamic XCFramework](#Dynamic-XCFramework)
  - [Swift Package Manager (SPM) :package:](#swift-package-manager-spm-package)
- [Settings](#settings)
  - [transactionToken](#transactiontoken)
  - [companyID](#companyid)
  - [environment](#environment)
  - [showErrorSuccessScreen](#showerrorsuccessscreen)
  - [showVideoOverviewCheck](#showvideooverviewcheck)
  - [forceModalPresentation](#forcemodalpresentation)
  - [modalPresentationStyle](#modalpresentationstyle)
  - [apiHost](#apihost)
  - [websocketHost](#websockethost)
  - [connectionType](#connectiontype)
  - [certificateProvider](#certificateProvider)
- [Branding](#branding)
  - [Colors](#colors)
    - [defaultTextColor](#defaulttextcolor)
    - [primaryBrandColor](#primarybrandcolor)
    - [proceedButtonBackgroundColor](#proceedbuttonbackgroundcolor)
    - [proceedButtonTextColor](#proceedbuttontextcolor)
    - [photoIdentRetakeButtonBackgroundColor](#photoidentretakebuttonbackgroundcolor)
    - [photoIdentRetakeButtonTextColor](#photoidentretakebuttontextcolor)
    - [textFieldColor](#textfieldcolor)
    - [failureColor](#failurecolor)
    - [successColor](#successcolor)
    - [headlineColor](#headlineColor)
    - [linkColor](#linkColor)
    - [checkIconColor](#checkIconColor)
    - [primaryAlertActionColor](#primaryAlertActionColor)
    - [secondaryAlertActionColor](#secondaryAlertActionColor)
    - [CallQualityCheckScreen](#callqualitycheckscreen)
    - [cqcOuterRingColor](#cqcouterringcolor)
    - [proceedButtonTextColor](#proceedbuttontextcolor)
    - [cqcDefaultInnerRingColor](#cqcdefaultinnerringcolor)
    - [cqcPoorQualityInnerColor](#cqcpoorqualityinnercolor)
    - [cqcModerateQualityInnerColor](#cqcmoderatequalityinnercolor)
    - [cqcExcellentQualityInnerColor](#cqcexcellentqualityinnercolor)
  - [StatusBar](#statusbar) 
    - [enableStatusBarStyleLightContent](#enablestatusbarstylelightcontent)
  - [Fonts](#fonts) 
    - [fontNameRegular](#fontnameregular)
    - [fontNameMedium](#fontnamemedium)
    - [fontNameLight](#fontnamelight)
    - [underlineButtonTitles](#underlineButtonTitles)
    - [boldButtonTitles](#boldButtonTitles)
- [PushNotifications](#pushnotifications)
- [Usage](#usage)
- [Localization](#localization)
  - [Example](#example) 
- [eID Framework](#eid-framework)
  - [eID Requirements](#eid-requirements)
  - [eID Installation](#eid-installation)
- [Host App settings](#host-app-settings)
  - [eID Usage](#eid-usage)
    - [Objective C](#objective-c)
    - [Swift](#swift)
- [eID Branding (IDN_eIDAppearance)](#eid-branding-(IDN_eIDAppearance))
  - [eID Colors](#eid-colors)
    - [defaultTextColor](#defaulttextcolor)
    - [primaryBrandColor](#primarybrandcolor)
    - [proceedButtonBackgroundColor](#proceedbuttonbackgroundcolor)
    - [proceedButtonTextColor](#proceedbuttontextcolor)
    - [textFieldColor](#textfieldcolor)
  - [eID Fonts](#eid-fonts)
    - [fontNameRegular](#fontnameregular)
    - [fontNameBold](#fontnamebold)
  - [eID Button styles](#eid-button-styles)
    - [underlineButtonTitles](#underlinebuttontitles)
    - [boldButtonTitles](#boldButtonTitles)
- [eID Usage example](#eid-usage-example)
  - [Swift](#swift)
    - [Error codes](#error-codes)
  - [Objective C](#Objective-C)
    - [Error codes](#error-codes)
  
## Requirements

- Xcode 14.3 or above for Swift Package Manager (SPM)
- Cocoapods installed v1.11.2 or above (Note: Xcdoe 15 requires Cocoapods v1.13.0 or above)
- Device with WiFi/3G/LTE

## Supported Versions
- Your current SDK will stop receiving further support by May 21 (VideoIdent SDKs of version 4.2.0 and lower; 4.2.1 and higher continue to be supported)
- After this time, the old SDK will continue to be operational, but we won’t provide any more updates and maintenance only with additional reimbursement
- Versions of IDnowSDK lower when v5.2.0 may have issues with iOS higher when 16.0
- Since Apple deprecated bitcode and the App Store no longer accepts bitcode submissions we have removed bitcode support from IDnow SDK starting from version 6.1.3
- SDK versions started from 6.0.0 to 6.1.3 were archived using Xcode 14. Therefore, they are likely to have compatibility issues with Xcode 13 and lower. To fix this, starting v6.1.4, we temporarily reverted to the older Xcode version 13.2.1, which is compatible with Xcode 13.x as well as Xcode 14.x.

## Compatibility, End of Support, End of Life

Please refer to the following link to find information about compatibility, end-of-support (EOS) and end-of-life (EOL) dates pertaining to our products: [IDnow Compatibility Matrix: Browser & OS Compatibility guide](https://www.idnow.io/developers/compatibility-overview/)

## Installation

### CocoaPods

[![Watch the video](/screenshots/Screenshot_vid.png)](https://www.youtube.com/watch?v=kLCUDDoHwlQ)

- Add the following config and pod dependencies to your podfile:
```
use_frameworks!
pod 'IDnowSDK'
```

- Then, run the following command:
```
pod install
```

- Import SDK by using "@import IDnowSDK"

Note: This is only available for Xcode 14.3 or above.

When integrating VideoIdent SDK into your project, please ensure you add the -ObjC flag to your project's Other Linker Flags. This can be done by:
1. Opening your project in Xcode
2. Navigating to the project settings
3. Selecting your application target
4. Going to the ‘Build Settings’ tab
5. Searching for Other Linker Flags
6. Adding -ObjC to the list of flags

### Manually 

[![Watch the video](/screenshots/Screenshot_vid.png)](https://www.youtube.com/watch?v=eHawhnaCcas)

### Static XCFramework

- Download idnow_vi_static.xcframework-<version>.tar.gz and copy the idnow_vi_static.xcframework folder to your project directory
- Or add the repo as a git submodule (git lfs required. For the initial checkout do git lfs pull)
- Drag idnow_vi_static.xcframework into your Xcode project
- Add to your "Link binary with libraries" section
  
```
AudioToolbox.framework
VideoToolbox.framework
AVFoundation.framework
CoreMedia.framework
GLKit.framework
OpenGLES.framework
SystemConfiguration.framework
Webkit.framework
StoreKit.framework
Accelerate.framework
```   
- import 'IDnowSDK.h' // --> Objective-C Project
- or import IDnowSDK // --> Swift Project

__Note__: To get the sample projects work, you have to call "pod install" to install dependencies.

### Dynamic XCFramework 

- Download the current release from and copy the idnow_vi.xcframework folder to your project directory.

- Or add the repo as a git submodule (git lfs required. For the initial checkout do git lfs pull)

- Add idnow_vi.xcframework folder into Embed Frameworks of your Xcode project as embed and signed.

- import 'idnow_vi.h' // --> Objective-C Project

- or import idnow_vi // --> Swift Project

### Swift Package Manager (SPM) :package:

With the release of VideoIdent SDK v7.4.1, we have added support for SPM by providing the corresponding dynamic XCFramework as a Package Product. Please refer to the following documentation in order to add the swift package to your project:
https://developer.apple.com/documentation/swift_packages/adding_package_dependencies_to_your_app

- Add swift package: `https://github.com/idnow/de.idnow.ios` as dependency ![swift_package_manager_choose](/screenshots/Screenshot_spm.png)
- Import SDK module into your code: `import idnow_vi`
- Reference [spm example project](/examples/spm-example-idnow)

Note: This is only available for Xcode 14.3 or above.

## Settings
The settings that should be used for the identification process provided by IDnow.

#### transactionToken
A token that will be used for instantiating a photo or video identification.

#### companyID
Your company id provided by IDnow.

#### environment
Optional: The environment that should be used for the identification (DEV, TEST, LIVE)
The default value is `IDnowEnvironmentNotDefined`. 
The used environment will then base on the prefix of the transaction token (DEV -> DEV, TST -> Test, else -> Live).
You can use the special IDnowEnvironmentCustom to define a custom IDnow installation. If this is done, you need to set the apiHost and websocketHost.

#### showErrorSuccessScreen
Optional: If set to `false`, the Error-Success-Screen provided by the SDK will not be displayed.
The default value of this property is `true`.

#### showVideoOverviewCheck
Optional: If set to `false`, the video overview check screen will not be shown befsore starting a video identification.
The default value of this property is `true`.

#### forceModalPresentation
Optional: If set to `true`, the UI for the identification will always be displayed modal. 
By default the value of this property is `false` and the identification UI will be pushed on an existing navigation controller if possible.

#### modalPresentationStyle
Optional: Specifies the presentation style for the modal ident viewcontroller.
E.g. Can be set to `UIModalPresentationCurrentContext` to allow presenting ident view controller within a popover on an iPad.
 
#### apiHost
The target server url for REST calls if custom server is used.

#### websocketHost
The target server url for websocket calls if custom server is used.

#### connectionType
The connection type to use to talk the backend. (Websocket)

#### certificateProvider

(supported by the SDK version 3.22.1 or before )

For custom DTLS certificates use certificateProvider parameter of IDnowSettings

 Sets a certificate provider for custom DTLS certificates used by the WebRTC connection.
 The certificate provider can be used to provide a custom DTLS certificate (featureCertificate == YES) and/or to check the
 SHA fingerprint of the server certificate (featureFingerprint == YES)
 
@property (strong, nullable, nonatomic)IDnowCertificateProvider* certificateProvider;


Starting from SDK version 6.5.0 we offer MTLS support for API connections

MTLS enables server/client certificate validation. SDK can provide custom client certificate and several server certificates

What has changed:

- Certificate provider now can validate multiple server certificates/fingerprints
- REST supports MTLS
- WebSocket supports MTLS. For this purpose, SRWebsocket implementation was slightly updated. So, now we have a local version of SRWebsocket.

To enable mTLS, it should be available in customer backend setting and client (consumer) should supply certificate provider to our SDK.

Certificate Generation :

Client certificate and private key pair can be generated in a number of ways, for example, with Certificate Sign Request on Mac OS X Keychain.

Client Certificates :

For iOS, key pair can be imported by platform tools from p12 package format. For example:

```

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
```


How to do it:

1- Create class similar to IDNMyMtlsCertificateProvider in ios folder

2- During SDK configuration:

[IDnowSettings sharedSettings].certificateProvider = [[IDNMyMtlsCertificateProvider alloc] init];

Feature flags for certificate provider allow usage of the corresponding features:

```
- (BOOL)featureCertificate;  // use client certificate
- (BOOL)featureFingerPrint;  // use server certificate fingerprints
- (BOOL)featureServerCert;   // use server certificates
```

Please check the certificate provider + certificates here https://github.com/idnow/de.idnow.ios/tree/master/IDnow 


## Branding
Warning: Branding is only allowed if you have the permissions from IDnow.

### Colors

#### defaultTextColor
Optional color, that replaces the default text color.
Default: A nearly black color
Recommendation: Should be some kind of a dark color that does not collide with white color.

#### primaryBrandColor
Optional color, that replaces the default brand color.
Default: defaultTextColor
Used in headlines, checkboxes, links, alerts etc.
Recommendation: Should be a color that does not collide with white color.

#### proceedButtonBackgroundColor
Optional color, that replaces the proceed button background color.
Default: An orange color

#### proceedButtonTextColor
Optional color, that replaces the proceed button text color.
Default value: White color

#### photoIdentRetakeButtonBackgroundColor
Optional color, that replaces the photo ident retake button background color.
Default value: defaultTextColor

#### photoIdentRetakeButtonTextColor
Optional color, that replaces the photo ident retake button text color.
Default value: proceedButtonTextColor

#### textFieldColor
Optional color, that replaces the default color of textfield backgrounds and borders
Default: defaultTextColor

#### failureColor
Optional color, that replaces the text color in the result screen, when an identification failed.
Default: A red color

#### successColor
Optional color, that replaces the text color in the result screen, when an identification was successful.
Default: A green color

#### headlineColor
Optional color, that replaces the color that will be used for headlines.
Default: primaryBrandColor.
Recommendation: Should be a color that does not collide with white color.

#### linkColor
Optional color, that replaces the color that will be used for links.
Default: primaryBrandColor.
Recommendation: Should be a color that does not collide with white color.

#### checkIconColor
Optional color, that replaces the color that will be used for checkboxes.
Default: primaryBrandColor.
Recommendation: Should be a color that does not collide with white color.

#### primaryAlertActionColor
Optional color, that replaces the color on the left action of alert controller
Default: Default: lighter grey color (#8D96A6)

#### secondaryAlertActionColor
Optional color, that replaces the color on the right action of alert controller
Default: black for light mode and white for dark mode.

#### CallQualityCheckScreen

#### cqcOuterRingColor
Optional color that replaces default dark gray for the outer ring indicator on the quality check screen.
Default: dark gray

#### cqcDefaultInnerRingColor
Optional color that replaces default light gray for the inner ring indicator on the quality check screen.
Default: light gray

#### cqcPoorQualityInnerColor
Optional color that replaces default bright red for the inner ring indicator in case bad network quality on the quality check screen.
Default: bright red

#### cqcModerateQualityInnerColor
Optional color that replaces default bright orange for the inner ring indicator in case moderate network quality on the quality check screen.
Default: bright orange

#### cqcExcellentQualityInnerColor
Optional color that replaces default strong yellow for the inner ring indicator in case excellent network quality on the quality check screen.
Default: strong yellow (almost green).

### StatusBar

#### enableStatusBarStyleLightContent
Optional: Forces the light status bar style to match dark navigation bars.
If you tint your navigation bar with a dark color by adjusting navigation bar appearance (e.g. a blue color) you can set this value to true. The statusbar style will then be adjusted to light in screens where the navigation bar is visible.

### Fonts

#### fontNameRegular
An optional font name that can be used to replace the regular font used by the SDK.
Default: System Font: Helvetica Neue Regular (< iOS 9), San Francisco Regular (>= iOS 9)

#### fontNameMedium
An optional font name that can be used to replace the medium font used by the SDK.
Default: System Font: Helvetica Neue Medium (< iOS 9), San Francisco Medium (>= iOS 9)

#### fontNameLight
An optional font name that can be used to replace the light font used by the SDK.
Default: System Font: Helvetica Neue Light (< iOS 9), San Francisco Light (>= iOS 9)

#### underlineButtonTitles
Default: YES - Underline all button titles
Set this to NO in order to underline button title text

#### boldButtonTitles
Default: YES - Make button titles bold
Set this to NO in order to use normal font weight in button titles

## PushNotifications

In order to use push notifications via the IDnow SDK it is neccessary that your own AppDelegate inherits from 
the provided IDnowAppDelegate. This is neccessary since the callbacks form Apple concerning registration and 
reception of push notifications is soley handled through the AppDelegate which is not part of our SDK. In case your
own AppDelegate implements interfaces present in the IDnow SDK please make sure to make a 
call the super classes (IDnowAppDelegate) implementation as well.

Additionally we will need the production certifcate/key pair to send notifications via push to your app via
our backend.

```objective-c

// header
@interface YourAppDelegate : IDnowAppDelegate

@end

// implementation
@implementation YourAppDelegate

- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error
{
    [super application:application didFailToRegisterForRemoteNotificationsWithError:error];
}

- (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings
{
    [super application:application didRegisterUserNotificationSettings:notificationSettings];
}

- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(nonnull NSData*)deviceToken
{
    [super application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions
{
    [super application:application didFinishLaunchingWithOptions:launchOptions];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    [super application:application didReceiveRemoteNotification:userInfo];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
                                                       fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler
{
    [super application:application didReceiveRemoteNotification:userInfo
                                         fetchCompletionHandler:completionHandler];
}

@end


```

## Usage

```objective-c

// Setup IDnowAppearance
IDnowAppearance *appearance = [IDnowAppearance sharedAppearance];
    
// Adjust colors
appearance.defaultTextColor = [UIColor blackColor];
appearance.primaryBrandColor = [UIColor blueColor];
appearance.proceedButtonBackgroundColor = [UIColor orangeColor];
appearance.failureColor = [UIColor redColor];
appearance.successColor = [UIColor greenColor];
    
// Adjust statusbar
appearance.enableStatusBarStyleLightContent = YES;
    
// Adjust fonts
appearance.fontNameRegular = @"AmericanTypewriter";
appearance.fontNameLight = @"AmericanTypewriter-Light";
appearance.fontNameMedium = @"AmericanTypewriter-CondensedBold";

// To adjust navigation bar / bar button items etc. you should follow Apples UIAppearance protocol.

// Setup IDnowSettings
IDnowSettings *settings = [IDnowSettings settingsWithCompanyID:@"yourCompanyIdentifier"];
settings.transactionToken = @"DEV-TXTXT";

// Initialise and start identification
IDnowController *idnowController = [[IDnowController alloc] initWithSettings: settings];

// Initialize identification using blocks 
// (alternatively you can set the delegate and implement the IDnowControllerDelegate protocol)
[idnowController initializeWithCompletionBlock: ^(BOOL success, NSError *error, BOOL canceledByUser)
{
        if ( success )
        {
              // Start identification using blocks
              [idnowController startIdentificationFromViewController: self 
              withCompletionBlock: ^(BOOL success, NSError *error, BOOL canceledByUser)
              {
                      if ( success )
                      {
                          // identification was successfull
                      }
                      else
                      {
                          // identification failed / canceled
                      }
                }];
        }
        else if ( error )
        {
              // Present an alert containing localized error description
              UIAlertController *alertController = [UIAlertController alertControllerWithTitle: @"Error" 
              message: error.localizedDescription 
              preferredStyle: UIAlertControllerStyleAlert];
              UIAlertAction *action = [UIAlertAction actionWithTitle: @"Ok" 
              style: UIAlertActionStyleCancel 
              handler: nil];
              [alertController addAction: action];
              [self presentViewController: alertController animated: true completion: nil];
        }
    }];
```

You can also change some of the optional settings:

```objective-c
// Optionally disable success and error screens
settings.showErrorSuccessScreen = NO;
settings.showVideoOverviewCheck = NO;
settings.forceModalPresentation = YES;
settings.showIdentTokenOnCheckScreen = YES;

// Optionally enable custom server with long polling
settings.environment = IDnowEnvironmentCustom;
settings.apiHost = @"https://api.yourserver.com";
settings.websocketHost = @"https://websocket.yourserver.com";
settings.connectionType = IDnowConnectionTypeLongPolling;
```

## Localization
Warning: Adapting localizations is only allowed if you have the permissions from IDnow.

In case you would like to change the localization used by the IDnow SDK at runtime you can do:

Allowed values are: en (English), de (German), fr (French), es (Spanish), it (Italian), pt (Portugese), et (Estonian), hr (Croatian), hu (Hungarian), ka (Georgian), ko(Korean), lt(Lithuanian), lv (Latvian), nl (Dutch), pl (Polish),  ru (Russian), zh (Chinese).
```
settings.userInterfaceLanguage = @"de"; // this field accepts the following languages (de, en, it, es, pt, fr, et, hr, hu, ka, ko, lt, lv, nl, pl, ru, zh).

```
English and German Localizations are provided by the SDK (IDnowSDKLocalization.bundle)
You can overwrite localisation in your own Localizable.strings files.


### Example
```
//Defined in the IDnowSDKLocalization.bundle
"NAVIGATION_ITEM_TITLE_DEFAULT" = "IDnow";

//Overwrite in your Localizable.strings file:
"NAVIGATION_ITEM_TITLE_DEFAULT" = "Video Ident";
```

# eID Framework

---

## eID Requirements
- Xcode 14.3 or later
- Deployment Target: iOS 11.0 or later
__Note__: NFC can work only with iPhone 7 and higher

----
## eID Installation
# Host app settings 
- Add the `idnow_eid.framework`, `CoreNFC.framework` to `Link Binary With Libraries`. And the AAL framework must be added to your Xcode project as well. You can simply drag and drop the `AuthadaAuthenticationLibrary.xcframework` folder to your Xcode project.![alt text](/screenshots/eid_screenshot_1.png)

- Add `Near Field Communication Tag Reading` as a capability. In the entitlements file, check if there is an array for the key `Near Field Communication Tag Reader Session Format`, make sure the array contains the entry `NFC tag-specific data protocol`. ![alt text](/screenshots/eid_screenshot_2.png)
- Update the Info.plis file:
-- Add an array with the key `com.apple.developer.nfc.readersession.iso7816.select-identifiers` / `ISO7816 application identifiers for NFC Tag Reader Session`. Then add 2 items to the array: `E80704007F00070302`, `A0000002471001`.
-- Add a description for `Privacy - NFC Scan Usage Description`
![alt text](/screenshots/eid_screenshot_3.png)
    __NOTE__: 
    - Due to technical reasons, we cannot make the following library available on Github: `AuthadaAuthenticationLibrary.xcframework`. Please contact your customer success manager so they can provide it to you.
    - Make sure both `AuthadaAuthenticationLibrary` and `idnow_eid` framework are added in `Embeded Frameworks` section
    
### eID Usage:
#### Objective C
```
@import idnow_eid;
```
#### Swift

```
import idnow_eid
```
## eID Branding (IDN_eIDAppearance)
All appearance settings are identical to the ones used in VI SDK.
**Warning**: Branding is only allowed if you have the permissions from IDnow.

### eID Colors

#### defaultTextColor
Optional color, that replaces the default text color.
Default: A nearly black color
Recommendation: Should be some kind of a dark color that does not collide with white color.

#### primaryBrandColor
Optional color, that replaces the default brand color.
Recommendation: Should be a color that does not collide with white color.

#### proceedButtonBackgroundColor
Optional color, that replaces the proceed button background color.
Default: An orange color

#### proceedButtonTextColor
Optional color, that replaces the proceed button text color.
Default value: White color

#### textFieldColor
Optional color, that replaces the default color of textfield backgrounds and borders
Default: defaultTextColor

### eID Fonts

#### fontNameRegular
An optional font name that can be used to replace the regular font used by the SDK.
Default: System regular Font

#### fontNameBold
An optional font name that can be used to replace the bold font used by the SDK.
Default: System bold Font

### eID Button styles
#### underlineButtonTitles
Default: YES - Underline all button titles
Set this to NO in order to underline button title text
#### boldButtonTitles
Default: YES - Make button titles bold
Set this to NO in order to use normal font weight in button titles
## eID Usage example
### Swift
```
        let eidAppearance = IDN_eIDAppearance.shared
        eidAppearance.underlineButtonTitles = false
        eidAppearance.fontNameBold          = "TimesNewRomanPS-BoldMT"
        eidAppearance.fontNameRegular       = "TimesNewRomanPSMT"
        eidAppearance.primaryBrandColor     = .cyan
        eidAppearance.proceedButtonBackgroundColor = .magenta
        eidAppearance.linkColor             = .systemBlue
```
```
guard let token = textField.text, !token.isEmpty else { 
            // input token validate
            return
        }
        eidRouter = IDN_eIDRouter(
            withControlller: self,
            token: token,            
            completion: { [unowned self] (support, error) in
                if support {
                    self.eidRouter.present { 
                    (identSuccess, continueVideoIdent, error) in
                        if continueVideoIdent { 
                            print("LOG: - Continue video identification")
                        } else if let error = error {
                            print("LOG: - Failed \(error)")
                        } else {
                            print("LOG: - Identification finished \(identSuccess ? "Successfully" : "Failed")")
                        }
                    }
                } else {
                    print("LOG: - Device not support nfc ")
                }
        })
```
#### Error codes
```
enum IDN_eIDError : Int, Error {
    case unsupportedNFC
    case userCancelled
    case invalidToken
    case preconditionFailed
    case tokenUnsupportElectronicCard
    case unknown
}
```
### Objective-C
```
    IDN_eIDAppearance *appearance = IDN_eIDAppearance.shared;
    appearance.primaryBrandColor             = UIColor.cyanColor;
    appearance.proceedButtonBackgroundColor = UIColor.magentaColor;
    appearance.linkColor                    = UIColor.blueColor;
    appearance.underlineButtonTitles        = false;
    appearance.fontNameRegular     = @"TimesNewRomanPSMT";
    appearance.fontNameBold        = @"TimesNewRomanPS-BoldMT";
```

```
self.eidRouter = [[IDN_eIDRouter alloc]
                      initWithControlller:self
                      token: token
                      completion:^(BOOL supported, NSError * error) {
        if (supported) { // device supported, and can continue eID
            [self.eidRouter present:^(BOOL success, BOOL
                                      continueVideoIdent,
                                      NSError * error) {
                if (continueVideoIdent) { // Start video ident
                    NSLog(@"LOG: - Video identification");
                }
                else if (error) {
                    NSLog(@"LOG: - Error %@", error.localizedDescription);
                } else {
                    NSLog(@"LOG: - Identification finished with %s",
                    success ? "Successfully" : "Failed" );
                }
            }];
        } else {
            NSLog(@"LOG: - Device doesnot support");
        }
    }];
```
#### Error codes:
```
  IDN_eIDErrorUnsupportedNFC
  IDN_eIDErrorUserCancelled
  IDN_eIDErrorInvalidToken
  IDN_eIDErrorPreconditionFailed
  IDN_eIDErrorTokenUnsupportElectronicCard
  IDN_eIDErrorUnknown
 ```
