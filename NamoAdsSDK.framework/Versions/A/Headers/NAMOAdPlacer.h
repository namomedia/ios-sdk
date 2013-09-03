// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

/**
 This protocol serves as a common interface for requesting ads from the server and placing them
 into your stream.

 @available NamoAds 1.0 and later.
*/
@protocol NAMOAdPlacer<NSObject>

/// @name Setting ad placement

/**
 Sets the ad placement for all sections.

 Calling this method resets any section specific placement you have set up using
 setAdPlacementForSection:section:firstPosition:spacing:maxAds.

 @param firstPosition The first position within a section at which to show an ad.
 @param spacing The spacing between subsequent ads.
 @param maxAds The maximum number of ads to display.
 @available NamoAds 1.0 and later.
*/
- (void)setAdPlacementWithFirstPosition:(NSUInteger)firstPosition
                                spacing:(NSUInteger)spacing
                                 maxAds:(NSUInteger)maxAds;

/**
 Sets ad placement for a specific section.

 Calling this method removes any global placement you have set up using
 setAdPlacementWithFirstPosition:spacing:maxAds.

 @param section The section for which to set placement information.
 @param firstPosition The first position within the section at which to show an ad.
 @param spacing The spacing between subsequent ads.
 @param maxAds The maximum number of ads to display.
 @available NamoAds 1.0 and later.
*/
- (void)setAdPlacementForSection:(NSUInteger)section
                   firstPosition:(NSUInteger)firstPosition
                         spacing:(NSUInteger)spacing
                          maxAds:(NSUInteger)maxAds;

/// @name Requesting ads from the server

/**
 Call to request ads from the server.

 We recommend requesting ads in your controller's viewWill appear method so that each
 visit to your stream results in a new set of ad impressions. You may also want to request
 ads after users perform an action that results in new stream items.

 Once ads are returned from the server, the placer will call your TableView reloadData method
 to ensure that ads are displayed in your stream.

 @available NamoAds 1.0 and later.
 */
- (void)requestAds;
@end
