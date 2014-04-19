#import <Namo/Namo.h>
#import "AdFormatSample4.h"

@interface AdFormatSample4 ()

@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@end

@implementation AdFormatSample4

+ (NSString *)formatIdentifier {
  return @"AdFormatSample4";
}

+ (CGSize)sizeWithMaxWidth:(CGFloat)maxWidth {
  return CGSizeMake(maxWidth, 200.0f);
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
  [self addSubview:self.adImageView];

  self.advertiserIconImageView = [[UIImageView alloc] init];
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
  self.adTextLabel.backgroundColor = [UIColor clearColor];
  self.adTextLabel.font = [UIFont systemFontOfSize:12.0f];
  self.adTextLabel.numberOfLines = 1;
  [self addSubview:self.adTextLabel];

  self.adIndicatorLabel = [[UILabel alloc] init];
  self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
  self.adIndicatorLabel.numberOfLines = 1;
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
  // |  advertiser |  advertiser name                      |
  // |     icon    |  Sponsored                            |
  // |             |  ad text                              |
  // | --------------------------------------------------- |
  // |                                                     |
  // |                                                     |
  // |                   image                             |
  // |                                                     |
  //  -----------------------------------------------------

  // Raw sizes
  static CGFloat iconSize = 32.0f;
  static CGFloat paddingWidth = 10.0f;
  static CGFloat paddingHeight = 6.0f;
  static CGFloat titleHeight = 18.0f;
  static CGFloat indicatorHeight = 13.0f;
  static CGFloat textHeight = 16.0f;

  CGRect contentRect = CGRectInset(self.bounds, paddingWidth, paddingHeight);
  CGFloat textLeft = paddingWidth + iconSize;
  CGFloat imageTop = titleHeight + indicatorHeight + textHeight + paddingHeight;

  // Divide vertically
  CGRect topRect;
  CGRect imageRect;
  CGRectDivide(contentRect, &topRect, &imageRect, imageTop, CGRectMinYEdge);

  // Divide horizontally
  CGRect leftRect;
  CGRect rightRect;
  CGRectDivide(topRect, &leftRect, &rightRect, textLeft, CGRectMinXEdge);
  CGRect iconRect = CGRectMake(leftRect.origin.x, leftRect.origin.y, iconSize, iconSize);

  // Divide vertically for lines 1 to 3
  CGRect line1Rect;
  CGRect line2Rect;
  CGRect line3Rect;
  CGRect tempRect;
  CGRectDivide(rightRect, &line1Rect, &tempRect, titleHeight, CGRectMinYEdge);
  CGRectDivide(tempRect, &line2Rect, &line3Rect, indicatorHeight, CGRectMinYEdge);

  self.advertiserIconImageView.frame = iconRect;
  self.advertiserNameLabel.frame = line1Rect;
  self.adIndicatorLabel.frame = line2Rect;
  self.adTextLabel.frame = line3Rect;
  self.adImageView.frame = imageRect;
}

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
}

@end
