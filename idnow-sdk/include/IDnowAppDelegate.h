//
//  IDnowAppDelegate.h
//  idnow-sdk
//
//  This interface is optional and only required if your app wants to us
//
//  Copyright © 2017 IDnow GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>



@interface IDnowAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) NSString* tokenFromPushNotification;
@property (strong, nonatomic) UIWindow* window;

- (void)application:(UIApplication*)application  didFailToRegisterForRemoteNotificationsWithError:(NSError*)error;
- (void)application:(UIApplication*)application  didRegisterUserNotificationSettings:(UIUserNotificationSettings*)notificationSettings;
- (void)application:(UIApplication*)application  didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;
- (BOOL)application:(UIApplication*)application  didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary*)userInfo;
- (void)applicationDidBecomeActive:(UIApplication*)application;
- (BOOL)application:(UIApplication*)application openURL:(NSURL *)url;

@end
