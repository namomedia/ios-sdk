// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 NAMOWebViewAdPlacer places ads into your UIWebView by inserting a Javascript snippet that
 can be read by the NAMO Javascript SDK.

 @available Namo 1.0 and later.
*/
@interface NAMOWebViewAdPlacer : NSObject

/// @name Creating a NAMOWebViewAdPlacer object

/**
 Create and return a new web view placer.

 @return The newly created web view placer.
 @available Namo 1.0 and later.
*/
+ (NAMOWebViewAdPlacer *)adPlacer;

/// @name Binding to a UIWebView

/**
 Bind to a new web view placer. The web view will immediately execute Javascript to request
 ads from the server and include them in your stream.

 @param webView The web view into which to bind ads.
 @available Namo 1.0 and later.
*/
- (void)bindToWebView:(UIWebView *)webView;
@end
