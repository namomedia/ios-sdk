//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

/**
 The targeting information with which to request ads from the Namo server. 
 
 Targeting information is used to return better targeted ads that result in higher click through
 rates and cost per impression. For a given request, you can set targeting to nil if no
 targeting information is available.
 
 @available Namo 1.0 and later.
 */
@interface NAMOTargeting : NSObject

// Gender constants
extern NSString *const NAMOGenderMale;
extern NSString *const NAMOGenderFemale;
extern NSString *const NAMOGenderUnknown;

// Education constants
extern NSString *const NAMOEducationHighSchool;
extern NSString *const NAMOEducationCollege;
extern NSString *const NAMOEducationGrad;
extern NSString *const NAMOEducationUnknown;

// Relationship constants
extern NSString *const NAMORelationshipSingle;
extern NSString *const NAMORelationshipInRelationship;
extern NSString *const NAMORelationshipEngaged;
extern NSString *const NAMORelationshipMarried;
extern NSString *const NAMORelationshipUnknown;

// Interest constants
extern NSString *const NAMOInterestFood;
extern NSString *const NAMOInterestGaming;
extern NSString *const NAMOInterestShopping;
extern NSString *const NAMOInterestTraveling;
extern NSString *const NAMOInterestAutos;
extern NSString *const NAMOInterestEducation;
extern NSString *const NAMOInterestNews;
extern NSString *const NAMOInterestPets;
extern NSString *const NAMOInterestPolitics;
extern NSString *const NAMOInterestEntertainment;

// Music constants
extern NSString *const NAMOMusicRock;
extern NSString *const NAMOMusicPop;
extern NSString *const NAMOMusicJazz;
extern NSString *const NAMOMusicClassical;

// Sport constants
extern NSString *const NAMOMusicBaseball;
extern NSString *const NAMOMusicFootball;
extern NSString *const NAMOMusicBasketball;
extern NSString *const NAMOMusicHockey;
extern NSString *const NAMOMusicCricket;
extern NSString *const NAMOMusicGolf;
extern NSString *const NAMOMusicSoccer;
extern NSString *const NAMOMusicTennis;


/// @name Creating a targeting object.

/**
 Creates and returns a new namo targeting object.
 
 @return The new namo targeting object.
 @available Namo 1.0 and later.
 */
+ (NAMOTargeting *) targeting;


/// @name Setting targeting information

/**
 Gender. Possible values for gender are:
 <ul>
 <li>NAMOGenderMale</li>
 <li>NAMOGenderFemale</li>
 <li>NAMOGenderUnknown</li>
 </ul>
 */
@property (nonatomic, strong) NSString *gender;

/**
 Education. Possible values for education are:
 
 <ul>
 <li>NAMOEducationHighSchool</li>
 <li>NAMOEducationCollege</li>
 <li>NAMOEducationGrad</li>
 <li>NAMOEducationUnknown</li>
 </ul>
 
 @return The education value for the targeting params.
 @available Namo 1.0 and later.
 */
@property (nonatomic, strong) NSString *education;

/**
 Relationship Status. Possible values are:
 
 <ul>
 <li>NAMORelationshipSingle</li>
 <li>NAMORelationshipInRelationship</li>
 <li>NAMORelationshipEngaged</li>
 <li>NAMORelationshipMarried</li>
 <li>NAMORelationshipUnknown</li>
 </ul>
 
 @return The relationship status value for the targeting params.
 @available Namo 1.0 and later.
 */
@property (nonatomic, strong) NSString *relationshipStatus;


/**
 Value that is greater than or equal to 0.
 
 @return The targeting age.
 @available Namo 1.0 and later.
 */
@property (nonatomic, assign) NSUInteger age;

/**
 Search term if this is a search view. This can contain multiple words.
 
 @return The search terms.
 @available Namo 1.0 and later.
 */
@property (nonatomic, strong) NSString *searchTerms;

/**
 Sets the birth day, month and year. This overwrite the age value.

 @param day The day of birth
 @param month The month of birth
 @param year The year of birth
 @available Namo 1.0 and later.
 */
- (void)setBirthDay:(NSUInteger)day month:(NSUInteger)month year:(NSUInteger)year;

/**
 Adds an interest to the targeting information.
 
 Possible values are:
 <ul>
 <li>NAMOInterestFood</li>
 <li>NAMOInterestGaming</li>
 <li>NAMOInterestShopping</li>
 <li>NAMOInterestTraveling</li>
 <li>NAMOInterestAutos</li>
 <li>NAMOInterestEducation</li>
 <li>NAMOInterestNews</li>
 <li>NAMOInterestPets</li>
 <li>NAMOInterestPolitics</li>
 <li>NAMOInterestEntertainment</li>
 </ul>
 
 @param interest The interest to add. Should be one of the NAMO_Interest constants.
 @available Namo 1.0 and later.
 */
- (void)addInterest:(NSString *)interest;

/**
 Adds a Music Type to the targeting information.
 
 Possible values are:
 <ul>
 <li>NAMOMusicRock</li>
 <li>NAMOMusicPop</li>
 <li>NAMOMusicJazz</li>
 <li>NAMOMusicClassical</li>
 </ul>

 @param musicType The Music Type to add. Should be one of the NAMO_MusicType constants.
 @available Namo 1.0 and later.
 */
- (void)addMusicType:(NSString *)musicType;

/**
 Adds a sport to the targeting information.
 
 Possible values are:
 <ul>
 <li>NAMOMusicBaseball</li>
 <li>NAMOMusicFootball</li>
 <li>NAMOMusicBasketball</li>
 <li>NAMOMusicHockey</li>
 <li>NAMOMusicCricket</li>
 <li>NAMOMusicGolf</li>
 <li>NAMOMusicSoccer</li>
 <li>NAMOMusicTennis</li>
 </ul>
 
 @param sport The sport to add. Should be one of the NAMO_Sport constants. 
 @available Namo 1.0 and later.
 */
- (void)addSport:(NSString *)sport;


/// @name Reading targeting lists

/**
 Returns the birthday as a string in yyyy-MM-dd format.

 @return The birthday string in yyyy-MM-dd format.
 @available Namo 1.0 and later.
 */
- (NSString *)birthday;

/**
 An array of interests.

 @return The array of interests for this targeting criteria.
 @available Namo 1.0 and later.
 */
- (NSArray *)interests;

/**
 An array of music types.

 @return The array of music types.
 @available Namo 1.0 and later.
 */
- (NSArray *) musicTypes;

/**
 An array of sports.

 @return The array of sports for this targeting criteria.
 @available Namo 1.0 and later.
 */
- (NSArray *)sports;


/// @name Removing targeting values

/**
 Removes a particular interest if it is in the list.

 @param interest The interest to remove.
 @available Namo 1.0 and later.
 */
- (void)removeInterest:(NSString *)interest;

/**
 Clears the list of interests.

 @available Namo 1.0 and later.
 */
- (void)clearInterests;

/**
 Removes a particular music type if it is in the list.

 @param musicType The Music Type to remove.
 @available Namo 1.0 and later.
 */
- (void)removeMusicType:(NSString *)musicType;

/**
 Clears the list of music types.

 @available Namo 1.0 and later.
 */
- (void)clearMusicTypes;

/**
 Removes particular sport if it is in the list.

 @param sport The sport to remove.
 @available Namo 1.0 and later.
 */
- (void)removeSport:(NSString *)sport;

/**
 Clears the list of sports.

 @available Namo 1.0 and later.
 */
- (void)clearSports;

@end
