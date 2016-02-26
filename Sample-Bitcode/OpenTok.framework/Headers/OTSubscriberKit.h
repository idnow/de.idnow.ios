//
//  OTSubscriberKit.h
//
//  Copyright (c) 2014 Tokbox, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OTStream, OTSession, OTConnectionTestResult,
OTSubscriberKitVideoNetworkStats, OTSubscriberKitAudioNetworkStats;

@protocol OTVideoRender;
@protocol OTSubscriberKitDelegate;
@protocol OTSubscriberKitAudioLevelDelegate;
@protocol OTSubscriberKitNetworkStatsDelegate;

/**
 * Video enabled and disabled events are accompanied with a reason code, for
 * determining why the video track was enabled/disabled.
 */
typedef NS_ENUM(int32_t, OTSubscriberVideoEventReason) {
    /**
     * The video event was caused by the stream's publisher changing the value
     * for OTPublisherKit.publishVideo.
     */
    OTSubscriberVideoEventPublisherPropertyChanged = 1,
    
    /**
     * The video event was caused by a change to this subscriber's
     * OTSubscriberKit.subscribeToVideo property.
     */
    OTSubscriberVideoEventSubscriberPropertyChanged = 2,
    
    /**
     * The video event was caused by a change to the video stream quality.
     * Stream quality may change due to network conditions or CPU usage
     * on either the subscriber or pubisher.
     *
     * This reason is only used in sessions that have the
     * [media mode](http://tokbox.com/opentok/tutorials/create-session/)
     * set to "routed".
     * This feature of the OpenTok Media Router has a subscriber drop the video
     * stream when the video stream quality degrades, and the
     * <[OTSubscriberKitDelegate subscriberVideoDisabled:reason:]> message
     * is sent. When conditions improve, the video stream resumes, and the
     * <[OTSubscriberKitDelegate subscriberVideoEnabled:reason:]> message is
     * sent.
     *
     * When the video stream is dropped, the subscriber continues to receive
     * the audio stream, if there is one.
     *
     * When the Subscriber's stream quality deteriorates to a level that
     * is low enough that the video stream is at risk of being disabled, the
     * <[OTSubscriberKitDelegate subscriberVideoDisableWarning:]> message is
     * sent. The <[OTSubscriberKitDelegate subscriberVideoDisableWarning:]>
     * message is sent before the
     * <[OTSubscriberKitDelegate subscriberVideoDisabled:reason:]> message is
     * sent.
     *
     * You can disable this audio-only fallback feature, by setting the
     * <[OTPublisherKit audioFallbackEnabled]> property to <code>NO</code>
     * for the publisher of the stream.
     */
    OTSubscriberVideoEventQualityChanged = 3
    
};

/**
 * An OTSubscriberKit (subscriber) object renders media data bound to an
 * <OTStream>. The OTSubscriberKit class lets you set a custom video renderer
 * for the video stream. Use this class if you are interested in providing your
 * own video processing and rendering implementation. Otherwise, use the
 * <OTSubscriber> class, which includes a pre-built video processor and
 * renderer.
 *
 * The stream property references the stream that you have subscribed to.
 * The OTSubscriberKit class includes methods that let you disable and enable
 * local audio and video playback for the subscribed stream.
 */

@interface OTSubscriberKit : NSObject

/** @name Getting basic information about a Subscriber */

/**
 * The <OTSession> object that owns this subscriber. An instance will have
 * one and only one <OTSession> associated with it, and this property
 * is immutable.
 */
@property(readonly) OTSession* session;

/**
 * The stream this subscriber is bound to. Any media channels
 * on the stream should be available for display/playback with
 * this instance.
 */
@property(readonly) OTStream* stream;

/**
 * The <OTSubscriberKitDelegate> object that serves as a delegate,
 * handling basic events for this OTSubscriber object.
 *
 * See also <[OTSubscriberKit audioLevelDelegate]> and
 * <[OTSubscriberKit networkStatsDelegate]>.
 */
@property(nonatomic, assign) id<OTSubscriberKitDelegate> delegate;

