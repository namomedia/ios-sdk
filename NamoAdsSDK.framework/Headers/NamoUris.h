//
// NamoUris
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoUris defines utility messages for generating uris
//

#import <Foundation/Foundation.h>

#import "NamoConnectivity.h"
#import "NamoRequests.h"

// Base urls
extern NSString *const NamoAdServerUrl;
extern NSString *const NamoAdServerStagingUrl;
extern NSString *const NamoAdServerLocalUrl;

// Required params
extern NSString *const NamoParamAppId;
extern NSString *const NamoParamDeviceId;

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
extern NSString *const NamoParamMaxAds;
extern NSString *const NamoParamSectionId;
extern NSString *const NamoParamKeywords;
extern NSString *const NamoParamTimeSinceViewOpened;

// Additional interaction params
extern NSString *const NamoParamInteractionType;

@interface NamoUris : NSObject

// Encodes a query parameter for safe use in a URI.
+ (NSString *)encodeQueryParam:(id)object;

// Builds a URI using the base url and nil terminated array of NamoPair arguments,
// The returned URI will be properly encoded.
+ (NSString *)uriWithBase:(NSString *)baseUrl params:(NSArray *)pairs;

// Returns a url parameter value for the given network status.
+ (NSString *)urlStringForNetworkStatus:(NamoNetworkStatus)networkStatus;

// Returns a url parameter value for the interaction type.
+ (NSString *)urlStringForInteractionType:(InteractionType)type;
@end