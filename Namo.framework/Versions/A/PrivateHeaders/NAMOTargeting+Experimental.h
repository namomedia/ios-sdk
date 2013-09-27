//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>

/**
 Targeting we aren't sure we want to release publically
 */
@interface NAMOTargeting (Experimental)

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
 
 @warning Raises an NSInvalidArgumentException if type is nil.
 
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
 
 @warning Raises an NSInvalidArgumentException if type is nil.
 
 @param type The interest type to add. Should be one of the NAMOInterest constants.
 */
- (void)addInterestType:(NSString *)type;

/// @name Reading targeting lists

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
 
 @warning Raises an NSInvalidArgumentException if type is nil.
 
 @param interest The interest type to remove.
 @available Namo 1.0 and later.
 */
- (void)removeInterestType:(NSString *)interest;

@end
