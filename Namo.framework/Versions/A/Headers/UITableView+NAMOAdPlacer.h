// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NAMOIndexPathAdjuster;
@protocol NAMOAdCell;
@protocol UITableViewDataSource;
@protocol UITableViewDelegate;

/**
 A helper category that makes a number of methods available on your `UITableView` that
 are convenient for dealing with the modified `NSIndexPath`s for your table rows.

 These methods are available after binding a `UITableView` to your a NAMOAdPlacer, which causes the
 `dataSource` and `delegate` properties of your `UITableView` to be replaced.

 Providing these methods directly on your `UITableView` makes it easy to do directly replace calls to
 your table view with Namo provided objects. For example, you should replace calls to
 `[tableView reloadData]` with calls to `[tableView namo_reloadData]`, which informs the ad placer that
 the number of rows in your table may have changed.

 @available Namo 1.0 and later.
*/
@interface UITableView (NAMOAdPlacer)

/// @name Getting an Associated Ad Placer

/**
 Returns the ad placer currently bound to this table.

 Without an ad placer, other methods on this class have undefined behavior, and will generate a
 warning log message.

 @return The ad placer currently bound to this table, or `nil`.
 @available Namo 1.0 and later.
*/
- (NAMOAdPlacer *)namo_adPlacer;

/**
 Returns the index path adjuster for this table. See `NAMOIndexPathAdjuster`.

 @return The index path adjuster for this table, or `nil` if there is none.
 @available Namo 1.0 and later.
*/
- (NAMOIndexPathAdjuster *)namo_indexPathAdjuster;

/// @name Registering an Ad Cell

/**
 Registers an ad cell class for this table.

 This method registers the ad cell class for table using the ad cells reuse identifier, and also
 registers the class with the attached ad placer. You must call this method before you table view
 will display ads.
 
 The Ad cell class must be a subclass of UITableViewCell and conform to the NAMOAdCell protocol.
 
 You can optionally use the pre-configured NAMOAdCellTableSample2 and NAMOAdCellTableSample1 classes
 provided by Namo if you want the default ad formats to show up instead of making your own custom ones.
 In that case, just call
 
  `[self.tableView namo_registerAdCellClass:[NAMOAdCellTableSample1 class]];`
 
 @param cellClass The class to register.
 @available Namo 1.0 and later.
*/
- (void)namo_registerAdCellClass:(Class)cellClass;

/// @name Proxying Table View Methods

/**
 Sets the table view data source.

 If you need to to set the table view data source AFTER binding to an ad placer, use this method,
 which will inform the underlying placer of the new data source.

 If you want to detach the ad placer, use `NAMOAdPlacer bindToTableView:nil` instead.

 @param dataSource The new table view data source.
 @available Namo 1.0 and later.
*/
- (void)namo_setDataSource:(id<UITableViewDataSource>)dataSource;

/**
 Returns the original table view data source before being bound to an an placer.

 If you need to access the original data source in your code, use this method instead of
 `tableView dataSource`.

 @return The original table view data source.
 @available Namo 1.0 and later.
*/
- (id<UITableViewDataSource>)namo_dataSource;

/**
 Sets the table view delegate.

 If you need to to set the table view delegate AFTER binding to an ad placer, use this method,
 which will inform the underlying placer of the new delegate.

 If you want to detach the ad placer, use `NAMOAdPlacer bindToTableView:nil` instead.

 @param delegate The new table view delegate.
 @available Namo 1.0 and later.
*/
- (void)namo_setDelegate:(id<UITableViewDelegate>)delegate;

/**
 Returns the original table view delegate before being bound to an ad placer.

 If you need to access the original data source in your code, use this method instead of
 `tableView delegate`.

 @return The original table view delegate.
 @available Namo 1.0 and later.
*/
- (id<UITableViewDelegate>)namo_delegate;

