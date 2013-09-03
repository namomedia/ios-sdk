// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

/**
 Utility class for representing a pair of objects.
*/
@interface NAMOPair : NSObject
@property(nonatomic, retain) id key;
@property(nonatomic, retain) id value;

/**
 Designated initializer.

 Initializes the pair with a key an value.
*/
- (id)initWithKey:(id)key value:(id)value;

/**
 Static initializer.

 Initializes the pair with a key an value.
*/
+ (id)forKey:(id)key value:(id)value;
@end
