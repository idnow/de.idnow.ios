//
//  OTPublisherKit.h
//
//  Copyright (c) 2014 Tokbox, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class OTPublisherKit, OTSession, OTError, OTStream;

@protocol OTVideoCapture;
@protocol OTVideoRender;
@protocol OTPublisherKitDelegate;
@protocol OTPublisherKitAudioLevelDelegate;

/**
* Defines values for the <[OTPublisherKit videoType]> property.
*/
typedef NS_ENUM(int32_t, OTPublisherKitVideoType) {
    /**
     * Defines the camera video mode setting for the
     * <[OTPublisherKit videoType]> property.
     */
    OTPublisherKitVideoTypeCamera = 1,
    /**
     * Defines the screen video mode setting for the
     * <[OTPublisherKit videoType]> property.
     */
    OTPublisherKitVideoTypeScreen = 2,
};

/**
 * A publisher captures an audio-video stream from the sources you specify. You
 * can then publish the audio-video stream to an OpenTok session by sending the
 * <[OTSession publish:error:]> message.
 *
 * The OpenTok iOS SDK supports publishing on all multi-core iOS devices.
 * See "Developer and client requirements" in the README file for the
 * [OpenTok iOS SDK](http://tokbox.com/opentok/libraries/client/ios).
 */
@interface OTPublisherKit : NSObject

/** @name Initializing a publisher */

/**
 * Initialize a publisher object and specify the delegate object.
 *
 * When running in the XCode iOS Simulator, this method returns `nil`.
 *
 * @param delegate The delegate (<OTPublisherKitDelegate>) object for the
 * publisher.
 *
 * @return The pointer to the instance, or `nil` if initialization failed.
 */
- (instancetype)initWithDelegate:(id<OTPublisherKitDelegate>)delegate;

/**
 * Initialize a publisher object, and specify the delegate object and the 
 * stream's name.
 *
 * When running in the XCode iOS Simulator, this method returns `nil`.
 *
 * @param delegate The delegate (<OTPublisherKitDelegate>) object for the 
 * publisher.
 *
 * @param name  The name for this stream. This string is displayed at the
 * bottom of publisher
 * video and at the bottom of subscriber videos associated with the published
 * stream.
 *
 * @return The pointer to the instance, or `nil` if initialization failed.
 */
- (instancetype)initWithDelegate:(id<OTPublisherKitDelegate>)delegate
                            name:(NSString*)name;

/**
 * Initialize the publisher, and specify whether audio and video will be
 * enabled for this instance. If either audioTrack or videoTrack are set to
 * NO, the respective subsystem will not be initialized, and setting the
 * corresponding <[OTPublisherKit publishAudio]> and
 * <[OTPublisherKit publishVideo]> properties will have no effect.
 *
 * If your application does not require the use of audio or video, it is
 * recommended to set these values rather than use the
 * <[OTPublisherKit publishAudio]> and <[OTPublisherKit publishVideo]>
 * properties, which only temporarily disable the tracks.
 *
 * @param delegate The delegate (<OTPublisherKitDelegate>) object for the
 * publisher.
 *
 * @param name  The name for this stream. This string is displayed at the
 * bottom of publisher video and at the bottom of subscriber videos associated
 * with the published stream.
 *
 * @param audioTrack Whether to publish audio (YES) or not (NO).
 *
 * @param videoTrack Whether to publish video (YES) or not (NO).
 */
- (instancetype)initWithDelegate:(id<OTPublisherKitDelegate>)delegate
                            name:(NSString*)name
                      audioTrack:(BOOL)audioTrack
                      videoTrack:(BOOL)videoTrack;

/** @name Getting information about the publisher */

/**
 * The <OTPublisherDelegate> object, which is the delegate for the OTPublisher
 * object.
 */
@property(nonatomic, assign) id<OTPublisherKitDelegate> delegate;

/**
 * Periodically receives reports of audio levels for this publisher.
 *
 * This is a separate delegate object from that set as the delegate property
 * (the OTPublisherKitDelegate object).
 *
 * If you do not set this property, the audio sampling subsystem is disabled.
 */
@property (nonatomic, assign)
id<OTPublisherKitAudioLevelDelegate> audioLevelDelegate;

/**
 * The session that owns this publisher.
 */
@property(readonly) OTSession* session;

/**
 * The <OTStream> object associated with the publisher.
 */
@property(readonly) OTStream* stream;

/**
 * A string that will be associated with this publisher's stream. This string is
 * displayed at the bottom of subscriber videos associated with the published
 * stream, if an overlay to display the name exists. 
 *
 * Name must be set at initialization, when you when you send the
 * <[OTPublisherKit initWithDelegate:name:]> message.
 *
 * This value defaults to an empty string.
 */
@property(readonly) NSString* name;

/** @name Controlling audio and video output for a publisher */

/**
 * Whether to publish audio.
 *
 * The default value is TRUE.
 */
