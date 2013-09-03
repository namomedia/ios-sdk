#import "UIImageView+NAMO_WebCache.h"

#import "NAMOAdData.h"
#import "NAMOTableViewAdCellThumb.h"
#import "UIImageView+NAMOImage.h"


@implementation NAMOTableViewAdCellThumb

+ (NSString *)reuseIdentifier {
  return @"NAMOTableViewAdCellThumb";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return 100.0f;
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.adImageView = [[UIImageView alloc] init];
    // TODO(nassar): Change to center in order to request ads from the ad server correctly.
    self.adImageView.contentMode = UIViewContentModeScaleAspectFill;
    [self addSubview:self.adImageView];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    // TODO(nassar): Change to center in order to request ads from the ad server correctly.
    self.advertiserIconImageView.contentMode = UIViewContentModeScaleAspectFill;
    [self addSubview:self.advertiserIconImageView];

    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.font = [UIFont systemFontOfSize:14.0f];
    [self addSubview:self.advertiserNameLabel];

    self.adIndicatorImageView = [[UIImageView alloc] init];
    self.adIndicatorImageView.contentMode = UIViewContentModeTopRight;
    self.adIndicatorImageView.image = [UIImage imageNamed:@"namo-ad-indicator.png"];
    [self addSubview:self.adIndicatorImageView];

    self.adTitleLabel = [[UILabel alloc] init];
    self.adTitleLabel.backgroundColor = [UIColor clearColor];
    self.adTitleLabel.font = [UIFont boldSystemFontOfSize:16.0f];
    [self addSubview:self.adTitleLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.numberOfLines = 3;
    self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
    [self addSubview:self.adTextLabel];

    self.adOverlayImageView = [[UIImageView alloc] init];
    self.adOverlayImageView.contentMode = UIViewContentModeCenter;
    [self addSubview:self.adOverlayImageView];

    self.contentView.backgroundColor = [UIColor whiteColor];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
  }
  return self;
}

#pragma mark - Layout logic

- (void)layoutSubviews {
  [super layoutSubviews];

  // Place content like this.
  //  -----------------------------------------------------
  // |             |  advertiser icon + name  |  indicator |
  // |             |  ad title                             |
  // |    image    |  ad text                              |
  // |             |                                       |
  // |             |                                       |
  //  -----------------------------------------------------

  CGRect imageRect;
  CGRect remainderRect;
  CGRectDivide(self.contentView.frame, &imageRect, &remainderRect, 96.0f,
      CGRectMinXEdge);
  CGRect contentRect = UIEdgeInsetsInsetRect(
      remainderRect, UIEdgeInsetsMake(2.0f, 6.0f, 2.0f, 2.0f));

  CGRect line1Rect;
  CGRect line2Rect;
  CGRect line3Rect;
  CGRectDivide(contentRect, &line1Rect, &line2Rect, 18.0f, CGRectMinYEdge);
  CGRectDivide(line2Rect, &line2Rect, &line3Rect, 20.0f, CGRectMinYEdge);
  CGRect advertiserRect;
  CGRect adIndicatorRect;
  CGRectDivide(line1Rect, &adIndicatorRect, &advertiserRect, 62.0f, CGRectMaxXEdge);

  CGRect advertiserIconRect;
  CGRect advertiserNameRect;
  CGRectDivide(advertiserRect, &advertiserIconRect, &advertiserNameRect,
      16.0f, CGRectMinXEdge);

  // Set the sub view locations.
  self.adImageView.frame = imageRect;
  self.advertiserIconImageView.frame = advertiserIconRect;
  self.advertiserNameLabel.frame = CGRectOffset(advertiserNameRect, 4.0f, 0.0f);
  self.adIndicatorImageView.frame = adIndicatorRect;
  self.adTitleLabel.frame = line2Rect;
  self.adTextLabel.frame = line3Rect;

  self.adOverlayImageView.frame = imageRect;
}

#pragma mark - NAMOAdCell implementation

- (void)setAdData:(NAMOAdData *)adData {
  [self.adImageView namo_bindAdImage:adData];
  [self.advertiserIconImageView namo_bindAdIcon:adData];
  self.advertiserNameLabel.text = adData.advertiserName;
  self.adTitleLabel.text = adData.title;
  self.adTextLabel.text = adData.text;

  // Fix the overlay image
  switch (adData.actionType) {
    case NAMOActionTypeVideo:
      [self.adOverlayImageView setHidden:NO];
      self.adOverlayImageView.image = [UIImage imageNamed:@"namo-action-type-overlay-video.png"];
      break;
    case NAMOActionTypeInstall:
      [self.adOverlayImageView setHidden:NO];
      self.adOverlayImageView.image = [UIImage imageNamed:@"namo-action-type-overlay-install.png"];
      break;
    case NAMOActionTypeLink:
    default:
      [self.adOverlayImageView setHidden:YES];
      break;
  }
}

@end