/**
 Reloads the rows and sections of your table view, and informs the attached ad placer that the row
 count may have changed.

 You must replace any calls to `tableView reloadData` with this method for a TableView bound to an
 ad placer. Otherwise the placer will attempt to place rows into your table based on what the previous
 row counts, which might cause an InternalConsistency error when performing certain operations on
 your table view, such as deleting rows.

 @available Namo 1.0 and later.
*/
- (void)namo_reloadData;

/**
 Deselect the row at the given original index path.
 
 You must replace all calls to `[tableView deselectRowAtIndexPath:animated:]` with this
 method for a `UITableView` bound to an ad placer.
 
 @param indexPath The index path of the row to deselect.
 @param animated Specify YES to animate the change in selection.
 @available Namo 1.0 and later.
 */
- (void)namo_deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

/**
 Inserts rows in the receiver at the locations identified by an array of index paths, and informs
 the attached ad placer of the insertions.

 You must replace calls to `tableView insertRowsAtIndexPaths` with this method for a `UITableView` bound
 to an ad placer. Otherwise you may receive `NSInternalInconsistencyException` errors.

 @param adjustedIndexPaths An array of NSIndexPath objects each representing a row index and
     section index that together identify a row in the table view.
 @param animation A constant that either specifies the kind of animation to perform when inserting.
 @available Namo 1.0 and later.
*/
- (void)namo_insertRowsAtIndexPaths:(NSArray *)adjustedIndexPaths
                   withRowAnimation:(UITableViewRowAnimation)animation;

/**
 Deletes rows in the receiver at the locations identified by an array of index paths, and informs
 the attached ad placer of the deletions.

 You must replace calls to `tableView deleteRowsAtIndexPaths` with this method for a `UITableView` bound
 to an ad placer. Otherwise you may receive `NSInternalInconsistencyException` errors.

 @param adjustedIndexPaths An array of NSIndexPath objects identifying the rows to delete.
 @param animation A constant that indicates how the deletion is to be animated.
 @available Namo 1.0 and later.
*/
- (void)namo_deleteRowsAtIndexPaths:(NSArray *)adjustedIndexPaths
                   withRowAnimation:(UITableViewRowAnimation)animation;

/**
 Moves the row at a specified location to a destination location, taking into account ads provided
 by the ad placer.

 You must replace calls to `tableView moveRowAtIndexPath` with this method for a UITableView bound
 to an ad placer. Otherwise you may receive `NSInternalInconsistencyException` errors.

 @param indexPath An index path identifying the row to move.
 @param newIndexPath An index path identifying the row that is the destination of the row at
     indexPath.
 @available Namo 1.0 and later.
*/
- (void)namo_moveRowAtIndexPath:(NSIndexPath *)indexPath
                    toIndexPath:(NSIndexPath *)newIndexPath;

/**
 Reloads the specified rows using the given animation effect, and informs that attached ad placer
 that the row positions may have changed.

 @param adjustedIndexPaths An array of `NSIndexPath` objects identifying the rows to reload.
 @param animation A constant that indicates how the reloading is to be animated.
 @available Namo 1.0 and later.
*/
- (void)namo_reloadRowsAtIndexPaths:(NSArray *)adjustedIndexPaths
                   withRowAnimation:(UITableViewRowAnimation)animation;

/**
 Selects the row at the specified original index path and optionally scrolls it into view.
 
 You must replace all calls to `[tableView selectItemsAtIndexPath:animated:scrollPosition:]`
 with this method for a `UITableView` bound to an ad placer.
 
 @param indexPath the index path of the row to select.
 @param animated Specify YES to animate the change in the selection or NO to make the change
 without animating it.
 @param scrollPosition An option that specifies where the row should be positioned when scrolling
 finishes. For a list of possible values, see `UITableViewScrollPosition`.
 @available Namo 1.0 and later.
 */
- (void)namo_selectRowAtIndexPath:(NSIndexPath *)indexPath
                         animated:(BOOL)animated
                   scrollPosition:(UITableViewScrollPosition)scrollPosition;
@end
