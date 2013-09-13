// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NAMOAdData;

/**
 A category to create image URLs to take advantage of Namo Media's ad image scaling.

 When uploading ad images to to Namo Media's servers, you specify a hotspot that describes
 a region of the image that should always be visible, as well as metadata describing how
 the image should scale to different aspect ratios. These functions return a URL for an ad
 image that will return an image with the given dimensions.

 @available Namo 1.0 and later.
*/
@interface NSURL (NAMOImage)

/// @name Creating image URLs

/**
 Creates and returns a URL object that you can use to request an ad image with the given
 size.

 @param adData Ad data downloaded from the server.
 @param imageSize The desired image size to return for the URL.
 @return An image URL for the ad image.
 @available Namo 1.0 and later.
 */
+ (NSURL *)namo_URLForImageWithAdData:(NAMOAdData *)adData size:(CGSize)imageSize;

/**
 Creates and returns a URL object that you can use to request an ad image with given size and
 scale factor.

 @param adData Ad data downloaded from the server.
 @param imageSize The desired image size to return for the URL.
 @param scaleFactor The scale factor applied to the image.
 @return An image URL for the ad image.
 @available Namo 1.0 and later.
*/
+ (NSURL *)namo_URLForImageWithAdData:(NAMOAdData *)adData
                                 size:(CGSize)imageSize
                          scaleFactor:(CGFloat)scaleFactor;

/// @name Creating advertiser icon URLs

/**
 Creates and returns a URL for the advertiser icon that will scale the image to the requested size.

 @param adData Ad data downloaded from the server.
 @param imageSize The desired image size to return for the URL.
 @return An advertiser icon URL for the ad image.
 @available Namo 1.0 and later.
 */
+ (NSURL *)namo_URLForIconWithAdData:(NAMOAdData *)adData size:(CGSize)imageSize;

/**
 Creates and returns a URL for the advertiser icon that will scale the image to the requested size
 and scale factor.

 @param adData Ad data downloaded from the server.
 @param imageSize The desired image size to return for the URL.
 @param scaleFactor The scale factor applied to the image.
 @return An advertiser icon URL for the ad image.
 @available Namo 1.0 and later.
 */
+ (NSURL *)namo_URLForIconWithAdData:(NAMOAdData *)adData
                                size:(CGSize)imageSize
                         scaleFactor:(CGFloat)scaleFactor;
@end
