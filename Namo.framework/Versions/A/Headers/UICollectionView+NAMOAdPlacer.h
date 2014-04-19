//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol NAMOAdFormat;
@protocol UICollectionViewDataSource;
@protocol UICollectionViewDelegate;
@class NAMOCollectionViewAdPlacer;

/**
 A helper category that makes a number of methods available on `UICollectionView` that are
 convenient for dealing with the modified `NSIndexPath`s for the view's items.
 
 These methods are available after binding a `UICollectionView` to the `NAMOAdPlacer`, which
 replaces the `dataSource` and `delegate` properties of the `UICollectionView`.
 
 After binding to a `NAMOAdPlacer`, you should replace calls to your collection view's methods with
 the namo_ prefixed version. For example: `[collectionView reloadData]` should be replaced by
 `[collectionView namo_reloadData]`.

 @available Namo 1.0 and later.
 */
@interface UICollectionView (NAMOCollectionViewAdPlacer)

/// @name Getting an Ad Placer

/**
 Returns the ad placer currently bound to this collection view.

 Without an ad placer, other methods on this class have undefined behavior, and will generate a
 warning log message.

 @return The ad placer bound to this collection view.
 @available Namo 1.0 and later.
*/
- (NAMOCollectionViewAdPlacer *)namo_adPlacer;


/// @name Proxying Collection View Methods

/**
 Sets the collection view data source.

 If you are using a UICollectionViewAdPlacer and need to set the collection view data source,
 use this method, which will inform the underlying placer of the new data source.

 If you want to detach the ad placer, use `NAMOCollectionViewAdPlacer dismiss` instead.

 @param dataSource The new collection view data source.
 @available Namo 1.0 and later.
*/
- (void)namo_setDataSource:(id<UICollectionViewDataSource>)dataSource;

/**
 Returns the original collection view data source before being bound to an an placer.

 If you need to access the original data source in your code, use this method instead of
 `collectionView dataSource`.

 @return The original collection view data source.
 @available Namo 1.0 and later.
*/
- (id<UICollectionViewDataSource>)namo_dataSource;

/**
 Sets the collection view delegate.

 If you are using a UICollectionViewDelegate and need to set the collection view delegate,
 use this method, which will inform the underlying placer of the new delegate.

 If you want to detach the ad placer, use `NAMOCollectionViewAdPlacer dismiss` instead.

 @param delegate The new collection view delegate.
 @available Namo 1.0 and later.
*/
- (void)namo_setDelegate:(id<UICollectionViewDelegate>)delegate;

/**
 Returns the original collection view delegate before being bound to an ad placer.

 If you need to access the original data source in your code, use this method instead of
 `collectionView delegate`.

 @return The original collection view delegate.
 @available Namo 1.0 and later.
*/
- (id<UICollectionViewDelegate>)namo_delegate;

/**
 Dequeues a UICollectionViewCell.

 After binding to a `NAMOCollectionViewAdPlacer`, you must replace all calls to
 `[collectionView dequeueReusableCellWithReuseIdentifier: forIndexPath:]` with a call to this
 method. Otherwise an ad format cell and content cell may be placed in the same position on the
 screen by the UICollectionViewLayout.

 @param reuseIdentifier The reuse identifier associated with this cell.
 @param indexPath The index path passed to a UICollectionViewDataSource's `cellForItemAtIndexPath`
     method. The data source should just pass this on without modification.
 @return A UICollectionViewCell instance for the given reuse identifier.
 @available Namo 1.0 and later.
*/
- (UICollectionViewCell *)namo_dequeueReusableCellWithReuseIdentifier:(NSString *)reuseIdentifier
                                                         forIndexPath:(NSIndexPath *)indexPath;

/**
 Reloads the items and sections of your collection view, and informs the attached ad placer that the item
 count may have changed.
 
 You must replace any calls to `collectionView reloadData` with this method for a UICollectionView
 bound to an ad placer. Otherwise the placer will attempt to place items into your collection
 based on what the previous item counts, which might cause an InternalConsistency error when
 performing certain operations on your collection view, such as deleting items.
 
 @available Namo 1.0 and later.
 */
- (void)namo_reloadData;

/**
 Returns the visible cell object at the specified index path.

 You must replace any calls to `collectionView cellForItemAtIndexPath` with this method for a UICollectionView
 bound to an ad placer. Otherwise you may access Ad Cell objects when you intend to access your app data.

 @param originalIndexPath The index path that specifies the section and item number of the cell.
 @return The cell object corresponding to the index path or `nil` if the cell is not visible or `indexPath` is out of range.
 @available Namo 3.0 and later.
*/
- (UICollectionViewCell *)namo_cellForItemAtIndexPath:(NSIndexPath *)originalIndexPath;

/**
 Insert items in the receiver at the locations identified by an array of index paths. This will
 notify the ad placer of the new items so that it can adjust ad positioning.
 
 You must replace all calls to `[collectionView insertItemsAtIndexPaths:]` with this method for a 
 `UICollectionView` bound to an ad placer. Otherwise you may receive
 `NSInternalInconsistencyException` errors.

 @param originalIndexPaths An array of NSIndexPath identifying the item locations to add.
 @available Namo 1.0 and later.
 */
- (void)namo_insertItemsAtIndexPaths:(NSArray *)originalIndexPaths;

/**
 Delete items in the receiver at the locations identified by an array of index paths. This will
 notify the ad placer of the deleted items so that it can adjust ad positioning.
 
 You must replace all calls to `[collectionView deleteItemsAtIndexPaths:]` with this method for a
 `UICollectionView` bound to an ad placer. Otherwise you may receive
 `NSInternalInconsistencyException` errors.

 @param originalIndexPaths An array of NSIndexPath identifying the items to delete.
 @available Namo 1.0 and later.
 */
