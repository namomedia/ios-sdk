//
// NamoAdItemDelegate.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoAdItemDelegate defines messages for responding to NamoAdItem callbacks.
//

#import <Foundation/Foundation.h>

@class NamoAdItem;

@protocol NamoAdItemDelegate<NSObject>

// Tells the delegate that the item was viewed.
- (void)adItemWasViewed:(NamoAdItem *)adItem;

// Tells the delegate that the item was expanded or unexpanded.
- (void)adItemWasExpanded:(NamoAdItem *)adItem withNewState:(BOOL)expanded;

// Tells the delegate that the item was clicked.
- (void)adItemWasClicked:(NamoAdItem *)adItem;
@end