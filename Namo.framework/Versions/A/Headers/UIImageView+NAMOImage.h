//  Copyright (c) 2013 Namo Media. All rights reserved.

// UIImageView category that adds methods for binding Namo Ad Images into the view.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 A category to help bind UIImageViews to and ad image, providing server side image scaling, a
 lightweight caching framework, and appropriate network throttling.

 The image requests generated from using this category use the popular SDWebImageCache library
 internally. The requests also generate image URLs that allow the Namo Media server to scale the
 image to the exact dimensions needed in order to reduce network bandwidth.

 @available NamoAds 1.0 and later.
*/
@interface UIImageView (NAMOImage)

/// @name Binding images to an Ad

/**
 Fills the UIImageView to the Ad image for the given ad.

 This makes an asynchronous request for the image.

 @param adData Ad data downloaded from the server.
 @available NamoAds 1.0 and later.
*/
- (void)namo_bindAdImage:(NAMOAdData *)adData;

/**
 Fills the UIImageView to the Ad image for the given ad.

 This makes an asynchronous request for the icon.

 @param adData Ad data downloaded from the server.
 @available NamoAds 1.0 and later.
 */
- (void)namo_bindAdIcon:(NAMOAdData *)adData;

@end
