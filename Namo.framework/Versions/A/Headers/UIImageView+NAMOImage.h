// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

// UIImageView category that adds methods for binding Namo Ad Images into the view.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 A category to help bind UIImageViews to an ad image, providing server side image scaling, a
 lightweight caching framework, and appropriate network throttling.

 The image requests generated from using this category use the popular SDWebImageCache library
 internally. The requests also generate image URLs that allow the Namo Media server to scale the
 image to the exact dimensions needed in order to reduce network bandwidth.

 @available Namo 1.0 and later.
*/
@interface UIImageView (NAMOImage)

/// @name Binding images to an Ad

/**
 Binds the UIImageView to the Ad image for the given ad.

 This makes an asynchronous request for the image.

 @param adData Ad data downloaded from the server.
 @available Namo 1.0 and later.
*/
- (void)namo_bindAdImage:(NAMOAdData *)adData;

/**
 Binds the UIImageView to the Ad image for the given ad.
 
 This makes an asynchronous request for the image. If you provide a non-nil success block, the block
 will be executed after the image request completes and after the UIImageView's image property has
 been set to the result of the image request. You can, for example, use this success block to
 provide transition effects on the view.
 
 @param adData Ad data downloaded from the server.
 @param placeholderImage An optionally-nil image to place in the UIImageView before the ad request completes.
 @param completed A block to execute after the image request completes. At this point the `UIView` `image` property will be set to the result of the image request if there is no error. If there is an error, the error property will be non-nil.
 @available Namo 1.0 and later.
 */
- (void)namo_bindAdImage:(NAMOAdData *)adData
        placeholderImage:(UIImage *)placeholder
               completed:(void (^)(UIImage *image, NSError *error))completed;

/**
 Binds the UIImageView to the Advertiser icon for the given ad.

 This makes an asynchronous request for the icon.

 @param adData Ad data downloaded from the server.
 @available Namo 1.0 and later.
 */
- (void)namo_bindAdIcon:(NAMOAdData *)adData;

/**
 Binds the UIImageView to the Advertiser icon for the given ad.
 
 This makes an asynchronous request for the icon. If you provide a non-nil success block, the block
 will be executed after the image request completes and after the UIImageView's image property has
 been set to the result of the image request. You can, for example, use this success block to
 provide transition effects on the view.
 
 @param adData Ad data downloaded from the server.
 @param placeholderImage An optionally-nil image to place in the UIImageView before the ad request completes.
 @param completed A block to execute after the image request completes. At this point the `UIView` `image` property will be set to the result of the image request if there is no error. If there is an error, the error property will be non-nil.
 @available Namo 1.0 and later.
 */
- (void)namo_bindAdIcon:(NAMOAdData *)adData
       placeholderImage:(UIImage *)placeholder
              completed:(void (^)(UIImage *image, NSError *error))completed;

@end
