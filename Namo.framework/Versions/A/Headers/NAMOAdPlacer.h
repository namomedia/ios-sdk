// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NAMOTargeting;

/**
 This protocol serves as a common interface for requesting ads from the server and placing them
 into your stream.

 To change ad placement use the `setAdPlacement` method. If you do not specify ad placement,
 Namo will place ads at default locations. In version 1.0, this is a first position of 6, spacing
 of 6, and maximum number of ads of 10. This is subject to change in future version of the SDK.

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

/// @name Setting ad placement

/**
 Sets the ad placement for all sections.

 Calling this method resets any section specific placement you have set up using
 setAdPlacementForSection:section:firstPosition:spacing:maxAds.

 @param firstPosition The zero based first position within a section at which to show an ad.
 @param spacing The spacing between subsequent ads. This is the number of regular cells for each
     ad cell.
 @param maxAds The maximum number of ads to display.
 @available Namo 1.0 and later.
*/
- (void)setAdPlacementWithFirstPosition:(NSUInteger)firstPosition
                                spacing:(NSUInteger)spacing
                                 maxAds:(NSUInteger)maxAds;

/**
 Sets ad placement for a specific section.

 Calling this method removes any global placement you have set up using
 setAdPlacementWithFirstPosition:spacing:maxAds.

 @param section The section for which to set placement information.
 @param firstPosition The zero based first position within the section at which to show an ad.
 @param spacing The spacing between subsequent ads. This is the number of regular cells for each
     ad cell.
 @param maxAds The maximum number of ads to display.
 @available Namo 1.0 and later.
*/
- (void)setAdPlacementForSection:(NSUInteger)section
                   firstPosition:(NSUInteger)firstPosition
                         spacing:(NSUInteger)spacing
                          maxAds:(NSUInteger)maxAds;

/// @name Requesting ads from the server

/**
 Call to request ads from the server.

 We recommend requesting ads in your controller's viewWillAppear method so that each
 visit to your stream results in a new set of ad impressions. You may also want to request
 ads after users perform an action that results in new stream items.

 Once ads are returned from the server, the placer will call your TableView reloadData method
 to ensure that ads are displayed in your stream.

 @param targeting Targeting information sent in the ad request.
 @available Namo 1.0 and later.
 */
- (void)requestAds:(NAMOTargeting *)targeting;
@end
