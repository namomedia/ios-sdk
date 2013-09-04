// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOIndexPathAdjuster.h"

@interface NAMOIndexPathAdjuster (Internal)

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
 @see NAMOAdPlacer.h
*/
- (void)setAdPlacementWithSpacing:(NSUInteger)spacing
                    firstPosition:(NSUInteger)firstPosition
                           maxAds:(NSUInteger)maxAds;

/**
 @see NAMOAdPlacer.h
*/
- (void)setAdPlacementForSection:(NSUInteger)section
                     withSpacing:(NSUInteger)spacing
                   firstPosition:(NSUInteger)firstPosition
                          maxAds:(NSUInteger)maxAds;

/**
 @see NAMOAdPlacer.h
*/
- (BOOL)hasAdsForSection:(NSUInteger)section;

/**
 @see NAMOAdPlacer.h
*/
- (NSUInteger)firstPositionForSection:(NSUInteger)section;

/**
 @see NAMOAdPlacer.h
*/
- (NSUInteger)spacingForSection:(NSUInteger)section;

/**
 @see NAMOAdPlacer.h
*/
- (NSUInteger)maxAdsForSection:(NSUInteger)section;

/**
 @see NAMOAdPlacer.h
*/
- (void)insertRowsAtIndexPaths:(NSArray *)adjustedIndexPaths;

/**
 @see NAMOAdPlacer.h
*/
- (void)deleteRowsAtIndexPaths:(NSArray *)adjustedIndexPaths;

/**
 @see NAMOAdPlacer.h
*/
- (void)moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath;

@end
