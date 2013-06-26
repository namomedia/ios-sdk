//
// NamoAdsController.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAdsController requests and displays Namo advertising in a UITableView.
//
// NamoAdsController does all of the following:
// - Requests ads from the NamoMedia servers
// - Caches a small set of targeted ad responses for better performance
// - Determines what index positions in your table should show ads based on your configuration
// - Records user interactions such as clicks and impressions and logs this information to
//   NamoMedia servers.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NamoBackendClient;
@class NamoTargeting;
@protocol NamoAdCellCustomizer;

@interface NamoAdsController : NSObject
// The number of items to show for each ad in this controller. Defaults to 5.
@property(nonatomic, assign) NSUInteger itemToAdRatio;

// Initializes the controller with a table view and backend client.
- (id)initWithTableView:(UITableView *)tableView
                backend:(NamoBackendClient *)backend
       adCellCustomizer:(id<NamoAdCellCustomizer>)customizer;

// Returns the row position of a table view adjusted for ads that should appear in stream.
- (NSUInteger)adjustedPosition:(NSUInteger)position;

// Returns the index path of a table view adjusted for ads that should appear in stream.
- (NSIndexPath *)adjustedIndexPath:(NSIndexPath *)indexPath;

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

// Call this if you are changing the number of rows in your table and want to also update the
// add positions. This also calls [tableView reloadData].
- (void)reloadData;

// Use this to inform the controller that a row were inserted manually. This will update ad indices.
- (void)insertRowAtIndexPath:(NSIndexPath *)adjustedIndexPath;

// Use this to inform the controller that a rows were deleted manually. This will update ad indices.
- (void)removeRowAtIndexPath:(NSIndexPath *)adjustedIndexPath;

// Use this to inform the controller that a row was moved. This will update ad indices.
- (void)moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath;

// Returns the cell at this index path.
- (UITableViewCell *)tableView:(UITableView *)tableView
         cellForRowAtIndexPath:(NSIndexPath *)indexPath;

// Requests ads from the NamoMedia servers with targeting information.
- (void)requestAdsWithTargeting:(NamoTargeting *)targeting;

// Returns the height for the row at this index path.
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;

@end
