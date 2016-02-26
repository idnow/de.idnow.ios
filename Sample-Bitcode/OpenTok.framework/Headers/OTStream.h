//
//  OTStream.h
//
//  Copyright (c) 2014 Tokbox, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

/**
* Defines values for the <[OTStream videoType]> property.
*/
typedef NS_ENUM(int32_t, OTStreamVideoType) {
    /**
     * Defines the camera video mode setting for the
     * <[OTStream videoType]> property.
     */
    OTStreamVideoTypeCamera = 1,
    /**
     * Defines the screen video mode setting for the
     * <[OTStream videoType]> property.
     */
    OTStreamVideoTypeScreen = 2,
};

@class OTSession, OTConnection;

/**
 * An OTStream object represents a stream of multimedia, which may
 * contain video and/or audio data.
 *
 * Use OTStream instances to initialize <OTSubscriber> interfaces. Do not
 * attempt to initialize an OTStream directly.
 */
@interface OTStream : NSObject

/** @name Getting basic stream information */

/**
 * The <OTConnection> object corresponding to the connection that is publishing the stream.
 * You can compare this to to the <[OTSession connection]> property to see if the stream
 * is being published by the local device.
 */
@property(readonly) OTConnection* connection;

/**
 * The session (an <OTSession> object) the stream is bound to.
 */
@property(readonly) OTSession* session;

/**
 * The unique ID of the stream.
 */
@property(readonly) NSString* streamId;

/**
 * The timestamp for the creation of the stream on the OpenTok media server.
 */
@property(readonly) NSDate *creationTime;

/**
 * The name of the stream. In the OpenTok iOS SDK, you can specify a published stream's name
 * when you send the <[OTPublisherKit initWithDelegate:name:]> message.
 */
@property(readonly) NSString* name;

/** @name Getting audio and video information */

/**
 * Whether the stream is publishing audio (YES) or not (NO).
 * See <[OTPublisherKit publishAudio]> and <[OTSubscriberKit subscribeToAudio]>.
 */
@property(readonly) BOOL hasAudio;

/**
 * Whether the stream is publishing video (YES) or not (NO).
 * See <[OTPublisherKit publishVideo]> and <[OTSubscriberKit subscribeToVideo]>.
 */
@property(readonly) BOOL hasVideo;

/**
 * The current dimensions of the video media track on this stream. 
 * This property can change if a stream published from an
 * iOS device resizes, based on a change in the device orientation, or a change
 * in video resolution occurs.
 *
 * For streams published using the scalable video feature, this is set to the
 * maximum resolution available for the stream.
 */
@property (readonly) CGSize videoDimensions;

/**
 * Specifies the type of video for this stream.
 *
 * This property is set one of the following values:
 *
 * * <code>OTStreamVideoTypeScreen</code> &mdash; The stream's video
 *   encoding is optimized for screen sharing.
 *
 * * <code>OTStreamVideoTypeCamera</code> &mdash; The stream is not
 *   optimized for screen sharing (for example, it uses a camera as the video
 *   source).
 *
 * For more information, see <[OTPublisherKit videoType]>.
 */
@property (readonly) OTStreamVideoType videoType;

@end
