//
// NamoConnectivity.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoConnectivity defines messages for determining the current network status and connection
// type. The implementation is a greatly simplified version of Apple's
// Reachability code: http://developer.apple.com/library/ios/#samplecode/Reachability
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

// An enumeration describing possible network statuses.
typedef enum {
  NamoConnectivityNotReachable = 0,
  NamoConnectivityReachableViaWiFi,
  NamoConnectivityReachableViaWWAN
} NamoNetworkStatus;

@interface NamoConnectivity : NSObject

// Returns the current network status.
+ (NamoNetworkStatus)currentNetworkStatus;
@end


