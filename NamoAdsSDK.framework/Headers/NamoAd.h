//
// NamoTableViewDelegate.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAd class defines an ad returned from the Namo servers.

#import <Foundation/Foundation.h>

@interface NamoAd : NSObject

// Initializes the ad object using a dictionary of key value pairs.
- (id)initWithDictionary:(NSDictionary *)data;

// Returns the value for the given key.
- (NSString *)valueForKey:(NSString *)key;

// TODO(nassar): Provide named values.
@end
