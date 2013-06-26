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
// The number of items to show for each ad in this controller. Defaults to 5.
@property(nonatomic, assign) NSUInteger itemToAdRatio;

// Initializes the object as a proxy for the given table view controller and namo ads controller.
- (id)initForController:(UITableViewController *)controller
           adController:(NamoAdsController *)adController;

// Initialize the objet as a proxy for the given table view and namo ads controller as well as
// data source and delegate.
- (id)initWithTableView:(UITableView *)tableView
    tableViewDatasource:(NSObject<UITableViewDataSource> *)aDataSource
      tableViewDelegate:(NSObject<UITableViewDelegate> *)aDelegate
           adController:(NamoAdsController *)adController;

// Requests ads with the given targeting params. Pass nil to return ads with no targeting.
- (void)requestAdsWithTargeting:(NamoTargeting *)targeting;

// Call this if you are changing the number of rows in your table and want to also update the
// add positions. This also calls [tableView reloadData].
- (void)reloadData;

// Use this to inform the controller that a row were inserted manually. This will update ad indices.
- (void)insertRowsAtIndexPaths:(NSArray *)adjustedIndexPaths;

// Use this to inform the controller that a rows were deleted manually. This will update ad indices.
- (void)removeRowsAtIndexPaths:(NSArray *)adjustedIndexPaths;

// Use this to inform the controller that a row was moved. This will update ad indices.
- (void)moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath;

// Returns the index path of a table view adjusted for ads that should appear in stream.
- (NSIndexPath *)adjustedIndexPath:(NSIndexPath *)indexPath;

// Given an adjusted index path, returns the original index path in the table view.
- (NSIndexPath *)originalIndexPath:(NSIndexPath *)adjustedIndexPath;
@end