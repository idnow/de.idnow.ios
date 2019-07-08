//
//  IDnowAppearance.h
//  IDnow
//
//  Created by Matthias Redlin on 11/09/15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


enum CHECKBOX_POSITION
{
    LEFT,
    RIGHT,
    TOP_LEFT,
};

enum NUMBER_LABEL_POSITION
{
    LABELTOP,
    LABELLEFT,
    LABELRIGHT
};

enum REQUEST_CODE_AGAIN_LAYOUT_TYPE
{
    BOTTOM,
    TOP,
};

/**
 *  This class is used to control the appearance of the SDK
 *  You can define colors, fonts and appearance settings here
 */
@interface IDnowAppearance : NSObject

// -----------------------------------------------------------------------------------
//									Initialization
// -----------------------------------------------------------------------------------

/**
 *  Returns the shared IDnowAppearance Object.
 *
 *  @return IDnowAppearance instance.
 */
+ (instancetype) sharedAppearance;


// -----------------------------------------------------------------------------------
//									Colors
// -----------------------------------------------------------------------------------

+ (BOOL) isColorDark:(UIColor *) color;

- (UIColor *)colorFromHexString:(NSString *)hexString;

/**
 *  Optional color, that replaces the default text color.
 *  Default: A nearly black color
 *  Recommendation: Should be some kind of a dark color that does not collide with white color.
 */
@property (strong, nonatomic) UIColor *defaultTextColor;

/**
 *  Optional color, that replaces the default brand color.
 *  Default: defaultTextColor.
 *  Used in headlines, checkboxes, links, alerts etc.
 *  Recommendation: Should be a color that does not collide with white color.
 */
@property (strong, nonatomic) UIColor *primaryBrandColor;

/**
 *  Optional color, that replaces the color that will be used for headlines.
 *  Default: primaryBrandColor.
 *  Recommendation: Should be a color that does not collide with white color.
 */
@property (strong, nonatomic) UIColor *headlineColor;

/**
 *  Optional color, that replaces the color that will be used for links.
 *  Default: primaryBrandColor.
 *  Recommendation: Should be a color that does not collide with white color.
 */
@property (strong, nonatomic) UIColor *linkColor;

/**
 *  Optional color, that replaces the color that will be used for checkboxes.
 *  Default: primaryBrandColor.
 *  Recommendation: Should be a color that does not collide with white color.
 */
@property (strong, nonatomic) UIColor *checkIconColor;


/**
 *  Optional color, that replaces the proceed button background color.
 *  Default value: An orange color
 *  Recommendation: Should be a color that does not collide with white font color (e.g. orange, blue, red etc.).
 */
@property (strong, nonatomic) UIColor *proceedButtonBackgroundColor;

/**
 *  Optional color, that replaces the proceed button text color.
 *  Default value: White color
 *  Recommendation: Should be a color that does not collide with proceedButtonBackgroundColor.
 */
@property (strong, nonatomic) UIColor *proceedButtonTextColor;


/**
 *  Optional color, that replaces the photo ident retake button background color.
 *  Default value: defaultTextColor
 *  Recommendation: Should be a color that does not collide with photoIdentRetakeButtonTextColor.
 */
@property (strong, nonatomic) UIColor *photoIdentRetakeButtonBackgroundColor;

/**
 *  Optional color, that replaces the photo ident retake button text color.
 *  Default value: proceedButtonTextColor
 *  Recommendation: Should be a color that does not collide with photoIdentRetakeButtonBackgroundColor.
 */
@property (strong, nonatomic) UIColor *photoIdentRetakeButtonTextColor;

/**
 *  Optional color that replaces the "Back" button color in the WebConsentProtocol-Signing contract review screen.
 *  Default value: proceedButtonBackgroundColor
 */
@property (strong, nonatomic) UIColor *checkContractFooterButtonBackgroundColor;

/**
 *  Optional color that replaces the "Back" button text color in the WebConsentProtocol-Signing contract review screen.
 *  Default value: proceedButtonBackgroundColor
 */
@property (strong, nonatomic) UIColor *checkContractFooterButtonTextColor;

/**
 *  Optional color, that replaces the default color of textfield backgrounds and borders
 *  Default: defaultTextColor
 */
