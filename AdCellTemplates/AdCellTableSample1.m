#import <Namo/Namo.h>
#import "AdCellTableSample1.h"

@interface AdCellTableSample1 ()

@property(nonatomic, strong) UILabel *adTitleLabel;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@end

@implementation AdCellTableSample1

+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample1";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return [self heightForWidth:width
               advertiserName:adData.advertiserName
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

+ (CGFloat)heightForWidth:(CGFloat)width
           advertiserName:(NSString *)advertiserName
                    title:(NSString *)adTitle
                     text:(NSString *)adText
               viewFrames:(ViewFrames *)pFrames {
  // The cell looks like this
  //  -----------------------------------------------------
  // |             |  advertiser icon + name               |
  // |             |  ad title                             |
  // |    image    |  ad text                              |
  // |             |                                       |
  // |             |                                       |
  //  -----------------------------------------------------

  // Horizontal positions
  CGFloat imageWidth = 96.0f;
  CGFloat iconSize = 16.0f;
  CGFloat contentLeft = imageWidth + 4.0f;
  CGFloat contentWidth = width - contentLeft - 4.0f;
  CGFloat advertiserNameLeft = contentLeft + iconSize + 2.0f;
  CGFloat advertiserNameWidth = width - advertiserNameLeft - 4.0f;

  // Vertical positions
  CGFloat advertiserTop = 4.0f;
  CGFloat advertiserHeight = [self heightForLabel:advertiserName
                                             font:[UIFont systemFontOfSize:14.0f]
                                         maxWidth:CGFLOAT_MAX];
  CGFloat titleTop = advertiserTop + advertiserHeight + 2.0f;
  CGFloat titleHeight = [self heightForLabel:adTitle
                                        font:[UIFont boldSystemFontOfSize:16.0f]
                                    maxWidth:contentWidth];
  CGFloat textTop = titleTop + titleHeight + 2.0f;
  CGFloat textHeight = [self heightForLabel:adText
                                       font:[UIFont systemFontOfSize:14.0f]
                                   maxWidth:contentWidth];
  CGFloat cellHeight = textTop + textHeight + 4.0f;

  // Make the subview frames
  if (pFrames != NULL) {
    pFrames->adImageRect = CGRectMake(0.0f, 0.0f, imageWidth, cellHeight);
    pFrames->advertiserIconRect = CGRectMake(contentLeft, advertiserTop, iconSize, iconSize);
    pFrames->advertiserNameRect = CGRectMake(
      advertiserNameLeft, advertiserTop, advertiserNameWidth, advertiserHeight);
    pFrames->adTitleRect = CGRectMake(contentLeft, titleTop, contentWidth, titleHeight);
    pFrames->adTextRect = CGRectMake(contentLeft, textTop, contentWidth, textHeight);
  }
  return cellHeight;
}

+ (CGFloat) heightForLabel:(NSString *)text font:(UIFont *)font maxWidth:(CGFloat)maxWidth {
  CGSize size = [text sizeWithFont:font
                 constrainedToSize:CGSizeMake(maxWidth, 1000.0f)
                     lineBreakMode:NSLineBreakByWordWrapping];
  return size.height;
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.adImageView = [[UIImageView alloc] init];
    self.adImageView.contentMode = UIViewContentModeCenter;
    [self.contentView addSubview:self.adImageView];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    self.advertiserIconImageView.contentMode = UIViewContentModeCenter;
    [self.contentView addSubview:self.advertiserIconImageView];

    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.numberOfLines = 1;
    self.advertiserNameLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.adTitleLabel = [[UILabel alloc] init];
    self.adTitleLabel.numberOfLines = 0;
    self.adTitleLabel.backgroundColor = [UIColor clearColor];
    self.adTitleLabel.font = [UIFont boldSystemFontOfSize:16.0f];
    [self.contentView addSubview:self.adTitleLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.numberOfLines = 0;
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.adTextLabel];

    self.contentView.backgroundColor = [UIColor whiteColor];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
  }
  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];

  ViewFrames frames;
  [AdCellTableSample1 heightForWidth:self.contentView.frame.size.width
                                  advertiserName:self.advertiserNameLabel.text
                                           title:self.adTitleLabel.text
                                            text:self.adTextLabel.text
                                      viewFrames:&frames];

  // Set the sub view locations.
  self.adImageView.frame = frames.adImageRect;
  self.advertiserIconImageView.frame = frames.advertiserIconRect;
  self.advertiserNameLabel.frame = frames.advertiserNameRect;
  self.adTitleLabel.frame = frames.adTitleRect;
  self.adTextLabel.frame = frames.adTextRect;
}

#pragma mark - NAMOAdCell implementation

- (void)setAdData:(NAMOAdData *)adData {
  ViewFrames result1;
  [[AdCellTableSample1 class] heightForWidth:self.contentView.frame.size.width
                                  advertiserName:self.advertiserNameLabel.text
                                           title:self.adTitleLabel.text
                                            text:self.adTextLabel.text
                                      viewFrames:&result1];
  [self.adImageView namo_bindAdImage:adData];
  [self.advertiserIconImageView namo_bindAdIcon:adData];
  self.advertiserNameLabel.text = adData.advertiserName;
  self.adTitleLabel.text = adData.title;
  self.adTextLabel.text = adData.text;
}

@end
