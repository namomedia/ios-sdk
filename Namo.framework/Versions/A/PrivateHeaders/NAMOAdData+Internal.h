// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import "NAMOAdData.h"

/**
 Defines non-public data for a NAMOAd.
 */
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
 The image metadata for the ad. The Namo framework uses this metadata along
 with the imageURL to request an appropriately sized image from the Namo image server.
 */
- (NSString *)imageMetadata;

/**
 The action URL.
 */
- (NSURL *)actionURL;

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

/**
 The url for video view tracking.
 */
- (NSURL *)videoViewTrackingURL;

/**
 Formatting data about the cell this ad was rendered into. This allows us to send information about
 the cell to the server when sending an impression. Ideally, we'd store this information in the
 ad placer rather than here, which would require refactoring our ad binding logic.
*/
@property(nonatomic, strong) NSData *layoutInfo;

@end