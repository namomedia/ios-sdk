// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
NAMOWebViewController can be used as a web browser replacement.
*/
@interface NAMOWebViewController : UIViewController
@property(retain, nonatomic) UIWebView *webView;
@property(nonatomic, copy) void (^dismissCallback)(NAMOWebViewController *);

/**
 Designated initializer.
*/
- (id)initWithURL:(NSURL *)url;
@end
