// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

#import "NAMOConnectivity.h"
#import "NAMORequest.h"
#import "NAMOAdData.h"

// Required params
extern NSString *const NAMOParamAppId;
extern NSString *const NAMOParamMacAddressHash;
extern NSString *const NAMOParamAdvertisingId;
extern NSString *const NAMOParamTrackingEnabled;

// Optional application level params
extern NSString *const NAMOParamBundleId;
extern NSString *const NAMOParamBundleVersion;
extern NSString *const NAMOParamUserInfo;
extern NSString *const NAMOParamSequence;
extern NSString *const NAMOParamConnectionType;
extern NSString *const NAMOParamScreenWidth;
extern NSString *const NAMOParamScreenHeight;
extern NSString *const NAMOParamSdkVersion;
extern NSString *const NAMOParamCarrier;
extern NSString *const NAMOParamLocalTime;
extern NSString *const NAMOParamTimeSinceAppOpened;

// Optional view level params
extern NSString *const NAMOParamViewId;
extern NSString *const NAMOParamViewSequence;
extern NSString *const NAMOParamNumAds;
extern NSString *const NAMOParamSectionId;
extern NSString *const NAMOParamKeywords;
extern NSString *const NAMOParamTimeSinceViewOpened;

/**
 NAMO_URLs defines utility messages for generating URLs.
*/
@interface NAMO_URLs : NSObject

/**
 Ad server URL.
 */
+ (NSURL *)adServerURL;

/**
 Image server URL.
 */
+ (NSURL *)imageServerURL;

/**
 Local image server URL.
 */
+ (NSURL *)imageServerLocalURL;

/**
 Encodes a query parameter for safe use in a URL.
*/
+ (NSString *)encodeQueryParam:(id)object;

/**
 Builds a URL using the base url and nil terminated array of NAMOPair arguments,
 The returned URI will be properly encoded.
*/
+ (NSURL *)URLWithBase:(NSURL *)baseURL params:(NSArray *)pairs;

/**
 Returns a url parameter value for the given network status.
*/
+ (NSString *)URLStringForNetworkStatus:(NAMONetworkStatus)networkStatus;

/**
 Returns a url parameter value for the interaction type.
*/
+ (NSString *)URLStringForActionType:(NAMOActionType)type;

/**
 Returns true if the url points to a known imageServer instance.
*/
+ (BOOL)isKnownImageServerURL:(NSURL *)url;

@end