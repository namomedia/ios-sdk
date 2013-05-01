//
// NamoAdCellProvider.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAdCellProvider class defines methods for creating Ad cells and providing them
// to the NamoAdsController on demand.
//

#import <Foundation/Foundation.h>
#import "NamoAdCell.h"

@protocol NamoAdCellProvider<NSObject>
@optional
// Returns the cell identifier to use when reusing cells. The SDK uses the default
// UITableView caching mechanism for caching cells. You must specify this if you
// implement createAdCellWithIdentifier.
- (NSString *)adCellIdentifier;

// Returns a newly allocated and initialized ad cell. Called if the table view is
// unable to return a cached cell.
- (NamoAdCell *)createAdCellWithIdentifier:(NSString *)identifier;

// Returns the height of the table view cell. Default is NamoAdCellDefaultHeight.
- (CGFloat)adCellHeight;

// For expandable ad cells returns the height of the table view cell when expanded.
// Default is NamoAdCellDefaultExpandedHeight.
- (CGFloat)expandedAdCellHeight;

// Implement this message to customize the setup of an ad cell. You can create custom
// layout here, or you can customize behavior by calling bindInteraction methods.
- (void)didSetupAdCell:(NamoAdCell *)cell;

// Implement this method to customize filling an ad cell using an ad item.
- (void)didFillAdCell:(NamoAdCell *)cell withAdContent:(NamoAd *)ad;

// Returns the placeholder image for any ad image views.
- (UIImage *)placeHolderImage;
@end
