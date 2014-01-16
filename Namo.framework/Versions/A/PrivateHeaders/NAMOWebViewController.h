// Copyright (c) 2014 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 NAMOWebViewController is a browser used to open URLs for "Open URL" type ads.
 */
@interface NAMOWebViewController : UIViewController <UIWebViewDelegate, UIActionSheetDelegate>

@property(nonatomic, copy) void (^dismissCallback)(NAMOWebViewController *);

/**
 Designated initializer.
 */
- (id)initWithURL:(NSURL *)url;
@end