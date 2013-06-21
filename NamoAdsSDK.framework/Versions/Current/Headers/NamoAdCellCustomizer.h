//
// NamoAdCellCustomizer.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAdCellCustomizer class defines methods for customizing ad cells.
//

// TODO(nassar): Include some concept of ad type to allow differentiating between normal ads,
// install ads, gallery ads, etc.

#import <Foundation/Foundation.h>
#import "NamoAdCell.h"

@protocol NamoAdCellCustomizer<NSObject>
@required
// Should return a custom cell identifier for caching your cells. The SDK uses the standard
// UITableViewCell mechanism for reusing cells.
- (NSString *)customAdCellIdentifier;

@optional
// Implement this method to return a completely custom ad cell. Your cell should be initialized with
// the given identifier. If you simply wish to customize your layout, use
// layoutAdCell instead of implementing this method.
- (NamoAdCell *)createCustomAdCell:(NSString *)identifier;

// Implement this method to customize the layout of an ad cell. One common pattern is to change the
// layout for UIView properties defined by NamoAdCell. See NamoAdCellTemplates.h for methods
// you can use to help with layout of your cell.
- (void)layoutAdCell:(NamoAdCell *)cell;

// Implement this method to customize an ad cell based on the content of the ad.
- (void)fillAdCell:(NamoAdCell *)cell withAdContent:(NamoAd *)ad;

// Implement this method to customize the height of your table view cell. Default is
// NamoAdCellDefaultHeight.
- (CGFloat)adCellHeight;

// Implement this method to return the placeholder image for all ad image views while downloading
// from the server.
- (UIImage *)placeHolderImage;
@end
