// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

@class NAMOAdData;


/**
 NAMOAdFormat defines an interface for displaying a native Ad, typically in a stream.

 To customize the look of your Format, you have to implement this protocol. Look in the
 AdFormatSamples directory for examples.

 The class implementing this protocol must derive from UIView. If you plan to only use this Format
 with a UITableViewAdPlacer or UICollectionViewAdPlacer, you may optionally derive from
 UITableViewCell or UICollectionViewCell respectively for a slight performance improvement.

 @available Namo 1.0 and later.
*/
@protocol NAMOAdFormat<NSObject>

/// @name Setting the Ad size

/**
 The size of the Ad Format.

 This value is used when creating your native Ad view. You should not return a size with a width
 equal to or less than the maxWidth. You are required to implement this method.

 For example:
   + (CGSize)sizeWithMaxWidth:(CGFloat)maxWidth {
     return CGSizeMake(maxWidth, 84.0f);
   }

 Your size of your Format will remain constant regardless of the Ad content. When loading an Ad
 into your Format, the SDK measures the size and your Ad text and image views and will display an
 Ad that matches. If you wish to experiment with different Ad sizes, you should create multiple
 Ad formats.

 @param maxWidth The maximum width of your Format. This is determined by the containing UITableView,
 UICollectionView, or other parent view.
 @return The size of your Ad Format.
 @available Namo 3.0 and later.
*/
+ (CGSize)sizeWithMaxWidth:(CGFloat)maxWidth;

/// @name Format identifier

/**
 A string used to identify the Ad Format.

 This string will be used when requesting ads from the server in order to select ads that have
 previously worked well in this Format. If you are using a UITableViewAdPlacer or
 UICollectionViewAdPlacer, this id will also be used as the reuse identifier to help recycle Ad
 views.

 @return The string used to identify the Format.
 @available Namo 3.0 and later.
*/
+ (NSString *)formatIdentifier;


/// @name Filling Ad data

/**
 Sets the Ad data for the Format.
 
 This method should apply the Ad data to your custom Format. At a minimum, you are required
 to display the Ad image and Ad text.

 @param adData The Ad data to apply to the Format.
 @available Namo 1.0 and later.
 */
- (void)setAdData:(NAMOAdData *)adData;

/// @name Initializing a NAMOAdFormat Object

@optional

/**
 Returns a new instance of the Format.

 This method is optional. If not specified, the framework will attempt to call the designated
 initializer for your Format, as follows:

 UITableViewCell classes:
     [[self alloc] initWithStyle:UITableViewCellStyleDefault
                 reuseIdentifier:[self formatIdentifier]];

 UICollectionViewCell classes:
     [[self alloc] initWithFrame:frame collectionViewLayout:layout

 All other UIView classes:
     [[self alloc] initWithFrame:frame];

 @param frame The frame that should be used as the initial rectangle for creating the UIView.
 @return A new instance of the ad format.
 @available Namo 3.0 and later.
*/
+ (UIView<NAMOAdFormat> *)createViewWithFrame:(CGRect)frame;
@end