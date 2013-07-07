//
// NamoAdCell.h
// NamoMedia Ads SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// NamoAdCell defines a standard table view cell for displaying an advertisement. To customize
// the look and behavior of a NamoAdCell use NamoAdCellDelegate. Alternatively, you can
// subclass NamoAdCell to provide a specialized ad format.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "NamoAd.h"

@class NamoAdItem;
@class NamoAdCell;

// Callback for when the cell performed layout.
typedef void(^NamoLayoutChangedBlock)(NamoAdCell *);

// Callback for when the ad content changes.
typedef void(^NamoAdContentChangedBlock)(NamoAdCell *, NamoAd *);

// Callback for actions, suc as impressions and clicks.
typedef void(^NamoActionBlock)(NamoAdCell *);

extern CGFloat const NamoDefaultCellHeight;

@interface NamoAdCell : UITableViewCell

// The ad title view for this cell.
@property(nonatomic, strong) IBOutlet UILabel *adTitle;

// The ad text view for this cell.
@property(nonatomic, strong) IBOutlet UILabel *adText;

// The ad image view for this cell.
@property(nonatomic, strong) IBOutlet UIImageView *adImage;

// The advertiser name view for this cell.
@property(nonatomic, strong) IBOutlet UILabel *advertiserName;

// The advertiser logo view for this cell.
@property(nonatomic, strong) IBOutlet UIImageView *advertiserLogo;

// The click label view for this cell.
@property(nonatomic, strong) IBOutlet UILabel *clickLabel;

// The sponsored text label for this cell.
@property(nonatomic, strong) IBOutlet UILabel *sponsoredText;

// The install button for this cell.
@property(nonatomic, strong) IBOutlet UIButton *installButton;

// The click target for this cell. Tapping this target or any child will perform
// a click action, typically browsing to an modal web page using an advertising link.
// By default the entire cell is the click target - set this property to specify
// a custom target.
@property(nonatomic, strong) UIView *clickTarget;

// A callback when the ad layout changes. This block is reserved for use by the SDK. You
// should typically use NamoAdCellCustomizer instead.
@property(nonatomic, copy) NamoLayoutChangedBlock layoutChangedCallback;

// The callback when the ad content changes. This block is reserved for use by the SDK. You
// should typically use the NamoAdCellCustomizer instead.
@property(nonatomic, copy) NamoAdContentChangedBlock contentChangedCallback;

// An impression callback, called when the ad has been viewed for a significant period
// of time.
@property(nonatomic, copy) NamoActionBlock impressionCallback;

// A click callback, called when the user taps the click target. Set this callback if
// you wish to process the click yourself rather than letting the default behavior occur
// for clicking.
@property(nonatomic, copy) NamoActionBlock clickCallback;

// The currently bound ad item for this binder.
@property(nonatomic, strong) NamoAdItem *adItem;

// A placeholder image for the cell.
@property(nonatomic, strong) UIImage *placeHolderImage;

// Designated initializer. Initializes the cell with an identifier.
- (id)initWithIdentifier:(NSString *)identifier;

// Sets up the cell layout, called if the cell is not loaded from a nib file. Override
// this message to perform custom layout.
- (void)layoutCell;

// Returns the current ad content for this cell.
- (NamoAd *)adContent;

// Sets the ad content of the cell. Derived classes can override this method to perform
// custom ad binding.
- (void)bindAdContent:(NamoAd *)adContent;
@end
