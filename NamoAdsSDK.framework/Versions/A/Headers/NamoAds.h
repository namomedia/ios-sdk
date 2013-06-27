//
// NamoAds.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoAds defines messages for interacting with the SDK.
//

#import <Foundation/Foundation.h>
#import <AdSupport/AdSupport.h>
#import <UIKit/UIKIt.h>

@class NamoAdsControllerProxy;
@class NamoAdsController;
@protocol NamoAdCellCustomizer;

@interface NamoAds : NSObject
// Tells the SDK that the app has loaded. This method should typically be called in your
// main AppDelegate.
+ (void)startWithAppId:(NSString *)appId;

// Creates a controller proxy object for the given table view controller. To use this proxy
// to insert ads into your stream, assign it to the delegate and dataSource properties of your
// table view.
+ (NamoAdsControllerProxy *)proxyForController:(UITableViewController *)controller;

// See proxyForController. Specify a customizer to customize how your ads look, or
// to provide your own ad cell implementation.
+ (NamoAdsControllerProxy *)proxyForController:(UITableViewController *)controller
                              adCellCustomizer:(id<NamoAdCellCustomizer>)customizer;

// Creates a controller object that can be used to manually insert NamoAdsController calls into
// your table view delegate and dataSource methods. Use this object as an alternative to
// NamoAdsControllerProxy if you need precise control over your ad placement and targeting.
+ (NamoAdsController *)adControllerForTableView:(UITableView *)tableView;

// See adControllerForTableView.  Specify a customizer to customize how your ads look, or
// to provide your own ad cell implementation.
+ (NamoAdsController *)adControllerForTableView:(UITableView *)tableView
                               adCellCustomizer:(id<NamoAdCellCustomizer>)customizer;

// See proxyForController. Specify a customizer to customize how your ads look, or
// to provide your own ad cell implementation.
+ (NamoAdsControllerProxy *)proxyForTableView:(UITableView *)tableView
                                   dataSource:(id<UITableViewDataSource>)dataSource
                                     delegate:(id<UITableViewDelegate>)delegate
                             adCellCustomizer:(id<NamoAdCellCustomizer>)customizer;

// Injects the data needed for serving ads in a UIWebView context. This method should be called
// within your UIWebViewDelegate's viewDidFinishLoad method.
+ (void)injectDataToWebView:(UIWebView *)webView;

// Allocates and initializes a UIWebViewDelegate that you can assign to your UIWebView's
// delegate property. This delegate simply call [NamoAds injectDataToWebView: withAppId:]
// in its viewDidFinishLoad method.
+ (id<UIWebViewDelegate>)uiWebViewDelegate;

@end