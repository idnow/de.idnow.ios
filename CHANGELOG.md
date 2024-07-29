## Changelog

### 8.3.0

- **UI/UX enhancements**: We have made various adjustments to our user interface (UI) and user experience (UX) to ensure users have a consistent experience throughout the flow.
- **Enhanced security**: We have taken additional steps in order to enhance the overall security of our SDK
- **Bug fixes**: We regularly test our products to assess areas where there is any room for improvement. We identified some minor bugs and fixed those as part of this release.


### 8.2.0

- **Bug fix**: Ensure that test system works with all test prefixes.


### 8.1.0

- **InstantSign feature**: We have introduced a new feature, InstantSign, that allows users to quickly sign documents online without having the need to go through the identity verification process. In order to make this happen, we will require additional information from customers during Ident-Id creation. This will serve as a much faster eSign solution for AML-compliant customers that have previously stored ident data, and is likely to improve user experience and increase conversions.
- **UX enhancements**: We have made various adjustments to our user interface (UI) and user experience (UX) to ensure users have a seamless experience throughout the flow.
- **Bug fixes**: We regularly test our products to assess areas where there is any room for improvement. We identified some bugs and fixed those as part of this release.


### 8.0.1

Updated the CocoaPods distribution configuration to resolve conflicts related to the Privacy Manifest. This adjustment was necessary due to an issue where the library erroneously included the PrivacyInfo.xcprivacy file in the main bundle, causing build conflicts if two or more pods with the incorrect configuration were used in the integrator app.

### 8.0.0

Apple has introduced some changes in regards to AppStore’s guidelines concerning data collection and API declaration, and this version is being released to ensure that the VideoIdent App/SDK complies with these changes.
A privacy manifest file named PrivacyInfo.xcprivacy has been added to the App’s target resources where we declare the user of certain APIs and explain why they are being used.

**Implications for customers**:

Starting from 01.05.2024, VideoIdent/eID SDK customers that wish to publish a new version of their Host App, have to ensure that they are using the version 8.0.0 or above. (edited) 

### 7.8.1

- **Fixed crashes**: We have identified and fixed some crashes to ensure that our end-users don't have any trouble as they use our app

### 7.8.0

- **UX enhancements**: We have made numerous adjustments to our user interface (UI) and user experience (UX) to ensure users have a seamless experience throughout the flow.

- **Better memory management**: We have identified some areas of improvement to achieve better memory management and taken the necessary steps to free portions of memory for reuse when no longer needed.

- **Replaced libPhoneNumber library with native implementation**: Instead of using a 3rd party library, we have developed the same functionality natively.


### 7.7.0

- **Language selector feature (v2)**: We have made some modifications to the recently-introduced Language Selector feature in order to ensure that our SaaS customers can also benefit from it.
- **UX enhancements**: We have made numerous adjustments to our user interface (UI) and user experience (UX) to ensure users have a seamless experience throughout the flow.
- **Masking users' PII data**: Given our focus on users' data privacy, we have taken additional steps to partially mask their Personal Identifiable Information (PII) data as it is shared between the server and client side
- **Better memory management**: We have identified some areas of improvement to achieve better memory management and taken the necessary steps to free portions of memory for reuse when no longer needed.
- **Name-matching for eID+QES**: For the eID QES use case, we have introduced an additional check to compare the user's full name specified during Ident ID creation with the full name received from their eID card

### 7.5.0

- **UI/UX enhancements**: We have made numerous adjustments to our user interface (UI) and user experience (UX) to ensure users have a seamless experience throughout the flow
- **Fixed crashes** : We have also identified and fixed some crashes in the flow to offer our end-users a seamless experience

### 7.4.1

- **Support for arm64**: As part of this release, we have made further modifications to ensure our SDK is buildable with the arm64 simulator
- **Fixed crashes**: We have also identified and fixed some crashes in the flow to offer our end-users a seamless experience
- **UI/UX enhancements**: We have made many adjustments to our user interface (UI) and user experience (UX) to ensure users don't have any trouble going through the flow

### 7.3.0

Improvements:

