//
// NamoAdContentBinder.h
// NamoAds iOS SDK
//
// Copyright (c) 2013 NamoMedia. All rights reserved.
//
// The NamoAdContentBinder class defines methods for binding a namo ad to a table view cell.
//
// You should not create a NamoAdContentBinder directly. Instead, create a NamoAdCellProvider
// and use the NamoAdContentBinder received in the shouldFillCell:usingBinder message.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class NamoAdItem;
@class NamoAd;

// Callback for performing expansion. The first argument is the new expand state. The second
// argument indicates whether to perform animations.
typedef BOOL(^NamoExpandCallbackBlock)(BOOL, BOOL);

typedef BOOL(^NamoClickCallbackBlock)(NSURL *);

@protocol NamoAdContentBinderDelegate<NSObject>
@required
// Tells the delegate that the item was viewed.
- (void)mightBeViewed:(UITableViewCell *)cell;

// Tells the delegate that the item was expanded or unexpanded.
- (void)adItemWasExpanded:(NamoAdItem *)adItem withNewState:(BOOL)expanded;

// Tells the delegate that the item was clicked.
- (void)adItemWasClicked:(NamoAdItem *)adItem;
@end

@interface NamoAdContentBinder : NSObject
// The currently bound ad item for this binder.
@property(nonatomic, strong) NamoAdItem *adItem;

// A placeholder image for the cell.
@property(nonatomic, strong) UIImage *placeHolderImage;

// The callback delegate for a NamoAdContentBinder.
@property(nonatomic, strong) id<NamoAdContentBinderDelegate> delegate;

// Returns whether this binder supports ad expansion.
@property(nonatomic) BOOL supportsExpansion;

// Returns the frame for the ad text.
@property(nonatomic) CGRect textFrame;

// Returns the frame for the ad title.
@property(nonatomic) CGRect titleFrame;

// Returns the frame for the ad image.
@property(nonatomic) CGRect imageFrame;

// Returns the frame for the advertiser logo.
@property(nonatomic) CGRect advertLogoFrame;

// Returns the frame for the advertiser name.
@property(nonatomic) CGRect advertNameFrame;

// Returns the frame for the expanded ad text.
@property(nonatomic) CGRect expandedTextFrame;

// Returns the frame for the expanded ad title.
@property(nonatomic) CGRect expandedTitleFrame;

// Returns the frame for the expanded ad image.
@property(nonatomic) CGRect expandedImageFrame;

// Returns the frame for the expanded advertiser logo.
@property(nonatomic) CGRect expandedAdvertLogoFrame;

// Returns the frame for the expanded advertiser name.
@property(nonatomic) CGRect expandedAdvertNameFrame;

// Initializes the Binder using a table view cell.
- (id)initWithCell:(UITableViewCell *)cell height:(CGFloat)height;

// Initializes the Binder using a table view cell.
- (id)initWithCell:(UITableViewCell *)cell
            height:(CGFloat)height
    expandedHeight:(CGFloat)expandedHeight;

// Returns the advertising content for this binder. While you should typically use
// the fill methods to allow the SDK to track clicks and impressions on your views,
// you can alternatively use this object to directly set your view content.
- (NamoAd *)adContent;

// Fills the given label with the ad title.
- (void)fillAdTitleUsingView:(UILabel *)label;

// Fills the given label with the ad text.
- (void)fillAdTextUsingView:(UILabel *)label;

// Fills the given view with the ad image.
- (void)fillAdImageUsingView:(UIImageView *)imageView;

// Fills the given label with the advertiser name.
- (void)fillAdvertiserNameUsingView:(UILabel *)label;

// Fills the given view with the advertiser logo.
- (void)fillAdvertiserLogoUsingView:(UIImageView *)imageView;

// Fills the given view with a friendly label to display for click text.
- (void)fillClickLabelUsingView:(UILabel *)label;

// A convenience method to fill the given views with the ad title, text, and image. These are
// the minimal fields you should typically use when displaying an ad.
- (void)fillRequiredViewsForAdTitle:(UILabel *)titleLabel
                             adText:(UILabel *)textLabel
                            adImage:(UIImageView *)imageView;

// Fill the cell content using the entire set of available fields for displaying an ad.
// Pas nil for fields you don't wish to fill.
- (void)fillViewsForAdTitle:(UILabel *)titleLabel
                     adText:(UILabel *)textLabel
                    adImage:(UIImageView *)mainImage
             advertiserName:(UILabel *)advertiserNameLabel
             advertiserLogo:(UIImageView *)advertiserLogoImageView
                 clickLabel:(UILabel *)clickLabel;

// Binds the click target view. Tapping on the target or any child will perform a click
// action. If you wish to perform a custom action when clicking pass a callback block
// and return a BOOL indicating whether the click was successfully performed.
- (void)bindClickTarget:(UIView *)target
               callback:(NamoClickCallbackBlock)callback;

// See bindClickTarget:callback. This version uses the default expand behavior, which
// opens the click url in a WebView.
- (void)bindClickTarget:(UIView *)target;

// Binds the click target view. Tapping on the target or any child will perform an expand
// action. If you wish to perform a custom action when expanding pass a callback block
// and return a BOOL indicating whether the expansion was successfully performed.
- (void)bindExpandTarget:(UIView *)target
                callback:(NamoExpandCallbackBlock)callback;

// See bindExpandTarget:callback. This version uses the default expand behavior, which
// animates the ad image view to the bottom of the cell.
- (void)bindExpandTarget:(UIView *)target;

// Run default expansion behavior for an ad cell.
- (BOOL)performDefaultExpand:(BOOL)expand withAnimations:(BOOL)animate;
@end
