//
//  ViewController.m
//  IDnow SDK Demo
//
//  Created by Matthias Redlin on 24.03.15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import "ViewController.h"
#import "IDnowSettingsPrivate.h"

@import IDnowSDK;


// The transaction token that should be used for a video identification
static NSString *const TRANSACTION_TOKEN_VIDEO_IDENT = @"DEV-YPENX";

// Your company id provided by IDnow
static NSString *const COMPANY_ID_VIDEO_IDENT = @"ihrebank";

// The transaction token that should be used for a photo identification
static NSString *const TRANSACTION_TOKEN_PHOTO_IDENT = @"DEV-TAZLS";

// Your company id provided by IDnow
static NSString *const COMPANY_ID_PHOTO_IDENT = @"idnow";


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
  self.settings.ignoreCompanyID        = true;
  
	// Set up IDnowController
	self.idnowController = [[IDnowController alloc] initWithSettings: self.settings];
}


#pragma mark - IBActions -

- (IBAction) startVideoIdent: (id) sender
{
	// Setting dummy dev token and company id -> will instantiate a video identification
    self.settings.transactionToken = TRANSACTION_TOKEN_VIDEO_IDENT;
    self.settings.companyID = COMPANY_ID_VIDEO_IDENT;

	self.idnowController.delegate  = nil;
	__weak typeof(self) weakSelf   = self;

	// Initialize identification using blocks (alternatively you can set the delegate and implement the IDnowControllerDelegate protocol)
	[self.idnowController initializeWithCompletionBlock:^(BOOL success, NSError * _Nullable error, BOOL canceledByUser)
	{
		if ( success )
		{
	        // Start identification using blocks
            [weakSelf.idnowController startIdentificationFromViewController:self withCompletionBlock:^(BOOL success, NSError * _Nullable error, BOOL canceledByUser)
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
    self.settings.transactionToken = TRANSACTION_TOKEN_PHOTO_IDENT;
    self.settings.companyID = COMPANY_ID_PHOTO_IDENT;
	
	// This time we use the delegate instead of blocks (it's your choice)
	self.idnowController.delegate = self;

	// Initialize identification
	[self.idnowController initialize];
}


#pragma mark - IDnowControllerDelegate -

- (void) idnowController: (IDnowController *) idnowController initializationDidFailWithError: (NSError *) error
{
	// Initialization failed -> Present an alert containing localized error description
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
