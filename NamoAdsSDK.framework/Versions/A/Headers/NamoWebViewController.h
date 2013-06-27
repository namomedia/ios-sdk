//
// NamoWebViewController
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoWebViewController can be used as a web browser replacement.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface NamoWebViewController : UIViewController
@property(retain, nonatomic) UIWebView *webView;
@property(nonatomic, copy) void (^dismissCallback)(NamoWebViewController *);

- (id)initWithUrl:(NSURL *)url;
@end
