#import <Namo/Namo.h>
#import "AdCellCollectionSample1.h"

@interface AdCellCollectionSample1 ()
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UILabel *adTitleLabel;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@end

@implementation AdCellCollectionSample1

+ (NSString *)reuseIdentifier {
  return @"AdCellCollectionSample1";
}

+ (CGSize)cellSizeWithData:(NAMOAdData *)adData {
  return [self sizeForAdvertiserName:adData.advertiserName
                               title:adData.title
                                text:adData.text
                          viewFrames:NULL];
}

/* Frames for all views. */
struct ViewFrames {
  CGRect adImageRect;
  CGRect advertiserIconRect;
  CGRect advertiserNameRect;
  CGRect adTitleRect;
  CGRect adTextRect;
} typedef ViewFrames;

+ (CGSize)sizeForAdvertiserName:(NSString *)advertiserName
                          title:(NSString *)adTitle
                           text:(NSString *)adText
                     viewFrames:(ViewFrames *)pFrames {

  // The cell looks like this
  //  -----------------------------------------------------
  // |                                                     |
  // |                   image                             |
  // |                                                     |
  // | --------------------------------------------------- |
  // |  title                                              |
  // |  text                                               |
  // |                                                     |
  // |  advertiser icon + name                             |
  //  -----------------------------------------------------

  // Heights
  CGFloat cellWidth = 320.0f;
  CGFloat margin = 8.0f;
  CGFloat imageHeight = 100.0f;
  CGFloat imageMargin = 4.0f;
  CGFloat contentWidth = cellWidth - margin - margin;

  CGFloat titleTop = imageHeight + imageMargin;
  CGFloat titleHeight = [self heightForLabel:adTitle
                                        font:[UIFont boldSystemFontOfSize:16.0f]
                                    maxWidth:contentWidth];

  CGFloat textTop = titleTop + titleHeight;
  CGFloat textHeight = [self heightForLabel:adText
                                       font:[UIFont systemFontOfSize:14.0f]
                                   maxWidth:contentWidth];

  CGFloat advertiserTop = textTop + textHeight + 4.0f;
  CGFloat advertiserHeight = [self heightForLabel:advertiserName
                                             font:[UIFont systemFontOfSize:12.0f]
                                         maxWidth:CGFLOAT_MAX];

  CGFloat iconSize = 14.0f;
  CGFloat advertiserNameLeft = margin + iconSize + 2.0f;
  CGFloat advertiserNameWidth = contentWidth - advertiserNameLeft;

  CGFloat cellHeight = advertiserTop + advertiserHeight + 4.0f;

  // Make the subview frames
  if (pFrames != NULL) {
    pFrames->adImageRect = CGRectMake(0.0f, 0.0f, cellWidth, imageHeight);
    pFrames->advertiserIconRect = CGRectMake(margin, advertiserTop, iconSize, iconSize);
    pFrames->advertiserNameRect = CGRectMake(
        advertiserNameLeft, advertiserTop, advertiserNameWidth, advertiserHeight);
    pFrames->adTitleRect = CGRectMake(margin, titleTop, contentWidth, titleHeight);
    pFrames->adTextRect = CGRectMake(margin, textTop, contentWidth, textHeight);
  }
  return CGSizeMake(cellWidth, cellHeight);
}

+ (CGFloat)heightForLabel:(NSString *)text font:(UIFont *)font maxWidth:(CGFloat)maxWidth {
  CGSize size = [text sizeWithFont:font
                 constrainedToSize:CGSizeMake(maxWidth, 1000.0f)
                     lineBreakMode:NSLineBreakByWordWrapping];
  return size.height;
}

- (id)initWithFrame:(CGRect)frame {
  self = [super initWithFrame:frame];
  if (self) {
    self.backgroundColor = [UIColor whiteColor];

    self.adImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.adImageView];

    self.adTitleLabel = [[UILabel alloc] init];
    self.adTitleLabel.numberOfLines = 0;
    self.adTitleLabel.backgroundColor = [UIColor clearColor];
    self.adTitleLabel.font = [UIFont boldSystemFontOfSize:16.0f];
    self.adTitleLabel.textColor = [UIColor colorWithRed:0.0f
                                                         green:0.4f
                                                          blue:0.8f
                                                         alpha:1.0f];
    [self.contentView addSubview:self.adTitleLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.numberOfLines = 0;
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.adTextLabel];

    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.numberOfLines = 1;
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.font = [UIFont systemFontOfSize:12.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.advertiserIconImageView];

  }
  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];

  ViewFrames frames;
  [AdCellCollectionSample1 sizeForAdvertiserName:self.advertiserNameLabel.text
                                               title:self.adTitleLabel.text
                                                text:self.adTextLabel.text
                                          viewFrames:&frames];
  self.adImageView.frame = frames.adImageRect;
  self.advertiserIconImageView.frame = frames.advertiserIconRect;
  self.advertiserNameLabel.frame = frames.advertiserNameRect;
  self.adTitleLabel.frame = frames.adTitleRect;
  self.adTextLabel.frame = frames.adTextRect;
}

- (void)setAdData:(NAMOAdData *)adData {
  self.adTextLabel.text = adData.text;
  self.adTitleLabel.text = adData.title;
  self.advertiserNameLabel.text = adData.advertiserName;

  [self.adImageView namo_bindAdImage:adData];
  [self.advertiserIconImageView namo_bindAdIcon:adData];
}
@end