- **Seamless video call experience**: We have taken additional steps to ensure our end-users have a seamless video call experience
- **Enhanced security via dTLS**: Given our commitment to data privacy and security, we have taken additional measures to make our SDK even more secure to use. A new method (setDtlsCertificateProvider) has been added in the SDK interface in order to support Datagram Transport Layer Security (dTLS).
- **Fixed crashes**: We have identified and fixed some crashes to offer our end-users a seamless experience
- **UI/UX enhancements**: We have made many adjustments to our user interface (UI) and user experience (UX) to ensure you have a seamless experience throughout the flow
- **Support for arm64 and xCode 15**: As part of this SDK release, we also offer support for arm64 and xCode 15

Update eID intermediary certificate: For our eID solution we have updated the intermediary certificate to match the server certificate

### 6.8.0

Improvements:
- Upgrade the target deployment version: In order to upgrade a deprecated dependency, we have changed the deployment target version from 9.0+ to 11.0+. This change was a prerequisite to upgrading the library.
- Upgrade libPhoneNumber-iOS: Previously the version being used for this library was 0.9.15. Now it has been upgraded to 1.0.4. Unlike in the past, the library will not be installed automatically along with the SDK. Please refer to more information here: pod 'libPhoneNumber-iOS', :git => 'https://github.com/iziz/libPhoneNumber-iOS.git'

- Language selector feature: We have introduced a new feature that will allow end-users to choose their preferred language of identification at the beginning of the flow. The choice will be offered depending on the language(s) configured for each customer and the languages supported by the IDnow call center.
Bug fixes:
- Mismatch area code and country flag: We have fixed an issue whereby we noticed a mismatch between the country flag chosen by the user and the corresponding area code appearing before the number.
- Missing callback: A callback was missing when the user clicked on 'My country is not listed here'. This has been fixed now so that our SDK customers don't face any difficulty displaying the corresponding step/screen to the users.

### 6.7.0

- Addressed deprecated dependencies: There were some dependencies in the iOS SDK that were deprecated. We have addressed these dependencies by either removing them, upgrading them to newer versions and/or building those inside our codebase.
- Configurability for the user of Bluetooth devices: We have now made it possible to configure whether end-users are allowed to perform the VideoIdent and/or eSign process, while being connected to a Bluetooth device. This configurability exists on an OS-level.
- Better control over WebSocket communication: We have enhanced the way we manage WebSocket communication to reduce connectivity issues once the call gets connected to the identification expert.
- Fixed waiting list behavior: We have modified the flow on iOS to match it with Android, so that the connection quality check (CQC) is not performed for users that are already on the waiting list.
- Some crashes have also been identified and fixed to offer end-users a seamless experience


### 6.6.0

- Treating the user's PII data with more care: We have introduced a configurable option to hide the user's PII data so that if a user's Ident ID is somehow accessed by someone else, the user's PII data is not exposed
- eSign wallet expiry use case: A popup is introduced to ensure that the user is informed once their eSign wallet has expired and they need to renew it.
- eSign token expiry use case: A user is only allowed to perform a successful eSign process as long as the token generated from our TSP is valid. In a situation where the token expires, we now show the appropriate messaging to the user so they know how to proceed.
- Dark mode issue: One of our clients had reported that when dark mode was enabled, users were not able to see the radio buttons shown on the Consent Protocol screen that is shown as part of the eSign process. This UI issue has been addressed.
### 6.5.0

- Changes have been made to the SDK in order to enhance the security of communication that takes place between the client and SDK.
- we have wrapped the IDnow SDK as XCFramework. At the moment it is only available for manual implementation. Please check the documentation for details.

### 6.4.0

- Removed PhotoIdent: PhotoIdent was an identification method that was offered as part of our SDK. However, this identification method is obsolete now and no longer being used by our customers. Therefore, we have removed it to reduce the overall SDK size. This will make the integration process easier for our customers.

- UI bug fix: In the eSign flow we noticed a text overlap on the consent protocol screen when the configured documents exceeded a certain number. This bug has been fixed in order to allow our users to seamlessly perform the whole process.


### 6.3.0

Improvement:
- The host URL for a third-party service provider required for the eID identification process has been updated upon the service provider's request. Previously, this URL had been statically specified inside our SDK. As part of this release, not only have we updated it to the new one, we have also made it configurable, so that in the future any changes can be taken care of without the need for a release.

### 6.2.0

Improvement:
- We have upgraded the libraries responsible for enabling the video call in order to offer end-users and identification experts a seamless experience.

Bug fix:
- We have fixed a UI discrepancy on one of the screens that existed when the device/application language was German

