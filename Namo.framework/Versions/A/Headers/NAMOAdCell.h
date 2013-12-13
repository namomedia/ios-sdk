// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

@class NAMOAdData;


/**
 NAMOAdCell defines an interface for displaying an advertisement inside a table view.

 To customize the look of your cell, you will typically want your own implementation of this
 protocol. Look in the AdCellTemplates directory for examples.
 
 @available Namo 1.0 and later.
*/
@protocol NAMOAdCell

/// @name Initializing a NAMOAdCell Object

/**
 Returns a new instance of the cell.

 @return A new instance of the cell.
 @available Namo 1.0 and later.
*/
+ (id)alloc;

/// @name Reusing cells

/**
 A string used to identify the cell when inserting multiple ads into a table view.

 When you call `tableView registerAdCellClass:`, this reuse identifier will be registered with the
 TableView, along with the ad placer associated with the table view.

 @return The string used to identify the cell when inserting multiple ads into a TableView.
 @available Namo 1.0 and later.
*/
+ (NSString *)reuseIdentifier;


/// @name Filling ad data

/**
 Sets the ad data for this cell.
 
 This method should apply the ad cell data to your custom layout. At a minimum, you are required
 to display the ad image and ad text.

 @param adData The ad data to render into the cell.
 @available Namo 1.0 and later.
 */
- (void)setAdData:(NAMOAdData *)adData;

/// @name Setting cell sizes

@optional
/**
 The row height for a cell with the given ad data and layout width.

 This value is used by NAMOAdPlacer when providing a `UITableViewDelegate` to your table view in
 order to implement `tableView:heightForRowAtIndexPath:`. If you do not implement this method, a
 default height of 100.0f will be used.

 @param adData The data for an Ad returned from the server.
 @param width The width of the table cell.
 @return The row height for a cell with the given ad data and layout width.
 @available Namo 1.0 and later.
*/
+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width;

/**
 The size for a cell with the given ad data.
 
 This value is used by NAMOAdPlacer when your collection view calls
 `collectionView:flowLayout:sizeForItemAtIndexPath:` on its delegate. If you do not implement this,
 a default size of CGSizeMake(150.0f, 100.0f) will be used.
 
 @param adData The data for an Ad returned from the server.
 @return The cell size for a cell of this class with the given data.
 @available Namo 1.0 and later.
*/
+ (CGSize)cellSizeWithData:(NAMOAdData *)adData;

@end