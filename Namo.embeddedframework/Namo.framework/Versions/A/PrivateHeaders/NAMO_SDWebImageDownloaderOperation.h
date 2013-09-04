/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "NAMO_SDWebImageDownloader.h"
#import "NAMO_SDWebImageOperation.h"

@interface NAMO_SDWebImageDownloaderOperation : NSOperation <NAMO_SDWebImageOperation>

@property (strong, nonatomic, readonly) NSURLRequest *request;
@property (assign, nonatomic, readonly) NAMO_SDWebImageDownloaderOptions options;

- (id)initWithRequest:(NSURLRequest *)request
                queue:(dispatch_queue_t)queue
              options:(NAMO_SDWebImageDownloaderOptions)options
             progress:(NAMO_SDWebImageDownloaderProgressBlock)progressBlock
            completed:(NAMO_SDWebImageDownloaderCompletedBlock)completedBlock
            cancelled:(void (^)())cancelBlock;

@end
