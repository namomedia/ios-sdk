// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol NAMOAdFormat;
@protocol UITableViewDataSource;
@protocol UITableViewDelegate;

/**
 A helper category that makes a number of methods available on your `UITableView` that
 are convenient for dealing with the modified `NSIndexPath`s for your table rows.

 These methods are available after binding a `UITableView` to your Ad Placer, which causes the
 `dataSource` and `delegate` properties of your `UITableView` to be replaced.

 Providing these methods directly on your `UITableView` makes it easy to do directly replace calls
 to your table view with Namo provided objects. For example, you should replace calls to
 `[tableView reloadData]` with calls to `[tableView namo_reloadData]`, which informs the ad placer
 that the number of rows in your table may have changed.

 @available Namo 1.0 and later.
*/
@interface UITableView (NAMOTableViewAdPlacer)

/// @name Getting an Associated Ad Placer

/**
 Returns the ad placer currently bound to this table.

 Without an ad placer, other methods on this class have undefined behavior, and will generate a
 warning log message.

 @return The ad placer currently bound to this table, or `nil`.
 @available Namo 1.0 and later.
*/
- (NAMOTableViewAdPlacer *)namo_adPlacer;

/// @name Proxying Table View Methods

/**
 Returns the original table view data source before being bound to an an placer.

 If you need to access the original data source in your code, use this method instead of
 `tableView dataSource`.

 @return The original table view data source.
 @available Namo 1.0 and later.
*/
- (id<UITableViewDataSource>)namo_dataSource;

/**
 Sets the table view data source.

 If you are using a UITableViewAdPlacer and need to set the table view data source,
 use this method, which will inform the underlying placer of the new data source.
 If you want to detach the ad placer, use `NAMOTableViewAdPlacer dismiss` instead.

 @param dataSource The new table view data source.
 @available Namo 1.0 and later.
*/
- (void)namo_setDataSource:(id<UITableViewDataSource>)dataSource;

/**
 Returns the original table view delegate before being bound to an ad placer.

 If you need to access the original data source in your code, use this method instead of
 `tableView delegate`.

 @return The original table view delegate.
 @available Namo 1.0 and later.
*/
- (id<UITableViewDelegate>)namo_delegate;

/**
 Sets the table view delegate.

 If you are using a UITableViewAdPlacer and need to set the table view delegate,
 use this method, which will inform the underlying placer of the new delegate.

 If you want to detach the ad placer, use `NAMOTableViewAdPlacer dismiss` instead.

 @param delegate The new table view delegate.
 @available Namo 1.0 and later.
*/
- (void)namo_setDelegate:(id<UITableViewDelegate>)delegate;

/**
 Reloads the rows and sections of your table view, and informs the attached ad placer that the row
 count may have changed.

 You must replace any calls to `tableView reloadData` with this method for a TableView bound to an
 ad placer. Otherwise the placer will attempt to place rows into your table based on what the
 previous row counts, which might cause an InternalConsistency error when performing certain
 operations on your table view, such as deleting rows.

 @available Namo 1.0 and later.
*/
- (void)namo_reloadData;

/**
 Deselect the row at the given original index path.

 You must replace all calls to `[tableView deselectRowAtIndexPath:animated:]` with this
 method for a `UITableView` bound to an ad placer.

 @param indexPath the index path of the row to deselect.
 @param animated Specify YES to animate the change in selection.
 @available Namo 1.0 and later.
 */
- (void)namo_deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

/**
 Inserts rows in the receiver at the locations identified by an array of index paths, and informs
 the attached ad placer of the insertions.

 You must replace calls to `tableView insertRowsAtIndexPaths` with this method for a `UITableView`
 bound to an ad placer. Otherwise you may receive `NSInternalInconsistencyException` errors.

 @param originalIndexPaths An array of NSIndexPath that represent rows to insert into the table.
 @param animation A constant that either specifies the kind of animation to perform when inserting.
 @available Namo 1.0 and later.
*/
- (void)namo_insertRowsAtIndexPaths:(NSArray *)originalIndexPaths
                   withRowAnimation:(UITableViewRowAnimation)animation;

/**
 Returns the table cell at the specified index path.

 You must replace calls to `tableView cellForRowAtIndexPath` with this method for a `UITableView`
 bound to an ad placer. Otherwise you may receive `NSInternalInconsistencyException` errors.

 @param originalIndexPath The index path locating the row in the receiver.
 @return An object representing a cell of the table or `nil` if the cell is not visible or `indexPath` is out of range.
 @available Namo 3.0 and later.
*/
- (UITableViewCell *)namo_cellForRowAtIndexPath:(NSIndexPath *)originalIndexPath;

/**
 Deletes rows in the receiver at the locations identified by an array of index paths, and informs
 the attached ad placer of the deletions.

 You must replace calls to `tableView deleteRowsAtIndexPaths` with this method for a `UITableView`
 bound to an ad placer. Otherwise you may receive `NSInternalInconsistencyException` errors.

 @param originalIndexPaths An array of NSIndexPath objects identifying the rows to delete.
 @param animation A constant that indicates how the deletion is to be animated.
 @available Namo 1.0 and later.
*/
- (void)namo_deleteRowsAtIndexPaths:(NSArray *)originalIndexPaths
                   withRowAnimation:(UITableViewRowAnimation)animation;

/**
 Moves the row at a specified location to a destination location, taking into account ads provided
 by the ad placer.

 You must replace calls to `tableView moveRowAtIndexPath:toIndexPath:` with this method for a UITableView bound
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

 @param originalIndexPaths An array of `NSIndexPath` objects identifying the rows to reload.
 @param animation A constant that indicates how the reloading is to be animated.
 @available Namo 1.0 and later.
*/
- (void)namo_reloadRowsAtIndexPaths:(NSArray *)originalIndexPaths
                   withRowAnimation:(UITableViewRowAnimation)animation;

