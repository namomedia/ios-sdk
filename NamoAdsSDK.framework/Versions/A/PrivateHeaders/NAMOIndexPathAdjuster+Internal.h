// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOIndexPathAdjuster.h"

@interface NAMOIndexPathAdjuster (Internal)

- (void)readjust;

- (NSArray *)sectionSizes;

- (void)setSectionSizes:(NSArray *)sectionSizes;

- (NSArray *)adData;

- (void)setAdData:(NSArray *)adData;

- (void)setAdPlacementWithSpacing:(NSUInteger)spacing
                    firstPosition:(NSUInteger)firstPosition
                           maxAds:(NSUInteger)maxAds;

- (void)setAdPlacementForSection:(NSUInteger)section
                     withSpacing:(NSUInteger)spacing
                   firstPosition:(NSUInteger)firstPosition
                          maxAds:(NSUInteger)maxAds;

- (BOOL)hasAdsForSection:(NSUInteger)section;

- (NSUInteger)firstPositionForSection:(NSUInteger)section;

- (NSUInteger)spacingForSection:(NSUInteger)section;

- (NSUInteger)maxAdsForSection:(NSUInteger)section;

- (void)insertRowsAtIndexPaths:(NSArray *)adjustedIndexPaths;

- (void)deleteRowsAtIndexPaths:(NSArray *)adjustedIndexPaths;

- (void)moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath;

@end
