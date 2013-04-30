//
// NamoAdsRequest.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoAdsRequest defines methods for requesting an ad from NamoMedia servers.
//

#import <Foundation/Foundation.h>

typedef void(^NamoAdsRequestCompletionBlock)(NSArray *ads, NSError *error);

@interface NamoAdsRequest : NSObject
// Returns the url to use when requesting ads.
@property(nonatomic, strong) NSURL *url;

// Initializes the request with the given url and params.
- (id)initWithUrl:(NSString *)url
           params:(NSDictionary *)params;

// Runs the request.
- (void)runOnQueue:(NSOperationQueue *)queue
        completion:(NamoAdsRequestCompletionBlock)callback;
@end
