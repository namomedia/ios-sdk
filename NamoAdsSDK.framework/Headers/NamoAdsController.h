//
// NamoAdsController.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAdsController requests and displays Namo advertising in a UITableView.
//
// NamoAdsController does all of the following:
// - Requests ads from the NamoMedia servers
// - Caches a small set of targeted ad responses for better performance
// - Determines what index positions in your table should show ads based on your configuration
// - Handles messages from a NamoAdItemDelegate to handle user interactions with ad cells
// - Records user interactions such as clicks and impressions and logs this information to
//   NamoMedia servers.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "NamoAdContentBinder.h"

@class NamoBackendClient;
@class NamoTargeting;
@protocol NamoAdCellProvider;

@interface NamoAdsController : NSObject<NamoAdContentBinderDelegate>

// Initializes the controller with a table view and backend client.
- (id)initWithTableView:(UITableView *)tableView
                backend:(NamoBackendClient *)backend
         adCellProvider:(id<NamoAdCellProvider>)provider;

// Returns the row position of a table view adjusted for ads that should appear in stream.
- (NSUInteger)adjustedPosition:(NSUInteger)position;

// Returns the index path of a table view adjusted for ads that should appear in stream.
- (NSIndexPath *)adjustedIndexPath:(NSIndexPath *)indexPath __unused;

// Given an adjusted row position, returns the original position in the table view.
- (NSUInteger)originalPosition:(NSUInteger)adjustedPosition;

// Given an adjusted index path, returns the original index path in the table view.
- (NSIndexPath *)originalIndexPath:(NSIndexPath *)adjustedIndexPath;

// Whether the row at the given adjusted position is an ad.
- (BOOL)isAdAtPosition:(NSUInteger)adjustedPosition;

// Whether the row at the given index path is an ad.
- (BOOL)isAdAtIndexPath:(NSIndexPath *)adjustedIndexPath;

// Returns the number of rows in the table view adjusted for ads that should appear in stream.
- (NSInteger)adjustedNumberOfRows:(NSUInteger)numberOfRows;

// Requests ads from the NamoMedia servers with targeting information.
- (void)requestAdsWithTargeting:(NamoTargeting *)targeting;
@end