@property(nonatomic) BOOL publishAudio;

/**
 * Whether to publish video.
 *
 * The default value is TRUE.
 */
@property(nonatomic) BOOL publishVideo;

/** @name Setting publisher device configuration */

/**
 * The <OTVideoCapture> instance used to capture video to stream to the OpenTok
 * session.
 */
@property(nonatomic, retain) id<OTVideoCapture> videoCapture;

/**
 * Specifies the type of video for the published stream.
 *
 * Set this to one of the following values:
 *
 * * <code>OTPublisherKitVideoTypeScreen</code> &mdash; Optimizes the video
 *   encoding for screen sharing. To publish a screen-sharing stream, you
 *   need to implement a custom video capturer for the OTPublisherKit object.
 *   See <[OTPublisherKit videoCapture]>. It is recommended to use a low frame
 *   rate (5 frames per second or lower) with this video type. When using the
 *   screen video type in a session that uses the OpenTok Media Server, the
 *   <[OTPublisherKit audioFallbackEnabled]> property is set to NO by default;
 *   this disables the audio-only fallback feature, so that the video does not
 *   drop out in subscribers. See [the OpenTok Media
 *   Router](http://tokbox.com/opentok/tutorials/create-session/#media-mode ).
 *
 * * <code>OTPublisherKitVideoTypeCamera</code> &mdash;
 *   This is the default setting, which you should use when using a camera
 *   as the video source.
 */
@property (nonatomic, assign) OTPublisherKitVideoType videoType;

/**
 * The <OTVideoRender> instance used to render video to stream to the OpenTok
 * session.
 */
@property(nonatomic, retain) id<OTVideoRender> videoRender;

/** @name Setting the audio-only fallback mode */

/**
 * Whether the stream will use the audio-fallback feature (<code>YES</code>) or
 * not (<code>NO</code>). The audio-fallback feature is available in sessions
 * that use the the OpenTok Media Router. With the audio-fallback feature
 * enabled, when the OpenTok Media Router determines that a stream's quality has
 * degraded significantly for a specific subscriber, it disables the video in
 * that subscriber in order to preserve call quality.
 *
 * The default setting is <code>YES</code> (the audio-fallback feature is
 * enabled) for publishers using the camera. To turn off the audio-fallback
 * feature, set this property to <code>NO</code> <i>before</i> calling the
 * <[OTSession publish:error:]> method. However, When using the
 * screen video type in a session that uses the OpenTok Media Server, the
 * audioFallbackEnabled property is set to NO by default; this disables the
 * audio-only fallback feature, so that the video does not drop out in
 * subscribers.
 *
 * For more information, see <[OTPublisherKit videoType]>,
 * <[OTSubscriberKitDelegate subscriberVideoDisabled:reason:]>,
 * <OTSubscriberVideoEventReason>, [the OpenTok Media
 * Router](http://tokbox.com/opentok/tutorials/create-session/#media-mode ).
 */
@property (nonatomic, assign) BOOL audioFallbackEnabled;

@end


/**
 * Used for sending messages for an OTPublisher instance. The OTPublisher class
 * includes a `delegate` property. When you send the
 * <[OTPublisherKit initWithDelegate:]> message or the
 * <[OTPublisherKit initWithDelegate:name:]> message, you specify an 
 * OTSessionDelegate object.
 */
@protocol OTPublisherKitDelegate <NSObject>

/**
 * Sent if the publisher encounters an error. After this message is sent,
 * the publisher can be considered fully detached from a session and may
 * be released.
 * @param publisher The publisher that signalled this event.
 * @param error The error (an <OTError> object). The `OTPublisherErrorCode` 
 * enum (defined in the OTError class)
 * defines values for the `code` property of this object.
 */
- (void)publisher:(OTPublisherKit*)publisher didFailWithError:(OTError*)error;

@optional

/**
 * Sent when the publisher starts streaming.
 *
 * @param publisher The publisher of the stream.
 * @param stream The stream that was created.
 */
- (void)publisher:(OTPublisherKit*)publisher streamCreated:(OTStream*)stream;

/**
 * Sent when the publisher stops streaming.
 * @param publisher The publisher that stopped sending this stream.
 * @param stream The stream that ended.
 */
- (void)publisher:(OTPublisherKit*)publisher streamDestroyed:(OTStream*)stream;

@end

/**
 * Used for monitoring the audio levels of the publisher.
 */
@protocol OTPublisherKitAudioLevelDelegate <NSObject>

/**
 * Sent on a regular interval with the recent representative audio level.
 *
 * @param publisher The publisher instance being represented.
 * @param audioLevel A value between 0 and 1, representing the audio level.
 * Adjust this value logarithmically for use in a user interface
 * visualization of the volume (such as a volume meter).
 */
- (void)publisher:(OTPublisherKit*)publisher
audioLevelUpdated:(float)audioLevel;

@end
