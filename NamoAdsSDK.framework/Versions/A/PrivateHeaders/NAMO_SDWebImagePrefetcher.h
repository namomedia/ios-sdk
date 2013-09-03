/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "NAMO_SDWebImageManager.h"

/**
 * Prefetch some URLs in the cache for future use. Images are downloaded in low priority.
 */
@interface NAMO_SDWebImagePrefetcher : NSObject

/**
 * Maximum number of URLs to prefetch at the same time. Defaults to 3.
 */
@property (nonatomic, assign) NSUInteger maxConcurrentDownloads;

/**
 * NAMO_SDWebImageOptions for prefetcher. Defaults to NAMO_SDWebImageLowPriority.
 */
@property (nonatomic, assign) NAMO_SDWebImageOptions options;


/**
 * Return the global image prefetcher instance.
 */
+ (NAMO_SDWebImagePrefetcher *)sharedImagePrefetcher;

/**
 * Assign list of URLs to let NAMO_SDWebImagePrefetcher to queue the prefetching,
 * currently one image is downloaded at a time,
 * and skips images for failed downloads and proceed to the next image in the list
 *
 * @param urls list of URLs to prefetch
 */
- (void)prefetchURLs:(NSArray *)urls;

/**
 * Assign list of URLs to let NAMO_SDWebImagePrefetcher to queue the prefetching,
 * currently one image is downloaded at a time,
 * and skips images for failed downloads and proceed to the next image in the list
 *
 * @param urls list of URLs to prefetch
 * @param completionBlock block to be called when prefetching is completed
 */
- (void)prefetchURLs:(NSArray *)urls completed:(void (^)(NSUInteger finishedCount, NSUInteger skippedCount))completionBlock;

/**
 * Remove and cancel queued list
 */
- (void)cancelPrefetching;


@end
