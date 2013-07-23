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

@property(nonatomic, strong) NSString *adId;
@property(nonatomic, strong) NSString *adGroupId;
@property(nonatomic, strong) NSString *campaignId;
@property(nonatomic, strong) NSString *requestId;
@property(nonatomic, strong) NSString *advertiserName;
@property(nonatomic, strong) NSString *advertiserLogoUrl;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *text;
@property(nonatomic, strong) NSString *imageUrl;
@property(nonatomic, strong) NSString *clickTargetText;
@property(nonatomic, strong) NSString *clickTargetUrl;
@property(nonatomic, strong) NSString *impressionTrackingUrl;
@property(nonatomic, strong) NSString *clickTrackingUrl;
@property(nonatomic, strong) NSString *actionType;
@end