/** @name Working with audio and video */

/**
 * Periodically receives reports of audio levels for this subscriber.
 *
 * This is a separate delegate object from that set as the
 * <[OTSubscriberKit delegate]> property (the OTSubscriberKitDelegate object).
 *
 * If you do not set this property, the audio sampling subsystem is disabled.
 */
@property (nonatomic, assign)
id<OTSubscriberKitAudioLevelDelegate> audioLevelDelegate;

/**
 * Whether to subscribe to the stream's audio.
 *
 * The default value is YES.
 *
 * Setting this property has no effect if the <[OTStream hasAudio]> property is
 * set to NO.
 */
@property(nonatomic) BOOL subscribeToAudio;

/**
 * Whether to subscribe to the stream's video.
 *
 * The default value is YES.
 *
 * Setting this property has no effect if the <[OTStream hasVideo]> property is
 * set to NO.
 */
@property(nonatomic) BOOL subscribeToVideo;

/**
 * The video renderer for this instance.
 */
@property(nonatomic, retain) id<OTVideoRender> videoRender;

/**
 * The preferred resolution for the subscriber's stream. This property only
 * applies to streams published using the scalable video feature. The subscriber
 * will use the closest available resolution based on the CPU and bandwidth
 * constraints.
 *
 * Scalable video is a beta feature. To participate in the beta program, see
 * the <a href="https://tokbox.com/platform/beta-programs">OpenTok Beta
 * programs</a> page.
 *
 * Not every resolution is available to a subscriber. When you set the preferred
 * resolution, the OpenTok iOS SDK picks the best resolution available that
 * matches your constraints. The resolutions available depend on the maximum
 * resolution the Publisher sets for the stream, which is set as the
 * <[OTStream videoDimensions]> property for the stream. Each of the
 * resolutions available for a stream will use the same aspect ratio.
 */
@property(nonatomic) CGSize preferredResolution;

/**
 * The preferred frame rate for the subscriber's stream. This property only
 * applies to streams published using the scalable video feature. The subscriber
 * will use the closest available resolution based on the CPU and bandwidth
 * constraints.
 *
 * Scalable video is a beta feature. To participate in the beta program, see
 * the <a href="https://tokbox.com/platform/beta-programs">OpenTok Beta
 * programs</a> page.
 *
 * The frame rates available are based on the value of the maximum frame rate
 * available for the stream. When you set the preferred frame rate for the
 * subscriber, the OpenTok iOS SDK picks the best frame rate available that is
 * closest to the `preferedFrameRate`, based on the client's bandwidth and CPU
 * constraints.
 *
 * The actual frame rates available depend, dynamically, on network and CPU
 * resources available to the publisher.
 */
@property(nonatomic) float preferredFrameRate;

/** @name Getting audio and video statistics */

/**
 * The <OTSubscriberKitNetworkStatsDelegate> object that periodically receives
 * subscriber quality statistics.
 *
 * This delegate object is sent messages reporting the following:
 *
 * * Total audio and video packets lost
 * * Total audio and video packets received
 * * Total audio and video bytes received
 *
 * This is a separate delegate object from that set as the
 * <[OTSubscriberKit delegate]> property (the OTSubscriberKitDelegate object).
 */
@property (nonatomic, assign)
id<OTSubscriberKitNetworkStatsDelegate> networkStatsDelegate;

/** @name Initializing a Subscriber */

