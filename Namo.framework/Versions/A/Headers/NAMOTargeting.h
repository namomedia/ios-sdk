//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

@interface NAMOTargeting : NSObject

// Gender constants
/*!
 @const Male
 */
extern NSString *const NAMO_Gender_Male;
extern NSString *const NAMO_Gender_Female;

// Education constants
extern NSString *const NAMO_Edu_HighSchool;
extern NSString *const NAMO_Edu_College;
extern NSString *const NAMO_Edu_Grad;

// Relationship constants
extern NSString *const NAMO_Rel_Single;
extern NSString *const NAMO_Rel_InRelationship;
extern NSString *const NAMO_Rel_Engaged;
extern NSString *const NAMO_Rel_Married;

// Interest constants
extern NSString *const NAMO_Interest_Food;
extern NSString *const NAMO_Interest_Gaming;
extern NSString *const NAMO_Interest_Shopping;
extern NSString *const NAMO_Interest_Traveling;
extern NSString *const NAMO_Interest_Autos;
extern NSString *const NAMO_Interest_Education;
extern NSString *const NAMO_Interest_News;
extern NSString *const NAMO_Interest_Pets;
extern NSString *const NAMO_Interest_Politics;
extern NSString *const NAMO_Interest_Entertainment;

// Music constants
extern NSString *const NAMO_Music_Rock;
extern NSString *const NAMO_Music_Pop;
extern NSString *const NAMO_Music_Jazz;
extern NSString *const NAMO_Music_Classical;

// Sport constants
extern NSString *const NAMO_Music_Baseball;
extern NSString *const NAMO_Music_Football;
extern NSString *const NAMO_Music_Basketball;
extern NSString *const NAMO_Music_Hockey;
extern NSString *const NAMO_Music_Cricket;
extern NSString *const NAMO_Music_Golf;
extern NSString *const NAMO_Music_Soccer;
extern NSString *const NAMO_Music_Tennis;

/**
 See Gender constants for possible values
 */
@property (nonatomic, strong) NSString *gender;
// Education. Use one of the constant values above.
@property (nonatomic, strong) NSString *education;
// Relationship Status. Use one of the constants above.
@property (nonatomic, strong) NSString *relationshipStatus;
// Value that is greater than 0
@property (nonatomic, assign) int age;
// Zip code in string format
@property (nonatomic, strong) NSString *zipCode;
// Search term if this is a search view
@property (nonatomic, strong) NSString *searchTerm;

// Set the birth day, month and year
- (void)setBirthDay:(int)day month:(int)month year:(int)year;
// Get the birthday in yyyy/mm/dd
- (NSString *)birthday;

// See Interest constants for possible values
- (void)addInterest:(NSString *)interest;
// Get a comma separated list of interests
- (NSString *)interests;

// See Music constants for possible values
- (void)addMusicType:(NSString *)musicType;
- (NSString *)musicTypes;

// See Sport constants for possible values
- (void)addSport:(NSString *)sport;
- (NSString *)sports;
@end
