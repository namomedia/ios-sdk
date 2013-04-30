//
// NamoAdsRequests.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoAdsRequests defines an abstract NamoRequest class for requesting data, and concrete
// request objects for specific request types. NamoRequest is a wrapper around NSURLRequest
// that exposes the API needed for the SDK.
//

#import <Foundation/Foundation.h>

// Base request object. Derived classes should implement runOnQueue:completion for sending the
// request.
@interface NamoRequest : NSObject

// Initializes the request with the given url and NamoPair param objects.
- (id)initWithUrl:(NSString *)baseUrl
           params:(NSArray *)pairs;

// Initializes the request with the given url and params.
- (id)initWithRequest:(NSURLRequest *)urlRequest;

@end


// Completion block type for NamoAdsRequest.
typedef void(^NamoAdsRequestCompletionBlock)(NSArray *ads, NSError *error);

// Request that fetches ad data.
@interface NamoAdsRequest : NamoRequest
// Returns the url to use when requesting ads.
@property(nonatomic, strong) NSURL *url;

// Initializes the request with the given url and params and array of NamoPair param objects.
- (id)initWithUrl:(NSString *)url
           params:(NSArray *)pairs;

// Runs the request.
- (void)runOnQueue:(NSOperationQueue *)queue
        completion:(NamoAdsRequestCompletionBlock)callback;
@end

// An enumeration describing possible interaction types.
typedef enum {
  NamoInteractionTypeView = 0,
  NamoInteractionTypeExpand,
  NamoInteractionTypeUnExpand,
  NamoInteractionTypeClick
} InteractionType;

// Request that logs user interactions.
@interface NamoAdInteractionRequest : NamoRequest

// Initializes the request with the given url and array of NamoPair param objects.
- (id)initWithUrl:(NSString *)baseUri params:(NSArray *)pairs;

// Sends the request to NamoMedia servers.
- (void)runOnQueue:(NSOperationQueue *)queue;
@end
