//
// NamoScreen.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoScreen defines messages for getting information about the device's screen
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface NamoScreen : NSObject
// Returns the current screen size of the device.
+ (CGSize)currentScreenSize;
@end