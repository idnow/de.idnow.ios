//
//  IDnowAppDelegate.h
//  idnow-sdk
//
//  This interface is optional and only required if your app wants to us
//
//  Copyright © 2017 IDnow GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>


@interface IDnowAppDelegate : UIResponder <UIApplicationDelegate, UNUserNotificationCenterDelegate>

@property (strong, nonatomic) NSString* tokenFromPushNotification;
@property (strong, nonatomic) UIWindow* window;

- (void)application:(UIApplication*)application  didFailToRegisterForRemoteNotificationsWithError:(NSError*)error;
- (void)application:(UIApplication*)application  didRegisterUserNotificationSettings:(UIUserNotificationSettings*)notificationSettings NS_DEPRECATED_IOS(8_0, 10_0);
- (void)application:(UIApplication*)application  didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;
- (BOOL)application:(UIApplication*)application  didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary*)userInfo;
- (void)applicationDidBecomeActive:(UIApplication*)application;
- (BOOL)application:(UIApplication*)application openURL:(NSURL *)url;

/*
 The method will be called on the delegate only if the application is in the foreground
 default UNNotificationPresentationOptions type alert
*/
-(void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

-(void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

@end
