#import <Namo/Namo.h>
#import "AdCellTableSample2.h"

@interface AdCellTableSample2 ()

@property(nonatomic, strong) UILabel *adTitleLabel;
@property(nonatomic, strong) UILabel *adTextLabel;
@property(nonatomic, strong) UILabel *advertiserNameLabel;
@property(nonatomic, strong) UIImageView *adImageView;
@property(nonatomic, strong) UIImageView *advertiserIconImageView;
@end

@implementation AdCellTableSample2

+ (NSString *)reuseIdentifier {
  return @"AdCellTableSample2";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  return [self heightForWidth:width
               advertiserName:adData.advertiserName
                        title:adData.title
                         text:adData.text
                  viewHeights:NULL];
}

/* Positions of views. */
struct ViewHeights {
  CGFloat margin;
  CGFloat imageHeight;
  CGFloat imageMargin;
  CGFloat advertiserHeight;
  CGFloat titleHeight;
  CGFloat textHeight;
} typedef ViewHeights;

+ (CGFloat)heightForWidth:(CGFloat)width
           advertiserName:(NSString *)advertiserName
                    title:(NSString *)adTitle
                     text:(NSString *)adText
              viewHeights:(ViewHeights *)pHeights {

  // The cell looks like this
  //  -----------------------------------------------------
  // |  advertiser icon + name                             |
  // | --------------------------------------------------- |
  // |                                                     |
  // |                   image                             |
  // |                                                     |
  // | --------------------------------------------------- |
  // |  title                                              |
  // |  text                                               |
  //  -----------------------------------------------------

  // Heights
  CGFloat contentWidth = width - 16.0f;
  CGFloat margin = 8.0f;
  CGFloat imageHeight = 100.0f;
  CGFloat imageMargin = 4.0f;
  CGFloat advertiserHeight = [self heightForLabel:advertiserName
                                             font:[UIFont systemFontOfSize:14.0f]
                                         maxWidth:CGFLOAT_MAX];
  CGFloat titleHeight = [self heightForLabel:adTitle
                                        font:[UIFont boldSystemFontOfSize:16.0f]
                                    maxWidth:contentWidth];
  CGFloat textHeight = [self heightForLabel:adText
                                       font:[UIFont systemFontOfSize:14.0f]
                                   maxWidth:contentWidth];
  CGFloat cellHeight = margin + advertiserHeight
      + imageMargin + imageHeight + imageMargin
      + titleHeight + textHeight + margin;

  // Make the subview frames
  if (pHeights != NULL) {
    pHeights->margin = margin;
    pHeights->imageMargin = imageMargin;
    pHeights->advertiserHeight = advertiserHeight;
    pHeights->imageHeight = imageHeight;
    pHeights-> titleHeight = titleHeight;
    pHeights->textHeight = textHeight;
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
    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.numberOfLines = 1;
    self.advertiserNameLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.advertiserNameLabel];

    self.advertiserIconImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.advertiserIconImageView];

    self.adImageView = [[UIImageView alloc] init];
    [self.contentView addSubview:self.adImageView];

    self.adTitleLabel = [[UILabel alloc] init];
    self.adTitleLabel.backgroundColor = [UIColor clearColor];
    self.adTitleLabel.numberOfLines = 0;
    self.adTitleLabel.font = [UIFont boldSystemFontOfSize:16.0f];
    [self.contentView addSubview:self.adTitleLabel];

    self.adTextLabel = [[UILabel alloc] init];
    self.adTextLabel.backgroundColor = [UIColor clearColor];
    self.adTextLabel.numberOfLines = 0;
    self.adTextLabel.font = [UIFont systemFontOfSize:14.0f];
    [self.contentView addSubview:self.adTextLabel];
  }

  return self;
}

- (void)layoutSubviews {
  [super layoutSubviews];

  CGFloat cellWidth = self.contentView.frame.size.width;
  ViewHeights heights;
  [AdCellTableSample2 heightForWidth:cellWidth
                          advertiserName:self.advertiserNameLabel.text
                                   title:self.adTitleLabel.text
                                    text:self.adTextLabel.text
                             viewHeights:&heights];

  CGFloat contentLeft = 8.0f;
  CGFloat contentWidth = cellWidth - contentLeft - 8.0f;

  self.advertiserIconImageView.frame = CGRectMake(contentLeft, heights.margin, 16.0f, 16.0f);

  CGFloat nameLeft = contentLeft + 16.0f + 2.0f;
  self.advertiserNameLabel.frame =
      CGRectMake(nameLeft, heights.margin, contentWidth - nameLeft, heights.advertiserHeight);

  CGFloat imageTop = heights.margin + heights.advertiserHeight + heights.imageMargin;
  self.adImageView.frame = CGRectMake(contentLeft, imageTop, contentWidth, heights.imageHeight);

  CGFloat titleTop = imageTop + heights.imageHeight + heights.imageMargin;
  self.adTitleLabel.frame = CGRectMake(contentLeft, titleTop, contentWidth, heights.titleHeight);

  CGFloat textTop = titleTop + heights.titleHeight;
  self.adTextLabel.frame = CGRectMake(contentLeft, textTop, contentWidth, heights.textHeight);
}

- (void)setAdData:(NAMOAdData *)adData {
  self.adTextLabel.text = adData.text;
  self.adTitleLabel.text = adData.title;
  self.advertiserNameLabel.text = adData.advertiserName;

  [self.adImageView namo_bindAdImage:adData];
  [self.advertiserIconImageView namo_bindAdIcon:adData];
}

@end
