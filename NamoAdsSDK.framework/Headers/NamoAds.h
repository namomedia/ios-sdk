//
// NamoAds.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoAds defines messages for interacting with the NamoMedia Ads SDK.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKIt.h>

@class NamoAdsControllerProxy;
@class NamoAdsController;
@protocol NamoAdCellProvider;

@interface NamoAds : NSObject
// Tells the NamoMedia Ads SDK that the app has loaded. This method should typically be called in your
// main AppDelegate.
+ (void)startWithAppId:(NSString *)appId;

// Creates a controller proxy object for the given table view controller. To use this proxy
// to insert ads into your stream, assign it to the delegate and dataSource properties of your
// table view.
+ (NamoAdsControllerProxy *)proxyForController:(UITableViewController *)controller
                                adCellProvider:(id<NamoAdCellProvider>)provider;

// Creates a controller object that can be used to manually insert NamoAdsController calls into
// your table view delegate and dataSource methods. Use this object as an alternative to
// NamoAdsControllerProxy if you need precise control over your ad placement and targeting./
+ (NamoAdsController *)adControllerForTableView:(UITableView *)tableView
                                 adCellProvider:(id<NamoAdCellProvider>)provider;
@end