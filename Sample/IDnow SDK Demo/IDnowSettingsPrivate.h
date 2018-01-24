//
//  IDnowSettingsPrivate.h
//  IDnow
//
//  Created by Matthias Redlin on 23.03.15.
//  Copyright (c) 2015 IDnow GmbH. All rights reserved.
//

#import "IDnowSettings.h"

@interface IDnowSettings ()

/**
 *  set this to YES in case you wish to perform idents with different short names.
 */
@property (assign, nonatomic) BOOL ignoreCompanyID;

@end