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

// Callback for performing expansion. The first argument is the new expand state. The second
// argument indicates whether to perform animations.
typedef BOOL(^NamoExpandCallbackBlock)(BOOL, BOOL);

// Callback for performing clicks. The URL is the target URL for an advertisement.
typedef BOOL(^NamoClickCallbackBlock)(NSURL *);


@protocol NamoAdCellInteractionDelegate<NSObject>
@required
// Tells the delegate that the item was viewed for a significant period of time.
- (void)mightBeImpression:(NamoAdCell *)cell;

// Tells the delegate that the item was clicked.
- (void)adItemWasClicked:(NamoAdItem *)adItem;

// Tells the delegate that the item was expanded or unexpanded.
- (void)adItemWasExpanded:(NamoAdItem *)adItem withNewState:(BOOL)expanded;
@end

extern CGFloat const NamoDefaultCellHeight;
extern CGFloat const NamoDefaultExpandedCellHeight;

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

// The expand target for this cell. If supports supportsExpansion is set to YES, tapping
// the expand target or any child view will perform an expand action. By default the entire
// cell is an expand target - set this property to specify a custom target.
@property(nonatomic, strong) UIView *expandTarget;

// An expand callback, called when the user taps the expand target. Set this callback if
// you wish to customize the expand behavior rather than letting the default expansion occur.
// You should return YES from this method in order to log an expand action to the server.
@property(nonatomic, copy) NamoExpandCallbackBlock expandCallback;

// The currently bound ad item for this binder.
@property(nonatomic, strong) NamoAdItem *adItem;

// A placeholder image for the cell.
@property(nonatomic, strong) UIImage *placeHolderImage;

// The callback delegate for interactions.
@property(nonatomic, strong) id<NamoAdCellInteractionDelegate> delegate;

// Returns whether expansion is enabled.
@property(nonatomic) BOOL supportsExpansion;

// Returns the expansion height.
@property(nonatomic) CGFloat expandedHeight;

// Designated initializer. Initializes the cell with an identifier.
- (id)initWithIdentifier:(NSString *)identifier;

// Setup the cell layout. This is called as part of initialization if not loading from a nib
// file. Derived classes can override setupCellLayout to perform custom layout.
- (void)setupCellLayout;

// Returns the current ad content for this cell.
- (NamoAd *)adContent;

// Sets the ad content of the cell. Derived classes can override this method to perform
// custom ad binding.
- (void)bindAdContent:(NamoAd *)adContent;

// Run default expansion behavior for an ad cell. Does nothing if expansion is
// not enabled on this cell, or if the cell is already in the given expand state.
- (BOOL)performDefaultExpansion:(BOOL)expand shouldAnimate:(BOOL)animate;
@end
