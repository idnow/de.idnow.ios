//
//  IDnowController.h
//  IDnow
//
//  Created by Matthias Redlin on 19.03.15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@class IDnowSettings;

NS_ASSUME_NONNULL_BEGIN

@protocol IDnowControllerDelegate;


/**
 *  Used as the callback for initializing and performing an identification.
 *
 *  @param success        Describes if the initialization or identification was successfull or not.
 *  @param error          The error that occurred during initialization or identification. Optionally, can be nil.
 *  @param canceledByUser Describes if the identification was canceled by the user.
 */
typedef void (^IDnowCompletionBlock)(BOOL success, NSError *__nullable error, BOOL canceledByUser);


/**
 *  The main class of the SDK. It provides functionality to instantiate a new
 *  identification process and presents the UI needed for the configured identification method
 *
 *  First you should create an IDnowSettings object, which should contain at least a transactionToken and a companyID.
 *  You can customize the identification process by setting some of the additional properties of the IDnowSettings instance.
 *  For more information take a look at the IDnowSettings class.
 *
 *  Create an instance by calling initWithSettings:, adding the created IDnowSettings object as parameter.
 *
 *  To start an identification you can call initializeWithCompletionBlock:.
 *  The completion block will contain additional information of success or failure of the initialization.
 *  For more information take a look at IDnowCompletionBlock.
 *  Alternatively you can set the delegate property and call initialize to get informed about success or failure.
 *  For more information take a look at IDnowControllerDelegate.
 *
 *  When the initialization failed, you will receive an error object, that contains additional information about the error.
 *  E.g. you can show an UIAlertView / UIAlertController taking the localizedDescription into account.
 *
 *  When the initialization was successful, you can start the identification process by
 *  calling startIdentificationFromViewController:presentModal:withCompletionBlock:.
 *  The completion block will contain additional information of success or failure of the identification process.
 *  For more information take a look at IDnowCompletionBlock.
 *  Alternatively you can set the delegate property and call startIdentificationFromViewController:presentModal:
 *  to get information about success or failure.
 *  For more information take a look at IDnowControllerDelegate.
 *
 *  When the identification failed the success value of the completion block will be set to false and you will receive an error object,
 *  that contains additional information about the error.
 *  The errors are automatically handled by the SDK, so you don't have to display an extra alert to the user.
 *
 *  When the identification was canceled by the user the canceledByUser value will be true (see IDnowCompletionBlock)
 *  or you will get the appropriate callback from the delegate (see IDnowControllerDelegate).
 *
 *  When the identification was successfull the success value will be set to true (see IDnowCompletionBlock) or you will get the appropriate callback from the delegate (see IDnowControllerDelegate).
 */
@interface IDnowController : NSObject

/**
 *  The delegate that should be notified by the IDnowController.
 *  Instead of using a delegate you can also use completion blocks (see IDnowCompletionBlock).
 */
@property (nullable, weak, nonatomic) NSObject<IDnowControllerDelegate> *delegate;

/**
 *  Creates a new instance of IDNowController with the specified settings object.
 *
 *  @param settings An IDnowSettings object that contains the params and options of the identification process.
 *  Should contain at least a transactionToken and a companyID (see IDnowSettings).
 *
 *  @return An IDnowController instance.
 */
- (instancetype) initWithSettings: (IDnowSettings *) settings;

/**
 *  Initializes an identification process provided by IDnow.
 *  Before calling it, you should have set the delegate property.
 *
 *  Success calls [IDnowControllerDelegate idnowControllerDidFinishInitializing:] on the delegate.
 *
 *  Failure calls [IDnowControllerDelegate idnowController:initializationDidFailWithError:] on the delegate.
 *
 *  When initialization was successfull you can call startIdentificationFromViewController:presentModal:
 *  or startIdentificationFromViewController:presentModal:withCompletionBlock: to start the identification process.
 *
 *  @warning *Note:* You can also call initializeWithCompletionBlock: instead if you don't want to use a delegate.
 */
- (void) initialize;

/**
 *  Initializes an identification process provided by IDnow.
 *  The completion block will contain information about success or failure of the identification.
 *  When initialization was successfull you can call startIdentificationFromViewController:presentModal:
 *  or startIdentificationFromViewController:presentModal:withCompletionBlock: to start the identification process.
 *
 *  @warning *Note:* You can also call initialize instead if you want to use the IDnowControllerDelegate protocol.
 *
 *  @param completionBlock Block that will be executed when operation was successfull or failed.
 *
 */
- (void) initializeWithCompletionBlock: (nullable IDnowCompletionBlock) completionBlock;

/**
 *  Starts the identification process and presents necessary UI from the given view controller.
 *  You will receive the results by implementing the IDnowControllerDelegate protocol.
 *
 *  @param presentingViewController The viewcontroller the identification UI should be presented from.
 */
- (void) startIdentificationFromViewController: (UIViewController *) presentingViewController;

/**
 *  Starts the identification process and presents necessary UI from the given view controller.
 *  You will receive the results within the completion block (see IDnowCompletionBlock).
 *
 *  @param presentingViewController The viewcontroller the identification UI should be presented from.
 *  @param completion Block that will be executed when operation was successfull or failed.
 */
- (void) startIdentificationFromViewController: (UIViewController *) presentingViewController
                           withCompletionBlock: (nullable IDnowCompletionBlock) completion;

/**
 * Loads a backend-supplied string in the current locale's language with a specified key.
 * Only available after the SDK did finish initialization.
 * @param key identifying the string to load
 * @return the requested string if the sdk was successfully initialized first and if there's a message for the key.
 */
+ (NSString*)getMessageFor:(NSString*)key;

/**
 * Returns the current IDnowController if there is one. Can be nil.
 * @return The current IDnowController or nil if there is none (yet).
 */
+ (instancetype) currentIDnowController;

@end


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

NS_ASSUME_NONNULL_END
