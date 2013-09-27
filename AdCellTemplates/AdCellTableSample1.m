#import <Namo/Namo.h>
#import "AdCellTableSample1.h"

@interface AdCellTableSample1 ()

@property(nonatomic, strong) UILabel *adTitleLabel;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UIImageView *adIndicatorImageView;
@end


@implementation AdCellTableSample1

+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample1";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return 100.0f;
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.adImageView = [[UIImageView alloc] init];
    self.adImageView.contentMode = UIViewContentModeCenter;
    [self.contentView addSubview:self.adImageView];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    self.advertiserIconImageView.contentMode = UIViewContentModeCenter;
    [self.contentView addSubview:self.advertiserIconImageView];

    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.adIndicatorImageView = [[UIImageView alloc] init];
    self.adIndicatorImageView.contentMode = UIViewContentModeTopRight;
    self.adIndicatorImageView.image = [NAMOAdCellImageResources namoAdIndicator];
    [self.contentView addSubview:self.adIndicatorImageView];

    self.adTitleLabel = [[UILabel alloc] init];
    self.adTitleLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.backgroundColor = [UIColor redColor];
    self.adTitleLabel.font = [UIFont boldSystemFontOfSize:16.0f];
    [self.contentView addSubview:self.adTitleLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.numberOfLines = 3;
    self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.adTextLabel];

    self.contentView.backgroundColor = [UIColor whiteColor];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
  }
  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];

  // The cell looks like this
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
}

#pragma mark - NAMOAdCell implementation

- (void)setAdData:(NAMOAdData *)adData {
  [self.adImageView namo_bindAdImage:adData];
  [self.advertiserIconImageView namo_bindAdIcon:adData];
  self.advertiserNameLabel.text = adData.advertiserName;
  self.adTitleLabel.text = adData.title;
  self.adTextLabel.text = adData.text;
}

@end
