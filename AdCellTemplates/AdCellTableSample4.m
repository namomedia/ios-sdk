#import <Namo/Namo.h>
#import "AdCellTableSample4.h"

@interface AdCellTableSample4 ()

@property(nonatomic, strong) UILabel *adTextLabel;
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
  return [AdCellTableSample4 cellHeightWithWidth:width];
}

+ (CGFloat)cellHeightWithWidth:(CGFloat)width {
  return 200.0f;
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.adImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.adImageView];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.advertiserIconImageView];

    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.numberOfLines = 1;
    self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.5f];
    self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                         green:0.4f
                                                          blue:0.8f
                                                         alpha:1.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.font = [UIFont systemFontOfSize:12.0f];
    self.adTextLabel.numberOfLines = 1;
    [self.contentView addSubview:self.adTextLabel];

    self.adIndicatorLabel = [[UILabel alloc] init];
    self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
    self.adIndicatorLabel.numberOfLines = 1;
    self.adIndicatorLabel.font = [UIFont systemFontOfSize:11.0f];
    self.adIndicatorLabel.textColor = [UIColor colorWithHue:0.0f
                                                 saturation:0.0f
                                                 brightness:0.55f
                                                      alpha:1.0f];
    self.adIndicatorLabel.text = @"Sponsored";
    [self.contentView addSubview:self.adIndicatorLabel];

    self.contentView.backgroundColor = [UIColor whiteColor];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
  }
  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];

  // The cell looks like this
  //  -----------------------------------------------------
  // |  advertiser |  advertiser name                      |
  // |     icon    |  Sponsored                            |
  // |             |  ad text                              |
  // | --------------------------------------------------- |
  // |                                                     |
  // |                                                     |
  // |                   image                             |
  // |                                                     |
  //  -----------------------------------------------------

  self.advertiserIconImageView.frame = CGRectMake(10.0f, 10.0f, 50.0f, 50.0f);
  self.advertiserNameLabel.frame = CGRectMake(70.0f, 10.0f, 240.0f, 16.0f);
  self.adIndicatorLabel.frame = CGRectMake(70.0f, 28.0f, 240.0f, 14.0f);
  self.adTextLabel.frame = CGRectMake(70.0f, 44.0f, 240.0f, 16.0f);
  self.adImageView.frame = CGRectMake(10.0f, 70.0f, 300.0f, 120.0f);
}

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
}

@end
