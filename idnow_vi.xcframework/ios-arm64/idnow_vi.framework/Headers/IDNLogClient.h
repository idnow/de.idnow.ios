//
//  IDNLogClient.h
//  idnow-sdk
//
//  Created by Phu Nguyen on 12/11/19.
//  Copyright © 2019 IDnow GmbH. All rights reserved.
//

#ifndef IDNLogClient_h
#define IDNLogClient_h

@protocol IDNLogClient <NSObject>

- (void)sendInfoWithMessage:(NSString *)message;
- (void)sendErrorWithMessage:(NSString *)message;
- (void)addInfoBreadcrumbWithMessage:(NSString *)message andCategory:(NSString *)category;
- (void)addErrorBreadcrumbWithMessage:(NSString *)message andCategory:(NSString *)category;

@optional
- (void)sendDebugWithMessage:(NSString *)message;
- (void)sendWarningWithMessage:(NSString *)message;
- (void)addDebugBreadcrumbWithMessage:(NSString *)message andCategory:(NSString *)category;
- (void)addWarningBreadcrumbWithMessage:(NSString *)message andCategory:(NSString *)category;

@end

#endif /* IDNLogClient_h */
