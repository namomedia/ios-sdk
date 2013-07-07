//
// NamoAdCellTemplates.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// WorldTube specific templates.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NamoAdCellTemplates.h"
#import "NamoAdCell.h"

@class UILabel;

@interface NamoAdCellTemplates (WorldTube)

// Layout the default ad cell, which is a banner like ad with the image on the left.
+ (void)layoutWorldTubeNormalTemplate:(NamoAdCell *)cell;

// Layout the default ad cell, which is a banner like ad with the image on the left.
+ (void)layoutWorldTubeInstallTemplate:(NamoAdCell *)cell;

@end

// Implementation is defined in the header file for easy distribution and modification.
@implementation NamoAdCellTemplates (WorldTube)

+ (void)layoutWorldTubeNormalTemplate:(NamoAdCell *)cell {
  UILabel *adText = cell.adText;
  adText.frame = CGRectMake(127.0, 0.0, 184.0, 62.0);
  adText.backgroundColor = [UIColor clearColor];
  adText.numberOfLines = 3;
  adText.textColor = [UIColor colorWithWhite:1.000 alpha:1.000];
  [adText setFont:[UIFont boldSystemFontOfSize:12.0f]];

  UIImageView *adImage = cell.adImage;
  adImage.frame = CGRectMake(0.0, 0.0, 119.0, 102.0);
  adImage.clipsToBounds = YES;
  adImage.contentMode = UIViewContentModeScaleAspectFill;

  UILabel *sponsoredText = cell.sponsoredText;
  sponsoredText.hidden = NO;
  sponsoredText.frame = CGRectMake(127.0, 66.0, 160.0, 22.0);
  sponsoredText.backgroundColor = [UIColor clearColor];
  sponsoredText.textColor = [UIColor colorWithWhite:1.000 alpha:1.000];
  [sponsoredText setFont:[UIFont boldSystemFontOfSize:12.0f]];
  sponsoredText.adjustsFontSizeToFitWidth = YES;
  sponsoredText.minimumScaleFactor = 0.8;
  // Replace 'SPONSORED' with 'Ad'.
  sponsoredText.text = @"Ad";

  // No advertiser logo for this format.
  cell.advertiserLogo.hidden = YES;

  // No advertiser name for this format.
  cell.advertiserName.hidden = YES;

  cell.selectionStyle = UITableViewCellSelectionStyleNone;
  cell.contentView.backgroundColor =
      [UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:1.000];
}

+ (void)layoutWorldTubeInstallTemplate:(NamoAdCell *)cell {
  [NamoAdCellTemplates layoutWorldTubeNormalTemplate:cell];

  UILabel *advertiserName = cell.advertiserName;
  CGRect frame = advertiserName.frame;
  frame.size.width = 96.0;
  advertiserName.frame = frame;
  [cell.advertiserName setFont:[UIFont systemFontOfSize:13.0f]];

  UIButton *installButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
  installButton.frame = CGRectMake(195.0, 58.0, 117.0, 24.0);
  UIImage *installImage = [[UIImage imageNamed:@"worldtube_button.png"]
      resizableImageWithCapInsets:UIEdgeInsetsMake(18, 18, 18, 18)];
  [installButton setBackgroundImage:installImage forState:UIControlStateNormal];
  [installButton setTitleColor:[UIColor colorWithRed:0 green:0 blue:0 alpha:1.0]
                      forState:UIControlStateNormal];
  cell.installButton = installButton;
  [installButton setTitle:@"Download App" forState:UIControlStateNormal];
  [cell addSubview:installButton];

  UIImageView *downloadImage =
      [[UIImageView alloc] initWithFrame:CGRectMake(36.0, 32.0, 45.0, 36.0)];
  downloadImage.contentMode = UIViewContentModeScaleToFill;
  downloadImage.image = [UIImage imageNamed:@"worldtube_download.png"];
  [cell addSubview:downloadImage];

//
//  // Ad some constraints when the content changes.
//  cell.contentChangedCallback = ^(NamoAdCell *changedCell, NamoAd *ad) {
//    // Change install button width based on the text.
//    UIButton *button = changedCell.installButton;
//    CGRect buttonFrame = button.frame;
//    CGFloat buttonRight = buttonFrame.origin.x + buttonFrame.size.width;
//    CGFloat buttonWidth = [ad.clickTargetText sizeWithFont:button.titleLabel.font].width + 14;
//    buttonFrame.origin.x = buttonRight - buttonWidth;
//    buttonFrame.size.width = buttonWidth;
//    button.frame = buttonFrame;
//
//
//    // Change the publisher name width to take up the remaining space.
//    CGRect nameFrame = changedCell.advertiserName.frame;
//    nameFrame.size.width = button.frame.origin.x - nameFrame.origin.x - 5;
//    changedCell.advertiserName.frame = nameFrame;
//  };
}

@end