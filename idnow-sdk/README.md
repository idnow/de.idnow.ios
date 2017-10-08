# SDK

## Changelog

### 3.3.1
Improvements:
- New native esigning user interface
- Added support for qualified signature in Switzerland
- Much faster connection setup
- Increased AFNetworking to 3.1.0

Bugfixes:
- Certificate handling bug fixes

Migration Guide:
- please change the SDK reference to 3.3.1 and call pod update
- be advised that this version of the SDK has increased the dependent version of AFNetworking from 2.6.3 to 3.1.0

### 3.2.2
Bugfixes:
- fix for an issue on iOS11 devices only

### 3.2.1
Bugfixes:
- removed an issued regarding IDnow SDK localizations

### 3.2.0
Improvements:
- improved connection speed
- added capabilities to change to localization
- new API to receive the server certicificate
- build against the new iOS 11 base SDK

Migration Guide:
- please change the SDK reference to 3.2.0 and call pod install

### 3.1.2
Improvements:
- enhancements to the waiting list feature (can be enforced backend side)

Migration Guide:
- please change the SDK reference to 3.1.2 and call pod install


### 3.1.1
Improvements:
- Portugese language support

Bugfixes:
- Fixed a minor bug regarding the push notifications mechanism

Migration Guide:
- please change the SDK reference to 3.1.1 and call pod install

### 3.1.0
Improvements:
- Optional support for waiting list feature

Bugfixes:
- Fixed success messages sometimes being shown in the wrong language

Migration Guide:
- please change the SDK reference to 3.1.0 and call pod install
- if you want to use the push notification waiting list feature please follow >Adding Push Notifications< below

### 3.0.1
Improvements:
- updated audio/video client
- custom DTLS client certificate  
- certificate pinning for known server certificates

### 3.0.0
Improvements:
- Improved dependencies by removing not needed OpenTok
- Improved overall size of the SDK


Migration Guide:
- Please execute >pod install< to get rid of the now not needed OpenTok dependency
- Make sure to reference the following frameworks in your host application:
  Accelerate, AudioToolBox, AVFoundation, CoreMedia, GLKit, OpenGLES and WebKit

### 2.11.0

Improvements:
- Added interface to use custom DTLS certificates for the WebRTC connection
- Improved reconnect behavior in case the server is unavailable for any reason
- Long polling connection type supports messages with or without size information

### 2.10.1

Improvements:
- custom error success/failure messages

Bugs:
- Fixed connection issues with low quality connections

### 2.10.0

Improvements:
- Added the ability to receive the Ident code via email
- Better support for XCode 8
- Deployment target is now iOS 8

Migration Guide:
- Note that as of this version the pod UIAlertView+Blocks is no longer needed. Please remove the line from the dependencies and execute 'pod install'.
- This version supports deployement targets iOS 8 and higher

### 2.9.0
- Added information about the current waiting queue position and estimated waiting time

### 2.8.2

Improvements:
- Improved images sizes for high resolution cameras

### 2.8.0

Improvements:
- Added support for text chat between user and agent
- Improved behaviour of the reconnect screen if connection is lost
- Updated OpenTok from 2.8.2 to 2.9.2
- Updated Masonry from 1.0.1 to 1.0.2

Bugs:
- Fixed crash during reconnect after ident has been aborted

### 2.7.0

No changes

### 2.6.0

Improvements:
- Support for back navigation
- Updated libraries to new versions
- Bitcode support now integrated in main version, no separate bitcode version necessary anymore

### 2.5.0

Improvements:
- Added support for spatial and temporal resampling of the video stream
- Better handling slow STUN requests
- Prevent parallel uploading of images for faster uploads
- Return success if user aborts on the goodbye screen instead of failure

Bugs:
- Fixed bug where audio was not reconnected if user temporarily lost connection

### 2.4.0

Improvements:
- Added jailbreak / rooting detection
- Better wording for Ident-ID
- Dependencies have been updated
- Support for AFNetworking from 2.6 to 3.2

Bugs:
- Fixed crash when launching with launch options

### 2.3.2

Improvements:
- Better candidate gathering over slow connections

### 2.3.1

Improvements:
- Additional handling of more connection loss cases

Bugs:
- Translated some missing keys to french and spanish

### 2.3.0

Improvements:
- Better handling of connection loss during video chat
- Prevent screenshots from containing sensitive data

Bugfixes:
- Fixed bug when starting several identification directly after each other

### 2.2.0

Improvements:
- iPad now supported natively
- Third party keyboards are disable due to security considerations
- Support for swiss environment
- Cocoapods support
- Custom fields in redirect URLs are now supported
- Check data screen now does not cover half the screen anymore
- Additional customization options: Example mobile number, cornerRadius, modalPresentationStyle, proceedButtonTextColor

Bugfixes:
- Fixed LTO: loop not vectorized warning
- Fixed bug how redirects where handled in error cases

### 2.1.0

Improvements
- Added support for echo cancellation

### 2.0.0

Improvements
- Bitcode support (see Bitcode Sample for details)
- New video technology für custom video stream routing and better quality
- Supported languages: de, en, fr, it

## Requirements
- Xcode 8.0 or later
- Deployment Target: iOS 8.0 or later
- Supported Devices: iPhone (4s + later), iPod Touch (5 + later), iPad (2 + later)
- Cocoapods installed
- Device with Wifi / 3G / LTE

## Installation

### CocoaPods
- Add the following pod dependencies to your podfile:
```
pod 'IDnowSDK'
```

- Then, run the following command:
```
pod install
```

- Import SDK by using "@import IDnowSDK"

### Manually 
- Add the following pod dependencies to your podfile:
```
pod 'Masonry', '~> 1.0.0'
pod 'SocketRocket', '~> 0.5.1'
pod 'AFNetworking', '~> 3.1.0'
```
- Download the current release from and copy the idnow-sdk folder to your project directory
- Or add the repo as a git submodule (git lfs required. For the initial checkout do git lfs pull)
- Drag idnow-sdk folder into your Xcode project
- Add to your "Link binary with libraries" section
```
Webkit.framework
Accelerate.framework
libz.dylib
```   
- Import 'IDnowSDK.h'

__Note__: To get the sample projects work, you have to call "pod install" to install dependencies.

## Settings (IDnowSettings)
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
The connection type to use to talk the backend. (Websocket (default) or long polling)

## Branding (IDnowAppearance)
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


### Status Bar

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

## Adding Push Notifications

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

## Usage example:

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

// Optionally enable custom server with long polling
settings.environment = IDnowEnvironmentCustom;
settings.apiHost = @"https://api.yourserver.com";
settings.websocketHost = @"https://websocket.yourserver.com";
settings.connectionType = IDnowConnectionTypeLongPolling;
```

## Localization
Warning: Adapting localizations is only allowed if you have the permissions from IDnow.

English and German Localizations are provided by the SDK (IDnowSDKLocalization.bundle)
You can overwrite localisation in your own Localizable.strings files.


### Example:
```
//Defined in the IDnowSDKLocalization.bundle
"NAVIGATION_ITEM_TITLE_DEFAULT" = "IDnow";

//Overwrite in your Localizable.strings file:
"NAVIGATION_ITEM_TITLE_DEFAULT" = "Video Ident";
```
