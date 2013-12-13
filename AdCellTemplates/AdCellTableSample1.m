#import <Namo/Namo.h>
#import "AdCellTableSample1.h"

@interface AdCellTableSample1 ()

@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@end

@implementation AdCellTableSample1

+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample1";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return 84.0f;
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
    self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.0f];
    self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                         green:0.4f
                                                          blue:0.8f
                                                         alpha:1.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.numberOfLines = 3;
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.adTextLabel];

    self.adIndicatorLabel = [[UILabel alloc] init];
    self.adIndicatorLabel.numberOfLines = 1;
    self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
    self.adIndicatorLabel.font = [UIFont boldSystemFontOfSize:14.0];
    self.adIndicatorLabel.text = @"Ad";
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
  // |             |  advertiser icon + name           Ad  |
  // |             |  ad text                              |
  // |  ad image   |                                       |
  // |             |                                       |
  // |             |                                       |
  //  -----------------------------------------------------

  // Set the sub view locations.
  self.adImageView.frame = CGRectMake(0.0f, 0.0f, 96.0f, 83.5f);
  self.advertiserIconImageView.frame = CGRectMake(100.0f, 4.0f, 18.0f, 18.0f);
  self.advertiserNameLabel.frame = CGRectMake(122.0f, 4.0f, 170.0f, 18.0f);
  self.adIndicatorLabel.frame = CGRectMake(294.0f, 4.0f, 20.0f, 18.0f);
  self.adTextLabel.frame = CGRectMake(100.0f, 26.0f, 214.0f, 54.0f);
}

#pragma mark - NAMOAdCell implementation

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
}

@end
