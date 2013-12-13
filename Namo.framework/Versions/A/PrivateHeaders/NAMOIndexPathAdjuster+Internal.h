// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOIndexPathAdjuster.h"

@class NAMOAdsInfo;

typedef void(^NAMOContinuationBlock)();

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
- (NAMOAdsInfo *)adsInfo;


- (void)clearAdData;

/**
 Sets the currently loaded ad data.
 */
- (void)addAdData:(NSArray *)adData
        positions:(NSArray *)positions
continuationBlock:(NAMOContinuationBlock)continuationBlock;

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
