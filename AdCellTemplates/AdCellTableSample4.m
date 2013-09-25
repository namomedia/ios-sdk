#import <Namo/Namo.h>
#import "AdCellTableSample4.h"

@interface AdCellTableSample4 ()

@property(nonatomic, strong) UILabel *adTitleLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@end

@implementation AdCellTableSample4

+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample4";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  CGSize maximumLabelSize = CGSizeMake(width - 50.0 - 10.0 - 9.0 - 10.0, 1000);
  CGSize titleSize = [adData.text sizeWithFont:[UIFont systemFontOfSize:12.0f]
                             constrainedToSize:maximumLabelSize
                                 lineBreakMode:NSLineBreakByWordWrapping];

  // Minimum height of 70.0f
  // Picture height of 200.0f
  return fmaxf(70.0f, titleSize.height + 10.0f + 18.0f + 18.0f + 10.0f + 200.0f);
}


- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.adImageView = [[UIImageView alloc] init];
    // TODO(nassar): Change to center in order to request ads from the ad server correctly.
    self.adImageView.contentMode = UIViewContentModeScaleAspectFill;
    [self.contentView addSubview:self.adImageView];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    // TODO(nassar): Change to center in order to request ads from the ad server correctly.
    self.advertiserIconImageView.contentMode = UIViewContentModeScaleAspectFill;
    [self.contentView addSubview:self.advertiserIconImageView];

    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.5f];
    self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                         green:0.4f
                                                          blue:0.8f
                                                         alpha:1.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.adTitleLabel = [[UILabel alloc] init];
    self.adTitleLabel.backgroundColor = [UIColor clearColor];
    self.adTitleLabel.font = [UIFont systemFontOfSize:12.0f];
    self.adTitleLabel.numberOfLines = 0;
    self.adTitleLabel.lineBreakMode = NSLineBreakByWordWrapping;
    [self.contentView addSubview:self.adTitleLabel];

    self.adIndicatorLabel = [[UILabel alloc] init];
    self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
    self.adIndicatorLabel.numberOfLines = 1;
    self.adIndicatorLabel.font = [UIFont systemFontOfSize:11.0f];
    self.adIndicatorLabel.textColor = [UIColor colorWithHue:0.0f
                                                 saturation:0.0f
                                                 brightness:0.55f
                                                      alpha:1.0f];
    self.adIndicatorLabel.text = @"Ad";
    [self.contentView addSubview:self.adIndicatorLabel];

    self.contentView.backgroundColor = [UIColor whiteColor];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
  }
  return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
  [super setSelected:selected animated:animated];

  // Configure the view for the selected state
}

- (void)layoutSubviews {
  [super layoutSubviews];

  // Place content like this.
  //  -----------------------------------------------------
  // |  advertiser |  name                                 |
  // |             |  indicator                            |
  // |             |  ad title                             |
  // | --------------------------------------------------- |
  // |                                                     |
  // |                                                     |
  // |                   image                             |
  // |                                                     |
  //  -----------------------------------------------------

  CGRect topRect;
  CGRect bottomRect;
  CGRectDivide(self.contentView.frame, &bottomRect, &topRect, 200.0f, CGRectMaxYEdge);

  CGRect leftRect;
  CGRect rightRect;
  CGRectDivide(topRect, &leftRect, &rightRect, 69.0f, CGRectMinXEdge);
  CGRect rightContentRect = UIEdgeInsetsInsetRect(rightRect,
      UIEdgeInsetsMake(10.0f, 0.0f, 10.0f, 10.0f));

  CGRect advertiserIconRect = CGRectMake(10.0, 10.0, 50.0, 50.0);

  CGRect line1Rect;
  CGRect line2Rect;
  CGRect line3Rect;
  CGRectDivide(rightContentRect, &line1Rect, &line2Rect, 16.0f, CGRectMinYEdge);
  CGRectDivide(line2Rect, &line2Rect, &line3Rect, 18.0f, CGRectMinYEdge);

  CGRect adImageRect = UIEdgeInsetsInsetRect(
      bottomRect, UIEdgeInsetsMake(5.0f, 10.0f, 10.0f, 10.0f));

  // Set the sub view locations.
  self.advertiserIconImageView.frame = advertiserIconRect;
  self.advertiserNameLabel.frame = line1Rect;
  self.adIndicatorLabel.frame = line2Rect;
  self.adTitleLabel.frame = line3Rect;
  self.adImageView.frame = adImageRect;
}

#pragma mark - NAMOAdCell implementation

- (void)setAdData:(NAMOAdData *)adData {
  [self.adImageView namo_bindAdImage:adData];
  [self.advertiserIconImageView namo_bindAdIcon:adData];
  self.advertiserNameLabel.text = adData.advertiserName;
  self.adTitleLabel.text = adData.text;
}

@end
