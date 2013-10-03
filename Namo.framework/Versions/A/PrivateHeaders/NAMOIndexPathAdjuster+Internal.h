// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOIndexPathAdjuster.h"

@interface NAMOIndexPathAdjuster (Internal)

/**
 An index path adjuster which doesn't actually adjust anything. Useful as a sentinel value
 when a table isn't yet bound.
*/
+ (NAMOIndexPathAdjuster *)nonAdjustingAdjuster;

/**
 Called to rebuild the ad indexes.
*/
- (void)readjust;

/**
 Returns original sizes for each section.
*/
- (NSArray *)sectionSizes;

/**
 Set the original sizes for each section.
*/
- (void)setSectionSizes:(NSArray *)sectionSizes;

/**
 The currently loaded ad data.
*/
- (NSArray *)adData;

/**
 Sets the currently loaded ad data.
*/
- (void)setAdData:(NSArray *)adData;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (void)setAdPlacementWithSpacing:(NSUInteger)spacing
                    firstPosition:(NSUInteger)firstPosition
                           maxAds:(NSUInteger)maxAds;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (void)setAdPlacementForSection:(NSUInteger)section
                     withSpacing:(NSUInteger)spacing
                   firstPosition:(NSUInteger)firstPosition
                          maxAds:(NSUInteger)maxAds;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (BOOL)hasAdsForSection:(NSUInteger)section;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (NSUInteger)firstPositionForSection:(NSUInteger)section;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (NSUInteger)spacingForSection:(NSUInteger)section;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (NSUInteger)maxAdsForSection:(NSUInteger)section;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (void)insertRowsAtIndexPaths:(NSArray *)adjustedIndexPaths;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (void)deleteRowsAtIndexPaths:(NSArray *)adjustedIndexPaths;

/**
 @see UITableView+NAMOAdPlacer.h
*/
- (void)moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath;

@end
