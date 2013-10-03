// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

/**
 Built-in video player view controller for viewing video ads.
 */
@interface NAMOMoviePlayerViewController : UIViewController

@property(nonatomic, copy) void (^dismissCallback)(
    NAMOMoviePlayerViewController *,
    NSTimeInterval playbackTime,
    NSTimeInterval totalTime);

- (id)initWithURL:(NSURL *)url;
@end
