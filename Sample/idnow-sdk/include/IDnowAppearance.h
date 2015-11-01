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

/**
 *  Optional color, that replaces the default text color.
 *  Default: A nearly black color
 *  Recommendation: Should be some kind of a dark color that does not collide with white color.
 */
@property (strong, nonatomic) UIColor *defaultTextColor;

/**
 *  Optional color, that replaces the default brand color.
 *  Default: defaultTextColor
 *  Used in headlines, checkboxes, links, alerts etc.
 *  Recommendation: Should be a color that does not collide with white color.
 */
@property (strong, nonatomic) UIColor *primaryBrandColor;

/**
 *  Optional color, that replaces the procees button background color.
 *  Default value: An orange color
 *  Recommendation: Should be a color that does not collide with white font color (e.g. orange, blue, red etc.).
 */
@property (strong, nonatomic) UIColor *proceedButtonBackgroundColor;

/**
 *  Optional color, that replaces the default color of textfield backgrounds and borders
 *  Default: defaultTextColor
 */
@property (strong, nonatomic) UIColor *textFieldColor;

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

@end

NS_ASSUME_NONNULL_END