//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NAMOIndexPathAdjuster;
@protocol NAMOAdCell;
@protocol UICollectionViewDataSource;
@protocol UICollectionViewDelegate;

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
@interface UICollectionView (NAMOAdPlacer)

/**
 Returns the ad placer currently bound to this table.

 Without an ad placer, other methods on this class have undefined behavior, and will generate a
 warning log message.

 @return The ad placer bound to this collection view.
 @available Namo 1.0 and later.
*/
- (NAMOAdPlacer *)namo_adPlacer;

/**
 Returns the index path adjuster for this collection view. See `NAMOIndexPathAdjuster`.
 
 @return The index path adjuster for this collection view, or `nil` if there is none.
 @available Namo 1.0 and later.
 */
- (NAMOIndexPathAdjuster *)namo_indexPathAdjuster;

/**
 Dequeues a UICollectionViewCell.
 
 After binding to a `NAMOAdPlacer`, you must replace all calls to
 `[collectionView dequeueReusableCellWithReuseIdentifier: forIndexPath:]` with a call to this method
 or an ad cell and content cell may be placed in the same position on the screen by the
 UICollectionViewLayout.
 
 @param reuseIdentifier The reuseIdentifier associated with this cell class.
 @param indexPath The index path passed to a UICollectionViewDataSource's `cellForItemAtIndexPath`
     method. The data source should just pass this on without modification.
 @return A UICollectionViewCell instance for the given reuse identifier.
 @available Namo 1.0 and later.
*/
- (UICollectionViewCell *)namo_dequeueReusableCellWithReuseIdentifier:(NSString *)reuseIdentifier
                                                         forIndexPath:(NSIndexPath *)indexPath;

/**
 Registers an ad cell class for this collection view.
 
 This method registers the ad cell class using the ad cells reuse identifier, and also registers
 the class with the attached ad placer. You must call this method before you collection view
 will display ads.
 
 The Ad cell class must be a subclass of UICollectionViewCell and conform to the NAMOAdCell protocol.
 
 @param cellClass The class to register.
 @available Namo 1.0 and later.
 */
- (void)namo_registerAdCellClass:(Class)cellClass;

/**
 Reloads the items and sections of your collection view, and informs the attached ad placer that the item
 count may have changed.
 
 You must replace any calls to `collectionView reloadData` with this method for a UICollectionView bound to an
 ad placer. Otherwise the placer will attempt to place items into your collection based on what the previous
 item counts, which might cause an InternalConsistency error when performing certain operations on
 your collection view, such as deleting items.
 
 @available Namo 1.0 and later.
 */
- (void)namo_reloadData;

/**
 Insert items in the receiver at the locations identified by an array of index paths. This will notify
 the ad placer of the new items so that it can adjust ad positioning.
 
 You must replace all calls to `[collectionView insertItemsAtIndexPaths:]` with this method for a 
 `UICollectionView` bound to an ad placer. Otherwise you may receive
 `NSInternalInconsistencyException` errors.

 @param indexPaths An array of NSIndexPath identifying the item locations to add.
 @available Namo 1.0 and later.
 */
- (void)namo_insertItemsAtIndexPaths:(NSArray  *)indexPaths;

/**
 Delete items in the receiver at the locations identified by an array of index paths. This will notify
 the ad placer of the deleted items so that it can adjust ad positioning.
 
 You must replace all calls to `[collectionView deleteItemsAtIndexPaths:]` with this method for a
 `UICollectionView` bound to an ad placer. Otherwise you may receive
 `NSInternalInconsistencyException` errors.

 @param indexPaths An array of NSIndexPath identifying the items to delete.
 @available Namo 1.0 and later.
 */
- (void)namo_deleteItemsAtIndexPaths:(NSArray *)indexPaths;

/**
 Move items in the receiver from the index path in the first argument to the index path specified
 by newIndexPath.
 
 You must replace all calls to `[collectionView moveItemAtIndexPaths:toIndexPath:]` with this method
 for a `UICollectionView` bound to an ad placer. Otherwise you may receive
 `NSInternalInconsistencyException` errors.

 @param indexPath The index path at which the item currently exists.
 @param newIndexPath The index path to move the item to.
 @available Namo 1.0 or later.
*/
- (void)namo_moveItemAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;

/**
 Reload items in the receiver at the locations specified in the array of index paths.
 
 You must replace all calls to `[collectionView reoladItemsAtIndexPaths:]` with this method for a 
 `UICollectionView` bound to an ad placer.

 @param indexPaths An array of NSIndexPath identifying items to reload.
 @available Namo 1.0 and later.
 */
- (void)namo_reloadItemsAtIndexPath:(NSArray *)indexPaths;
@end
