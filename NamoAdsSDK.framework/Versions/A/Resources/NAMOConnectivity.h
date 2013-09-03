// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

/**
 An enumeration describing possible network statuses.
*/
typedef NS_ENUM(NSInteger, NAMONetworkStatus) {
  NamoConnectivityNotReachable = 0,
  NamoConnectivityReachableViaWiFi,
  NamoConnectivityReachableViaWWAN
};

/**
 NAMOConnectivity defines messages for determining the current network status and connection
 type. The implementation is a greatly simplified version of Apple's
 Reachability code: http://developer.apple.com/library/ios/#samplecode/Reachability
*/
@interface NAMOConnectivity : NSObject

/**
 Returns the current network status.
*/
+ (NAMONetworkStatus)currentNetworkStatus;

@end