@property (strong, nonatomic) UIColor *textFieldColor;

/**
 *  Optional corner radius for text fields
 *  Default: 4.0
 */
@property (strong, nonatomic) NSNumber *textFieldCornerRadius;

/**
 *  Optional UIColor determining a text field's inset color
 */
@property (strong, nonatomic) UIColor *textFieldBorderColor;

/**
 *  Optional color, that replaces the text color in the result screen, when an identification failed.
 *  Default: A red color
 */
@property (strong, nonatomic) UIColor *failureColor;

/**
 *  Optional color, that replaces the text color in the result screen, when an identification was successful.
 *  Default: A green color
 */
@property (strong, nonatomic) UIColor *successColor;

/**
 *  Optional color that replaces the background color in each view controller with a navigation bar.
 *  Default: primaryBrandColor
 */
@property (strong, nonatomic) UIColor *titleBackgroundColor;

/**
 *  Optional color that replaces default green / red title colors for the success indicator label on the result screen.
 *  Default: green / red depending on success
 */
@property (strong, nonatomic) UIColor *resultScreenHeaderLabelColor;

/**
 *  Optional separator dividing title and view body. Default height is 2 points.
 *  Separator color: primaryBrandColor
 */
@property (assign, nonatomic) BOOL useTitleSeparator;

/**
 *  Optional UIImageView that replaces the title on the result screen.
 *  Default: nil
 */
@property (strong, nonatomic) UIImage *titleBackgroundImage;

/**
 *  Optional value that separates titleBackgroundImage from its superview's edges.
 *  Default: nil
 */
@property (assign, nonatomic) CGFloat titleBackgroundImageOffset;

/**
 * Optional value that determines if buttons on the result page should appear in the navigation bar or below as normal UIButtons.
 * Default: NO
 */
@property (assign, nonatomic) BOOL resultButtonsAsUIButtonsBelow;

@property (assign, nonatomic) BOOL useResultIcon;

// -----------------------------------------------------------------------------------
//									Table View
// -----------------------------------------------------------------------------------
/**
 * Default: LEFT - the checkboxes are positioned on the left side
 * set this to RIGHT to reverse the order
 */
@property (assign, nonatomic) enum CHECKBOX_POSITION checkBoxPosition;

@property (assign, nonatomic) BOOL shouldShowGTCInline;

/**
 * Default: LEFT - The number label position in the instructions view.
 * Set to TOP, this causes the number label to appear on top of text,
 * rather than next to it.
 */
@property (assign, nonatomic) enum NUMBER_LABEL_POSITION numberLabelPosition;

/**
 *  Default: NO - the seperator line is only visible below the content and not the checkbox
 *  settings this to YES draws the line across the entire cell width
 */
@property (assign, nonatomic) BOOL seperatorLineComplete;

/**
 *  Default: NO - since all checkboxes are mandory this is not really neccessary
 *  set this to YES in order to show a littel asterix behind the cells title
 */
@property (assign, nonatomic) BOOL markMandatoryCells;

/**
 *  Default: YES - Underline all button titles
 *  Set this to NO in order to underline button title text
 */
@property (assign, nonatomic) BOOL underlineButtonTitles;

/**
 *  Default: YES - Make button titles bold
 *  Set this to NO in order to use normal font weight in button titles
 */
@property (assign, nonatomic) BOOL boldButtonTitles;

/**
 *  Default: NO - Whether or not all titles should use a bold font weight
 *  Set this to YES in order to use bold font weight for titles throughout the SDK
 */
@property (assign, nonatomic) BOOL boldTitles;

/**
 *  Default: BOTTOM
 *  Set this to TOP - the ident code box above request again button, refer Whitelabeling Fiducia
 */
@property (assign, nonatomic) enum REQUEST_CODE_AGAIN_LAYOUT_TYPE requestCodeAgainLayoutType;

/**
 *  Default: NO - Whether or not check boxes should be squared rather than round
 */
@property (assign, nonatomic) BOOL checkBoxesSquared;

/**
 *  Default NO - makes input boxes squared and slightly larger.
 */
@property (assign, nonatomic) BOOL inputFieldsSquared;