/**
 * Initializes a subscriber and binds it to an <OTStream> instance.
 * Once initialized, the instance is permanently bound to the stream.
 *
 * The OpenTok iOS SDK supports a limited number of simultaneous audio-video
 * streams in an app:
 *
 * - In a relayed session, the limit is two streams. An app can
 *   have up to two subscribers, or one publisher and one subscriber.
 *
 * - In a routed session, an app can support one audio-video publisher,
 *   one audio-video subscriber, and up to three additional subscribed audio-only
 *   streams simultaneously.
 *
 * (For information on relayed and routed sessions see the documentation on the
 * [media mode](http://tokbox.com/opentok/tutorials/create-session/#media-mode)
 * of a session.)
 *
 * Initializing a subscriber causes it to start streaming data from the OpenTok
 * server, regardless of whether the view of the subscriber object is added to a
 * superview.
 *
 * You can stream audio only (without subscribing to the video stream) by
 * setting the <[OTSubscriberKit subscribeToVideo]> property to NO immediately
 * after initializing the OTSubscriber object.
 * You can stream video only (without subscribing to the audio stream) by
 * setting the <[OTSubscriberKit subscribeToAudio]> property to NO immediately
 * after initializing the OTSubscriber object.
 *
 * When the subscriber connects to the stream, the
 * <[OTSubscriberKitDelegate subscriberDidConnectToStream:]> message is sent.
 *
 * For an OTSubscriber object, when the first frame of video has been decoded,
 * the <[OTSubscriberDelegate subscriberVideoDataReceived:]> message is sent.
 *
 * If the subscriber fails to connect to the stream, the
 * <[OTSubscriberKitDelegate subscriber:didFailWithError:]> message is sent.
 *
 * @param stream The <OTStream> object to bind this instance to.
 * @param delegate The delegate (<OTSubscriberKitDelegate>) that will handle
 * events generated by this instance.
 */
- (id)initWithStream:(OTStream*)stream
            delegate:(id<OTSubscriberKitDelegate>)delegate;

@end

/**
 * Used to send messages for an OTSubscriber instance. When you send
 * the <[OTSubscriberKit initWithStream:delegate:]> message, you specify an
 * OTSubscriberKitDelegate object.
 */
@protocol OTSubscriberKitDelegate <NSObject>

/** @name Using subscribers */

/**
 * Sent when the subscriber successfully connects to the stream.
 * @param subscriber The subscriber that generated this event.
 */
- (void)subscriberDidConnectToStream:(OTSubscriberKit*)subscriber;

/**
 * Sent if the subscriber fails to connect to its stream.
 * @param subscriber The subscriber that generated this event.
 * @param error The error (an <OTError> object) that describes this connection
 * error. The `OTSubscriberErrorCode` enum (defined in the OTError class)
 * defines values for the `code` property of this object.
 */
- (void)subscriber:(OTSubscriberKit*)subscriber
  didFailWithError:(OTError*)error;

@optional

/**
 * This message is sent when the subscriber stops receiving video.
 * Check the reason parameter for the reason why the video stopped.
 *
 * @param subscriber The <OTSubscriber> that will no longer receive video.
 * @param reason The reason that the video track was disabled. See
 * <OTSubscriberVideoEventReason>.
 */
- (void)subscriberVideoDisabled:(OTSubscriberKit*)subscriber
                         reason:(OTSubscriberVideoEventReason)reason;

/**
 * This message is sent when the subscriber starts (or resumes) receiving video.
 * Check the reason parameter for the reason why the video started (or resumed).
 *
 * @param subscriber The <OTSubscriber> that will no longer receive video.
 * @param reason The reason that the video track was enabled. See
 * <OTSubscriberVideoEventReason>.
 */
- (void)subscriberVideoEnabled:(OTSubscriberKit*)subscriber
                        reason:(OTSubscriberVideoEventReason)reason;

/**
 * This message is sent when the OpenTok Media Router determines that the stream
 * quality has degraded and the video will be disabled if the quality degrades
 * further. If the quality degrades further, the subscriber disables the video
 * and the <[OTSubscriberKitDelegate subscriberVideoDisabled:reason:]> message
 * is sent. If the stream quality improves, the
 * <[OTSubscriberKitDelegate subscriberVideoDisableWarningLifted:]> message is
 * sent.
 *
 * This feature is only available in sessions that use the
 * OpenTok Media Router (sessions with the
 * [media mode](http://tokbox.com/opentok/tutorials/create-session/#media-mode)
 * set to routed), not in sessions with the media mode set to relayed.
 *
 * This message is mainly sent when connection quality degrades.
 *
 * @param subscriber The <OTSubscriber> that may stop receiving video soon.
 */
