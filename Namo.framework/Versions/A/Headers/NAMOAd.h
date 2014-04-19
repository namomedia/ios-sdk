// Copyright (c) 2014 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#import "NAMOAdFormat.h"

/**
 This class represents an ad, and is capable of attaching that ad into a UIView object.

 If you are using a NAMOCustomStreamAdPlacer, you can retrieve the next available ad by calling
 dequeueAd. You can then either create the UIView for the ad, or attach the ad to an existing
 UIView.
 @available Namo 3.0 and later.
*/
@interface NAMOAd : NSObject


/// @name Getting format information

/**
 Returns the identifier for the format that will be shown by this ad.

 For native Namo Ads, this will be the formatIdentifier implemented by your NAMOAdFormat class.

 @return The format identifier of this ad.
 @available Namo 3.0 and later.
*/
- (NSString *)formatIdentifier;

/**
 Returns the class that will be used for your ad view.

 For native Namo Ads, this class should implement the NAMOAdFormat protocol. For non-native ads,
 such as those provided by DFP, this can be any UIView class.

 If you plan to only use this cell inside a UITableView or UICollectionView, you can derive directly
 from UITableViewCell<NAMOAdFormat> or UICollectionViewCell<NAMOAdFormat>. To allow your format to
 be used across your app, you should derive from UIView<NAMOAdFormat>.

 @return The format class.
 @available Namo 3.0 and later.
*/
- (Class)formatClass;

/**
 The size of the ad format.

 For native Namo Ads, this will be the formatIdentifier implemented by your NAMOAdFormat class.

 @param maxWidth The maximum width to allow when calculating the ad cell width.
 @return The size of this ad.
 @available Namo 3.0 and later.
*/
- (CGSize)sizeWithMaxWidth:(CGFloat)maxWidth;


/// @name Creating a view

/**
 Creates and returns the ad view associated with this ad.

 For native ads, this method will also call setAdData: on the newly created view.

 @param frame The for which to initialize the UIView.
 @return The new UIView. This class should be an instance of formatClass.
 @available Namo 3.0 and later.
*/
- (UIView *)createViewWithFrame:(CGRect)frame;


/// @name Attaching to an existing view

/**
 Attaches the ad to the given view.

 For native ads, attaching the view results in calls to setAdData: and layoutIfNeeded.
 This method is idempotent - attaching the same view multiple times will only call setAdData and
 layoutIfNeeded one time.

 @param reusableView The view to attach to the ad. This class will be an instance of formatClass.
 NAMOAdFormat. Cannot be nil - if you do not have a view, you
 @available Namo 3.0 and later.
*/
- (void)attachReusableView:(UIView *)reusableView;
@end
