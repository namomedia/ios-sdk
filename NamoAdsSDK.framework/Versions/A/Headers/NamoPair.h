//
// NamoPair
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// Utility class for representing a pair of objects.
//

#import <Foundation/Foundation.h>

@interface NamoPair : NSObject
@property (nonatomic, retain) id key;
@property (nonatomic, retain) id value;

// Initialize the pair with a key an value.
- (id)initWithKey:(id)key value:(id)value;

+ (id)forKey:(id)key value:(id)value;
@end