- (void)subscriberVideoDisableWarning:(OTSubscriberKit*)subscriber;

/**
 * This message is sent when the OpenTok Media Router determines that the stream
 * quality has improved to the point at which the video being disabled is not an
 * immediate risk. This message is sent after the
 * <[OTSubscriberKitDelegate subscriberVideoDisableWarning:]> message is
 * sent.
 *
 * This feature is only available in sessions that use the
 * OpenTok Media Router (sessions with the
 * [media mode](http://tokbox.com/opentok/tutorials/create-session/#media-mode)
 * set to routed), not in sessions with the media mode set to relayed.
 *
 * This message is mainly sent when connection quality improves.
 *
 * @param subscriber The <OTSubscriber> instance.
 */
- (void)subscriberVideoDisableWarningLifted:(OTSubscriberKit*)subscriber;

/**
 * Called when the subscriber's stream has been interrupted.
 *
 * In response to this message being sent, you may want to provide a user
 * interface notification, to let the user know that the audio-video stream is
 * temporarily disconnected and the app is trying to reconnect to the stream.
 *
 * If the client reconnects to the stream, the
 * <[OTSubscriberKitDelegate subscriberDidReconnectToStream:]> message is sent.
 * Otherwise, the <[OTSubscriberKitDelegate subscriberVideoDisabled:reason:]>
 * message is sent.
 *
 * This method is part of the automatic reconnection beta feature.
 * To participate in the beta program, see the
 * <a href="https://tokbox.com/platform/beta-programs">OpenTok Beta
 * programs</a> page.
 *
 * @param subscriber The subscriber that generated this event.
 */
- (void)subscriberDidDisconnectFromStream:(OTSubscriberKit*)subscriber;

/**
 * Sent when the subscriber's stream has resumed, after the
 * <[OTSubscriberKitDelegate subscriberDidDisconnectFromStream:]> message
 * is sent.
 *
 * This method is part of the automatic reconnection beta feature.
 * To participate in the beta program, see the
 * <a href="https://tokbox.com/platform/beta-programs">OpenTok Beta
 * programs</a> page.
 *
 * @param subscriber The subscriber that generated this event.
 *
 * See <[OTSessionDelegate sessionDidReconnect:]>.
 */
- (void)subscriberDidReconnectToStream:(OTSubscriberKit*)subscriber;

@end

/**
 * Used for monitoring the audio levels of the subscriber.
 */
@protocol OTSubscriberKitAudioLevelDelegate <NSObject>

/**
 * Sent on a regular interval with the recent representative audio level.
 *
 * @param subscriber The subscriber instance being represented.
 * @param audioLevel A value between 0 and 1, representing the audio level.
 * Adjust this value logarithmically for use in a user interface
 * visualization of the volume (such as a volume meter).
 */
- (void)subscriber:(OTSubscriberKit*)subscriber
audioLevelUpdated:(float)audioLevel;

@end

/**
 * Used to monitor audio and video statistics for the subscriber. See
 * <[OTSubscriberKit networkStatsDelegate]>.
 */
@protocol OTSubscriberKitNetworkStatsDelegate <NSObject>

@optional

/**
 * Sent periodically to report audio statistics for the subscriber.
 *
 * @param subscriber The subscriber these statistic apply to.
 *
 * @param stats An <OTSubscriberKitVideoNetworkStats> object, which has
 * properties for the video bytes received, video packets lost, and video
 * packets received for the subscriber.
 */
- (void)subscriber:(OTSubscriberKit*)subscriber
videoNetworkStatsUpdated:(OTSubscriberKitVideoNetworkStats*)stats;

/**
 * Sent periodically to report video statistics for the subscriber.
 *
 * @param subscriber The subscriber these statistic apply to.
 *
 * @param stats An <OTSubscriberKitAudioNetworkStats> object, which has
 * properties for the audio bytes received, audio packets lost, and audio
 * packets received for the subscriber.
 */
- (void)subscriber:(OTSubscriberKit*)subscriber
audioNetworkStatsUpdated:(OTSubscriberKitAudioNetworkStats*)stats;

@end
