#import <Namo/Namo.h>
#import "AdCellCollectionSample1.h"

@interface AdCellCollectionSample1 ()
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@end

@implementation AdCellCollectionSample1

+ (NSString *)reuseIdentifier {
  return @"AdCellCollectionSample1";
}

+ (CGSize)cellSizeWithData:(NAMOAdData *)adData {
  return CGSizeMake(320.0f, 168.0f);
}

- (id)initWithFrame:(CGRect)frame {
  self = [super initWithFrame:frame];
  if (self) {
    self.backgroundColor = [UIColor whiteColor];

    self.adImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.adImageView];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.numberOfLines = 2;
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.adTextLabel];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.advertiserIconImageView];

    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.numberOfLines = 1;
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.0f];
    self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                  green:0.4f
                                                   blue:0.8f
                                                  alpha:1.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.adIndicatorLabel = [[UILabel alloc] init];
    self.adIndicatorLabel.numberOfLines = 1;
    self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
    self.adIndicatorLabel.font = [UIFont boldSystemFontOfSize:14.0];
    self.adIndicatorLabel.text = @"Ad";
    [self.contentView addSubview:self.adIndicatorLabel];
  }
  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];

  // The cell looks like this
  //  -----------------------------------------------------
  // |                                                     |
  // |                  ad image                           |
  // |                                                     |
  // | --------------------------------------------------- |
  // |  ad text                                            |
  // |                                                     |
  // |                                                     |
  // |  advertiser icon + name                         Ad  |
  //  -----------------------------------------------------

  self.adImageView.frame = CGRectMake(0.0f, 0.0f, 320.0f, 100.0f);
  self.adTextLabel.frame = CGRectMake(8.0f, 104.0f, 304.0f, 36.0f);
  self.advertiserIconImageView.frame = CGRectMake(8.0f, 144.0f, 18.0f, 18.0f);
  self.advertiserNameLabel.frame = CGRectMake(28.0f, 144.0f, 260.0f, 18.0f);
  self.adIndicatorLabel.frame = CGRectMake(290.0f, 144.0f, 22.0f, 18.0f);
}

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
}
@end
