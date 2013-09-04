// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import "Namo.h"

/**
 This category defines additional methods for testing and debugging the SDK.
*/
@interface Namo (Testing)

/**
 Debugging method for setting an ad server URL. You do not need to set this URL for normal
 use of the SDK.
*/
+ (void)setAdServerURL:(NSString *)url;

/**
 Debugging method for setting an image server URL. You do not need to set this URL for normal use
 of the SDK.
*/
+ (void)setImageServerURL:(NSString *)url;

/**
 Debugging for getting the ad server URL.
*/
+ (NSString *)adServerURL;

/**
 Debugging for getting the image server URL.
*/
+ (NSString *)imageServerURL;
@end