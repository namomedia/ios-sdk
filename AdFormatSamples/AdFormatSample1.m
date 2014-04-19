#import <Namo/Namo.h>
#import "AdFormatSample1.h"

@interface AdFormatSample1 ()

@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@end

@implementation AdFormatSample1

+ (NSString *)formatIdentifier {
  return @"AdFormatSample1";
}

+ (CGSize)sizeWithMaxWidth:(CGFloat)maxWidth {
  return CGSizeMake(maxWidth, 90.5f);
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
  self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.0f];
  self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                       green:0.4f
                                                        blue:0.8f
                                                       alpha:1.0f];
  [self addSubview:self.advertiserNameLabel];

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
  // |             |  icon + name                      Ad  |
  // |   image     |  ad text                              |
  // |             |                                       |
  // |   90x90     |                                       |
  // |             |                                       |
  //  -----------------------------------------------------

  // Raw sizes
  static CGFloat imageSize = 90.0f;
  static CGFloat iconSize = 18.0f;
  static CGFloat indicatorWidth = 20.0f;
  static CGFloat paddingWidth = 6.0f;
  static CGFloat paddingHeight = 4.0f;

  // Remove a half pixel from the bottom to allow the divider to display cleanly
  CGRect bounds;
  CGRect unused;
  CGRectDivide(self.bounds, &unused, &bounds, 0.5f, CGRectMaxYEdge);

  // Divide horizontally for image and content dimensions
  CGRect imageRect;
  CGRect rightRect;
  CGRectDivide(bounds, &imageRect, &rightRect, imageSize, CGRectMinXEdge);
  CGRect contentRect = CGRectInset(rightRect, paddingWidth, paddingHeight);

  // Divide vertically for first line and text dimensions
  CGRect line1Rect;
  CGRect textRect;
  CGRectDivide(contentRect, &line1Rect, &textRect, iconSize, CGRectMinYEdge);

  // Divide horizontally for icon, name, and indicator dimensions
  CGRect titleRect;
  CGRect indicatorRect;
  CGRectDivide(line1Rect, &indicatorRect, &titleRect, indicatorWidth, CGRectMaxXEdge);
  CGRect iconRect;
  CGRect nameRect;
  CGRectDivide(titleRect, &iconRect, &nameRect, iconSize, CGRectMinXEdge);

  // Set the sub view locations.
  self.adImageView.frame = imageRect;
  self.advertiserIconImageView.frame = iconRect;
  self.advertiserNameLabel.frame = CGRectInset(nameRect, 4.0f, 0.0f);
  self.adTextLabel.frame = textRect;
  self.adIndicatorLabel.frame = indicatorRect;
}

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
  [adData loadAdvertiserIconIntoImageView:self.advertiserIconImageView];
  [adData loadAdvertiserNameIntoLabel:self.advertiserNameLabel];
}

@end