### 6.1.5

Improvement:
- For the signing process, we allow additional checkboxes to be configured and displayed to the end-user in case our customers have any regulatory requirement to do so

Bug fix:
- In order to avoid backward compatibility issues resulting from provisioning profiles added by xCode 14, we have now built eID with xCode 13, which enables our customers to build and archive their apps without any issues

### 6.1.4

Bug fixes:
- Translation discrepancies in French and Italian
- Localization wasn't being applied to the list of countries in VI+. This has been fixed now

Note: This SDK version was archived usig Xcode 13.2.1

### 6.1.3

- Minor eID bug fixes
- Generic UX improvements

### 6.1.0

Added some enhancements for security

### 6.0.0

Upgrade to liveswitch

### 5.3.0

Minor improvements & bugfixes

### 5.2.0

Minor improvements & bugfixes

### 5.1.12

Make IDnow logo configurable
Minor improvements & bugfixes


### 5.1.6

* Provided configuration option conform to PVID requirements
* Only one flag is now required to show custom waiting screen: `enableWaitingScreenCustomised`
* Provided configuration option to collect additional device data

### 5.1.5

- Waiting screen animation updated
- Accessibility Voice Over usage improved
- Other minor improvements & bugfixes

### 5.1.4

- Customizable waiting list fix for VI+

### 5.1.3

- Wallet expired popup
- Other minor improvements & bugfixes

### 5.1.2

- Customizable waiting list
- Other minor improvements & bugfixes

### 5.1.0

- Updated SDK to new build system
- eID QES feature
- Other minor improvements & bugfixes

### 5.0.12
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.12,  and call pod update

### 5.0.11
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.11  and call pod update

### 5.0.9
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.9  and call pod update

### 5.0.8
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.8  and call pod update

### 5.0.6
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.6  and call pod update

### 5.0.4
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.4  and call pod update

### 5.0.3
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.3  and call pod update

### 5.0.2
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.2  and call pod update

### 5.0.0
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 5.0.0  and call pod update

### 4.5.2
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.5.2  and call pod update

### 4.5.1
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.5.1,  and call pod update

### 4.5.0
Changes:
- Dark mode support
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.5.0,  and call pod update

### 4.4.1
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.4.1,  and call pod update

### 4.4.0
Changes:
- Minor improvements & bugfixes

Migration Guide:

- Change the SDK reference to 4.4.0,  and call pod update
- IDnow rebranding

### 4.3.4
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.3.4,  and call pod update

### 4.3.3
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.3.3,  and call pod update

### 4.3.2
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.3.2,  and call pod update

### 4.3.1
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.3.1,  and call pod update

### 4.3.0
Changes:
- Implemented Video Ident Plus feature

Migration Guide:
- Change the SDK reference to 4.3.0,  and call pod update

### 4.2.4
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.2.4,  and call pod update

### 4.2.3
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.2.3,  and call pod update

### 4.2.2
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.2.2,  and call pod update

### 4.2.1
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.2.1,  and call pod update

### 4.2.0
Changes:
-IDnow eID : new method enabling users to identify themselves online.

Migration Guide:
- Change the SDK reference to 4.2.0,  and call pod update
- Add eID framework
- Add Authada framework

### 4.1.7
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.1.7,  and call pod update

### 4.1.6
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Update Platform ios to 9.0
- Change the SDK reference to 4.1.6,  and call pod update

### 4.1.5
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.1.5,  and call pod update

### 4.1.4
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.1.4,  and call pod update

### 4.1.3
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.1.3,  and call pod update

### 4.1.2
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.1.2,  and call pod update

### 4.1.1
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.1.1,  and call pod update

### 4.1.0
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.1.0,  and call pod update

### 4.0.0
Changes:
- Migrate to Icelink 3
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 4.0.0,  and call pod update

### 3.22.0
Changes:
- Added waiting screens with animation.
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 3.22.0,  and call pod update

### 3.21.0
Changes:
- Updated to newest Sentry version
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 3.21.0, update Sentry dependency version and call pod update

### 3.20.0
Changes:
- Added possibility to use Sentry logging
- Minor improvements & bugfixes

Migration Guide:
- New dependency added: 'Sentry' in version 4.0.1
- Change the SDK reference to 3.20.0, add new dependency and call pod update

