//
//  OTNetworkStatsKit.h
//  otkit-objc-libs
//
//  Created by Charley Robinson on 12/1/14.
//
//

#import <Foundation/Foundation.h>

/**
 * Describes video statistics for a subscriber. See
 * <[OTSubscriberKit setNetworkStatsDelegate:]>.
 */
@interface OTSubscriberKitVideoNetworkStats : NSObject

/**
 * The estimated number of video packets lost by this subscriber.
 */
@property (readonly) uint64_t videoPacketsLost;

/**
 * The number of video packets received by this subscriber.
 */
@property (readonly) uint64_t videoPacketsReceived;

/**
 * The number of video bytes received by this subscriber.
 */
@property (readonly) uint64_t videoBytesReceived;

/**
 * The timestamp, in milliseconds since the Unix epoch, for when these stats
 * were gathered.
 */
@property (readonly) double timestamp;

- (instancetype)initWithPacketsLost:(uint64_t)packetsLost
                    packetsReceived:(uint64_t)packetsReceived
                      bytesReceived:(uint64_t)bytesReceived
                          timestamp:(double)timestamp;

@end


/**
 * Describes audio statistics for a subscriber. See
 * <[OTSubscriberKit setNetworkStatsDelegate:]>.
 */
@interface OTSubscriberKitAudioNetworkStats : NSObject

/**
 * The estimated number of audio packets lost by this subscriber.
 */
@property (readonly) uint64_t audioPacketsLost;

/**
 * The number of audio packets received by this subscriber.
 */
@property (readonly) uint64_t audioPacketsReceived;

/**
 * The number of audio bytes received by this subscriber.
 */
@property (readonly) uint64_t audioBytesReceived;

/**
 * The timestamp, in milliseconds since the Unix epoch, for when these stats
 * were gathered.
 */
@property (readonly) double timestamp;

- (instancetype)initWithPacketsLost:(uint64_t)packetsLost
                    packetsReceived:(uint64_t)packetsReceived
                      bytesReceived:(uint64_t)bytesReceived
                          timestamp:(double)timestamp;

@end
