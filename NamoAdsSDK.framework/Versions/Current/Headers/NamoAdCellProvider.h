//
// NamoAdCellProvider.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAdCellProvider class defines methods for creating Ad cells and providing them
// to the NamoAdsController on demand.
//

#import <Foundation/Foundation.h>

@class NamoAdContentBinder;

@protocol NamoAdCellProvider<NSObject>
// Returns the cell identifier to use when reusing cells. The SDK uses the default
// UITableView caching mechanism for caching cells.
- (NSString *)adCellIdentifier;

// Returns a newly allocated and initialized ad cell. Called if the table view is
// unable to return a cached cell.
- (UITableViewCell *)createAdCell;

// You must implement this method to fill the ad cell with ad content. Use the binder messages
// fillCellContent and bindCellInteractions to fill your native ad format ad setup interactive
// behaviors.
- (void)shouldFillAdCell:(UITableViewCell *)tableViewCell usingBinder:(NamoAdContentBinder *)binder;

// Returns the height of the table view cell.
- (CGFloat)adCellHeight;

@optional
// For expandable ad cells returns the height of the table view cell when expanded.
- (CGFloat)expandedAdCellHeight;

// Returns the placeholder image for any ad image views.
- (UIImage *)placeHolderImage;
@end
