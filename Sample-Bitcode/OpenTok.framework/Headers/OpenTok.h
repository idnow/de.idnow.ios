//
//  OpenTok.h
//  OpenTok iOS SDK
//
//  Copyright (c) 2014 TokBox, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Defines values for the <[OTSubscriber viewScaleBehavior]> and
 * <[OTPublisher viewScaleBehavior]> methods.
 */
typedef NS_ENUM(NSInteger, OTVideoViewScaleBehavior) {    
    /**
     * The video shrinks, as needed, so that the entire video is visible
     * with pillarboxing.
     */
    OTVideoViewScaleBehaviorFit,
    /**
     * The video scales to fill the entire area of the renderer, with cropping
     * as needed.
     */
    OTVideoViewScaleBehaviorFill,
};

#import <OpenTok/OpenTokObjC.h>
#import <OpenTok/OTPublisher.h>
#import <OpenTok/OTSubscriber.h>