### 3.19.0
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 3.19.0 and call pod update

### 3.18.0
Changes:
- Wallet
- New languages
- Updated AFNetworking to 3.2.1
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 3.18.0 and call pod update

### 3.17.0
Changes:
- Minor improvements & bugfixes

Migration Guide:
- Change the SDK reference to 3.17.0 and call pod update

### 3.15.0
Improvements:
- Minor improvements

Bugfixes:
- iPhone X layout fix
- Minor bugfixes

Migration Guide:
- Change the SDK reference to 3.15.0 and call pod update

### 3.14.0
Improvements:
- Minor improvements

Migration Guide:
- Change the SDK reference to 3.14.0 and call pod update

### 3.13.0
Improvements:
- Minor improvements

Bugfixes:
- Minor bugfixes

Migration Guide:
- Change the SDK reference to 3.13.0 and call pod update

### 3.12.0
Improvements:
- Minor improvements

Bugfixes:
- Minor bugfixes

Migration Guide:
- Change the SDK reference to 3.12.0 and call pod update

### 3.11.0
Improvements:
- Document validation

Bugfixes:
- Minor bugfixes

Migration Guide:
- Change the SDK reference to 3.11.0 and call pod update

### 3.10.3
Improvements:
- Minor bugfixes

Migration Guide:
- Change the SDK reference to 3.10.3 and call pod update

### 3.10.2
Improvements:
- Korean language support

Migration Guide:
- Change the SDK reference to 3.10.2 and call pod update

### 3.10.1
Migration Guide:
- Change the SDK reference to 3.10.1 and call pod update

Bugfixes:
- Minor bugfixes

### 3.10.0
Migration Guide:
- please change the SDK reference to 3.10.0 and call pod update

Bugfixes:
- Newly customer-customizable texts within SDK
- Minor bugfixes

### 3.9.1
Migration Guide:
- please change the SDK reference to 3.9.1 and call pod update

Bugfixes:
- Minor bugfixes and new translations

### 3.9.0
Improvements:
- Now supporting Russian and Chinese

Migration Guide:
- please change the SDK reference to 3.9.0 and call pod update

Bugfixes:
- minor bugfixes

### 3.7.0
Improvements:
- Enhancements to the PhotoIdent process
- adds deep link support for ident code urls (https://go.idnow.de/code/XXXXXX). Requires host app's
application delegate to subclass the `IDNAppDelegate`.

Migration Guide:
- please change the SDK reference to 3.7.0 and call pod update

Bugfixes:
- minor bugfixes

### 3.6.0
Improvements:
- checks the users internet connection before starting a video chat.

**IMPORTANT NOTE:**
With previous release 3.5.0 of the IDnow SDK a new dependency has been added.
The library name is `libPhoneNumber-iOS` (Version 0.9).

Migration Guide:
- please change the SDK reference to 3.6.0 and call pod update

Bugfixes:
- minor bugfixes

### 3.5.0
Improvements:
- mobile phone number validation

**IMPORTANT NOTE:**
This release of the IDnow SDK makes use of a library to validate phone numbers originally developed by Google.
The library name is `libPhoneNumber-iOS` (Version 0.9). In order to build apps using the IDnow SDK please update
your Podfile with the following entry:
`pod 'libPhoneNumber-iOS', '~> 0.9'`

Migration Guide:
- please change the SDK reference to 3.5.0 and call pod update

Bugfixes:
- minor bugfixes


### 3.4.1
Improvements:
- dynamic links for the terms of use and privacy policy

Migration Guide:
- please change the SDK reference to 3.4.1 and call pod update

Bugfixes:
- fixes a bug with the agent video stream
- minor bugfixes


### 3.4.0
Improvements:
- added positioning overlay for the front and backside id card steps
- communicate foreground/background state to the backend
- new version of IceLink WebRTC library

Bugfixes:
- fixes a bug with the agent video stream
- minor bugfixes

Migration Guide:
- please change the SDK reference to 3.4.0 and call pod update


### 3.3.3
Improvements:
- added a new setting to show the ident token on the checkscreen as well

Migration Guide:
- please change the SDK reference to 3.3.3 and call pod update
- using XCode 9 with CocoaPods might introduce a problem with your AppIcon. More details can be found below at `CocoaPods & XCode 9`

### 3.3.2
Bugfixes:
- minor bugixes

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
