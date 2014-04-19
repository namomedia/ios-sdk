// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

/**
 Namo.h is the Namo.framework library header file. Import this file to import
 all the public header files in SDK.
*/

#import <Foundation/Foundation.h>

#ifndef __IPHONE_6_0
#error "The Namo SDK uses features only available in iOS SDK 6.0 and later."
#endif

#if !__has_feature(objc_arc)
#error "The Namo SDK is ARC only. Either turn on ARC for the project or use -fobjc-arc flag."
#endif

#import "NAMOErrors.h"
#import "NAMOAdFormat.h"
#import "NAMOAdData.h"
#import "NAMOAd.h"
#import "NAMOTargeting.h"

#import "NAMOTableViewAdPlacer.h"
#import "NAMOCollectionViewAdPlacer.h"
#import "NAMOCustomStreamAdPlacer.h"
#import "UITableView+NAMOAdPlacer.h"
#import "UICollectionView+NAMOAdPlacer.h"
#import "NAMOAdPlacerDelegate.h"
#import "NAMOAdView.h"

#import "NAMOAdFormatSample6.h"
#import "NAMOAdFormatSample1.h"
#import "NAMOAdFormatSample2.h"
#import "NAMOAdFormatSample3.h"
#import "NAMOAdFormatSample4.h"
#import "NAMOAdFormatSample5.h"

/**
 Defines application level configuration for the Namo SDK.
 
 @available Namo 1.0 and later.
 */
@interface Namo : NSObject

/// @name Enabling the SDK

/**
 Sets the applicationId for your application.

 You must invoke this method in order to use the Namo SDK. You must provide your
 application ID as found in your Namo Publisher Account at
 <a href="http://dashboard.namomedia.com/monetize" target="_blank">dashboard.namomedia.com</a>.

 @param applicationId The application ID for your registered application.
 @available Namo 1.0 and later.
 */
+ (void)setApplicationId:(NSString *)applicationId;

/// @name Globally deactivating ads

/**
 Enables or disables the SDK from connecting to the server for ads.

 When not active, calling `[NAMOAdPlacer requestAdsWithTargeting:]` will log a warning message. To
 prevent this warning, you can check the active value before requesting ads.

 @param active Whether to enable or disable serving ads.
 @available Namo 1.0 and later.
 */
+ (void)setActive:(BOOL)active;

/**
 Returns whether the SDK is active.

 Defaults to `YES` unless you have explicitly called `setActive:NO`.

 @return Whether the SDK is active.
 @available Namo 1.0 and later.
 */
+ (BOOL)active;

/// @name Test Mode

/**
 Puts the given device in 'test' mode.

 Test mode ensures that ads will be always be shown. It also will prevent impressions and clicks
 from the device from being counted as revenue. We recommend adding any devices you use for
 development.

 On iOS 6 and greater devices, your test device ID is the the advertiser identifier. On pre
 iOS 6 devices where the advertiser identifier is unavailable, this ID is a hash or your device's
 MAC address. You can easily obtain both of these values by copying and pasting them
 from the console logs printed by the SDK when you first call setApplicationId.

 @param testDeviceIds An array of strings containing test device ids. You do not need to pass an
 ID for your simulator. Use the `includeSimulator` parameter instead.
 @param includeSimulator Whether to include the iPhone simulator as a test device.
 @available Namo 1.0.1 and later.
*/
+ (void)setTestDevices:(NSArray *)testDeviceIds includeSimulator:(BOOL)includeSimulator;
@end