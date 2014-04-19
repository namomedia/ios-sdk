#import <Namo/Namo.h>
#import "AdFormatSample3.h"

@interface AdFormatSample3 ()

@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@property(nonatomic, strong) UILabel *adTextLabel;
@end

@implementation AdFormatSample3

+ (NSString *)formatIdentifier {
  return @"AdFormatSample3";
}

+ (CGSize)sizeWithMaxWidth:(CGFloat)maxWidth {
  return CGSizeMake(maxWidth, 80.0f);
}

- (instancetype)initWithFrame:(CGRect)frame {
  self = [super initWithFrame:frame];
  if (self) {
    [self createSubViews];
  }
  return self;
}

- (instancetype)initWithCoder:(NSCoder *)coder {
  self = [super initWithCoder:coder];
  if (self) {
    [self createSubViews];
  }
  return self;
}

- (void)createSubViews {
  self.adImageView = [[UIImageView alloc] init];
  self.adImageView.contentMode = UIViewContentModeCenter;
  [self addSubview:self.adImageView];

  self.advertiserIconImageView = [[UIImageView alloc] init];
  self.advertiserIconImageView.contentMode = UIViewContentModeCenter;
  [self addSubview:self.advertiserIconImageView];

  self.advertiserNameLabel = [[UILabel alloc] init];
  self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
  self.advertiserNameLabel.numberOfLines = 1;
  self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.5f];
  self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                       green:0.4f
                                                        blue:0.8f
                                                       alpha:1.0f];
  [self addSubview:self.advertiserNameLabel];

  self.adTextLabel = [[UILabel alloc] init];
  self.adTextLabel.numberOfLines = 2;
  self.adTextLabel.backgroundColor = [UIColor clearColor];
  self.adTextLabel.font = [UIFont systemFontOfSize:12.0f];
  [self addSubview:self.adTextLabel];

  self.adIndicatorLabel = [[UILabel alloc] init];
  self.adIndicatorLabel.numberOfLines = 1;
  self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
  self.adIndicatorLabel.font = [UIFont systemFontOfSize:11.0f];
  self.adIndicatorLabel.textColor = [UIColor colorWithHue:0.0f
                                               saturation:0.0f
                                               brightness:0.55f
                                                    alpha:1.0f];
  self.adIndicatorLabel.text = @"Sponsored";
  [self addSubview:self.adIndicatorLabel];

  self.backgroundColor = [UIColor whiteColor];
}

- (void)layoutSubviews {
  [super layoutSubviews];

  // The format looks like this
  //  -----------------------------------------------------
  // |  -------    icon + name                             |
  // | | image |   Sponsored                               |
  // | | 50x50 |   ad text                                 |
  // | |       |                                           |
  // |  -------                                            |
  //  -----------------------------------------------------

  // Raw sizes
  static CGFloat imageSize = 50.0f;
  static CGFloat iconSize = 16.0f;
  static CGFloat paddingWidth = 10.0f;
  static CGFloat paddingHeight = 8.0f;
  static CGFloat lineHeight = 16.0f;

  CGRect contentRect = CGRectInset(self.bounds, paddingWidth, paddingHeight);
  CGFloat textLeft = paddingWidth + imageSize;

  // Divide horizontally
  CGRect leftRect;
  CGRect rightRect;
  CGRectDivide(contentRect, &leftRect, &rightRect, textLeft, CGRectMinXEdge);
  CGRect imageRect = CGRectMake(leftRect.origin.x, leftRect.origin.y, 50.0f, 50.0f);

  // Divide vertically for lines 1 to 3
  CGRect line1Rect;
  CGRect line2Rect;
  CGRect line3Rect;
  CGRect tempRect;
  CGRectDivide(rightRect, &line1Rect, &tempRect, lineHeight, CGRectMinYEdge);
  CGRectDivide(tempRect, &line2Rect, &line3Rect, lineHeight, CGRectMinYEdge);

  // Divide horizontally for icon and name
  CGRect iconRect;
  CGRect nameRect;
  CGRectDivide(line1Rect, &iconRect, &nameRect, iconSize, CGRectMinXEdge);

  self.advertiserIconImageView.frame = iconRect;
  self.advertiserNameLabel.frame = CGRectInset(nameRect, 4.0f, 0.0f);
  self.adIndicatorLabel.frame = line2Rect;
  self.adImageView.frame = imageRect;
  self.adTextLabel.frame = line3Rect;
}

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
}

@end
