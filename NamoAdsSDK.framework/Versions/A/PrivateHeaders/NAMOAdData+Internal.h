//  Copyright (c) 2013 Namo Media. All rights reserved.

#import <Foundation/Foundation.h>
#import "NamoAdData.h"

// TODO(nassar): Documentation

@interface NAMOAdData (Internal)

#pragma - mark Initializers
/**
 Initializes the ad object using a dictionary of key value pairs.
 */
- (id)initWithDictionary:(NSDictionary *)data;

#pragma - mark Private values

/**
 * The unique identifier for the ad.
 */
- (NSString *)adId;

/**
 * The unique identifier for the ad group.
 */
- (NSString *)adGroupId;

/**
 * The unique identifier for the campaign.
 */
- (NSString *)campaignId;

/**
 * The unique identifier the the request used to retrieve this ad.
 */
- (NSString *)requestId;

/**
 * The image metadata for the ad. The Namo Ads framework uses this metadata along
 * with the imageURL to request an appropriately sized image from the Namo image server.
 */
- (NSString *)imageMetadata;

/**
 * The url for impression tracking. You do not need to access this URL unless you
 * are overriding impression tracking for direct sold ads.
 */
- (NSString *)impressionTrackingURL;

/**
 * The url for click tracking. You do not need to access this URL unless you are
 * overriding click tracking for direct sold ads.
 */
- (NSString *)clickTrackingURL;

#pragma - mark Setters

//- (void)setTitle:(NSString *)title;
//- (void)setText:(NSString *)text;
//- (void)setAdvertiserName:(NSString *)advertiserName;
//- (void)setActionType:(NAMOActionType)actionType;
- (void)setActionURL:(NSString *)actionURL;
//- (void)setImageURL:(NSString *)imageURL;
//- (void)setAdvertiserIconURL:(NSString *)advertiserIconURL;

@end