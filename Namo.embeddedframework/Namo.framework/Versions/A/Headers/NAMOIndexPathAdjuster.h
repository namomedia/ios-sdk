// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NAMOAdData;

/**
 This class is responsible for adjusting the indices of your table view in order
 to place ads. NAMOAdPlacer uses a NAMOIndexPathAdjuster instance internally, but you can optionally
 to use it directly to translate positions in your dataSource to positions in your table view,
 or vice versa.
 
 @available Namo 1.0 and later.
*/
@interface NAMOIndexPathAdjuster : NSObject

/// @name Adjusting table indices

/**
 Returns the index path of a row adjusted based on ad placement in the stream.

 @param indexPath The original index path.
 @return The index path of a row adjusted based on ad placement in the stream.
 @available Namo 1.0 and later.
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
 Given an adjusted index path, returns the original index path in the table view.

 @param adjustedIndexPath The adjusted index path.
 @return The original index path.
 @available Namo 1.0 and later.
*/
- (NSIndexPath *)originalIndexPath:(NSIndexPath *)adjustedIndexPath;

/// @name Getting the ad for an index

/**
 Whether the row at the given index path is an ad.

 @param adjustedIndexPath The adjusted index path.
 @return Whether the row at the given index path is an ad.
 @available Namo 1.0 and later.
*/
- (BOOL)isAdAtIndexPath:(NSIndexPath *)adjustedIndexPath;

/**
 Returns the ad at the given index path, or nil if there is no ad.

 @param adjustedIndexPath An adjusted index path.
 @return The ad at the index path, or nil if there is no ad.
 @available Namo 1.0 and later.
*/
- (NAMOAdData *)adAtIndexPath:(NSIndexPath *)adjustedIndexPath;

/// @name Adjusting section sizes

/**
 Returns the number of rows in a table view section adjusted for ads that should appear in the
 section.

 @param originalNumberOfRows The original number of rows in the section.
 @param section The section index.
 @return The adjusted number of rows in the section.
 @available Namo 1.0 and later.
*/
- (NSInteger)adjustedNumberOfRows:(NSUInteger)originalNumberOfRows forSection:(NSInteger)section;

@end
