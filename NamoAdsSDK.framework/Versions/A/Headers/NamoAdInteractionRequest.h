//
// NamoAdInteractionRequest.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoAdInteractionRequest defines methods for logging a user interaction to NamoMedia servers.
//

#import <Foundation/Foundation.h>

@interface NamoAdInteractionRequest : NSObject
// Returns the url to use when requesting an interaction.
@property(nonatomic, strong) NSURL *url;

// Initializes the request with the given device id.
- (id)initWithUrl:(NSString *)url deviceId:(NSString *)deviceId;

// Sends the request to NamoMedia servers.
- (void)runOnQueue:(NSOperationQueue *)queue;
@end
