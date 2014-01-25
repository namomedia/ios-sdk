#import <Namo/Namo.h>
#import "AdCellTableSample2.h"

@interface AdCellTableSample2 ()

@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@end

@implementation AdCellTableSample2

+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample2";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return [AdCellTableSample2 cellHeightWithWidth:width];
}

+ (CGFloat)cellHeightWithWidth:(CGFloat)width {
  return 196.0f;
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.numberOfLines = 1;
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.0f];
    self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                         green:0.4f
                                                          blue:0.8f
                                                         alpha:1.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.advertiserIconImageView];

    self.adImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.adImageView];

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
  }

  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];

  // The cell looks like this
  //  -----------------------------------------------------
  // |  advertiser icon + name                         Ad  |
  // | --------------------------------------------------- |
  // |                                                     |
  // |                   image                             |
  // |                                                     |
  // | --------------------------------------------------- |
  // |  text                                               |
  // |                                                     |
  //  -----------------------------------------------------

  self.advertiserIconImageView.frame = CGRectMake(6.0f, 6.0f, 18.0f, 18.0f);
  self.advertiserNameLabel.frame = CGRectMake(30.0f, 6.0f, 258.0f, 18.0f);
  self.adIndicatorLabel.frame = CGRectMake(294.0f, 6.0f, 20.0f, 18.0f);
  self.adImageView.frame = CGRectMake(0.0f, 30.0f, 320.0f, 120.0f);
  self.adTextLabel.frame = CGRectMake(6.0f, 154.0f, 304.0f, 36.0f);
}

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
}

@end
