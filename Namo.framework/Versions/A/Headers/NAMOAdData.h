// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

@class UILabel;
@class UIImage;
@class UIImageView;

/**
 Defines data for a Namo ad returned from the server.

 @available Namo 1.0 and later.
 */
@interface NAMOAdData : NSObject

/// @name Determining the action type.

/**
 The action type for an Ad.

 @available Namo 1.0 and later.
*/
typedef NS_ENUM(NSInteger, NAMOActionType) {
  /**
   The ad opens an in-app browser with a web URL.
   */
  NAMOActionTypeLink,

  /**
   The ad opens an in-app video player with a video feed URL.
   */
  NAMOActionTypeVideo,

  /**
   The ad opens the App Store with an iTunes app URL. The action URL may also link to an
   intermediary attribution tracking platform before redirecting to iTunes, such as HasOffers.
   */
  NAMOActionTypeInstall
};

/**
 The action type associated with this ad.

 You may want to show a different UI for different action types. For example, you could
 show an "Install" button for an install ad, or a play video image overlay for a video
 ad. The SDK will correctly handle different action types when clicking on your ad cell.

 @return The action type associated with this ad.
 @available Namo 1.0 and later.
 */
- (NAMOActionType)actionType;

/// @name Showing ad text.

/**
 Callback block for text loading, called after the UILabel text property is set.

 @available Namo 2.0 and later.
 */
typedef void(^NAMO_TextLoadedBlock)(UILabel *label);

/**
 Loads the Ad text into the given UILabel.

 This will asynchronously measure the UILabel and load ad text of the appropriate length based on
 its dimensions.

 @param label The UILabel into which to load the text.
 @available Namo 2.0 and later.
*/
- (void)loadTextIntoLabel:(UILabel *)label;

/**
 Loads the Ad text into the given UILabel, with a callback.

 If you provide a non-nil success block, the block will be executed after the text has been set.
 You can, for example, use this block to provide a transition animation.

 @param label The UILabel into which to load the text.
 @param completedBlock A block to execute after the text loads.
 @available Namo 2.0 and later.
 */
- (void)loadAdTextIntoLabel:(UILabel *)label
                  completedBlock:(NAMO_TextLoadedBlock)completedBlock;

/**
 Loads the advertiser name into the given UILabel.

 This will asynchronously measure the UILabel and set the advertiser name.

 @param label The UILabel into which to load the text.
 @available Namo 2.0 and later.
*/
- (void)loadAdvertiserNameIntoLabel:(UILabel *)label;

/**
 Loads the advertiser name into the given UILabel, with a callback.

 If you provide a non-nil success block, the block will be executed after the text has been set.
 You can, for example, use this block to provide a transition animation.

 @param label The UILabel into which to load the text.
 @param completedBlock A block to execute after the text loads.
 @available Namo 2.0 and later.
 */
- (void)loadAdvertiserNameIntoLabel:(UILabel *)label
             completedBlock:(NAMO_TextLoadedBlock)completedBlock;

/// @name Showing ad images.

/**
 Callback block for image requests, called when image loading completes.

 When this block gets called, the `UIImageView` `image` property will be set to the result of the
 image request if there is no error. If there is an error, the error property will be non-nil.
 @available Namo 2.0 and later.
 */
typedef void(^NAMO_ImageLoadedBlock)(UIImageView *imageView, NSError *error);

/**
 Loads the Ad image into the given UIImageView.

 This makes a request for the image using the dimensions of the ImageView. The resulting image will
 be asynchronously loaded into the ImageView.

 @param imageView The image view into which to load the image.
 @available Namo 2.0 and later.
*/
- (void)loadImageIntoImageView:(UIImageView *)imageView;

/**
 Loads the Ad image into the given UIImage, with a callback.

 This makes an asynchronous request for the image. If you provide a non-nil success block, the block
 will be executed after the image request completes and after the UIImageView's image property has
 been set to the result of the image request. You can, for example, use this success block to
 provide transition effects on the view.

 @param imageView The UIImageView that will hold the ad image.
 @param placeholder An optionally-nil image to place in the UIImageView before the ad request
 completes.
 @param completedBlock A block to execute after the image request completes.
 @available Namo 2.0 and later.
 */
- (void)loadAdImageIntoImageView:(UIImageView *)imageView
                placeholderImage:(UIImage *)placeholder
                  completedBlock:(NAMO_ImageLoadedBlock)completedBlock;

/**
 Loads the Advertiser icon into the given UIImageView.

 This makes a request for the icon using the dimensions of the ImageView. The resulting image will
 be asynchronously loaded into the ImageView.

 @param imageView The image view into which to load the image.
 @available Namo 2.0 and later.
 */
- (void)loadAdvertiserIconIntoImageView:(UIImageView *)imageView;

/**
 Loads the Advertiser icon into the given UIImageView, with a callback.

 This makes an asynchronous request for the icon. If you provide a non-nil success block, the block
 will be executed after the image request completes and after the UIImageView's image property has
 been set to the result of the image request. You can, for example, use this block to
 provide transition effects on the view.

 @param imageView The image view into which to load the image.
 @param placeholder An optionally-nil image to place in the UIImageView before the ad request
 completes.
 @param completedBlock A block to execute after the image request completes.
 @available Namo 2.0 and later.
 */
- (void)loadAdvertiserIconIntoImageView:(UIImageView *)imageView
                       placeholderImage:(UIImage *)placeholder
                         completedBlock:(NAMO_ImageLoadedBlock)completedBlock;
@end