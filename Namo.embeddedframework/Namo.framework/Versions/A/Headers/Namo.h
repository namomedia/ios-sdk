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

#import "NAMOAdCell.h"
#import "NAMOAdData.h"
#import "UIImageView+NAMOImage.h"
#import "NSURL+NAMOImage.h"
#import "NAMOTargeting.h"

#import "NAMOAdPlacer.h"
#import "NAMOIndexPathAdjuster.h"
#import "UITableView+NAMOAdPlacer.h"
#import "UICollectionView+NAMOAdPlacer.h"
#import "NAMOAdCellCollectionSample1.h"
#import "NAMOAdCellTableSample1.h"
#import "NAMOAdCellTableSample2.h"
#import "NAMOAdCellTableSample3.h"
#import "NAMOAdCellTableSample4.h"
#import "NAMOAdCellTableSample5.h"

#import "NAMOWebViewAdPlacer.h"

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
 <a href="http://beta.namomedia.com/monetize" target="_blank">beta.namomedia.com</a>.

 @param applicationId The application ID for your registered application.
 @available Namo 1.0 and later.
 */
+ (void)setApplicationId:(NSString *)applicationId;

/// @name Globally deactivating ads

/**
 Start or stop the SDK from connecting to the server for ads.

 When not active, calling `[NAMOAdPlacer requestAds:]` will log a warning message. To prevent this
 warning, you can check the active value before requesting ads.

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

@end