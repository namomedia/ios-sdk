#import <Namo/Namo.h>
#import "AdCellCollectionSample1.h"

@interface NamoAdCellCollectionSample1 ()
@property(nonatomic, strong) UILabel *labelTitle;
@property(nonatomic, strong) UILabel *labelText;
@property(nonatomic, strong) UILabel *labelAdvertiserName;
@property(nonatomic, strong) UIImageView *adImage;
@property(nonatomic, strong) UIButton *actionButton;
@end

@implementation NamoAdCellCollectionSample1

+ (NSString *)reuseIdentifier {
  return @"NamoAdCellCollectionSample1";
}

+ (CGSize)cellSizeWithData:(NAMOAdData *)adData {
  return CGSizeMake(320.0f, 200.0f);
}

- (id)initWithFrame:(CGRect)frame {
  self = [super initWithFrame:frame];
  if (self) {
    self.backgroundColor = [UIColor colorWithRed:0.87f green:0.87f blue:0.87f alpha:1.0f];
    self.labelTitle = [[UILabel alloc] init];
    self.labelTitle.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.labelTitle];

    self.labelText = [[UILabel alloc] init];
    self.labelText.font = [UIFont systemFontOfSize:12.0f];
    [self.contentView addSubview:self.labelText];

    self.labelAdvertiserName = [[UILabel alloc] init];
    self.labelAdvertiserName.font = [UIFont systemFontOfSize:10.0f];
    self.labelAdvertiserName.textAlignment = NSTextAlignmentLeft;
    [self.contentView addSubview:self.labelAdvertiserName];

    self.adImage = [[UIImageView alloc] init];
    self.adImage.contentMode = UIViewContentModeScaleAspectFill;
    self.adImage.clipsToBounds = YES;
    [self.contentView addSubview:self.adImage];

    self.actionButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [self.actionButton setUserInteractionEnabled:NO];

    [self.actionButton setTitleColor:[UIColor colorWithWhite:0 alpha:1]
                            forState:UIControlStateNormal];
    [self.actionButton setTitle:@"Download App" forState:UIControlStateNormal];
    [self.contentView addSubview:self.actionButton];
  }
  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];
  // The cell looks like:
  //   +-------------------------------------+
  //   |                                     |
  //   |                                     |
  //   |              Ad Image               |
  //   |                                     |
  //   |                                     |
  //   |                                     |
  //   +-------------------------------------+
  //   | Ad Title...                         |
  //   | Ad Text...                          |
  //   | Advertiser Name       Action Button |
  //   +-------------------------------------+
  CGFloat width = self.contentView.frame.size.width;
  CGRect imageRect;
  CGRect bottomRect;
  CGRectDivide(self.contentView.frame, &imageRect, &bottomRect, 120.0f, CGRectMinYEdge);
  self.adImage.frame = imageRect;

  self.labelAdvertiserName.frame = UIEdgeInsetsInsetRect(
      bottomRect, UIEdgeInsetsMake(11.0f + 18.0f + 20.0f, 2.0f, 2.0f, width * 0.5f));
  self.labelTitle.frame = CGRectMake(
      bottomRect.origin.x + 2.0f, bottomRect.origin.y + 2.0f, width, 18.0f);
  self.labelText.frame = CGRectMake(bottomRect.origin.x + 2.0f,
      bottomRect.origin.y + 11.0f, width, 50.0f);
  self.actionButton.frame = UIEdgeInsetsInsetRect(
      bottomRect, UIEdgeInsetsMake(11.0f + 18.0f + 20.0f, width * 0.56f, 2.0f, 6.0f));
  UIImage *actionImage = [[NAMOInternalImageResources namoSample3Button]
      resizableImageWithCapInsets:UIEdgeInsetsMake(12.0f, 12.0f, 12.0f, 12.0f)];
  [self.actionButton setBackgroundImage:actionImage forState:UIControlStateNormal];
}

- (void)setAdData:(NAMOAdData *)adData {
  self.labelText.text = adData.text;
  self.labelTitle.text = adData.title;
  self.labelAdvertiserName.text = adData.advertiserName;
  [self.adImage namo_bindAdImage:adData];

  switch (adData.actionType) {
    case NAMOActionTypeVideo:
      [self.actionButton setHidden:YES];
      break;
    case NAMOActionTypeInstall:
      [self.actionButton setHidden:NO];
      break;
    case NAMOActionTypeLink:
    default:
      [self.actionButton setHidden:YES];
      break;
  }
}
@end
