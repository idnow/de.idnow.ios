//
//  OTNetworkDeviceManagement.h
//  otkit-objc-libs
//
//  Created by Charley Robinson on 5/7/15.
//
//

#import "OTSession.h"

#ifndef otkit_objc_libs_OTNetworkDeviceManagement_h
#define otkit_objc_libs_OTNetworkDeviceManagement_h

@interface OTSession ()

/*
 * Set the list of network devices to ignore. For example, to disable
 * the cellular interface then pass in @[@"pdp_ip0"] for the
 * list parameter. This applies to the media engine only. Default behavior
 * still applies for the signaling socket to OpenTok: WiFi is used by default,
 * WWAN will be used otherwise.
 * Also note: If no list is specified, the media engine will negotiate
 * ICE connections on all available interfaces, and send STUN keepalives on
 * these interfaces. In iOS, this is all managed with a default controller.
 * To override this behavior, disable the default controller with
 * `[[OTNetworkReachabilityMonitor sharedInstance] invalidate];`
 *
 * @parm list An array of NSString
 */
+ (void) setNetworkDeviceIgnoreList:(NSArray*) list;

@end


#endif
