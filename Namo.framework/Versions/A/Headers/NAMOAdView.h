// Copyright (c) 2014 Namo Media. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NAMOTargeting;

/**
 A single UIView that can contain a Namo Media native ad, allowing ad placement anywhere that a UIView could be placed.

 After instantiating this class you should add it as a subview to an enclosing view on this page.

 @available Namo 3.0 and later.
*/
@interface NAMOAdView : UIView


/// @name Registering an ad format

/**
 Registers a native ad format class with the NAMOAdView.

 You must register an ad format for ads to be displayed.

 @param formatClass The Class for an object that conforms to the (NAMOAdFormat) protocol.
 @available Namo 3.0 and later.
*/
- (void)registerAdFormat:(Class)formatClass;


/// @name Setting an app section Id.

/**
 The ad unit ID for this NAMOAdView.

 If your app uses ad units to provide more granular targeting and reporting, you should set
 this property on the NAMOAdView before calling any ad request methods. The id can be found in
 the Namo Media Dashboard.

 @available Namo 3.0 and later.
*/
@property(nonatomic, copy) NSString *adUnitId;


/// @name Receiving delegate events

/**
 The object assigned to this property will be notified of events in the ad request cycle as
 described in the documentation for the NAMOAdPlacerDelegate protocol.

 This is useful when you wish to be notified whether an ad request succeeds or not and whenever
 more ads become available.

 @available Namo 3.0 and later.
*/
@property(nonatomic, weak) id<NAMOAdPlacerDelegate> delegate;


/// @name Requesting ads

/**
 Requests an ad from the Namo Media servers using the provided targeting information.

 You should only call this method once when you want ads to be displayed. If an ad request is in
 progress, calling this method will cancel that request.

 If you aren't seeing ads, try the following:
 <ol>
 <li>Put your device into 'test' mode.</li>
 <li>Check your device logs. The logs will tell you if you did something obvious, like failing
 to set an application key or not registering an ad format.</li>
 <li>Check your network connection. We allow up to 2 seconds for the server to return ads.</li>
 </ol>

 @see [Namo test mode]([Namo setTestDevices:includeSimulator:])</li>

 @param targeting Targeting information sent as part of the Ad request. This may be nil.
 @available Namo 3.0 and later.
 */
- (void)requestAdWithTargeting:(NAMOTargeting *)targeting;

@end