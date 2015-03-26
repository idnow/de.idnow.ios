//
//  IDnowError.h
//  IDnow
//
//  Created by Matthias Redlin on 19.03.15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  All types of errors that can occure during an initialization or identification process.
 *  The errors will be returned in the completion blocks or delegate callbacks (see IDnowController).
 */
typedef NS_ENUM(NSInteger, IDnowErrorType){
	/**
	 *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
	 *  Occurs when the IDnowSettings instance does not contain a transactionToken.
	 */
	IDnowErrorTypeMissingTransactionToken,
	/**
	 *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
	 *  Occurs when the IDnowSettings instance does not contain a companyID.
	 */
	IDnowErrorTypeMissingCompanyID,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when the user tries to initialize a video ident on an iPhone 4 (not supported).
     */
    IDnowErrorTypeVideoIdentNotSupportedOniPhone4,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when an identification cannot be initialized because the time is outside business hours.
     */
    IDnowErrorTypeOfficeClosed,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when the device does either have no front camera or no back camera.
     */
    IDnowErrorTypeMissingCamera,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when a video ident was request, but the camera access was not granted by the user.
     */
    IDnowErrorTypeCameraAccessNotGranted,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when a video ident was requested, but the microphone access was not granted by the user.
     */
    IDnowErrorTypeMicrophoneAccessNotGranted,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when a video ident was requested, but the device does not provide a microphone.
     */
    IDnowErrorTypeMissingMicrophone,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when a video ident was requested, but no internet connection is present.
     */
    IDnowErrorTypeNoInternetConnection,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize])
     *  and identification process (e.g. triggered by [IDnowController startIdentificationFromViewController:]).
     *  The IDnowError object will also contain the status code returned by the server.
     */
    IDnowErrorTypeServer,
    /**
     *  Can occur during an identification process (e.g. triggered by [IDnowController startIdentificationFromViewController:]).
     */
    IDnowErrorTypeTokbox,
    /**
     *  Can occur during an identification process (e.g. triggered by [IDnowController startIdentificationFromViewController:]).
     *  Describes that an identification failed.
     */
    IDnowErrorTypeIdentificationFailed
};


/**
 *  A custom error object that describes errors that can occur while initializing or executing a photo or video identification.
 *  It contains the type of the error, a localized description and optionally a status code (when type == IDnowErrorTypeServer).
 */
@interface IDnowError : NSObject

/**
 *  The type of the error.
 */
@property (assign, nonatomic) IDnowErrorType type;

/**
 *  Optional, can contain the status code that was comming from the server.
 *  Set when type = IDnowErrorTypeServer
 */
@property (assign, nonatomic) NSInteger statusCode;

/**
 *  Optional, can be used as the message in an alert view for example
 */
@property (strong, nonatomic) NSString *localizedErrorDescription;

@end
