// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import "Namo.h"

/**
 This category defines additional methods for testing and debugging the SDK.
*/
@interface Namo (Testing)

/**
 Debugging method for setting an ad server URL. You do not need to set this URL for normal
 use of the SDK.
*/
+ (void)setAdServerURL:(NSURL *)url;

/**
 Debugging method for setting an image server URL. You do not need to set this URL for normal use
 of the SDK.
*/
+ (void)setImageServerURL:(NSURL *)url;

/**
 Debugging for getting the ad server URL.
*/
+ (NSURL *)adServerURL;

/**
 Debugging for getting the image server URL.
*/
+ (NSURL *)imageServerURL;

// Debugging for setting a campaign ID filter
+ (void)setDebugCampaignId:(NSInteger)campaignId;

// Debugging - should set the star value on ads without it.
+ (void)setShouldShowStars:(BOOL)showStars;

// Debugging for setting a star rating for all ads.
+ (void)setStarRating:(CGFloat)starRating;

@end