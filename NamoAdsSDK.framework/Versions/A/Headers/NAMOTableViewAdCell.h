// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class NAMOAdData;


/**
 NAMOTableViewAdCell defines an interface for displaying an advertisement inside a table view.

 To customize the look of your cell, you will typically want your own implementation of this
 protocol. Look in the AdCellTemplates directory for examples.
 
 @available NamoAds 1.0 and later.
*/
@protocol NAMOTableViewAdCell

/// @name Reusing cells

/**
 A string used to identify the cell when inserting multiple ads into a table view.

 When you call `tableView registerAdCellClass:` this reuse identifier will be registered with the
 TableView, along with the ad placer associated with the table view.

 @return The string used to identify the cell when inserting multiple ads into a TableView.
 @available NamoAds 1.0 and later.
*/
+ (NSString *)reuseIdentifier;

/// @name Setting cell heights

/**
 The row height for a cell with the given ad data and layout width.

 This value is used by NAMOAdPlacer when providing a `UITableViewDelegate` to your table view in
 order to implement `tableView:heightForRowAtIndexPath:`.

 @param adData The data for an Ad returned from the server.
 @param width The width of the table cell.
 @return The row height for a cell with the given ad data and layout width.
 @available NamoAds 1.0 and later.
*/
+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width;

/// @name Filling ad data

/**
 Sets the ad data for this cell.

 This method should apply the ad cell data to your custom layout. At a minimum, we recommend
 displaying the ad image, ad title, and ad text.

 @param adData The ad data to render into the cell.
 @available NamoAds 1.0 and later.
*/
- (void)setAdData:(NAMOAdData *)adData;
@end