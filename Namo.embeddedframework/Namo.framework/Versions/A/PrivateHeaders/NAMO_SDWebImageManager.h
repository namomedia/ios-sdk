/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "NAMO_SDWebImageCompat.h"
#import "NAMO_SDWebImageOperation.h"
#import "NAMO_SDWebImageDownloader.h"
#import "NAMO_SDImageCache.h"

typedef enum
{
    /**
     * By default, when a URL fail to be downloaded, the URL is blacklisted so the library won't keep trying.
     * This flag disable this blacklisting.
     */
    NAMO_SDWebImageRetryFailed = 1 << 0,
    /**
     * By default, image downloads are started during UI interactions, this flags disable this feature,
     * leading to delayed download on UIScrollView deceleration for instance.
     */
    NAMO_SDWebImageLowPriority = 1 << 1,
    /**
     * This flag disables on-disk caching
     */
    NAMO_SDWebImageCacheMemoryOnly = 1 << 2,
    /**
     * This flag enables progressive download, the image is displayed progressively during download as a browser would do.
     * By default, the image is only displayed once completely downloaded.
     */
    NAMO_SDWebImageProgressiveDownload = 1 << 3,
    /**
     * Even if the image is cached, respect the HTTP response cache control, and refresh the image from remote location if needed.
     * The disk caching will be handled by NSURLCache instead of SDWebImage leading to slight performance degradation.
     * This option helps deal with images changing behind the same request URL, e.g. Facebook graph api profile pics.
     * If a cached image is refreshed, the completion block is called once with the cached image and again with the final image.
     *
     * Use this flag only if you can't make your URLs static with embeded cache busting parameter.
     */
    NAMO_SDWebImageRefreshCached = 1 << 4
} NAMO_SDWebImageOptions;

typedef void(^NAMO_SDWebImageCompletedBlock)(UIImage *image, NSError *error, NAMO_SDImageCacheType cacheType);
typedef void(^NAMO_SDWebImageCompletedWithFinishedBlock)(UIImage *image, NSError *error, NAMO_SDImageCacheType cacheType, BOOL finished);


@class NAMO_SDWebImageManager;

@protocol NAMO_SDWebImageManagerDelegate <NSObject>

@optional

/**
 * Controls which image should be downloaded when the image is not found in the cache.
 *
 * @param imageManager The current `NAMO_SDWebImageManager`
 * @param imageURL The url of the image to be downloaded
 *
 * @return Return NO to prevent the downloading of the image on cache misses. If not implemented, YES is implied.
 */
- (BOOL)imageManager:(NAMO_SDWebImageManager *)imageManager shouldDownloadImageForURL:(NSURL *)imageURL;

/**
 * Allows to transform the image immediately after it has been downloaded and just before to cache it on disk and memory.
 * NOTE: This method is called from a global queue in order to not to block the main thread.
 *
 * @param imageManager The current `NAMO_SDWebImageManager`
 * @param image The image to transform
 * @param imageURL The url of the image to transform
 *
 * @return The transformed image object.
 */
- (UIImage *)imageManager:(NAMO_SDWebImageManager *)imageManager transformDownloadedImage:(UIImage *)image withURL:(NSURL *)imageURL;

@end

/**
 * The NAMO_SDWebImageManager is the class behind the UIImageView+NAMO_WebCache category and likes.
 * It ties the asynchronous downloader (NAMO_SDWebImageDownloader) with the image cache store (NAMO_SDImageCache).
 * You can use this class directly to benefit from web image downloading with caching in another context than
 * a UIView.
 *
 * Here is a simple example of how to use NAMO_SDWebImageManager:
 *
 *  NAMO_SDWebImageManager *manager = [NAMO_SDWebImageManager sharedManager];
 *  [manager downloadWithURL:imageURL
 *                  delegate:self
 *                   options:0
 *                  progress:nil
 *                 completed:^(UIImage *image, NSError *error, BOOL fromCache)
 *                 {
 *                     if (image)
 *                     {
 *                         // do something with image
 *                     }
 *                 }];
 */
@interface NAMO_SDWebImageManager : NSObject

@property (weak, nonatomic) id<NAMO_SDWebImageManagerDelegate> delegate;

@property (strong, nonatomic, readonly) NAMO_SDImageCache *imageCache;
@property (strong, nonatomic, readonly) NAMO_SDWebImageDownloader *imageDownloader;

/**
 * The cache filter is a block used each time NAMO_SDWebImageManager need to convert an URL into a cache key. This can
 * be used to remove dynamic part of an image URL.
 *
 * The following example sets a filter in the application delegate that will remove any query-string from the
 * URL before to use it as a cache key:
 *
 * 	[[NAMO_SDWebImageManager sharedManager] setCacheKeyFilter:^(NSURL *url)
 *	{
 *	    url = [[NSURL alloc] initWithScheme:url.scheme host:url.host path:url.path];
 *	    return [url absoluteString];
 *	}];
 */
@property (strong) NSString *(^cacheKeyFilter)(NSURL *url);

/**
 * Returns global NAMO_SDWebImageManager instance.
 *
 * @return NAMO_SDWebImageManager shared instance
 */
+ (NAMO_SDWebImageManager *)sharedManager;

/**
 * Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 * @param url The URL to the image
 * @param delegate The delegate object used to send result back
 * @param options A mask to specify options to use for this request
 * @param progressBlock A block called while image is downloading
 * @param completedBlock A block called when operation has been completed.
 *
 *                       This block as no return value and takes the requested UIImage as first parameter.
 *                       In case of error the image parameter is nil and the second parameter may contain an NSError.
 *
 *                       The third parameter is a Boolean indicating if the image was retrived from the local cache
 *                       of from the network.
 *
 *                       The last parameter is set to NO when the NAMO_SDWebImageProgressiveDownload option is used and
 *                       the image is downloading. This block is thus called repetidly with a partial image. When
 *                       image is fully downloaded, the block is called a last time with the full image and the last
 *                       parameter set to YES.
 *
 * @return Returns a cancellable NSOperation
 */
- (id<NAMO_SDWebImageOperation>)downloadWithURL:(NSURL *)url
                                   options:(NAMO_SDWebImageOptions)options
                                  progress:(NAMO_SDWebImageDownloaderProgressBlock)progressBlock
                                 completed:(NAMO_SDWebImageCompletedWithFinishedBlock)completedBlock;

/**
 * Cancel all current opreations
 */
- (void)cancelAll;

/**
 * Check one or more operations running
 */
- (BOOL)isRunning;

@end
