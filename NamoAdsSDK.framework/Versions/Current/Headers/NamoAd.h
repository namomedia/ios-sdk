//
// NamoTableViewDelegate.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAd class defines an ad returned from the Namo servers.

#import <Foundation/Foundation.h>

@interface NamoAd : NSObject

// Initializes the ad object using a dictionary of key value pairs.
- (id)initWithDictionary:(NSDictionary *)data;

// Returns the advertiser name.
- (NSString *)advertiserName;

// Returns the advertiser logo url.
- (NSString *)advertiserLogoUrl;

// Returns the ad title.
- (NSString *)title;

// Returns the ad text.
- (NSString *)text;

// Returns the ad image url.
- (NSString *)imageUrl;

// Returns the click target text.
- (NSString *)clickTargetText;

// Returns the click target url.
- (NSString *)clickTargetUrl;

// Returns the url for tracking impressions.
- (NSString *)impressionTrackingUrl;

// Returns the url for tracking expands.
- (NSString *)expandTrackingUrl;

// Returns the url for tracking clicks.
- (NSString *)clickTrackingUrl;
@end
