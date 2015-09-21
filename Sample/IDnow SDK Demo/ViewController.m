//
//  ViewController.m
//  IDnow SDK Demo
//
//  Created by Matthias Redlin on 24.03.15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import "ViewController.h"
#import "IDnowSDK.h"

@interface ViewController () <IDnowControllerDelegate>

@property (strong, nonatomic) IDnowController *idnowController;
@property (strong, nonatomic) IDnowSettings	  *settings;

@end

@implementation ViewController

#pragma mark - View lifecycle -

- (void) viewDidLoad
{
	[super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.


	// Set up and customize settings
	self.settings = [IDnowSettings new];
	self.settings.showErrorSuccessScreen = true;
	self.settings.showVideoOverviewCheck = true;
	self.settings.environment = IDnowEnvironmentDev;


	// Set up IDnowController
	self.idnowController = [[IDnowController alloc] initWithSettings: self.settings];
}


#pragma mark - IBActions -

- (IBAction) startVideoIdent: (id) sender
{
	// Setting dummy dev token and company id -> will instantiate a video identification
	self.settings.transactionToken = @"DEV-TXJKC";
	self.settings.companyID = @"ihrebank";

	self.idnowController.delegate  = nil;
	__weak typeof(self) weakSelf   = self;

	// Initialize identification using blocks (alternatively you can set the delegate and implement the IDnowControllerDelegate protocol)
	[self.idnowController initializeWithCompletionBlock: ^(bool success, NSError *error, bool canceledByUser)
	{
		if ( success )
		{
	        // Start identification using blocks
			[weakSelf.idnowController startIdentificationFromViewController: self withCompletionBlock: ^(bool success, NSError *error, bool canceledByUser)
				{
					if ( success )
					{
	                    // If showErrorSuccessScreen (Settings) is disabled
	                    // you can show for example an alert to your users.
					}
					else
					{
	                    // If showErrorSuccessScreen (Settings) is disabled and error.type == IDnowErrorTypeIdentificationFailed
	                    // you can show for example an alert to your users.
					}
				}];
		}
		else if ( error )
		{
	        // Present an alert containing localized error description
			// When targeting iOS 7 and later, you should use an UIAlertView instead when running on iOS 7.
			UIAlertController *alertController = [UIAlertController alertControllerWithTitle: @"Error" message: error.localizedDescription preferredStyle: UIAlertControllerStyleAlert];
			UIAlertAction *action = [UIAlertAction actionWithTitle: @"Ok" style: UIAlertActionStyleCancel handler: nil];
			[alertController addAction: action];
			[weakSelf presentViewController: alertController animated: true completion: nil];
		}
	}];
}


- (IBAction) startPhotoIdent: (id) sender
{
	// Setting dummy dev token and company id -> will instantiate a photo identification
	self.settings.transactionToken = @"DEV-LDFRG";
	self.settings.companyID = @"idnow";
	
	// This time we use the delegate instead of blocks (it's your choice)
	self.idnowController.delegate = self;

	// Initialize identification
	[self.idnowController initialize];
}


#pragma mark - IDnowControllerDelegate -

- (void) idnowController: (IDnowController *) idnowController initializationDidFailWithError: (NSError *) error
{
	// Initialization failed -> Present an alert containing localized error description
	// When targeting iOS 7 and later, you should use an UIAlertView instead when running on iOS 7.
	UIAlertController *alertController = [UIAlertController alertControllerWithTitle: @"Error" message: error.localizedDescription preferredStyle: UIAlertControllerStyleAlert];
	UIAlertAction	  *action		   = [UIAlertAction actionWithTitle: @"Ok" style: UIAlertActionStyleCancel handler: nil];
	[alertController addAction: action];
	[self presentViewController: alertController animated: true completion: nil];
}


- (void) idnowControllerDidFinishInitializing: (IDnowController *) idnowController
{
	// Initialization was successfull -> Start identification
	[self.idnowController startIdentificationFromViewController: self];
}


- (void) idnowControllerCanceledByUser: (IDnowController *) idnowController
{
	// The identification was canceled by the user.
	// For example the user tapped on the "x"-Button or simply navigates back.
	// Normally you don't have to do anything...
}


- (void) idnowController: (IDnowController *) idnowController identificationDidFailWithError: (NSError *) error
{
	// Identification failed
	// If showErrorSuccessScreen (Settings) is disabled and error.type == IDnowErrorTypeIdentificationFailed
	// you can show for example an alert to your users.
}


- (void) idnowControllerDidFinishIdentification: (IDnowController *) idnowController
{
	// Identification was successfull
	// If showErrorSuccessScreen (Settings) is disabled
	// you can show for example an alert to your users.
}


#pragma mark - Memory Management -

- (void) didReceiveMemoryWarning
{
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}


@end