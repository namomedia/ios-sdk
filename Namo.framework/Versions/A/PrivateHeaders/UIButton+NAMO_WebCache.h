/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "NAMO_SDWebImageCompat.h"
#import "NAMO_SDWebImageManager.h"

/**
 * Integrates SDWebImage async downloading and caching of remote images with UIButtonView.
 */
@interface UIButton (NAMO_WebCache)

/**
 * Set the imageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 */
- (void)namo_setImageWithURL:(NSURL *)url forState:(UIControlState)state;

/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see namo_setImageWithURL:placeholderImage:options:
 */
- (void)namo_setImageWithURL:(NSURL *)url
                    forState:(UIControlState)state
            placeholderImage:(UIImage *)placeholder;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see NAMO_SDWebImageOptions for the possible values.
 */
- (void)namo_setImageWithURL:(NSURL *)url
                    forState:(UIControlState)state
            placeholderImage:(UIImage *)placeholder
                     options:(NAMO_SDWebImageOptions)options;

/**
 * Set the imageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param completedBlock A block called when operation has been completed. This block as no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrived from the local cache of from the network.
 */
- (void)namo_setImageWithURL:(NSURL *)url
                    forState:(UIControlState)state
                   completed:(NAMO_SDWebImageCompletedBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param completedBlock A block called when operation has been completed. This block as no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrived from the local cache of from the network.
 */
- (void)namo_setImageWithURL:(NSURL *)url
                    forState:(UIControlState)state
            placeholderImage:(UIImage *)placeholder
                   completed:(NAMO_SDWebImageCompletedBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see NAMO_SDWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block as no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrived from the local cache of from the network.
 */
- (void)namo_setImageWithURL:(NSURL *)url
                    forState:(UIControlState)state
            placeholderImage:(UIImage *)placeholder
                     options:(NAMO_SDWebImageOptions)options
                   completed:(NAMO_SDWebImageCompletedBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 */
- (void)namo_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state;

/**
 * Set the backgroundImageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see namo_setImageWithURL:placeholderImage:options:
 */
- (void)namo_setBackgroundImageWithURL:(NSURL *)url
                              forState:(UIControlState)state
                      placeholderImage:(UIImage *)placeholder;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see NAMO_SDWebImageOptions for the possible values.
 */
- (void)namo_setBackgroundImageWithURL:(NSURL *)url
                              forState:(UIControlState)state
                      placeholderImage:(UIImage *)placeholder
                               options:(NAMO_SDWebImageOptions)options;

/**
 * Set the backgroundImageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param success A block to be executed when the image request succeed This block has no return value and takes the retrieved image as argument.
 * @param failure A block object to be executed when the image request failed. This block has no return value and takes the error object describing the network or parsing error that occurred (may be nil).
 */
- (void)namo_setBackgroundImageWithURL:(NSURL *)url
                              forState:(UIControlState)state
                             completed:(NAMO_SDWebImageCompletedBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param success A block to be executed when the image request succeed This block has no return value and takes the retrieved image as argument.
 * @param failure A block object to be executed when the image request failed. This block has no return value and takes the error object describing the network or parsing error that occurred (may be nil).
 */
- (void)namo_setBackgroundImageWithURL:(NSURL *)url
                              forState:(UIControlState)state
                      placeholderImage:(UIImage *)placeholder
                             completed:(NAMO_SDWebImageCompletedBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder and custom options.
 *
 * The downloand is asynchronous and cached.
 *
 * @param url The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options The options to use when downloading the image. @see NAMO_SDWebImageOptions for the possible values.
 * @param success A block to be executed when the image request succeed This block has no return value and takes the retrieved image as argument.
 * @param failure A block object to be executed when the image request failed. This block has no return value and takes the error object describing the network or parsing error that occurred (may be nil).
 */
- (void)namo_setBackgroundImageWithURL:(NSURL *)url
                              forState:(UIControlState)state
                      placeholderImage:(UIImage *)placeholder
                               options:(NAMO_SDWebImageOptions)options
                             completed:(NAMO_SDWebImageCompletedBlock)completedBlock;

/**
 * Cancel the current download
 */
- (void)namo_cancelCurrentImageLoad;

@end
