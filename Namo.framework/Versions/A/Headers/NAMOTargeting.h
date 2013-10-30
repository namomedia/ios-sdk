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

/// @name Creating a targeting object.

/**
 Creates and returns a new namo targeting object.
 
 @return The new namo targeting object.
 @available Namo 1.0 and later.
 */
+ (NAMOTargeting *)targeting;


/// @name Setting targeting information

/**
 Gender. Possible values for gender are:
 <ul>
 <li>NAMOGenderMale</li>
 <li>NAMOGenderFemale</li>
 <li>NAMOGenderUnknown</li>
 </ul>
 */
@property(nonatomic, strong) NSString *gender;

/**
 Education. You can specify your own value, or use one of the
 following pre-defined constants:
 
 <ul>
 <li>NAMOEducationHighSchool</li>
 <li>NAMOEducationCollege</li>
 <li>NAMOEducationGrad</li>
 <li>NAMOEducationUnknown</li>
 </ul>
 
 @return The education value for the targeting params.
 @available Namo 1.0 and later.
 */
@property(nonatomic, strong) NSString *education;

/**
 Relationship Status. You can specify your own value, or use one of the
 following pre-defined constants:

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
@property(nonatomic, strong) NSString *relationshipStatus;


/**
 Value that is greater than or equal to 0.
 
 @return The targeting age.
 @available Namo 1.0 and later.
 */
@property(nonatomic, assign) NSUInteger age;

/**
 Search term if this is a search view. This can contain multiple words.
 
 @return The search terms.
 @available Namo 1.0 and later.
 */
@property(nonatomic, strong) NSString *searchTerms;

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

 You can define your own interest strings. Some examples:
 <ul>
 <li>Food</li>
 <li>Gaming</li>
 <li>Shopping</li>
 <li>Traveling</li>
 <li>Autos</li>
 <li>Education</li>
 <li>News</li>
 <li>Pets</li>
 <li>Politics</li>
 <li>Entertainment</li>
 <li>Music</li>
 <li>Sports</li>
 <li><a href="http://docs.namomedia.com/interests.txt" target="_blank">More examples</a>
 </ul>

 @param interest The interest to add.
 @available Namo 1.0 and later.
 */
- (void)addInterest:(NSString *)interest;

/// @name Reading targeting values

/**
 Returns the birthday as a string in yyyy-MM-dd format.

 @return The birthday string in yyyy-MM-dd format.
 @available Namo 1.0 and later.
 */
- (NSString *)birthday;

/**
 An array of interests for a particular interest type.
 
 @return An array of interests for a particular type.
 @available Namo 1.0 and later.
 */
- (NSArray *)interests;

/// @name Removing targeting values

/**
 Removes a particular interest type if it is in the list.
 
 @warning Raises an NSInvalidArgumentException if type is nil.
 
 @param interest The interest type to remove.
 @available Namo 1.0 and later.
 */
- (void)removeInterest:(NSString *)interest;

/**
 Clears the list of interests.

 @available Namo 1.0 and later.
 */
- (void)clearInterests;

/**
 Add a keyword to the targeting data. You should only use keywords if you directly sell
 advertising campaigns for your app and have ad groups in campaigns that are only shown under
 specific conditions.
 
 @param keyword The keyword to target.
 @available Namo 1.0 and later.
 */
- (void)addKeyword:(NSString *)keyword;

/**
 An array of keywords currently set on the targeting object.
 
 @available Namo 1.0 and later.
 */
- (NSArray *)keywords;
/**
 Clears all the keywords.
 
 @available Namo 1.0 and later.
 */
- (void)clearKeywords;

@end
