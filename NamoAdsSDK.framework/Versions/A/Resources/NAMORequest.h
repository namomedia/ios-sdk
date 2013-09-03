// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

/**
 NamoAdsRequests defines an abstract NamoRequest class for requesting data, and concrete
 request objects for specific request types. NamoRequest is a wrapper around NSURLRequest
 that exposes the API needed for the SDK.

 Base request object. Derived classes should implement runOnQueue:completion for sending the
 request.
*/
@interface NamoRequest : NSObject

/**
 Initializes the request with the given url and NAMOPair param objects.
*/
- (id)initWithURL:(NSString *)baseURL
           params:(NSArray *)pairs;

/**
 Initializes the request with the given url and params.
*/
- (id)initWithRequest:(NSURLRequest *)urlRequest;

@end


/**
 Completion block type for NamoAdsRequest.
*/
typedef void(^NamoAdsRequestCompletionBlock)(NSArray *ads, NSError *error);

/**
 Request that fetches ad data.
*/
@interface NamoAdsRequest : NamoRequest

/**
 Returns the url to use when requesting ads.
*/
@property(nonatomic, strong) NSURL *url;

/**
 Initializes the request with the given url and params and array of NAMOPair param objects.
*/
- (id)initWithURL:(NSString *)url
           params:(NSArray *)pairs;

/**
 Runs the request.
*/
- (void)runOnQueue:(NSOperationQueue *)queue
        completion:(NamoAdsRequestCompletionBlock)callback;
@end

/**
 Request that logs user interactions.
*/
@interface NamoAdInteractionRequest : NamoRequest

/**
 Initializes the request with the given url and array of NAMOPair param objects.
*/
- (id)initWithURL:(NSString *)baseUri params:(NSArray *)pairs;

/**
 Sends the request to NamoMedia servers.
*/
- (void)runOnQueue:(NSOperationQueue *)queue;

@end
