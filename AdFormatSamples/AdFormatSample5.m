#import <Namo/Namo.h>
#import "AdFormatSample5.h"

@interface AdFormatSample5 ()

@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *adIndicatorLabel;
@end

@implementation AdFormatSample5

+ (NSString *)formatIdentifier {
  return @"AdFormatSample5";
}

+ (CGSize)sizeWithMaxWidth:(CGFloat)maxWidth {
  return CGSizeMake(maxWidth, 90.0f);
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

  self.adTextLabel = [[UILabel alloc] init];
  self.adTextLabel.numberOfLines = 4;
  self.adTextLabel.backgroundColor = [UIColor clearColor];
  self.adTextLabel.font = [UIFont boldSystemFontOfSize:14.0];
  self.adTextLabel.textColor = [UIColor whiteColor];
  [self addSubview:self.adTextLabel];

  self.adIndicatorLabel = [[UILabel alloc] init];
  self.adIndicatorLabel.numberOfLines = 1;
  self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
  self.adIndicatorLabel.font = [UIFont boldSystemFontOfSize:14.0];
  self.adIndicatorLabel.textColor = [UIColor colorWithRed:0.0f
                                                       green:0.4f
                                                        blue:0.8f
                                                       alpha:1.0f];
  self.adIndicatorLabel.text = @"Ad";
  [self addSubview:self.adIndicatorLabel];

  self.backgroundColor = [UIColor blackColor];
}

- (void)layoutSubviews {
  [super layoutSubviews];

  // The format looks like this
  //  -----------------------------------------------------
  // |              |                                      |
  // |              |               text                   |
  // |  ad image    |                                      |
  // |              |                                      |
  // |              |                                  Ad  |
  //  -----------------------------------------------------

  CGRect imageRect;
  CGRect remainderRect;
  CGRectDivide(self.bounds, &imageRect, &remainderRect, 120.0f, CGRectMinXEdge);
  CGRect contentRect = UIEdgeInsetsInsetRect(
      remainderRect, UIEdgeInsetsMake(2.0f, 6.0f, 4.0f, 2.0f));

  CGRect topRect;
  CGRect bottomRect;
  CGRectDivide(contentRect, &topRect, &bottomRect, 58.0f, CGRectMinYEdge);
  CGRect bottomLeftRect;
  CGRect bottomRightRect;
  CGRectDivide(bottomRect, &bottomRightRect, &bottomLeftRect, 130.0f, CGRectMaxXEdge);

  // Set the sub view locations.
  self.adImageView.frame = imageRect;
  self.adTextLabel.frame = topRect;
  self.adIndicatorLabel.frame = bottomLeftRect;

  self.adImageView.frame = CGRectMake(0.0f, 0.0f, 120.0f, 90.0f);
  self.adTextLabel.frame = CGRectMake(128.0f, 8.0f, 184.0f, 74.0f);
  self.adIndicatorLabel.frame = CGRectMake(294.0f, 68.0f, 22.0f, 18.0f);
}

- (void)setAdData:(NAMOAdData *)adData {
  [adData loadImageIntoImageView:self.adImageView];
  [adData loadTextIntoLabel:self.adTextLabel];
}

@end
