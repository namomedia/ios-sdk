// Copyright (c) 2014 Namo Media. All rights reserved.


#import <Foundation/Foundation.h>

/**
 Objects that need to respond to ad request events like loading or failure to load should implement
 this protocol. A NAMOCustomStreamAdPlacer, NAMOCollectionViewAdPlacer, NAMOTableViewAdPlacer, or
 NAMOAdView can all have a NAMOAdPlacerDelegate set.

 @available Namo 3.0 and later.
*/
@protocol NAMOAdPlacerDelegate<NSObject>

// name Responding to Ad Request events.

/**
 Called by the NAMO SDK when the initial ad request succeeds.

 @available Namo 3.0 and later.
*/
- (void)didReceiveAds;

/**
 Called by the NAMO SDK when the initial ad request fails.

 There are several reasons why an ad request might fail, including:
 <ul>
   <li>The SDK is in an invalid state. For example, you might not have set a valid
   Application ID.</li>
   <li>There is no network connection.</li>
   <li>There were no ads available from the server due to frequency capping, lack of inventory, or
   other ad quality restrictions.</li>
 </ul>

 See NamoErrors.h for a list of possible NSError codes.

 @param error The error that caused the SDK to not receive ads.
 @available Namo 3.0 and later.
*/
- (void)didFailWithError:(NSError *)error;

@optional
/**
 Called by the NAMO SDK when a refresh request succeeds.

 These requests retrieve more ads after the initial batch has been shown.

 @available Namo 3.0 and later.
*/
- (void)didReceiveMoreAds;
@end