//
// NamoAdsControllerProxy.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoAdsControllerProxy proxies calls between a native UITableViewController instance and
// a NamoAdsController instance.
//
// To use NamoAdsControllerProxy, install it as the dataSource and delegate for
// your UITableView. All calls to the proxy will be forwarded to your own UITableViewController
// or to NamoAdsController, depending on whether the NSIndexPath for the call matches an ad. If
// you prefer to your own UITableViewController handle methods directly, you may choose to
// wrap NamoAdsController directly rather than using this proxy object.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NamoAdsController;
@class NamoTargeting;

@interface NamoAdsControllerProxy : NSObject<UITableViewDataSource, UITableViewDelegate>

// Initializes the object as a proxy for the given table view controller and namo ads controller.
- (id)initForController:(UITableViewController *)controller
           adController:(NamoAdsController *)adController;

// Requests ads with the given targeting params. Pass nil to return ads with no targeting.
- (void)requestAdsWithTargeting:(NamoTargeting *)targeting;
@end