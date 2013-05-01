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

// See bindClickTarget:callback. This version uses the default click behavior, which
// opens the click url in a WebView.
- (void)bindClickTarget:(UIView *)target;

// Binds a click target view. Tapping on the target or any child will perform a click
// action. By default the entire cell is a click target - use this method to override
// that behavior. You may choose to perform click handling yourself, in which case
// you can pass a callback that returns a BOOL indicating whether the click was
// successfully performed.
- (void)bindClickTarget:(UIView *)target
               callback:(NamoClickCallbackBlock)callback;

// See bindExpandTarget:callback. This version uses the default expand behavior, which
// animates the ad image view to the bottom of the cell.
- (void)bindExpandTarget:(UIView *)target;

// Binds the expand target view. Tapping on the target or any child will perform an expand
// action. By default the entire cell is an expand target - use this method to override that
// behavior. You may choose to perform expansion handling yourself, in which case you can
// can pass a BOOL indicating the expand was successfully performed.
- (void)bindExpandTarget:(UIView *)target
                callback:(NamoExpandCallbackBlock)callback;

// Run default expansion behavior for an ad cell. Does nothing if expansion is
// not enabled on this cell, or if the cell is already in the given expand state.
- (BOOL)performExpand:(BOOL)expand shouldAnimate:(BOOL)animate;
@end
