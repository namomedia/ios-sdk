#import <Namo/Namo.h>
#import "AdCellTableSample3.h"

@interface AdCellTableSample3 ()

@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@property(nonatomic, strong) UILabel *adTextLabel;
@end

@implementation AdCellTableSample3

+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample3";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return 80.0f;
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
    self.advertiserNameLabel.numberOfLines = 1;
    self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.5f];
    self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                         green:0.4f
                                                          blue:0.8f
                                                         alpha:1.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.numberOfLines = 2;
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.font = [UIFont systemFontOfSize:12.0f];
    [self.contentView addSubview:self.adTextLabel];

    self.adIndicatorLabel = [[UILabel alloc] init];
    self.adIndicatorLabel.numberOfLines = 1;
    self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
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
  // |             |  advertiser icon + name               |
  // |             |  Sponsored                            |
  // |    image    |  ad text                              |
  // |             |                                       |
  // |             |                                       |
  //  -----------------------------------------------------

  self.adImageView.frame = CGRectMake(10.0f, 10.0f, 50.0f, 50.0f);
  self.advertiserIconImageView.frame = CGRectMake(70.0f, 10.0f, 16.0f, 16.0f);
  self.advertiserNameLabel.frame = CGRectMake(90.0f, 10.0f, 220.0f, 16.0f);
  self.adIndicatorLabel.frame = CGRectMake(70.0f, 28.0f, 240.0f, 14.0f);
  self.adTextLabel.frame = CGRectMake(70.0f, 40.0f, 240.0f, 36.0f);
}

#pragma mark - NAMOAdCell implementation

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
}

@end
