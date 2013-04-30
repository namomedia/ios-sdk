//
// NamoBackendClient.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoBackendClient is a singleton object responsible for connecting to NamoMedia
// backend servers.
//

#import <Foundation/Foundation.h>
#import "NamoRequests.h"

@class NamoTargeting;

@interface NamoBackendClient : NSObject
@property(nonatomic, strong) NSString *baseAdServerUrl;

// Initialize the backend object using an application id.
- (id)initWithAppId:(NSString *)namoAppId;

// Request ads with a callback block for success and failure.
- (void)requestAdsWithTargeting:(NamoTargeting *)targeting
                         viewId:(NSUInteger)viewId
                     completion:(NamoAdsRequestCompletionBlock)callback;

// Send an interaction request with a callback block for success and failure.
- (void)sendInteractionWithUrl:(NSString *)url
                        viewId:(NSUInteger)viewId
               interactionType:(InteractionType)type;
@end