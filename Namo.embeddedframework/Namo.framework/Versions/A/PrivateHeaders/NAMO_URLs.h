// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

#import "NAMOConnectivity.h"
#import "NAMORequest.h"
#import "NAMOAdData.h"

// Base urls
extern NSString *const NamoAdServerURL;

extern NSString *const NamoImageServerURL;
extern NSString *const NamoImageServerLocalURL;

// Required params
extern NSString *const NamoParamAppId;
extern NSString *const NamoParamMacAddressHash;
extern NSString *const NamoParamAdvertisingId;
extern NSString *const NamoParamTrackingEnabled;

// Optional application level params
extern NSString *const NamoParamBundleId;
extern NSString *const NamoParamBundleVersion;
extern NSString *const NamoParamUserInfo;
extern NSString *const NamoParamSequence;
extern NSString *const NamoParamConnectionType;
extern NSString *const NamoParamScreenWidth;
extern NSString *const NamoParamScreenHeight;
extern NSString *const NamoParamSdkVersion;
extern NSString *const NamoParamCarrier;
extern NSString *const NamoParamLocalTime;
extern NSString *const NamoParamTimeSinceAppOpened;

// Optional view level params
extern NSString *const NamoParamViewId;
extern NSString *const NamoParamViewSequence;
extern NSString *const NamoParamNumAds;
extern NSString *const NamoParamSectionId;
extern NSString *const NamoParamKeywords;
extern NSString *const NamoParamTimeSinceViewOpened;

// Additional interaction params
extern NSString *const NamoParamActionType;

/**
 NAMO_URLs defines utility messages for generating uris
*/
@interface NAMO_URLs : NSObject

/**
 Encodes a query parameter for safe use in a URI.
*/
+ (NSString *)encodeQueryParam:(id)object;

/**
 Builds a URI using the base url and nil terminated array of NAMOPair arguments,
 The returned URI will be properly encoded.
*/
+ (NSString *)URIWithBase:(NSString *)baseURL params:(NSArray *)pairs;

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
+ (BOOL)isKnownImageServerURL:(NSString*)url;

@end