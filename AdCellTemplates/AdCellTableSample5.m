#import <Namo/Namo.h>
#import "AdCellTableSample5.h"

@interface AdCellTableSample5 ()

@property(nonatomic, strong) NAMOAdData *adItem;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@property(nonatomic, strong) UIButton *installButton;
@property(nonatomic, strong) UIImage *placeHolderImage;
@end

@implementation AdCellTableSample5


+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample5";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return 90.0f;
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.adImageView = [[UIImageView alloc] init];
    self.adImageView.contentMode = UIViewContentModeScaleAspectFill;
    self.adImageView.clipsToBounds = YES;
    [self.contentView addSubview:self.adImageView];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.numberOfLines = 3;
    self.adTextLabel.font = [UIFont boldSystemFontOfSize:13.0];
    self.adTextLabel.textColor = [UIColor whiteColor];
    [self.contentView addSubview:self.adTextLabel];

    self.adIndicatorLabel = [[UILabel alloc] init];
    self.adIndicatorLabel.contentMode = UIViewContentModeLeft;
    self.adIndicatorLabel.text = @"Ad";
    self.adIndicatorLabel.font = [UIFont systemFontOfSize:13.0];
    self.adIndicatorLabel.textColor = [UIColor whiteColor];
    self.adIndicatorLabel.backgroundColor = [UIColor blackColor];
    [self.contentView addSubview:self.adIndicatorLabel];

    self.installButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [self.installButton setUserInteractionEnabled:NO];

    [self.installButton setTitleColor:[UIColor colorWithWhite:0 alpha:1]
                             forState:UIControlStateNormal];
    [self.installButton setTitle:@"Download App" forState:UIControlStateNormal];
    [self.contentView addSubview:self.installButton];

    self.contentView.backgroundColor = [UIColor blackColor];
  }
  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];
  // Split up the cell as follows:
  //  -----------------------------------------------------
  // |              |                                      |
  // |              |               topRect                |
  // |  imageRect   |                                      |
  // |              |--------------------------------------
  // |              |  bottomLeftRect  |  bottomRightRect  |
  //  -----------------------------------------------------

  CGRect imageRect;
  CGRect remainderRect;
  CGRectDivide(self.contentView.bounds, &imageRect, &remainderRect, 120.0f, CGRectMinXEdge);
  CGRect contentRect = UIEdgeInsetsInsetRect(
      remainderRect, UIEdgeInsetsMake(2.0f, 6.0f, 4.0f, 2.0f));

  CGRect topRect;
  CGRect bottomRect;
  CGRectDivide(contentRect, &topRect, &bottomRect, 58.0f, CGRectMinYEdge);
  CGRect bottomLeftRect;
  CGRect bottomRightRect;
  CGRectDivide(bottomRect, &bottomRightRect, &bottomLeftRect, 130.0f, CGRectMaxXEdge);

  // Set the sub view locations.
  self.adImageView.frame = imageRect;
  self.adTextLabel.frame = topRect;
  self.adIndicatorLabel.frame = bottomLeftRect;
  self.installButton.frame =
      UIEdgeInsetsInsetRect(bottomRightRect, UIEdgeInsetsMake(0.0f, 0.0f, 2.0f, 6.0f));

  // Set install button background.
  UIImage *installImage = [[NAMOInternalImageResources namoSample3Button]
      resizableImageWithCapInsets:UIEdgeInsetsMake(12.0f, 12.0f, 12.0f, 12.0f)];
  [self.installButton setBackgroundImage:installImage forState:UIControlStateNormal];
}

- (void)setAdData:(NAMOAdData *)adData {
  self.adTextLabel.text = adData.text;

  [self.adImageView namo_bindAdImage:adData];

  switch (adData.actionType) {
    case NAMOActionTypeVideo:
      [self.installButton setHidden:YES];
      break;
    case NAMOActionTypeInstall:
      [self.installButton setHidden:NO];
      break;
    case NAMOActionTypeLink:
    default:
      [self.installButton setHidden:YES];
      break;
  }
}

@end
