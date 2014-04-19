// Copyright (c) 2014 NamoMedia. All rights reserved.


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>

#import "NAMOTargeting.h"

@protocol NAMOAdPlacerDelegate;

@class NAMOAd, NAMOCustomStreamAdPlacer;

/**
 This class facilitates requesting Ads and placing them into a custom stream.

 If you are inserting Ads into a UITableView or UICollectionView, you may want to use a
 UITableViewAdPlacer or UICollectionViewAdPlacer object instead. The internal implementations of
 those objects use an instance this class, but make it easy to insert Ads without needing to
 handle changes in your table row positions.

 Some examples of using this class:

 1) You are building a stream that doesn't use a UITableView or UICollectionView. You can
 use shouldInsertAdAtPosition to determined where you need to insert Ads, and dequeueAdForPosition
 to fetch the ad.

 2) You are using a UITableView or UICollectionView but don't want to use
 NAMOTableViewAdPlacer or NAMOCollectionViewAdPlacer.

 3) You have an array of content data that you are showing in your stream, and you want to insert
 an Ad into the content itself. You can call dequeueAdForPosition for each position where you want
 to show an Ad.

 @available Namo 3.0 and later.
*/
@interface NAMOCustomStreamAdPlacer : NSObject

/// @name Creating an Ad placer

/**
 Creates and returns a new ad placer.

 @return The new Ad placer.
 @available Namo 3.0 and later.
*/
+ (NAMOCustomStreamAdPlacer *)placer;

/**
 Creates and returns a new ad placer for the specified ad unit. If your app uses ad units to
 provide more granular ad targeting and reporting, you should use this method to create your placer.

 @param adUnitId The id of the ad unit this placer inserts ads into. The id can be found
 in the Namo Media Dashboard.
 @available Namo 3.0 and later.
*/
+ (NAMOCustomStreamAdPlacer *)placerForAdUnitId:(NSString *)adUnitId;

/// @name Registering an Ad Format

/**
 Registers a native Namo Ad format class for this placer.

 Registering an Ad format allows this placer to create an Ad with the given format. You must
 register a format before you request Ads. The format class must conform to the NAMOAdFormat
 protocol.

 You can optionally use the pre-configured NAMOAdFormat classes
 provided by Namo if you want the default Ad formats to show up instead of making your own custom
 ones. For example:

  `[self.adPlacer registerAdFormat:NAMOAdFormatSample1.class];`

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


/// @name Requesting Ads

/**
 Call to request Ads from the server.

 Once Ads are returned from the server, the newly returned Ads will be available using
 the dequeueAd methods.

 In most cases you should only call this method once per object. Before calling it a second time you should call
 the placer's clear: method to clear ads from their dequeued positions.

 If you aren't seeing ads, try the following:
 <ol>
 <li>Put your device into 'test' mode.</li>
 <li>Check your device logs. The logs will tell you if you did something obvious, like failing
 to set an application key or not registering an ad format.</li>
 <li>Check your network connection. We allow up to 2 seconds for the server to return ads.</li>
 </ol>

 @param targeting Targeting information sent as part of the Ad request.
 @available Namo 3.0 and later.
 */
- (void)requestAdsWithTargeting:(NAMOTargeting *)targeting;

/**
 Clears all dequeued ad positions. If you wish to replace all ads you are displaying with new ads in new positions,
 you should call this method and then call requestAdsWithTargeting.

 @available Namo 3.0 and later.
*/
- (void)clear;

/// @name Showing Ads

/**
 Returns the number of ads that have not been dequeued. The value returned by this method is volatile and should not be
 stored by the caller.

 @return The number of ads that can be dequeued before dequeueAdForPosition returns nil.
 @available Namo 3.0 and later.
*/
- (NSUInteger)remainingAdsCount;

/**
 Returns a sorted array of ad positions where ads should be inserted.

 The returned array will contain ad positions recommended by the server. You can modify these
 positions from your Publisher Dashboard. The upper bound for positions will be
 numberOfItems + number of items returned in the array.

 To insert an ad, you should call dequeueAdForPosition, after which this array will no longer
 contain the ad. You can find dequeued ads using isAdAtPosition.

 If you do not care about controlling ad positioning from your dashboard, you can choose to ignore
 these positions and insert ads where ever you wish.

 @param numberOfItems The number of items in your stream.
 @return An array of sorted ad positions where ads should be inserted.
 @available Namo 3.0 and later.
*/
- (NSArray *)positionsToInsertAdsForItemCount:(NSUInteger)numberOfItems;