- (void)namo_deleteItemsAtIndexPaths:(NSArray *)originalIndexPaths;

/**
 Deselect the item at the given original index path.

 You must replace all calls to `[collectionView deselectItemAtIndexPath:animated:]` with this
 method for a `UICollectionView` bound to an ad placer.
 
 @param originalIndexPath the index path of the row to deselect.
 @param animated Specify YES to animate the change in selection.
 @available Namo 1.0 or later.
 */
- (void)namo_deselectItemAtIndexPath:(NSIndexPath *)originalIndexPath animated:(BOOL)animated;

/**
 Move items in the receiver from the index path in the first argument to the index path specified
 by newIndexPath.
 
 You must replace all calls to `[collectionView moveItemAtIndexPaths:toIndexPath:]` with this method
 for a `UICollectionView` bound to an ad placer. Otherwise you may receive
 `NSInternalInconsistencyException` errors.

 @param originalIndexPath The index path at which the item currently exists.
 @param newIndexPath The index path to move the item to.
 @available Namo 1.0 or later.
*/
- (void)namo_moveItemAtIndexPath:(NSIndexPath *)originalIndexPath
                     toIndexPath:(NSIndexPath *)newIndexPath;

/**
 Returns the layout information for the item at the specified index path.

 You must replace all calls to `[collectionView layoutAttributesForItemAtIndexPaths:toIndexPath:]` with this method
 for a `UICollectionView` bound to an ad placer.

 @param originalIndexPath The index path of the item.
 @return The layout attributes for the item or `nil` if no item exists at the specified path.
 @available Namo 3.0 and later.
*/
- (UICollectionViewLayoutAttributes *)namo_layoutAttributesForItemAtIndexPath:(NSIndexPath *)originalIndexPath;

/**
 Reload items in the receiver at the locations specified in the array of index paths.
 
 You must replace all calls to `[collectionView reloadItemsAtIndexPaths:]` with this method for a
 `UICollectionView` bound to an ad placer.

 @param indexPaths An array of NSIndexPath identifying items to reload.
 @available Namo 1.0 and later.
 */
- (void)namo_reloadItemsAtIndexPaths:(NSArray *)indexPaths;

/**
 Selects the item at the specified original index path and optionally scrolls it into view.
 
 You must replace all calls to `[collectionView selectItemsAtIndexPath:animated:scrollPosition:]` 
 with this method for a `UICollectionView` bound to an ad placer.
 
 @param originalIndexPath The index path of the row to select. If you get the index path from a
 collectionView method you should call [indexPathAdjuster originalIndexPath:] to get the value to
 use in this method.

 @param animated Specify YES to animate the change in the selection or NO to make the change without
 animating it.
 @param scrollPosition An option that specifies where the item should be positioned when scrolling
 finishes. For a list of possible values, see `UICollectionViewScrollPosition`.
 @available Namo 1.0 and later.
*/
- (void)namo_selectItemAtIndexPath:(NSIndexPath *)originalIndexPath
                          animated:(BOOL)animated
                    scrollPosition:(UICollectionViewScrollPosition)scrollPosition;

/**
 Returns the original index paths for the selected items. Index paths for ads are not returned.

 You must replace all calls to `[collectionView indexPathsForSelectedItems]`
 with this method for a `UICollectionView` bound to an ad placer.

 @return An array of index paths for the selected items in the collection view.
 @available Namo 3.0 and later.
*/
- (NSArray *)namo_indexPathsForSelectedItems;

/**
 Returns the original index path for the given cell or nil if the cell is an ad cell.

 You must replace all calls to `[collectionView indexPathForCell]` with this method for a
 `UICollectionView` bound to an ad placer.

 @param cell a UICollectionViewCell
 @return The original index path for the cell.
 @available Namo 3.0 and later.
*/
- (NSIndexPath *)namo_indexPathForCell:(UICollectionViewCell *)cell;

/**
 Returns the original index paths for the visible items. Index paths for ads are not returned.

 You must replace all calls to `[collectionView indexPathsForVisibleItems]` with this method for a
 `UICollectionView` bound to an ad placer.

 @return An array of the original index paths for the visible items.
 @available Namo 3.0 and later.
*/
- (NSArray *)namo_indexPathsForVisibleItems;

/**
 Returns the original index path for the item at the point, or nil if the item is an ad or no point
 is found.

 You must replace all calls to `[collectionView indexPathForItemAtPoint]` with this method for a
 `UICollectionView` bound to an ad placer.

 @param point A CGPoint that represents a spot on the screen.
 @return The original index path for the item at the point.
 @available Namo 3.0 and later.
*/
- (NSIndexPath *)namo_indexPathForItemAtPoint:(CGPoint)point;

/**
 Scrolls the collection view contents until the specified item is visible.

 You must replace all calls to `[collectionView scrollToItemAtIndexPath: atScrollPosition: animated:]` with this method for a
 `UICollectionView` bound to an ad placer.

 @param originalIndexPath The index path of the item to scroll to.
 @param scrollPosition An option that specifies where the item should be positioned when scrolling finishes.
 @param animated Specify YES to animate the scrolling behavior or NO to adjust the scroll view’s visible content immediately.

 @available Namo 3.0 and later.
*/
- (void)namo_scrollToItemAtIndexPath:(NSIndexPath *)originalIndexPath
                    atScrollPosition:(UICollectionViewScrollPosition)scrollPosition
                            animated:(BOOL)animated;
@end
