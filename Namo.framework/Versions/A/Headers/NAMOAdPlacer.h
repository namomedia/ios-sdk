// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NAMOTargeting;
@protocol NAMOAdPlacerDelegate;

/**
 This protocol serves as a common interface for requesting ads from the server and placing them
 into your stream.

 Ad positions are set by the Namo Media Ad Server and can be controlled by the app's owner at:
 https://dashboard.namomedia.com/

 @available Namo 1.0 and later.
*/
@interface NAMOAdPlacer : NSObject

/// @name Creating an ad placer

/**
 Creates and returns a new ad placer.
 
 @return The new ad placer.
 @available Namo 1.0 and later.
 */
+ (NAMOAdPlacer *)adPlacer;

/// @name Binding to a stream

/**
 Binds this placer to your table view.
 
 The placer will replace the tableView's delegate and dataSource objects with a proxy version
 that can insert ads into the stream according to your placement rules. In addition binding
 to a placer makes a number of new methods available on your UITableView that are convenient for
 dealing with the modified NSIndexPath's for your table rows. See UITableView+NAMOAdPlacer.h.
 
 A placer instance can only be bound to one table view. Calling bindToTableView on another table
 view results in the placer being removed from the original table view and the table view's original
 dataSource and delegate properties being restored. You can also bind to nil to remove a placer from
 a table view.
 
 @param tableView The table view to bind.
 @available Namo 1.0 and later.
 */
- (void)bindToTableView:(UITableView *)tableView;

/**
 Binds this placer to you collection view.
 
 The placer will replace the collectionView's delegate and dataSource objects with a proxy version
 that can insert ads into the stream according to your placement rules. In addition binding
 to a placer makes a number of new methods available on your UICollectionView that are convenient 
 for dealing with the modified NSIndexPath's for your items.
 See UICollectionView+NAMOAdPlacer.h.
 
 A placer instance can only be bound to one collection view. Calling bindToCollectionView on another
 collection view results in the placer being removed from the original collection view and the
 collection view's original dataSource and delegate properties being restored. You can also bind
 to nil to remove a placer from a collection view.
 
 @param collectionView The collection view to bind.
 @available Namo 1.0 and later.
 */
- (void)bindToCollectionView:(UICollectionView *)collectionView;

/// @name Requesting ads from the server

/**
 Call to request ads from the server.

 We recommend requesting ads in your controller's viewWillAppear method so that each
 visit to your stream results in a new set of ad impressions. You may also want to request
 ads after your user performs an action that results in new stream items.

 Once ads are returned from the server, the placer will call your TableView reloadData method
 to ensure that ads are displayed in your stream.

 @param targeting Targeting information sent in the ad request.
 @available Namo 1.0 and later.
 */
- (void)requestAds:(NAMOTargeting *)targeting;

/**
 Call to request ads from the server, with a callback.

 The callback will be called when the ad request completes, either successfully or with a
 failure. The placer may request additional ads as the user moves through the stream, in which case
 the callback may be called multiple times.

 @see requestAds:
 @param targeting Targeting information sent in the ad request.
 @param completedBlock Called when the ad request completes or fails. To avoid memory leaks, you
 should take care not to use strong references inside your block.
 @available Namo 2.3 and later.
 */
- (void)requestAds:(NAMOTargeting *)targeting
    completedBlock:(void (^)(NAMOAdPlacer *, NSError *))completedBlock;
@end