/**
 * Default NO - Ident code request for only covers half the screen
 */
@property (assign, nonatomic) BOOL identCodeLayoutHalf;

/**
 * Default nil - Set this to a UIBarButtonItem of your preference in order to customize its appearance throughout the SDK
 */
@property (nullable, strong, nonatomic) UIBarButtonItem *customBackButtonItem;

/**
 * Default nil - Set this to a UIButton of your choice in order to customize the appearance of the cancel button during idents
 */
@property (nullable, strong, nonatomic) UIButton *customCancelButton;

/**
 * Default nil - Set this to a UIView in order to customize the appearance of the agent's window prior to connecting
 */
@property (nullable, strong, nonatomic) UIView *customAgentView;

/**
 * Default nil - Set this to a valid NSURL to a 60x60 gif relative to your main bundle in order to use this as activity indicator throughout your app
 */
@property (nullable, strong, nonatomic) NSURL *customActivityIndicatorURL;

// -----------------------------------------------------------------------------------
//									Status Bar
// -----------------------------------------------------------------------------------


/**
 *  Optional: Forces the light status bar style to match dark navigation bars.
 *  If you tint your navigation bar with a dark color by adjusting navigation bar appearance (e.g. a blue color)
 *  you can set this value to true. The statusbar style will then be adjusted to light in screens where the navigation bar is visible.
 */
@property (assign, nonatomic) BOOL enableStatusBarStyleLightContent;


// -----------------------------------------------------------------------------------
//									Font Names
// -----------------------------------------------------------------------------------

/**
 *  An optional font name that can be used to replace the bold font used by the SDK.
 *  Default: System Font: Helvetica Neue Bold (< iOS 9), San Francisco Bold (>= iOS 9)
 */
@property (nullable, strong, nonatomic) NSString *fontNameBold;

/**
 *  An optional font name that can be used to replace the regular font used by the SDK.
 *  Default: System Font: Helvetica Neue Regular (< iOS 9), San Francisco Regular (>= iOS 9)
 */
@property (nullable, strong, nonatomic) NSString *fontNameRegular;

/**
 *  An optional font name that can be used to replace the medium font used by the SDK.
 *  Default: System Font: Helvetica Neue Medium (< iOS 9), San Francisco Medium (>= iOS 9)
 */
@property (nullable, strong, nonatomic) NSString *fontNameMedium;

/**
 *  An optional font name that can be used to replace the light font used by the SDK.
 *  Default: System Font: Helvetica Neue Light (< iOS 9), San Francisco Light (>= iOS 9)
 */
@property (nullable, strong, nonatomic) NSString *fontNameLight;

// -----------------------------------------------------------------------------------
//                                    Video Ident
// -----------------------------------------------------------------------------------

/**
 * Should show a blur overlay on video while identification
 * False is default
 */

@property (assign, nonatomic) BOOL shouldShowBlurOverlayLayer;

/**
 * Alpha value for blur view (default - 1.0)
 */

@property (assign, nonatomic) CGFloat alphaBlurViewValue;

/**
 * Light blur for ident code container only
 */

@property (assign, nonatomic) BOOL lightBlurForIdentCodeContainer;

// -----------------------------------------------------------------------------------
//                                    Call Quality Check
// -----------------------------------------------------------------------------------

@property (assign, nonatomic) BOOL shouldShowNavigationBarOnCQCScreen; // Put CQC screen in navigation stack instead of present it
@property (assign, nonatomic) BOOL shouldUseHeadlineColorForPreCheckTitle; // Default grey, apply headline color for title
@property (assign, nonatomic) BOOL progressBarsSquared; // Squared bars instead of

@property (assign, nonatomic) BOOL shouldShowResultTitleForCQCResult; // on the call quality check screen, should be show result
@property (assign, nonatomic) BOOL shouldShowNetworkIndicatorForCQCResult;// three dots indicate network condition
@property (assign, nonatomic) BOOL recheckButtonsBordered; // default is underline
@property (assign, nonatomic) BOOL shouldSeparateFooter; // on CQC result screen, show footer separator
@property (assign, nonatomic) BOOL suggestionListBulleted;


@end

NS_ASSUME_NONNULL_END
