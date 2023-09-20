//
//  NSError+IDnowError.h
//  idnow-sdk
//
//  Created by Matthias Redlin on 21/08/15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


FOUNDATION_EXPORT NSString *const IDnowErrorDomain;

FOUNDATION_EXPORT NSString *const IDnowStatusCodeErrorKey;

FOUNDATION_EXPORT NSString *const IDnowExceptionIDErrorKey;

FOUNDATION_EXPORT NSString *const IDnowCauseErrorKey;

FOUNDATION_EXPORT NSString *const IDnowSupportEmail;

/**
 * Declares possible error codes that can occur within a video or photo identification.
 */
typedef NS_ENUM (NSInteger, IDnowError)
{
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when the IDnowSettings instance does not contain a transactionToken.
     */
    IDnowErrorMissingTransactionToken		  = 1000,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when the IDnowSettings instance does not contain a companyID.
     */
    IDnowErrorMissingCompanyID				  = 1001,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when an identification cannot be initialized because the time is outside business hours.
     */
    IDnowErrorOfficeClosed                    = 1003,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when the device does either have no front camera or no back camera.
     */
    IDnowErrorMissingCamera                   = 1004,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when a video ident was request, but the camera access was not granted by the user.
     */
    IDnowErrorCameraAccessNotGranted          = 1005,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when a video ident was requested, but the microphone access was not granted by the user.
     */
    IDnowErrorMicrophoneAccessNotGranted      = 1006,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when a video ident was requested, but the device does not provide a microphone.
     */
    IDnowErrorMissingMicrophone               = 1007,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize]).
     *  Occurs when a video ident was requested, but no internet connection is present.
     */
    IDnowErrorNoInternetConnection            = 1008,
    /**
     *  Can occur during initialization (e.g. triggered by [IDnowController initialize])
     *  and identification process (e.g. triggered by [IDnowController startIdentificationFromViewController:]).
     *  The error object will also contain the status code returned by the server.
     */
    IDnowErrorServer                          = 1009,
    /**
     *  Can occur during an identification process (e.g. WebRTC service could not establish a video connection).
     */
    IDnowErrorWebRTC                          = 1010,
    /**
     *  Can occur during an identification process (e.g. triggered by [IDnowController startIdentificationFromViewController:]).
     *  Describes that an identification failed.
     */
    IDnowErrorIdentificationFailed            = 1011,
    /**
     *  With version 3.0.0 we stopped to support TokBox
     */
    IDnowErrorTokBoxNotSupported              = 1012,
    /**
     *  The token for Auto Ident
     */
    IDnowErrorTokenNotSupported               = 1013,
    /**
     *  Unable to perform an identification on a jailbroken device.
     *
     */
    IDnowErrorJailbreakPhoneNotSupported      = 1014,
    
    /**
     *  Using Icelink3 with invalid key
     *
     */
    IDnowErrorInvalidIcelinkToken             = 1015,
    
    /**
     *  High call volume so user agree to try later
     *
     */
    IDnowErrorHighCallVolumeTryLater            = 1016,
    
    /**
     *  User enrolled in Waiting List so current identification session aborted
     *
     */
    IDnowErrorEnrolledInWaitingList            = 1017,
    
    /**
     *  The PVID requirements is to only allow those users with the VideoIdent process whose device supports the required resolution criteria specified in the PVID standard
     *  i.e. The minimum resolution cannot be lower than 720p: 1280 × 720 at 25 frames per second.
     *
     */
    IDnowErrorDeviceNotMeetPVIDRequirements    = 1018,
    
    /**
     *  Error for a Unified Ident
     *  which states user decided to switch to another type of identification
     */
    IDnowErrorUnifiedIdentAnotherMethod  = 1019,

    /**
     *  eID standalone tokens
     */
    IDnowErrorTokenNotSupported_eIDStandalone  = 1020,

    /**
     *  Server trust certificate is not valid
     */
    IDnowErrorInvalidServerCertificate    = 1021,
    
    /**
     *  Unsupported products
     */
    IDnowErrorUnsupportedProduct  = 1022,
    
    /**
     *  Not support bluetooth headset
     */
    IDnowErrorUnsupportedBluetoothHeadset  = 1023,
};

@interface NSError (IDnowError)

@end
