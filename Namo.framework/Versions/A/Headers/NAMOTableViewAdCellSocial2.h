// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <UIKit/UIKit.h>

#import "NAMOTableViewAdCell.h"

/**
 A table view cell for social streams with a big photo. 
 
 Only displays ad title, not ad text.
 
 @available Namo 1.0 and later.
 */

@interface NAMOTableViewAdCellSocial2 : UITableViewCell<NAMOTableViewAdCell>

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
