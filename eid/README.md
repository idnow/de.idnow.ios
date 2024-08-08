# IDnow eID SDK

## Table of Contents

- [IDnow eID SDK](#idnow-eid-sdk)
  - [Table of Contents](#table-of-contents)
  - [Requirements](#requirements)
  - [Installation](#installation)
    - [Host app configuration](#host-app-configuration)
    - [Usage:](#usage)
      - [Swift](#swift)
      - [Objective C](#objective-c)
      - [Swift](#swift-1)
      - [Objective C](#objective-c-1)
      - [Swift](#swift-2)
      - [Objective C](#objective-c-2)
  - [Error codes](#error-codes)
  - [Branding (IDN\_eIDAppearance)](#branding-idn_eidappearance)
    - [Colors](#colors)
    - [Configuration](#configuration)
      - [enableTnC](#enabletnc)
    - [Fonts](#fonts)
      - [fontNameRegular](#fontnameregular)
      - [fontNameBold](#fontnamebold)
      - [fontNameMedium](#fontnamemedium)
      - [fontNameLight](#fontnamelight)
    - [Button styles](#button-styles)
      - [underlineButtonTitles](#underlinebuttontitles)
      - [boldButtonTitles](#boldbuttontitles)

---

## Requirements

- Xcode 14.3 or later
- Deployment Target: iOS 11.0 or later (__Note__: NFC can work only with iPhone 7 or higher)

---

## Installation

Download the latest version of the [eID framework](https://github.com/idnow/de.idnow.ios/releases).

### Host app configuration

- Add the `idnow_eid.framework` and `AuthadaAuthenticationLibrary.xcframework` to your Xcode project files. __NOTE__:
  - Due to technical reasons, we cannot make the following library available on Github: `AuthadaAuthenticationLibrary.xcframework`. Please contact your customer success manager so that they can provide it to you.
- Navigate to your project settings, select your build target and open `Build Phases`.
- Add the `idnow_eid.framework`, `CoreNFC.framework` and `AuthadaAuthenticationLibrary.xcframework` to `Link Binary With Libraries` ![alt text](/screenshots/eid_screenshot_1.png)
- Make sure both `AuthadaAuthenticationLibrary` and `idnow_eid` frameworks are added in `Embed Frameworks` section.![alt text](/screenshots/eid_screenshot_4.png)
- Add `Near Field Communication Tag Reading` as a capability. In the entitlements file, check if there is an array for the key `Near Field Communication Tag Reader Session Format`, make sure the array contains the entry `NFC tag-specific data protocol`. ![alt text](/screenshots/eid_screenshot_2.png)
- Update the `Info.plist` file:

  - Add an array with the key `com.apple.developer.nfc.readersession.iso7816.select-identifiers` / `ISO7816 application identifiers for NFC Tag Reader Session`. Then add 2 items to the array: `E80704007F00070302`, `A0000002471001`.
  - Add a description for `Privacy - NFC Scan Usage Description`
    ![alt text](/screenshots/eid_screenshot_3.png)

### Usage:

**Step 1:** Import the library into your source code.

#### Swift

```
import idnow_eid
```

#### Objective C

```
@import idnow_eid;
```

**Step 2:** Configure the apearance.

You can customize the SDK appearance by accessing the properties of the IDN_eIDAppearance class. The complete list of properties and possible values can be found [here](#branding-idn_eidappearance).

#### Swift

```
let eidAppearance = IDN_eIDAppearance.shared
eidAppearance.underlineButtonTitles = false
eidAppearance.fontNameBold          = "TimesNewRomanPS-BoldMT"
eidAppearance.fontNameRegular       = "TimesNewRomanPSMT"
eidAppearance.primaryBrandColor     = .cyan
eidAppearance.proceedButtonBackgroundColor = .magenta
eidAppearance.linkColor             = .systemBlue
```

#### Objective C

```
IDN_eIDAppearance *appearance = IDN_eIDAppearance.shared;
appearance.primaryBrandColor         = UIColor.cyanColor;
appearance.proceedButtonBackgroundColor = UIColor.magentaColor;
appearance.linkColor                 = UIColor.blueColor;
appearance.underlineButtonTitles     = false;
appearance.fontNameRegular           = @"TimesNewRomanPSMT";
appearance.fontNameBold              = @"TimesNewRomanPS-BoldMT";
```

**Step 3:** Obtain the ident token and instantiate the eID flow router.

#### Swift

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
                        print("LOG: - Identification  \(identSuccess ? "Succeded" : "Failed")")
                    }
                }
            } else {
                print("LOG: - Device not support nfc ")
            }
    })
```

#### Objective C

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
                NSLog(@"LOG: - Identification %s",
                success ? "Succeded" : "Failed" );
            }
        }];
    } else {
        NSLog(@"LOG: - Device doesnot support");
    }
}];
```

## Error codes


| Swift                        | Objective C                              | Description                                                                                             |
| ------------------------------ | ------------------------------------------ | :-------------------------------------------------------------------------------------------------------- |
| unsupportedNFC               | IDN_eIDErrorUnsupportedNFC               | The flow cannot be started because the device does not support NFC.                                     |
| userCancelled                | IDN_eIDErrorUserCancelled                | The user cancelled the identification process manually.                                                 |
| invalidToken                 | IDN_eIDErrorInvalidToken                 | The supplied token is invalid.                                                                          |
| preconditionFailed           | IDN_eIDErrorPreconditionFailed           | Some of the preconditions weren't met. This includes: expired ident code, already used ident code, etc. |
| tokenUnsupportElectronicCard | IDN_eIDErrorTokenUnsupportElectronicCard | The document used for the identification is unsupported.                                                |
| unknown                      | IDN_eIDErrorUnknown                      | The process has failed with an undefined error.                                                         |

## Branding (IDN_eIDAppearance)

All appearance settings are identical to the ones used in VI SDK.
**Warning**: Branding is only allowed if you have the permissions from IDnow.

### Colors


| Parameter name               | Description                                                                                                                                                                              | Appearance                                                                                                                                    |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| defaultTextColor             | Optional color that replaces the default text color.</br> Default: A nearly black color</br> Recommendation: Should be some kind of a dark color that does not collide with white color. | <img src="/screenshots/eid_text_color.jpeg" width="250">   |
| secondaryTextColor           | Optional secondary text color. Used to contrast the primary color for some text elements.                                                                                                | <img src="/screenshots/eid_secondary_color.jpeg" width="250">                                                                                    |
| primaryBrandColor            | Optional color that replaces the default brand color. Recommendation: Should be a color that does not collide with white color.                                                          | <img src="/screenshots/eid_brand_color.jpeg" width="250">                                                              |
| proceedButtonBackgroundColor | Optional color that replaces the proceed button background color. Default: An orange color                                                                                               | <img src="/screenshots/eid_custom_proceed.jpeg" width="250">                                                                             |
| proceedButtonTextColor       | Optional color that replaces the proceed button text color. Default value: White color                                                                                                   | <img src="/screenshots/eid_custom_button_text_color.jpeg" width="250">                                                         |
| backgroundColor              | Optional color to be used as the screen background. Default value: Light gray color.                                                                                                     | <img src="/screenshots/eid_background.jpeg" width="250">                                                                                      |
| backgroundCellsColor         | Background color for cell UI elements, e.g. input cells, entry buttons.                                                                                                                  | <img src="/screenshots/eid_cell_background.jpeg" width="250">                                                                           |
| primarySubstitutionColor     | A color for link actions/subtitles in case the brand color is unreadable. Default value: brand color.                                                                                    | <img src="/screenshots/eid_substitution.jpeg" width="250">                                                                          |
| textFieldColor               | Optional color that replaces the default text color of the textfield components. Default: defaultTextColor                                                                               | <img src="/screenshots/eid_textfield_color.jpeg" width="250">                                                                                 |
| mode                         | IDN_eIDAppearanceMode flag that is responsible for controlling the flow appearance mode.<br />*Possible values:* </br> *light*</br>*dark*</br>*system*                                   | *IDN_eIDAppearanceMode.dark*<img src="/screenshots/eid_night_mode.jpeg" width="250"></br></br>Light mode can be seen on other illustrations. |
| usedNewBrand                 | A flag that specifies if the flow should use the new style (this includes fonts, logo and button corner radius).<br />Default value: `true`                                              | *usedNewBrand = false*<img src="/screenshots/eid_old_brand.jpeg" width="250"><br /><br />*usedNewBrand = true* <img src="/screenshots/eid_new_brand.jpeg" width="250"></br>          |
| cornerRadius                 | An optional value for button corner radius.</br>**Note**: works only with `usedNewBrand = false` otherwise the button has round corners. </br>Default value: `4.0`                       | <img src="/screenshots/eid_corner_radius.jpeg" width="250">                                                                            |
| userInterfaceLanguage        | Optional string representing a language code to be used for the flow.</br>Default value: system language.                                                                                | -                                                                                                                                             |

### Configuration

Additionally, the Terms and Conditions checkbox visibility can be configured via `IDN_eIDConfig`.

#### enableTnC

A flag that toggles the visibility of the Terms&Conditions checkbox.
*Default*: true

*Example usage*:

```
IDN_eIDConfig.shared.enableTnC = false
```

### Fonts

#### fontNameRegular

An optional font name that can be used to replace the regular font used by the SDK.</br>
_Default:_ System regular Font

#### fontNameBold

An optional font name that can be used to replace the bold font used by the SDK.</br>
_Default:_ System bold Font

#### fontNameMedium

An optional font name that can be used to replace the medium font used by the SDK.</br>*Default: System medium Font*

#### fontNameLight

An optional font name that can be used to replace the light font used by the SDK.</br>*Default: System light Font*

### Button styles

#### underlineButtonTitles

Underline all button titles. Set this to `true` in order to underline button text.</br>
_Default:_ `false`

#### boldButtonTitles

Make button titles bold. Set this to `false` in order to use normal font weight in button titles.</br>
_Default:_ `true`
