//  Copyright (c) 2013 Namo Media. All rights reserved.

#import <Foundation/Foundation.h>

/**
 The action type for an Ad.

 @available NamoAds 1.0 and later.
*/
typedef NS_ENUM(NSInteger, NAMOActionType) {
  /** The ad links to an in app browser popup with a web URL. */
  NAMOActionTypeLink,
  /** The ad links to an in app video player with a video feed URL. */
  NAMOActionTypeVideo,
  /** The ad links to the app store with an app install URL. */
  NAMOActionTypeInstall
};

/**
 Defines data for a NAMO ad returned from the server.

 @available NamoAds 1.0 and later.
 */
@interface NAMOAdData : NSObject

/// @name Accessing Ad data

/**
 A short ad title.

 Your ad should show an ad title or ad text. If you show both, you should display the
 title above the ad text.

 @return The title for this ad.
 @available NamoAds 1.0 and later.
 */
- (NSString *)title;

/**
 Ad text.

 Ad text will be longer than the ad title, typically between 2 and 5 lines of medium size
 font on an iPhone device in horizontal orientation.

 @return The text for this ad.
 @available NamoAds 1.0 and later.
 */
- (NSString *)text;

/**
 The advertiser name.

 Showing the advertiser name is optional.

 @return The advertiser name for this ad.
 @available NamoAds 1.0 and later.
 */
- (NSString *)advertiserName;

/**
 The action type associated with this ad.

 You may want to show a different UI for different action types. For example, you could
 show an "Install" button for an install ad, or a play video image overlay for a video
 ad. The SDK will correctly handle different action types when clicking on your ad cell.

 @return The action type associated with this ad.
 @available NamoAds 1.0 and later.
 */
- (NAMOActionType)actionType;

// TODO(nassar): Change to return NSURL

/**
 The action URL.

 Typically you do not need to call this link yourself, as the SDK will attach the appropriate
 GestureRecognizer classes to your cell. You may need this property if you wish to override the
 default action handling behavior.

 @return The action URL for this ad.
 @available NamoAds 1.0 and later.
 */
- (NSString *)actionURL;

/**
 The primary ad image URL.

 Showing the image is required. You may show the image at whatever dimensions you wish within
 a reasonable aspect ratio for your app, although we recommend a minimum height and width of
 80 pixels, and an aspect ration between 3:1 and 4:7. The image returned from the Namo Media ad
 servers will be scaled and cropped according to the image metadata associated with the ad, which
 describes a desired hotspot to keep visible, and a scaling algorithm to resize the image
 appropriately.

 @return The image URL for this ad.
 @available NamoAds 1.0 and later.
 */
- (NSString *)imageURL;

/**
 An advertiser icon URL.

 Showing the advertiser icon is optional. If you display both the advertiser name and icon, we
 recommend placing the icon to the left of the name, and showing it as square image with a
 minimum size of 14x14.

 @return The advertiser icon for this ad.
 @available NamoAds 1.0 and later.
 */
- (NSString *)advertiserIconURL;
@end