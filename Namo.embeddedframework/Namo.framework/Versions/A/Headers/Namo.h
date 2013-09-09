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

#import "NAMOTableViewAdCell.h"
#import "NAMOAdData.h"
#import "UIImageView+NAMOImage.h"
#import "NSURL+NAMOImage.h"

#import "NAMOAdPlacer.h"
#import "NAMOIndexPathAdjuster.h"
#import "NAMOTableViewAdPlacer.h"
#import "UITableView+NAMOAdPlacer.h"
#import "NAMOTableViewAdCellPhoto.h"
#import "NAMOTableViewAdCellSocial1.h"
#import "NAMOTableViewAdCellThumb.h"

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
 application ID as found in your Namo Media publisher account. http://www.namomedia.com/monetize

 @param applicationId The application id for your Namo Application.
 @available Namo 1.0 and later.
 */
+ (void)setApplicationId:(NSString *)applicationId;

/// @name Globally deactivating ads

/**
 Start or stop the SDK from connecting to the server for ads.

 When not active, calling `[NAMOAdPlacer requestAds]` will log a warning message. To prevent this
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