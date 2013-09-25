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
extern NSString *const NAMOInterestMusic;
extern NSString *const NAMOInterestSports;

// Music constants
extern NSString *const NAMOMusicRock;
extern NSString *const NAMOMusicPop;
extern NSString *const NAMOMusicJazz;
extern NSString *const NAMOMusicClassical;

// Sport constants
extern NSString *const NAMOSportBaseball;
extern NSString *const NAMOSportFootball;
extern NSString *const NAMOSportBasketball;
extern NSString *const NAMOSportHockey;
extern NSString *const NAMOSportCricket;
extern NSString *const NAMOSportGolf;
extern NSString *const NAMOSportSoccer;
extern NSString *const NAMOSportTennis;


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
 Adds an interest type and array of interests to the targeting information. Calling
 this method twice adds the array of interests to the previously added interests
 and ignores duplicates.
 
 Possible values are:
 <ul>
 <li><b>Type</b>: NAMOInterestFood</li>
 <li><b>Type</b>: NAMOInterestGaming</li>
 <li><b>Type</b>: NAMOInterestShopping</li>
 <li><b>Type</b>: NAMOInterestTraveling</li>
 <li><b>Type</b>: NAMOInterestAutos</li>
 <li><b>Type</b>: NAMOInterestEducation</li>
 <li><b>Type</b>: NAMOInterestNews</li>
 <li><b>Type</b>: NAMOInterestPets</li>
 <li><b>Type</b>: NAMOInterestPolitics</li>
 <li><b>Type</b>: NAMOInterestEntertainment</li>
 <li><b>Type</b>: NAMOInterestMusic
     <ul>
     <li><b>Interests</b>: NAMOMusicRock, NAMOMusicPop, NAMOMusicJazz, NAMOMusicClassical</li>
     </ul>
 </li>
 <li><b>Type</b>: NAMOInterestSports
     <ul>
     <b>Interests</b>: NAMOSportBaseball, NAMOSportFootball, NAMOSportBasketball,
 NAMOSportHockey, NAMOSportCricket, NAMOSportGolf, NAMOSportSoccer, NAMOSportTennis
     </ul>
 </li>
 </ul>
 
 @warning *Important:* Raises an NSInvalidArgumentException if type is nil.
 
 @param type The interest type to add. Should be one of the NAMOInterest constants.
 @param interests The array of interests for a particular type. Set to nil if no
     specific interests are available for the type.
 @available Namo 1.0 and later.
 */
- (void)addInterestType:(NSString *)type interests:(NSArray *)interests;

/**
 Adds an interest type to the targeting information without specifying particular interests.
 
 Possible values are:
 <ul>
 <li><b>Type</b>: NAMOInterestFood</li>
 <li><b>Type</b>: NAMOInterestGaming</li>
 <li><b>Type</b>: NAMOInterestShopping</li>
 <li><b>Type</b>: NAMOInterestTraveling</li>
 <li><b>Type</b>: NAMOInterestAutos</li>
 <li><b>Type</b>: NAMOInterestEducation</li>
 <li><b>Type</b>: NAMOInterestNews</li>
 <li><b>Type</b>: NAMOInterestPets</li>
 <li><b>Type</b>: NAMOInterestPolitics</li>
 <li><b>Type</b>: NAMOInterestEntertainment</li>
 <li><b>Type</b>: NAMOInterestMusic</li>
 <li><b>Type</b>: NAMOInterestSports</li>
 </ul>
 
 @warning *Important:* Raises an NSInvalidArgumentException if type is nil.
 
 @param type The interest type to add. Should be one of the NAMOInterest constants.
 */
- (void)addInterestType:(NSString *)type;

/// @name Reading targeting lists

/**
 Returns the birthday as a string in yyyy-MM-dd format.

 @return The birthday string in yyyy-MM-dd format.
 @available Namo 1.0 and later.
 */
- (NSString *)birthday;

/**
 An array of interest types.

 @return The array of interest types for this targeting criteria.
 @available Namo 1.0 and later.
 */
- (NSArray *)interestTypes;

/**
 An array of interests for a particular interest type.
 
 @param interestType One of the values that start with NAMOInterest*
 @return An array of interests for a particular type.
 @available Namo 1.0 and later.
 */
- (NSArray *)interestsForType:(NSString *)interestType;

/// @name Removing targeting values

/**
 Removes a particular interest type if it is in the list.
 
 @warning *Important:* Raises an NSInvalidArgumentException if type is nil.
 
 @param interest The interest type to remove.
 @available Namo 1.0 and later.
 */
- (void)removeInterestType:(NSString *)interest;

/**
 Clears the list of interests.

 @available Namo 1.0 and later.
 */
- (void)clearInterests;

@end
