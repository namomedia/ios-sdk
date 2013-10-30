#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOAdData.h"

/**
 Internal definitions for the ad placer class.
*/
@interface NAMOAdPlacer (Internal)
- (BOOL)hadImpressionForAdId:(NSString *)adId;

- (void)handleImpression:(UIView *)view withData:(NAMOAdData *)adData;

- (void)handleTap:(UIGestureRecognizer *)recognizer;

- (void)handleVideoView:(NAMOAdData *)ad
        videoViewLength:(NSTimeInterval)videoView
       videoTotalLength:(NSTimeInterval)videoTotal;

- (BOOL)openTargetForAd:(NAMOAdData *)ad;

- (void)openInternalWebViewForURL:(NSURL *)url;

- (void)openInternalMoviePlayerForURL:(NSURL *)url ad:(NAMOAdData *)ad;

@end