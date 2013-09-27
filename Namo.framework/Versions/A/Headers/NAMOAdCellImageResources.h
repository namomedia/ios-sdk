// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Provides common image resources useful for implementing NamoAdCell views.

 On Retina devices, images will be returned as 2x scaled images.

 These images are subject to change in future versions of the SDK. If you are implementing your
 own cells, you may want to copy image resources from
 <a href="https://github.com/namomedia/ios-sdk/tree/master/AdCellTemplates" target="_blank">
 our open source repository</a> into your project instead of relying on this class.

  @available Namo 1.0 and later.
 */
@interface NAMOAdCellImageResources : NSObject

/// @name Getting ad cell images

/**
 Returns a small ad indicator image demarcating the ad as a Namo Ad.

 @available Namo 1.0 and later.
 */
+ (UIImage *)namoAdIndicator;

/**
 Returns a small ad indicator image demarcating the ad as a Namo Ad, appropriate for
 display on a dark background.

 @available Namo 1.0 and later.
*/
+ (UIImage *)namoAdIndicatorLight;

/**
 Returns a grey metallic button background, currently used by our samples as an install button
 background.

 @available Namo 1.0 and later.
*/
+ (UIImage *)namoGreyInstallButton;

@end
