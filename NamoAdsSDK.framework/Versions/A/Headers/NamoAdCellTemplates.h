//
// NamoAdCellTemplates.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAdCellTemplates class defines template methods to layout an ad cell.
//

#import <Foundation/Foundation.h>

@class NamoAdCell;

@interface NamoAdCellTemplates : NSObject

// Layout the default ad cell, which is a banner like ad with the image on the left.
+ (void)layoutNormalTemplate:(NamoAdCell *)cell;

// Layout the default ad cell, which is a banner like ad with the image on the left.
+ (void)layoutInstallTemplate:(NamoAdCell *)cell;

@end