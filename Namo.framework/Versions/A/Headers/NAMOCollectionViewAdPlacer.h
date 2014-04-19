// Copyright (c) 2014 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOAd.h"

@class NAMOTargeting;
@class NAMOCollectionViewAdPlacer;

/**
 This class allows you to request Ads from the Namo server and easily place them into a
 UICollectionView object.

 Usage:
   self.adPlacer = [NAMOCollectionViewAdPlacer placerForCollectionView:self.collectionView];
   [self.adPlacer registerAdFormat:ExampleAdView.class];
   [self.adPlacer requestAdsWithTargeting:nil];

 The implementation works by replacing the data source of your collection view
 in order to insert Ads and adjust the positions of your regular content.  If you would prefer to
 do your own ad placement, you can use a NAMOCustomStreamAdPlacer object instead, along with
 NAMOPositionAdjuster.

 _Important:_ After binding to an Ad Placer, you must replace calls to your collection view's
 methods with a `namo` prefixed version. For example, `[collectionView reloadData]` should be
 replaced by `[collectionView namo_reloadData]`.

 You can control Ad positions from your Namo Ad dashboard at https://dashboard.namomedia.com/.

 @available Namo 3.0 and later.
*/
@interface NAMOCollectionViewAdPlacer : NSObject

/// @name Creating an Ad Placer

/**
 Creates and returns an Ad placer that will insert Ads into a collection view.

 If your UICollectionView object contains multiple sections, the placer will insert Ads into just
 the first section.

 @param collectionView The collection view into which to insert Ads.
 @return The new collection view Ad placer.
 @available Namo 3.0 and later.
 */
+ (NAMOCollectionViewAdPlacer *)placerForCollectionView:(UICollectionView *)collectionView;

/**
 Creates and returns an Ad placer that will insert Ads into a collection view.

 If your UICollectionView object contains multiple sections, the placer will insert Ads into just
 the first section.

 If your app uses app sections to provide more granular ad targeting and reporting, you should use
 this method to create your ad placer.

 @param collectionView The collection view into which to insert Ads.
 @param adUnitId The id of the ad unit this placer inserts ads into. The id can be
 found in the Namo Media Dashboard.
 @return The new collection view Ad placer.
 @available Namo 3.0 and later.
 */
+ (NAMOCollectionViewAdPlacer *)placerForCollectionView:(UICollectionView *)collectionView
                                               adUnitId:(NSString *)adUnitId;

/**
 Creates and returns an Ad placer that will insert Ads into a specified section of a collection
 view.

 @param collectionView The collection view into which to insert Ads.
 @param section The section into which to insert Ads.
 @return The new collection view Ad placer.
 @available Namo 3.0 and later.
 */
+ (NAMOCollectionViewAdPlacer *)placerForCollectionView:(UICollectionView *)collectionView
                                                section:(NSUInteger)section;

/**
 Creates and returns an Ad placer that will insert Ads into a specified section of a collection
 view.

 If your app uses app sections to provide more granular ad targeting and reporting, you should use
 this method to create your ad placer.

 @param collectionView The collection view into which to insert Ads.
 @param section The section into which to insert Ads.
 @param adUnitId The id of the ad unit this placer inserts ads into. The id can be found in the
  Namo Media Dashboard.
 @return The new collection view Ad placer.
 @available Namo 3.0 and later.
 */
+ (NAMOCollectionViewAdPlacer *)placerForCollectionView:(UICollectionView *)collectionView
                                                section:(NSUInteger)section
                                               adUnitId:(NSString *)adUnitId;

/// @name Registering an Ad Format

/**
 Registers an Ad format for displaying Ads.

 Registering an Ad format allows this placer to create an Ad with the given format. You must
 register a format before you request Ads. The format class must conform to the NAMOAdFormat
 protocol.

 You can optionally use the pre-configured NAMOAdFormat classes
 provided by Namo if you want the default Ad formats to show up instead of making your own custom
 ones. For example:

  `[self.adPlacer registerAdFormat:NAMOAdFormatSample6.class];`

 If you register multiple formats, the SDK will choose which format to use for a given Ad by
 dynamically determining how well the Ad's image and text match the image and label sizes of your
 format. To extend your ability to show different types of Ads, you should consider registering at
 least 2 formats, including a format with a large photo and short text, as well as a format with a
 thumbnail image and longer text. See NAMOAdFormatSample1 and NAMOAdFormatSample2 for examples.

 @param formatClass The class to register.
 @available Namo 3.0 and later.
*/
- (void)registerAdFormat:(Class)formatClass;


