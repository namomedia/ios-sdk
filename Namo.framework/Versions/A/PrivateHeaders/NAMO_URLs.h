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
extern NSString *const NAMOParamTimeSinceViewOpened;

// Optional list of supported format types. On iOS, these correspond to the
// cell reuseIdentifier, which the server can use for targeting.
extern NSString *const NAMOParamFormatType;

// Optional targeting params
extern NSString *const NAMOParamTargetGender;
extern NSString *const NAMOParamTargetEducation;
extern NSString *const NAMOParamTargetRelationshipStatus;
extern NSString *const NAMOParamTargetAge;
extern NSString *const NAMOParamTargetSearchTerm;
extern NSString *const NAMOParamTargetBirthday;
extern NSString *const NAMOParamTargetInterests;

// Optional video params
extern NSString *const NAMOParamVideoViewLength;
extern NSString *const NAMOParamVideoTotalLength;

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
 Returns true if the url points to a known image server instance.
*/
+ (BOOL)isKnownImageServerURL:(NSURL *)url;

@end