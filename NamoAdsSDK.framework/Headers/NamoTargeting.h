//
// NamoTargeting.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoTargeting defines properties used for targeting ads from the NamoMedia servers.
//

#import <Foundation/Foundation.h>

@interface NamoTargeting : NSObject
// Returns a section id that will be used when tracking statistics for different
// sections of the app via the publisher web interface.
@property(nonatomic, strong) NSString *sectionId;

// Returns the maximum number of ads to display for a given list.
@property(nonatomic, assign) NSUInteger maxAds;

// Returns a set of publisher configurable keywords for improved ad targeting.
@property(nonatomic, strong) NSString *keywords;

// TODO(nassar): Gender, birthdate, location, test strategy
@end