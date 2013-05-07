//
// NamoAdItem.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAdItem class defines messages for displaying a NamoAd object
// as a table cell list item, and for handling delegate callbacks from that table cell.
//
// NamoAdItem serves as a kind of controller for a single ad row.
//

#import <Foundation/Foundation.h>

@class NamoAd;

@interface NamoAdItem : NSObject
// Returns the ad associated with this adItem. This value remains constant for the life-time
// of the item.
@property(nonatomic, strong) NamoAd *ad;

// The NSIndexPath row at which this ad item will render.
@property(nonatomic, assign) NSUInteger position;

// Returns whether this ad item has been viewed in the current list context.
@property(nonatomic, assign) BOOL hasBeenViewed;

// Returns whether this ad item is in an expanded state
@property(nonatomic, assign) BOOL isExpanded;

// Initializes the object with an ad and a position.
- (id)initWithAd:(NamoAd *)ad position:(NSUInteger)position;
@end
