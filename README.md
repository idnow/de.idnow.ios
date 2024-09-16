# IDnowSDK

## Table of Contents

- [IDnowSDK](#idnowsdk)
  - [Table of Contents](#table-of-contents)
  - [Requirements](#requirements)
  - [Supported Versions](#supported-versions)
  - [Compatibility, End of Support, End of Life](#compatibility-end-of-support-end-of-life)
  - [Installation](#installation)
    - [CocoaPods](#cocoapods)
    - [Manually](#manually)
      - [Static XCFramework](#static-xcframework)
      - [Dynamic XCFramework](#dynamic-xcframework)
    - [Swift Package Manager (SPM) :package:](#swift-package-manager-spm-package)
  - [Usage](#usage)
      - [Swift](#swift)
      - [Objective C](#objective-c)
      - [Swift](#swift-1)
      - [Objective C](#objective-c-1)
      - [Swift](#swift-2)
      - [Objective C](#objective-c-2)
      - [Swift](#swift-3)
      - [Objective C](#objective-c-3)
      - [Swift](#swift-4)
      - [Objective C](#objective-c-4)
    - [Settings](#settings)
      - [Swift](#swift-5)
      - [Objective C](#objective-c-5)
  - [Custom Certificate Providers](#custom-certificate-providers)
      - [DTLS](#dtls)
      - [mTLS](#mtls)
  - [Branding](#branding)
    - [Colors](#colors)
    - [Fonts](#fonts)
      - [fontNameRegular](#fontnameregular)
      - [fontNameMedium](#fontnamemedium)
      - [fontNameLight](#fontnamelight)
    - [Buttons](#buttons)
      - [underlineButtonTitles](#underlinebuttontitles)
      - [boldButtonTitles](#boldbuttontitles)
  - [PushNotifications](#pushnotifications)
  - [Error codes](#error-codes)
  - [Localization](#localization)
- [Other Supported Platforms](#other-supported-platforms)
  - [Cordova](#cordova)
  - [React native](#react-native)
- [eID Framework](#eid-framework)

## Requirements

- Xcode 14.3 or above for Swift Package Manager (SPM)
- Cocoapods installed v1.11.2 or above (Note: Xcode 15 requires Cocoapods v1.13.0 or above)
- Device with WiFi/3G/LTE

## Supported Versions

The minimum SDK version required for publishing to the App Store is now 8.0.1, following the introduction of Apple's Privacy Manifest. The SDK is compiled with Xcode 15.4, which is recommended for optimal compatibility and performance.

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

- Then run the following command from the project's root folder in the terminal:

```
pod install
```

__Note:__ When integrating VideoIdent SDK into your project, please ensure you have the `-ObjC` flag in your project's `Other Linker Flags`. This can be done by:

1. Opening your project in Xcode
2. Navigating to the project settings
3. Selecting your application target
4. Going to the `Build Settings` tab
5. Searching for Other Linker Flags
6. Adding `-ObjC` to the list of flags

### Manually

[![Watch the video](/screenshots/Screenshot_vid.png)](https://www.youtube.com/watch?v=eHawhnaCcas)

#### Static XCFramework

- Download `idnow_vi_static.xcframework-<version>.tar.gz` from [here.](https://github.com/idnow/de.idnow.ios/releases)
- Import `idnow_vi_static.xcframework` into your Xcode project.
- Add the following to your project's `Link binary with libraries` section.

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

__Note__: To get the sample projects to work, you have to run `pod install` to install dependencies.

#### Dynamic XCFramework

- Download the current release from [here.](https://github.com/idnow/de.idnow.ios/releases)
- Import the `idnow_vi.xcframework` folder into your project.
- Add `idnow_vi.xcframework` to `Embed Frameworks` step of your Xcode project as `required`.

### Swift Package Manager (SPM) :package:

Since the release of VideoIdent SDK v7.4.1, we now support Swift Package Manager (SPM) by providing a dynamic XCFramework as a package product. For instructions on how to add the Swift package to your project, please refer to the following [documentation](https://developer.apple.com/documentation/swift_packages/adding_package_dependencies_to_your_app).

- Add swift package: `https://github.com/idnow/de.idnow.ios` as dependency ![swift_package_manager_choose](/screenshots/Screenshot_spm.png)
- Follow the regular setup described in the [Usage](#usage) section.
- Reference [spm example project](/examples/spm-example-idnow)

**Note:** This is only available for Xcode 14.3 or above.

## Usage

After adding the IDnowSDK into your project you need to follow these steps in order to setart an identification process.

**Step 1:** Import the SDK module into your source code.

#### Swift

```import IDnowSDK```

#### Objective C

```#import "IDNowSDK.h"```

**Step 2:** Configure the appearance of the SDK. Detailed description of possible values can be found [here](#branding).

#### Swift

```swift
let appearance = IDnowAppearance.shared()
// Adjust colors
appearance.defaultTextColor = UIColor.black
appearance.primaryBrandColor = UIColor.blue
appearance.proceedButtonBackgroundColor = UIColor.orange
appearance.checkIconColor = UIColor.red
appearance.primaryAlertActionColor = UIColor.green

// Adjust fonts
appearance.fontNameRegular = "AmericanTypewriter"
appearance.fontNameLight = "AmericanTypewriter-Light"
appearance.fontNameMedium = "AmericanTypewriter-CondensedBold"

// To adjust navigation bar / bar button items etc. you should follow Apples UIAppearance protocol.
```

#### Objective C

```objectivec

// Setup IDnowAppearance
IDnowAppearance *appearance = [IDnowAppearance sharedAppearance];
  
// Adjust colors
appearance.defaultTextColor = [UIColor blackColor];
appearance.primaryBrandColor = [UIColor blueColor];
appearance.proceedButtonBackgroundColor = [UIColor orangeColor];
appearance.checkIconColor = [UIColor redColor];
appearance.primaryAlertActionColor = [UIColor greenColor];
  
// Adjust fonts
appearance.fontNameRegular = @"AmericanTypewriter";
appearance.fontNameLight = @"AmericanTypewriter-Light";
appearance.fontNameMedium = @"AmericanTypewriter-CondensedBold";

// To adjust navigation bar / bar button items etc. you should follow Apples UIAppearance protocol.
```

**Step 3:** Instantiate the `IDnowSettings` with your `companyId` and the `transactionToken` obtained from the user. The complete list of settings can be found [here](#settings).

#### Swift

```swift
let settings = IDnowSettings(companyID: "example_comp", transactionToken: "DEV-EXMPL") 
```

#### Objective C

```objectivec
IDnowSettings *settings = [IDnowSettings settingsWithCompanyID:@"example_comp" transactionToken:@"DEV-EXMPL"];
```

**Step 4:** Initialize and start the identification controller

#### Swift

```swift
let idnowController = IDnowController.init(settings: settings)
self.controller.initialize(completionBlock: {(success, error, canceledByUser) -> Void in
    if (error != nil) {
        // Handle initialization error - display an alert
    }
    
    if (canceledByUser) {
        // Identification was cancelled by user
        return
    }
    // Otherwise display the identification flow to the user  
    self.controller.startIdentification(from: ViewUtils.rootController(), withCompletionBlock: {(success, error, canceledByUser) -> Void in
        
        if (error != nil) {
            // Hnadle an identification error
             return
        }
        
        if (canceledByUser) {
            // The ident process was cancelled by the user
            return
        }
        
        // Identidication was successful, proceed to the next steps in your app flow
        
    })
})
```

#### Objective C

```objectivec
// Initialize and start identification
IDnowController *idnowController = [[IDnowController alloc] initWithSettings: settings];

// Initialize identification using blocks
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

Alternatively, instead of handling the events via the callbacks you can implement the `IDnowControllerDelegate` and pass it as a delegate to the `IDnowViewController`.

The protocol is as follows:

```objectivec
/**
 *  Notifies the delegate
 *  about the success or failure of an initialization or identification.
 */
@protocol IDnowControllerDelegate

/**
 *  Sent to the delegate when an initialization (e.g. triggered by [IDnowController initialize]) was successfull.
 *
 *  @param idnowController The responsible caller.
 */
- (void) idnowControllerDidFinishInitializing: (IDnowController *) idnowController;

/**
 *  Sent to the delegate when an initialization (e.g. triggered by [IDnowController initialize]) failed.
 *
 *  @param idnowController The responsible caller.
 *  @param error The error that occurred
 */
- (void) idnowController: (IDnowController *) idnowController initializationDidFailWithError: (NSError *) error;

@optional

/**
 *  Sent to the delegate when an identification (e.g. triggered by [IDnowController startIdentificationFromViewController:]) was successfull.
 *
 *  @param idnowController The responsible caller.
 */
- (void) idnowControllerDidFinishIdentification: (IDnowController *) idnowController;

/**
 *  Sent to the delegate when an identification (e.g. triggered by [IDnowController startIdentificationFromViewController:]) was canceled by the user.
 *
 *  @param idnowController The responsible caller.
 */
- (void) idnowControllerCanceledByUser: (IDnowController *) idnowController;

/**
 *  Sent to the delegate when an identification
 *  (e.g. triggered by [IDnowController startIdentificationFromViewController:]) failed.
 *
 *  @param idnowController The responsible caller.
 *  @param error The error that occurred.
 */
- (void) idnowController: (IDnowController *) idnowController identificationDidFailWithError: (NSError *) error;

@end
```

In that case, you can setup the flow like this:

#### Swift

```swift
let idnowController = IDnowController.init(settings: settings)
indowController.delegate = self // Conforms to IDnowControllerDelegate
idnowController.initialize()
```

#### Objective C

```objectivec
IDnowController *idnowController = [[IDnowController alloc] initWithSettings: settings];
indowController.delegate = self; // Conforms to IDnowControllerDelegate
[idnowController initialize];
```

### Settings

Before initializing the identification process at least a `transactionToken` and a `companyID` have to be set in the `IDnowSettings`. Below is an example of setting a field in the `IDnowSettings`

#### Swift

```swift
let settings = IDnowSettings() 
settings.transactionToken = ident
```

#### Objective C

```objectivec
IDnowSettings *settings = [[IDnowSettings alloc] init];
settings.transactionToken = validatedToken;
```


| Property name           | Description                                                                                                                                                                                                                                                                                                                                                                                                            |
| ------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| transactionToken        | A token that will be used for instantiating a video identification.                                                                                                                                                                                                                                                                                                                                                    |
| companyID               | Your Company ID provided by IDnow.                                                                                                                                                                                                                                                                                                                                                                                     |
| environment             | **Optional:** The environment that should be used for the identification (DEV, TEST, LIVE) The default value is`IDnowEnvironmentNotDefined`. The used environment will then base on the prefix of the transaction token (DEV -> DEV, TST -> Test, else -> Live). You can use the special IDnowEnvironmentCustom to define a custom IDnow installation. If this is done, you need to set the apiHost and websocketHost. |
| showErrorSuccessScreen  | **Optional:** If set to `false`, the Error-Success-Screen provided by the SDK will not be displayed. <br />The default value of this property is `true`.                                                                                                                                                                                                                                                               |
| showVideoOverviewCheck  | **Optional:** If set to `false`, the `Terms and Conditions` screen will not be shown before starting a video identification. <br />The default value of this property is `true`.                                                                                                                                                                                                                                       |
| forceModalPresentation  | **Optional:** If set to`true`, the UI for the identification will always be displayed modal. By default the value of this property is `false` and the identification UI will be pushed on an existing navigation controller if possible.                                                                                                                                                                               |
| apiHost                 | The target server url for REST calls if custom server is used.                                                                                                                                                                                                                                                                                                                                                         |
| websocketHost           | The target server url for websocket calls if custom server is used.                                                                                                                                                                                                                                                                                                                                                    |
| connectionType          | The connection type to use to talk the backend.`IDnowConnectionType` <br />Possible values:<br />- IDnowConnectionTypeWebsocket *(default)*<br />- IDnowConnectionTypeLongPolling                                                                                                                                                                                                                                      |
| certificateProvider     | Accepts a subclass of`IDnowCertificateProvider`. Used to provide custom mTLS certificates used by the network connections. See [Custom certificate providres](#custom-certificate-providers).                                                                                                                                                                                                                          |
| dtlsCertificateProvider | Accepts a subclass of`IDnowDtlsCertificateProvider`. Used to provide custom DTLS certificates used by the WebRTC connection. See [Custom certificate providres](#custom-certificate-providers).                                                                                                                                                                                                                        |

## Custom Certificate Providers

#### DTLS

For custom DTLS certificates use `dtlsCertificateProvider` parameter of `IDnowSettings`.

The certificate provider can be used to provide a custom DTLS certificate (`featureCertificate == YES`) and/or to check the
SHA fingerprint of the server certificate (`featureFingerprint == YES`).

#### mTLS

For custom mTLS certificates use `certificateProvider` parameter of `IDnowSettings`.

Starting from SDK version 6.5.0 we offer mTLS support for API connections.

mTLS enables server/client certificate validation. SDK can provide custom client certificate and several server certificates.

What has changed:

- Certificate provider now can validate multiple server certificates/fingerprints
- REST supports mTLS
- WebSocket support for mTLS. For this purpose, SRWebsocket implementation was slightly updated. So, now we have a local version of SRWebsocket.

To enable mTLS, it should be available in the customer backend configuration, and client (consumer) should supply certificate provider to the SDK.

Certificate Generation:

Client certificate and private key pair can be generated in a number of ways, for example, with Certificate Sign Request on Mac OS X Keychain.

Client Certificates:

For iOS, key pair can be imported by platform tools from p12 package format. For example:

```objectivec

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

1 - Create subclass of `IDnowCertificateProvider` similar to [IDNMyMtlsCertificateProvider](https://github.com/idnow/de.idnow.ios/blob/master/examples/IDnow/IDnow/IDNMyMtlsCertificateProvider.m)

2 - During the SDK configuration step set the certificate provider:

```objectivec
[IDnowSettings sharedSettings].certificateProvider = [[IDNMyMtlsCertificateProvider alloc] init];
```

```swift
let settings = IDnowSettings() 
settings.certificateProvider = IDNMyMtlsCertificateProvider()
```

Feature flags for certificate provider allow usage of the corresponding features:

```objectivec
- (BOOL)featureCertificate;  // use client certificate
- (BOOL)featureFingerPrint;  // use server certificate fingerprints
- (BOOL)featureServerCert;   // use server certificates
```

You can check the certificate provider + certificates [here](https://github.com/idnow/de.idnow.ios/tree/master/IDnow).

## Branding

### Colors


| Property name                | Description                                                                                                                                                                                                                                                                                                                                              | Appearance                                                       |
| ------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------ |
| defaultTextColor             | Optional color that replaces the default text color.<br />Default: <a href="#"><img valign='middle' alt='#000000' src='https://readme-swatches.vercel.app/000000?style=round'/></a> #000000 <br />Recommendation: Should be some kind of a dark color that does not collide with light color.                                                                    | <img src="/screenshots/vi_default_text.jpeg" width="300">        |
| secondaryTextColor           | Optional color that replaces the secondary text color.<br />Default: <a href="#"><img valign='middle' alt='#000000' src='https://readme-swatches.vercel.app/000000?style=round'/></a> #000000 <br />Recommendation: Should be some kind of a dark color that does not collide with light color.                                                                  | <img src="/screenshots/vi_secondary_text.jpeg" width="300">      |
| primaryBrandColor            | Optional color that replaces the default brand color.<br />Default: <a href="#"><img valign='middle' alt='#F95602' src='https://readme-swatches.vercel.app/F95602?style=round'/></a> #F95602<br />Used in buttons, labels, links etc.<br />Recommendation: Should be a color that does not collide with light color.                                             | <img src="/screenshots/vi_brand_color.jpeg" width="300">         |
| proceedButtonBackgroundColor | Optional color that replaces the proceed button background color.<br />Default: `primaryBrandColor`                                                                                                                                                                                                                                                      | <img src="/screenshots/vi_primary_button.jpeg" width="300">      |
| proceedButtonTextColor       | Optional color that replaces the proceed button text color.<br />Default value: <a href="#"><img valign='middle' alt='#FFFFFF' src='https://readme-swatches.vercel.app/f6f6f6?style=round'/></a>  #FFFFFF    | <img src="/screenshots/vi_primary_button_text.jpeg" width="300"> |
| textFieldColor               | Optional color that replaces the default color of the text in the textField components.<br />Default: `defaultTextColor`                                                                                                                                                                                                                                 | <img src="/screenshots/vi_textfield_color.jpeg" width="300">     |
| checkIconColor               | Optional color that replaces the color that will be used for checkboxes.<br />Default: `primaryBrandColor`.<br />Recommendation: it should be a color that does not collide with light color.                                                                                                                                                            | <img src="/screenshots/vi_checkbox_color.jpeg" width="300">      |
| primaryAlertActionColor      | Optional color, that replaces the color on the left action of alert controller.<br />Default: <a href="#"><img valign='middle' alt='#8D96A6' src='https://readme-swatches.vercel.app/8D96A6?style=round'/></a> #8D96A6 | <img src="/screenshots/vi_alert_primary.jpeg" width="300">       |
| secondaryAlertActionColor    | Optional color, that replaces the color on the right action of alert controller<br />Default: *dark mode* <a href="#"><img valign='middle' alt='#FFFFFF' src='https://readme-swatches.vercel.app/f6f6f6?style=round'/></a> #FFFFFF </br> *light mode* <a href="#"><img valign='middle' alt='#000000' src='https://readme-swatches.vercel.app/000000?style=round'/></a> #000000 | <img src="/screenshots/vi_alert_secondary.jpeg" width="300">     |

<details>
    <summary>Deprecated parameters (not used in VideoIdent+)</summary>


| Property name                    | Description                                                                                                                                                                                                                                                                                                                |
| ---------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| failureColor                     | Optional color, that replaces the text color in the result screen, when an identification failed.<br />Default: A red color                                                                                                                                                                                                |
| successColor                     | Optional color, that replaces the text color in the result screen, when an identification was successful.<br />Default: A green color                                                                                                                                                                                      |
| headlineColor                    | Optional color, that replaces the color that will be used for headlines.<br />Default: primaryBrandColor. <br />Recommendation: Should be a color that does not collide with white color.                                                                                                                                  |
| linkColor                        | Optional color, that replaces the color that will be used for links.<br />Default: primaryBrandColor. <br />Recommendation: Should be a color that does not collide with white color.                                                                                                                                      |
| cqcOuterRingColor                | Optional color that replaces default dark gray for the outer ring indicator on the quality check screen. Default: dark gray                                                                                                                                                                                                |
| cqcDefaultInnerRingColor         | Optional color that replaces default light gray for the inner ring indicator on the quality check screen. Default: light gray                                                                                                                                                                                              |
| cqcPoorQualityInnerColor         | Optional color that replaces default bright red for the inner ring indicator in case bad network quality on the quality check screen. Default: bright red                                                                                                                                                                  |
| cqcModerateQualityInnerColor     | Optional color that replaces default bright orange for the inner ring indicator in case moderate network quality on the quality check screen. Default: bright orange                                                                                                                                                       |
| cqcExcellentQualityInnerColor    | Optional color that replaces default strong yellow for the inner ring indicator in case excellent network quality on the quality check screen. Default: strong yellow (almost green).                                                                                                                                      |
| enableStatusBarStyleLightContent | Optional: Forces the light status bar style to match dark navigation bars. If you tint your navigation bar with a dark color by adjusting navigation bar appearance (e.g. a blue color) you can set this value to true. The statusbar style will then be adjusted to light in screens where the navigation bar is visible. |

</details>

### Fonts

Using custom fonts can be observed on the appearance illustrations fo the [branding](#branding) section.

#### fontNameRegular

An optional font name that can be used to replace the regular font used by the SDK.
Default: San Francisco Regular

#### fontNameMedium

An optional font name that can be used to replace the medium font used by the SDK.
Default: San Francisco Medium

#### fontNameLight

An optional font name that can be used to replace the light font used by the SDK.
Default: San Francisco Light

### Buttons

#### underlineButtonTitles

Default: `false` - Underline all button titles. Set this to `true` in order to underline button title text

#### boldButtonTitles

Default: `true` - Make button titles bold. Set this to `false` in order to use normal font weight in button titles

## PushNotifications

In order to use push notifications via the IDnow SDK it is neccessary that your own `AppDelegate` inherits from
the provided `IDnowAppDelegate`. This is necessary because the callbacks from Apple regarding the registration and reception of push notifications are solely handled through the `AppDelegate`, which is not part of our SDK. If your own `IDnowAppDelegate` subclass overrides some methods, please make sure to call the superclass's implementation within your overrides.

Additionally we will need the production certifcate/key pair to send notifications via push to your app via
our backend.

```objectivec

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

## Error codes

In case the identification process ends with an error a resulting callback will be passed an instance of an `NSError` with a corresponding error code. The full localized description of the error can be found in the `userInfo` of the `error` object.

Below is the list of possible errors.


| Error Code                                | Description                                                                                                                                                                                                                                                             |
| ------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| IDnowErrorMissingTransactionToken         | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`). Occurs when the `IDnowSettings` instance does not contain a `transactionToken`.                                                                                                      |
| IDnowErrorMissingCompanyID                | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`). Occurs when the `IDnowSettings` instance does not contain a `companyID`.                                                                                                             |
| IDnowErrorOfficeClosed                    | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`). Occurs when an identification cannot be initialized because the time is outside business hours.                                                                                      |
| IDnowErrorMissingCamera                   | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`). Occurs when the device does either have no front camera or no back camera.                                                                                                           |
| IDnowErrorCameraAccessNotGranted          | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`). Occurs when a video ident was requested, but the camera access was not granted by the user.                                                                                          |
| IDnowErrorMicrophoneAccessNotGranted      | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`). Occurs when a video ident was requested, but the microphone access was not granted by the user.                                                                                      |
| IDnowErrorMissingMicrophone               | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`). Occurs when a video ident was requested, but the device does not provide a microphone.                                                                                               |
| IDnowErrorNoInternetConnection            | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`). Occurs when a video ident was requested, but no internet connection is present.                                                                                                      |
| IDnowErrorServer                          | Can occur during initialization (e.g. triggered by`[IDnowController initialize]`) and identification process (e.g. triggered by `[IDnowController startIdentificationFromViewController:]`). The error object will also contain the status code returned by the server. |
| IDnowErrorWebRTC                          | Can occur during an identification process (e.g. WebRTC service could not establish a video connection).                                                                                                                                                                |
| IDnowErrorIdentificationFailed            | Can occur during an identification process (e.g. triggered by`[IDnowController startIdentificationFromViewController:]`). Describes that an identification failed.                                                                                                      |
| IDnowErrorJailbreakPhoneNotSupported      | Unable to perform an identification on a jailbroken device.                                                                                                                                                                                                             |
| IDnowErrorInvalidWebRTCToken              | Using LiveSwitch with an invalid key.                                                                                                                                                                                                                                   |
| IDnowErrorHighCallVolumeTryLater          | User agreeed to try the identification later due to the high call volume.                                                                                                                                                                                               |
| IDnowErrorEnrolledInWaitingList           | User enrolled in the Waiting List so current identification session aborted.                                                                                                                                                                                            |
| IDnowErrorDeviceNotMeetPVIDRequirements   | The PVID requirements only allow users with devices that support the required resolution criteria (minimum 720p: 1280 × 720 at 25 frames per second) for the VideoIdent process.                                                                                       |
| IDnowErrorUnifiedIdentAnotherMethod       | Error for a Unified Ident which states the user decided to switch to another type of identification.                                                                                                                                                                    |
| IDnowErrorTokenNotSupported_eIDStandalone | eID standalone tokens are not supported.                                                                                                                                                                                                                                |
| IDnowErrorInvalidServerCertificate        | Server trust certificate is not valid.                                                                                                                                                                                                                                  |
| IDnowErrorUnsupportedProduct              | Unsupported products.                                                                                                                                                                                                                                                   |
| IDnowErrorUnsupportedBluetoothHeadset     | Bluetooth headset not supported.                                                                                                                                                                                                                                        |
| IDnowInstantSignDocumentExpired           | `INSTANT_SIGN` rejected, the trusted document is expired. This document is not valid.                                                                                                                                                                                   |

## Localization

In case you would like to change the localization used by the IDnow SDK at runtime you can do it by supplying the language code to the `IDnowSettings` instance:

Supported values are: en (English), de (German), fr (French), es (Spanish), it (Italian), pt (Portugese), et (Estonian), hr (Croatian), hu (Hungarian), ka (Georgian), ko(Korean), lt(Lithuanian), lv (Latvian), nl (Dutch), pl (Polish), ua (Ukrainian),  zh (Chinese), ru (Russian).

```objectivec
settings.userInterfaceLanguage = @"de"; // this field accepts the following languages (de, en, it, es, pt, fr, et, hr, hu, uk, ka, ko, lt, lv, nl, pl, ru, zh).

```

# Other Supported Platforms

## Cordova

Our Cordova plugin offers the possibility of integrating our native Android and iOS SDK into the Cordova-based applications. The plugin offers the possibility to customize and setup of the SDK. At the end of the identification process, the SDK communicates with the plug-in via a callback, allowing the Cordova application to update the flow. Please refer to this [link](https://www.npmjs.com/package/com-idnow-plugin) for implementation details.
**Note**: Only VideoIdent and eSign are supported so far. eID is not supported.

## React native

Our React Native plug-in offers the possibility of integrating our native Android and iOS SDK into the React Native-based applications. It offers the possibility to customize and setup the SDK, and uses the latest expo native modules to create the bridging mechanism. Please refer to this [link](https://www.npmjs.com/package/react-native-vi-idnow-library) for implementation details.
**Note**: Only VideoIdent and eSign are supported so far. eID is not supported

# eID Framework

IDnow eID is an automated and fully AML-compliant identification product. All it requires is an NFC-enabled (Near Field Communication) smartphone and a German ID document (ID card or Residence permit) with an activated eID function or the eID card for EU citizens.

For configuration details, please refer to the [IDnow eID SDK Documentation](/eid/README.md)
