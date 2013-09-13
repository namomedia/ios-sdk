// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Namo/Namo.h>
#import <UIKit/UIKit.h>

/**
 A table view cell for social streams. Does not display the ad text

 @available Namo 1.0 and later.
 */
@interface TableViewAdCellSocial1 : UITableViewCell<NAMOTableViewAdCell>

/// @name Managing cell content

/**
 A short ad title label.
 
 @return The title for this ad.
 @available Namo 1.0 and later.
 */
@property(nonatomic, strong) UILabel *adTitleLabel;

/**
 An advertiser name label.
 
 @return The advertiser name for this ad.
 @available Namo 1.0 and later.
 */
@property(nonatomic, strong) UILabel *advertiserNameLabel;

/**
 The primary ad image URL.
 
 @return The image view for this ad.
 @available Namo 1.0 and later.
 */
@property(nonatomic, strong) UIImageView *adImageView;

/**
 An advertiser icon image view.
 
 @return The advertiser icon for this ad.
 @available Namo 1.0 and later.
 */
@property(nonatomic, strong) UIImageView *advertiserIconImageView;

/**
 A text indicator explaining that this is an ad. It says "sponsored post".
 
 @return The ad indicator label.
 @available Namo 1.0 and later.
 */
@property(nonatomic, strong) UILabel *adIndicatorLabel;

@end
