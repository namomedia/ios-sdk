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

// Callback for performing clicks. The URL is the target URL for an advertisement.
typedef BOOL(^NamoClickCallbackBlock)(NSURL *);

// Callback for adding layout constraints when ad content changes.
typedef void(^NamoAdContentChangedBlock)(NamoAdCell *, NamoAd *);

// A delegate to support getting callbacks for various user interactions.
@protocol NamoAdCellInteractionDelegate<NSObject>
@required
// Tells the delegate that the item was viewed for a significant period of time.
- (void)mightBeImpression:(NamoAdCell *)cell;

// Tells the delegate that the item was clicked.
- (void)adItemWasClicked:(NamoAdItem *)adItem;
@end


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

// A click callback, called when the user taps the click target. Set this callback if
// you wish to process the click yourself rather than letting the default behavior occur
// for clicking. You should return YES from this method in order to log a click action
// to the server.
@property(nonatomic, copy) NamoClickCallbackBlock clickCallback;

// The callback when the ad content changes. This block is reserved for use by the SDK. You
// should typically use the NamoAdCellCustomizer instead.
@property(nonatomic, copy) NamoAdContentChangedBlock contentChangedBlock;

// The currently bound ad item for this binder.
@property(nonatomic, strong) NamoAdItem *adItem;

// A placeholder image for the cell.
@property(nonatomic, strong) UIImage *placeHolderImage;

// The callback delegate for interactions.
@property(nonatomic, strong) id<NamoAdCellInteractionDelegate> interactionDelegate;

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
