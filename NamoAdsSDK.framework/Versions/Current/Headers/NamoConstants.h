//
// NamoConstants.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoConstants defines global constants for the NamoAds SDK.
//

#import <Foundation/Foundation.h>

// Monotonically increasing SDK version. This is used by the server to determine what
// features are supported by the SDK.
extern NSUInteger const NamoSdkVersion;

// The number of seconds an ad must be visible before counting as an impression.
extern NSTimeInterval const NamoImpressionTimeInSecs;

// The timeout interval for SDK server requests.
extern NSTimeInterval const NamoRequestTimeoutInterval;
