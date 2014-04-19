// Copyright (c) 2014 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NAMOTableViewAdPlacer;
@class NAMOTargeting;
@protocol NAMOAdPlacerDelegate;

/**
 This class allows you to request ads from the Namo server and easily place them into a UITableView
 object.

 The implementation works by replacing the data source of your table view
 in order to insert ads and adjust the positions of your regular content.  If you would prefer to
 do your own ad placement, you can use a NAMOCustomStreamAdPlacer object instead, along with
 NAMOPositionAdjuster.

 _Important:_ After binding to an Ad Placer, you must replace calls to your table view's methods
 with a `namo_` prefixed version. For example, `[collectionView reloadData]` should be replaced
 by `[collectionView namo_reloadData]`.

 You can control ad positions from your Namo ad dashboard at https://dashboard.namomedia.com/.

 @available Namo 3.0 and later.
*/
@interface NAMOTableViewAdPlacer : NSObject

/// @name Creating an Ad Placer

/**
 Creates and returns an ad placer that will insert ads into a table view.

 If your UITableView object contains multiple sections, the placer will insert ads into just the
 first section.

 @param tableView The table view into which to insert ads.
 @return The new table view ad placer.
 @available Namo 3.0 and later.
 */
+ (NAMOTableViewAdPlacer *)placerForTableView:(UITableView *)tableView;

/**
 Creates and returns an ad placer that will insert ads into a table view.

 If your UITableView object contains multiple sections, the placer will insert ads into just the
 first section.

 @param tableView The table view into which to insert ads.
 @param adUnitId The id of the ad unit this placer inserts ads into. The id can be found in
 the Namo Media Dashboard.
 @return The new table view ad placer.
 @available Namo 3.0 and later.
  */
+ (NAMOTableViewAdPlacer *)placerForTableView:(UITableView *)tableView
                                     adUnitId:(NSString *)adUnitId;

/**
 Creates and returns an ad placer that will insert ads into a specified section of a table view.

 @param tableView The table view into which to insert ads.
 @param section The section into which to insert ads.
 @return The new table view ad placer.
 @available Namo 3.0 and later.
 */
+ (NAMOTableViewAdPlacer *)placerForTableView:(UITableView *)tableView
                                      section:(NSUInteger)section;

/**
 Creates and returns an ad placer that will insert ads into a specified section of a table view.

 @param tableView The table view into which to insert ads.
 @param section The section into which to insert ads.
 @param adUnitId The id of the ad unit this placer inserts ads into. The id can be found in
 the Namo Media Dashboard.
 @return The new table view ad placer.
 @available Namo 3.0 and later.
 */
+ (NAMOTableViewAdPlacer *)placerForTableView:(UITableView *)tableView
                                      section:(NSUInteger)section
                                     adUnitId:(NSString *)adUnitId;

/// @name Registering an Ad Format

/**
 Registers an ad format for displaying ads.

 You must register a format for your table view before requesting ads. You can use one of the the
 pre-configured NAMOAdFormatSample classes provided in the SDK, or you can implement your own custom
 format. If you create a custom format, it must conform to the NAMOAdFormat protocol.

 If you register multiple formats, the SDK will choose which format to use for a given ad by
 dynamically determining how well the ad's image and text match the image and label sizes of your
 format. To extend your ability to show different types of ads, you should consider registering at
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


/// @name Requesting Ads from the Server

/**
 Requests ads from the server.

 Each call to request ads will show a new set of ads in your table view. We recommend requesting ads
 in your controller's viewWillAppear method so that each visit to your stream results in a new set
 of ad impressions. You may also want to request ads after your user performs an action that
 results in new stream items.

 Once ads are returned from the server, the placer will call reloadRowsAtIndexPaths for the visible rows in your
 table, inserting ads if any of their positions are visible on the screen. To avoid this animated insertion, you can set
 the first ad position in the Namo Media web dashboard so that it is off the screen when the table is loaded.

 If you aren't seeing ads, try the following:
 <ol>
 <li>Put your device into 'test' mode.</li>
 <li>Check your device logs. The logs will tell you if you did something obvious, like failing
 to set an application key or not registering an ad format.</li>
 <li>Check your network connection. We allow up to 2 seconds for the server to return ads.</li>
 </ol>

 @see [Namo test mode]([Namo setTestDevices:includeSimulator:])</li>

 @param targeting Targeting information sent in the ad request.
 @available Namo 3.0 and later.
 */
- (void)requestAdsWithTargeting:(NAMOTargeting *)targeting;

/// @name Dismissing

/**
 Dismisses the ad placer from the table view.

 This will completely remove the ad placer from your table view. This will restore the table to
 it's original datasource and delegate.

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
@return The original index paths. If any items in adjustedIndexPaths are index paths for ads, they will not be
returned and the array will be smaller.
@available Namo 2.0.1 and later.
*/
- (NSArray *)originalIndexPaths:(NSArray *)adjustedIndexPaths;


/// @name Determining ad positions

/**
 Returns a sorted array of index paths where ads have been inserted.

 @return An array of sorted ad index paths, expressed as adjusted index paths.
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