/// @name Receiving delegate events

/**
 The object assigned to this property will be notified of events in the ad request cycle as
 described in the documentation for the NAMOAdPlacerDelegate protocol.

 This is useful when you wish to be notified whether an ad request succeeds or not and whenever
 more ads become available.

 @available Namo 3.0 and later.
*/
@property(nonatomic, weak) id<NAMOAdPlacerDelegate> delegate;


/// @name Requesting Ads

/**
 Requests Ads from the server.

 Each call to request Ads will show a new set of Ads in your collection view. We recommend
 requesting Ads in your controller's viewWillAppear method so that each visit to your stream
 results in a new set of Ad impressions. You may also want to request Ads after your user
 performs an action that results in new stream items.

 Once Ads are returned from the server, the placer will call reloadItemsForIndexPaths for the
 visible items in your collection view, inserting ads if the first ad position is on the screen.
 To avoid this animated insertion, you can set the first ad position in the Namo Media dashboard
 so that it is off screen when the collection is loaded.

 If you aren't seeing Ads, try the following:
 <ol>
 <li>Put your device into 'test' mode.</li>
 <li>Check your device logs. The logs will tell you if you did something obvious, like failing
 to set an application key or not registering an Ad format.</li>
 <li>Check your network connection. We allow up to 2 seconds for the server to return Ads.</li>
 </ol>

 @see [Namo test mode]([Namo setTestDevices:includeSimulator:])</li>

 @param targeting Targeting information sent in the Ad request.
 @available Namo 3.0 and later.
 */
- (void)requestAdsWithTargeting:(NAMOTargeting *)targeting;


/// @name Dismissing

/**
 Dismisses the Ad placer from the collection view.

 This will completely remove the Ad placer from your collection view. This will restore the
 collection to its original datasource and delegate.

 @available Namo 3.0 and later.
*/
- (void)dismiss;


/// @name Adjusting index paths

/**
 Returns an index path adjusted based on ad placement in the stream.

 @param indexPath The original index path.
 @return The index path adjusted based on ad placement in the stream.
 @available Namo 3.0 and later.
 */
- (NSIndexPath *)adjustedIndexPath:(NSIndexPath *)indexPath;

/**
 Returns an array of index paths adjusted from the array of original index paths.

 @param indexPaths An array of original index paths.
 @return The array of adjusted index paths based on ad placement in the stream.
 @available Namo 1.0 and later.
*/
- (NSArray *)adjustedIndexPaths:(NSArray *)indexPaths;

/**
 Given an adjusted index path, returns the original index path.

 @param adjustedIndexPath The adjusted index path.
 @return The original index path.
 @available Namo 1.0 and later.
*/
- (NSIndexPath *)originalIndexPath:(NSIndexPath *)adjustedIndexPath;

/**
Given an array of adjusted index paths, returns the original index paths.

@param adjustedIndexPaths The adjusted index paths.
@return The original index paths. If any items in adjustedIndexPaths are index paths for ads, they
will not be returned and the array will be smaller.
@available Namo 2.0.1 and later.
*/
- (NSArray *)originalIndexPaths:(NSArray *)adjustedIndexPaths;


/// @name Determining ad positions

/**
 Returns a sorted array of index paths where ads have been inserted.

 @return An array of sorted ad positions, expressed as adjusted positions
 @available Namo 3.0 and later.
*/
- (NSArray *)adIndexPaths;

/**
 Returns YES if there is an ad at the given index path.

 @param indexPath The adjusted index path in your UITableView.
 @return YES if an ad has been dequeued at this position.
 @available Namo 3.0 and later
*/
- (BOOL)isAdAtIndexPath:(NSIndexPath *)indexPath;
@end
