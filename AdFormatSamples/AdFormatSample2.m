#import <Namo/Namo.h>
#import "AdFormatSample2.h"

@interface AdFormatSample2 ()

@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@end

@implementation AdFormatSample2

+ (NSString *)formatIdentifier {
  return @"AdFormatSample2";
}

+ (CGSize)sizeWithMaxWidth:(CGFloat)maxWidth {
  return CGSizeMake(maxWidth, 230.0f);
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
  self.advertiserNameLabel = [[UILabel alloc] init];
  self.advertiserNameLabel.numberOfLines = 1;
  self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
  self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.0f];
  self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                       green:0.4f
                                                        blue:0.8f
                                                       alpha:1.0f];
  [self addSubview:self.advertiserNameLabel];

  self.advertiserIconImageView = [[UIImageView alloc] init];
  [self addSubview:self.advertiserIconImageView];

  self.adImageView = [[UIImageView alloc] init];
  [self addSubview:self.adImageView];

  self.adTextLabel = [[UILabel alloc] init];
  self.adTextLabel.numberOfLines = 3;
  self.adTextLabel.backgroundColor = [UIColor clearColor];
  self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
  [self addSubview:self.adTextLabel];

  self.adIndicatorLabel = [[UILabel alloc] init];
  self.adIndicatorLabel.numberOfLines = 1;
  self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
  self.adIndicatorLabel.font = [UIFont boldSystemFontOfSize:14.0];
  self.adIndicatorLabel.text = @"Ad";
  [self addSubview:self.adIndicatorLabel];

  self.backgroundColor = [UIColor whiteColor];
}

- (void)layoutSubviews {
  [super layoutSubviews];

  // The format looks like this
  //  -----------------------------------------------------
  // | icon + name                                     Ad  |
  // | --------------------------------------------------- |
  // |                                                     |
  // |                                                     |
  // |                      image                          |
  // |                                                     |
  // |                     widthx160                       |
  // |                                                     |
  // |                                                     |
  // | --------------------------------------------------- |
  // |  text                                               |                                                     |
  //  -----------------------------------------------------

  // Raw sizes
  static CGFloat imageHeight = 160.0f;
  static CGFloat iconSize = 18.0f;
  static CGFloat indicatorWidth = 20.0f;
  static CGFloat paddingWidth = 6.0f;
  static CGFloat paddingHeight = 4.0f;

  CGRect contentRect = CGRectInset(self.bounds, paddingWidth, 0);

  // Divide vertically
  CGFloat topHeight = iconSize + paddingHeight * 2;
  CGRect topRect;
  CGRect tempRect;
  CGRect middleRect;
  CGRect textRect;
  CGRectDivide(contentRect, &topRect, &tempRect, topHeight, CGRectMinYEdge);
  CGRectDivide(tempRect, &middleRect, &textRect, imageHeight, CGRectMinYEdge);
  CGRect topContentRect = CGRectInset(topRect, 0, paddingHeight);

  // Divide horizontally for icon, name, and indicator dimensions
  CGRect titleRect;
  CGRect indicatorRect;
  CGRectDivide(topContentRect, &indicatorRect, &titleRect, indicatorWidth, CGRectMaxXEdge);
  CGRect iconRect;
  CGRect nameRect;
  CGRectDivide(titleRect, &iconRect, &nameRect, iconSize, CGRectMinXEdge);

  self.advertiserIconImageView.frame = iconRect;
  self.advertiserNameLabel.frame = CGRectInset(nameRect, 4.0f, 0.0f);
  self.adIndicatorLabel.frame = indicatorRect;
  self.adImageView.frame = middleRect;
  self.adTextLabel.frame = textRect;
}

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
}

@end
