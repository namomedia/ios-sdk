/*
 The MIT License (MIT)
 
 Copyright (c) 2013 Namo Media, Inc.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#import <UIKit/UIKit.h>

#import <Namo/NAMOTableViewAdCell.h>

/**
 A table view cell for displaying a thumbnail ad format.
 
 A _Thumbnail Ad_ is an ad that shows a small to medium sized thumbnail photo along with text
 describing the the ad information. These ads are suitable to display in streams with similar
 content. For example, many news streams display a small picture and a text preview of an article.
 
 You can use this thumbnail cell as a template to build your own ad cell. You can either build your
 cell as a nib with matching UIView outlets for this cell, or you can copy this cell implementation
 and create your own cell.
 
 @available NamoAds 1.0 and later.
 */
@interface AdCellThumb : UITableViewCell<NAMOTableViewAdCell>

/// @name Managing cell content

/**
 A short ad title label.
 
 @return The title for this ad.
 @available NamoAds 1.0 and later.
 */
@property(nonatomic, strong) UILabel *adTitleLabel;

/**
 Ad text label.
 
 @return The text for this ad.
 @available NamoAds 1.0 and later.
 */
@property(nonatomic, strong) UILabel *adTextLabel;


/**
 An advertiser name label.
 
 @return The advertiser name for this ad.
 @available NamoAds 1.0 and later.
 */
@property(nonatomic, strong) UILabel *advertiserNameLabel;

/**
 The primary ad image URL.
 
 @return The image view for this ad.
 @available NamoAds 1.0 and later.
 */
@property(nonatomic, strong) UIImageView *adImageView;

/**
 An image overlay for displaying an action hint.
 
 This image will show a different image for link, install, and video ads.
 
 @return The image view for the overlay.
 @available NamoAds 1.0 and later.
 */
@property(nonatomic, strong) UIImageView *adOverlayImageView;

/**
 An advertiser icon image view.
 
 @return The advertiser icon for this ad.
 @available NamoAds 1.0 and later.
 */
@property(nonatomic, strong) UIImageView *advertiserIconImageView;

/**
 A small indicator showing a clear ad demarcation for this ad, such as "Ads by Namo"
 
 @return The ad indicator image view.
 @available NamoAds 1.0 and later.
 */
@property(nonatomic, strong) UIImageView *adIndicatorImageView;
@end
