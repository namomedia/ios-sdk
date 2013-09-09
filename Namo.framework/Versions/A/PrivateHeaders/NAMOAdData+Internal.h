//  Copyright (c) 2013 Namo Media. All rights reserved.

#import <Foundation/Foundation.h>
#import "NAMOAdData.h"

// TODO(nassar): Documentation

@interface NAMOAdData (Internal)

#pragma - mark Initializers
/**
 Initializes the ad object using a dictionary of key value pairs.
 */
- (id)initWithDictionary:(NSDictionary *)data actionURL:(NSURL *)actionURL;

#pragma - mark Private values

/**
 The unique identifier for the ad.
 */
- (NSString *)adId;

/**
 The unique identifier for the ad group.
 */
- (NSString *)adGroupId;

/**
 The unique identifier for the campaign.
 */
- (NSString *)campaignId;

/**
 The unique identifier the the request used to retrieve this ad.
 */
- (NSString *)requestId;

/**
 The image metadata for the ad. The Namo framework uses this metadata along
 with the imageURL to request an appropriately sized image from the Namo image server.
 */
- (NSString *)imageMetadata;

/**
 The url for impression tracking. You do not need to access this URL unless you
 are overriding impression tracking for direct sold ads.
 */
- (NSURL *)impressionTrackingURL;

/**
 The url for click tracking. You do not need to access this URL unless you are
 overriding click tracking for direct sold ads.
 */
- (NSURL *)clickTrackingURL;
@end