/**
 Selects the row at the specified original index path and optionally scrolls it into view.

 You must replace all calls to `[tableView selectItemsAtIndexPath:animated:scrollPosition:]`
 with this method for a `UITableView` bound to an ad placer.

 @param originalIndexPath the index path of the row to select. If you get the index path from a
 tableView you should call [indexPathAdjuster originalIndexPath:] to get the value to use
 in this method.
 @param animated Specify YES to animate the change in the selection or NO to make the change
 without animating it.
 @param scrollPosition An option that specifies where the row should be positioned when scrolling
 finishes. For a list of possible values, see `UITableViewScrollPosition`.
 @available Namo 1.0 and later.
 */
- (void)namo_selectRowAtIndexPath:(NSIndexPath *)originalIndexPath
                         animated:(BOOL)animated
                   scrollPosition:(UITableViewScrollPosition)scrollPosition;

/**
 Scrolls the table view so that the selected row nearest to a specified position in the table view is at that position.

 You must replace all calls to `[tableView scrollToRowAtIndexPath: scrollPosition: animated:]`
 with this method for a `UITableView` bound to an ad placer.

 @param originalIndexPath An index path that identifies a row in the table view by its row index and
  its section index.
 @param scrollPosition A constant that identifies a relative position in the receiving table view (top, middle, bottom)
  for row when scrolling concludes. See “Table View Scroll Position” for descriptions of valid constants.
 @param animated YES if you want to animate the change in position, NO if it should be immediate.
 @available Namo 3.0 and later.
*/
- (void)namo_scrollToRowAtIndexPath:(NSIndexPath *)originalIndexPath
                     scrollPosition:(UITableViewScrollPosition)scrollPosition
                           animated:(BOOL)animated;

/**
 Returns a reusable table-view cell object for the specified reuse identifier.

 You must replace all calls to `[tableView dequeueReusableCellWithIdentifier]` with this method for
 a UITableView bound to an ad placer.

 @param identifier A string identifying the cell object to be reused. This parameter must not be
 nil.
 @return A UITableViewCell object with the associated reuse identifier.

 @available Namo 3.0 and later.
*/
- (UITableViewCell *)namo_dequeueReusableCellWithIdentifier:(NSString *)identifier;

/**
 Returns a reusable table-view cell object for the specified reuse identifier.

 You must replace all calls to `[tableView dequeueReusableCellWithIdentifier:forIndexPath]` with
 this method for a UITableView bound to an ad placer.

 @param identifier A string identifying the cell object to be reused. This parameter must not be
 nil.
 @param indexPath The index path specifying the location of the cell. The data source receives this
 information when
 asked for the cell and should just pass it along.
 @return A UITableViewCell object with the associated reuse identifier.
 @available Namo 3.0 and later.
*/
- (UITableViewCell *)namo_dequeueReusableCellWithIdentifier:(NSString *)identifier
                                               forIndexPath:(NSIndexPath *)indexPath;

/**
 Returns the index path identifying the row and section of the selected row.

 In order to retrieve the original selected row before inserting ads, you should replace calls to
`[tableView indexPathForSelectedRow`] with this method for a `UITableView` bound to and ad placer.

@return  And index path identifying the row and section indexes of the selected row or `nil`.
*/
- (NSIndexPath *)namo_indexPathForSelectedRow;

/**
 Returns an array of the original index paths for the selected rows.

 You must replace all calls to `[tableView indexPathsForSelectedRows]` with this method for a
 UITableView bound to an ad placer.

 @return An array of the original index paths for the selected rows.
 @available Namo 3.0 and later.
*/
- (NSArray *)namo_indexPathsForSelectedRows;

/**
 Returns the original index paths for the visible items in the table view. Index paths for ad items
 are not returned.

 You must replace all calls to `[tableView indexPathsForVisibleRows]` with this method for a
 UITableView bound to an ad placer.

 @return An array of the original index paths for the visible rows.
 @available Namo 3.0 and later.
*/
- (NSArray *)namo_indexPathsForVisibleRows;

/**
 Returns the original index paths for the rows inside the given rect. Index paths for ad items are
 not returned.

 You must replace all calls to `[tableView indexPathsForRowsInRect]` with this method for a
 UITableView bound to an ad placer.

 @param rect A `CGRect` that represents an area on the screen.
 @return An array of the original index paths for the rows within the rect.
 @available Namo 3.0 and later.
*/
- (NSArray *)namo_indexPathsForRowsInRect:(CGRect)rect;

/**
 Returns the original index path for the row at the point. If this row is an ad object it will
 return nil. You must check the result of this  method.

 You must replace all calls to `[tableView indexPathForRowAtPoint]` with this method for a
 UITableView bound to an ad placer.

 @param point A `CGPoint` that represents a point on the screen.
 @return The original index path for a cell beneath this point, or nil if there is no cell or the
 cell is an ad.
 @available Namo 3.0 and later.
*/
- (NSIndexPath *)namo_indexPathForRowAtPoint:(CGPoint)point;

/**
 Returns the original index path for the given UITableViewCell. If the cell is an ad object,
 this method returns nil.

 You must replace all calls to `[tableView indexPathForCell]` with this method for a UITableView
 bound to an ad placer.

 @param cell A `UITableViewCell`
 @return The original index path of the cell.
 @available Namo 3.0 and later.
*/
- (NSIndexPath *)namo_indexPathForCell:(UITableViewCell *)cell;

@end
