#import <Namo/Namo.h>
#import "AdCellTableSample2.h"

@interface AdCellTableSample2 ()

@property(nonatomic, strong) UILabel *adTitleLabel;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UIImageView *adIndicatorImageView;
@end

@implementation AdCellTableSample2

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    // create and add subviews
    self.adTitleLabel = [[UILabel alloc] init];
    self.adTitleLabel.font = [UIFont boldSystemFontOfSize:16.0f];
    [self addSubview:self.adTitleLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.numberOfLines = 3;
    self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
    [self addSubview:self.adTextLabel];

    self.advertiserNameLabel = [[UILabel alloc] init];
    [self addSubview:self.advertiserNameLabel];

    self.adImageView = [[UIImageView alloc] init];
    [self addSubview:self.adImageView];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    [self addSubview:self.advertiserIconImageView];

    self.adIndicatorImageView = [[UIImageView alloc] init];
    [self addSubview:self.adIndicatorImageView];
  }

  return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
  [super setSelected:selected animated:animated];

  // Configure the view for the selected state
}

#pragma mark - Layout logic

- (void)layoutSubviews {
  [super layoutSubviews];

  CGFloat cellWidth = self.bounds.size.width;

  self.advertiserIconImageView.frame = CGRectMake(2.0f, 2.0f, 16.0f, 16.0f);
  self.advertiserNameLabel.frame = CGRectMake(20.0f, 2.0f, cellWidth - 20.0f, 16.0f);

  self.adIndicatorImageView.frame = CGRectMake(cellWidth - 64.0f, 6.0f, 62.0f, 8.0f);

  self.adImageView.frame = CGRectMake(2.0f, 20.0f, cellWidth - 4.0f, 100.0f);

  CGFloat imageViewBottom = CGRectGetMaxY(self.adImageView.frame);

  self.adTitleLabel.frame = CGRectMake(2.0f, imageViewBottom + 2.0f, cellWidth - 4.0f, 18.0f);
  self.adTextLabel.frame =
      CGRectMake(2.0f, imageViewBottom + 18.0f + 4.0f, cellWidth - 4.0f, 52.0f);
}

#pragma mark - NAMOAdCell implementation

+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample2";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return 200.0f;
}

- (void)setAdData:(NAMOAdData *)adData {
  self.adTextLabel.text = adData.text;
  self.adTextLabel.text = adData.title;
  self.advertiserNameLabel.text = adData.advertiserName;

  [self.adImageView namo_bindAdImage:adData];
  [self.advertiserIconImageView namo_bindAdIcon:adData];

  self.adIndicatorImageView.image = [NAMOInternalImageResources namoAdIndicator];
}

@end