/**
 Returns YES if there is an ad should be inserted at the given position.

 @see positionsToInsertAdsForItemCount:
 @param position A position in your stream
 @return Whether an ad should appear in your stream at the given position.
 @available Namo 3.0 and later
*/
- (BOOL)shouldInsertAdAtPosition:(NSUInteger)position;

/**
 Returns a sorted array of positions where ads have been dequeued.

 @return An array of sorted ad positions.
 @available Namo 3.0 and later.
*/
- (NSArray *)adPositions;

/**
 Returns YES if there is a dequeued ad at the given position.

 @param position The position in your stream.
 @return YES if an ad has been dequeued at this position.
 @available Namo 3.0 and later
*/
- (BOOL)isAdAtPosition:(NSUInteger)position;

/**
 Dequeues the next available Ad.

 Each time you call this method, the placer returns a new Ad, or nil if no more Ads have been
 received from the server. If you are showing Ads in a stream, we recommend using
 dequeueAdForPosition: instead, which will return the same Ads for the same positions.

 As the queue of Ads runs low, the Ad placer will request additional Ads from the server and load
 them into the queue. If you need to know when more Ads are available, you should pass a callback
 block to requestAdsWithTargeting:completedBlock.

 @return The next available ad, which may be nil if no ads are available.
 @available Namo 3.0 and later.
*/
- (NAMOAd *)dequeueAd;

/**
 Dequeues the next Ad available, or if an Ad was previously dequeued from this position returns the
 same Ad.

 This method is similar to dequeueAd:, except that this method memoizes the Ad at the given
 position, and will return the same Ad the next time this method is called with the same position.
 We recommend using this method when showing Ads in a stream of content.

 If you call requestAds subsequently, the memoized Ads are released once new Ads are returned from
 the server.

 @param position The position in your stream for which you are requesting an ad.
 @return An ad for the position, or nil if no ads are available.
 @available Namo 3.0 and later.
*/
- (NAMOAd *)dequeueAdForPosition:(NSUInteger)position;

/**
 Returns the position of an item has in the stream when ads are included.

 @param originalPosition The original position in your stream.
 @return The position in your stream after ads have been included.
 @available Namo 3.0 and later.
*/
- (NSUInteger)adjustedPosition:(NSUInteger)originalPosition;

/**
 Returns the original position of an item in your stream as if there were no ads inserted.

 This method is useful when retrieving objects from your datasource for the non-ad items in your
 stream. Your UIView will request an object using the adjusted position, which you should check for
 type using isDesiredAdAtPosition. If isDesiredAdAtPosition returns
 NO, the position in your data source can be found by calling getOriginalPosition.

 @param adjustedPosition The position in your stream of an item.
 @return The original position as if no ads were included. If you call this for an ad position,
 returns `NSNotFound`.
 @available Namo 3.0 and later.
*/
- (NSUInteger)originalPosition:(NSUInteger)adjustedPosition;

/**
 Returns the number of items in the stream when ads are included, given the number of non-ad items
 in the stream.

 @param numberOfItems The number of items
 @available Namo 3.0 and later.
*/
- (NSUInteger)adjustedNumberOfItems:(NSUInteger)numberOfItems;

/**
 Alerts the ad placer that content items will be added to the end of the stream.

 Calling this method may result in additional ads being displayed. You should make this call after
 modifying your data source but before updating your UI.

 @param count The number of items to be appended.
 @param originalSize The number of content items in the stream not including the appended items.
 @return The positions where ads were inserted into the stream.
 @available Namo 3.0 and later.
*/
- (NSArray *)appendItemsWithCount:(NSUInteger)count originalSize:(NSUInteger)originalSize;

/**
 Alerts the ad placer that content items have been inserted into the stream at the given positions.

 Calling this method changes the positions at which ads appear. You should make this call after
 modifying your data source but before updating your UI.

 @param originalPositions The positions in your data source where you are inserting items.
 @available Namo 3.0 and later.
*/
- (void)insertItemsAtPositions:(NSArray *)originalPositions;

/**
 Alerts the ad placer that content items have been removed from the stream at the given positions.

 Calling this method changes the positions at which ads appear. You should make this call after
 modifying your data source but before updating your UI.

 @param originalPositions The positions in your data source where you are removing items.
 @available Namo 3.0 and later.
*/
- (void)removeItemsAtPositions:(NSArray *)originalPositions;
@end
