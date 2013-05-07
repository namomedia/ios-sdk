//
// NamoAds+Testing.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// This category defines additional methods for testing and debugging the SDK.
//

#import <Foundation/Foundation.h>
#import "NamoAds.h"

@interface NamoAds (Testing)

// Debugging method for setting an ad server URL. You do not need to set this URL for normal
// use of the SDK.
+ (void)setAdServerUrl:(NSString *)url;
@end