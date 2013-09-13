#import <Namo/Namo.h>
#import "TableViewAdCellSocial1.h"

@implementation TableViewAdCellSocial1

+ (NSString *)reuseIdentifier {
  return @"TableViewAdCellThumb";
}

+ (CGFloat)cellHeightWithData:(NAMOAdData *)adData andWidth:(CGFloat)width {
  CGSize maximumLabelSize = CGSizeMake(width - 50.0 - 10.0 - 9.0 - 10.0, 1000);
  CGSize titleSize = [adData.text sizeWithFont:[UIFont systemFontOfSize:12.0f]
                             constrainedToSize:maximumLabelSize
                                 lineBreakMode:NSLineBreakByWordWrapping];
  
  // minimum height of 70.0f
  return fmaxf(70.0f, titleSize.height + 10.0f + 18.0f + 18.0f + 10.0f);
}


- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
  self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
  if (self) {
    self.adImageView = [[UIImageView alloc] init];
    // TODO(nassar): Change to center in order to request ads from the ad server correctly.
    self.adImageView.contentMode = UIViewContentModeScaleAspectFill;
    [self addSubview:self.adImageView];
    
    self.advertiserIconImageView = [[UIImageView alloc] init];
    // TODO(nassar): Change to center in order to request ads from the ad server correctly.
    self.advertiserIconImageView.contentMode = UIViewContentModeScaleAspectFill;
    [self addSubview:self.advertiserIconImageView];
    
    self.advertiserNameLabel = [[UILabel alloc] init];
    self.advertiserNameLabel.backgroundColor = [UIColor clearColor];
    self.advertiserNameLabel.font = [UIFont boldSystemFontOfSize:14.5f];
    self.advertiserNameLabel.textColor = [UIColor colorWithRed:0.0f
                                                         green:0.4f
                                                          blue:0.8f
                                                         alpha:1.0f];
    [self addSubview:self.advertiserNameLabel];
    
    self.adTitleLabel = [[UILabel alloc] init];
    self.adTitleLabel.backgroundColor = [UIColor clearColor];
    self.adTitleLabel.font = [UIFont systemFontOfSize:12.0f];
    self.adTitleLabel.numberOfLines = 0;
    self.adTitleLabel.lineBreakMode = NSLineBreakByWordWrapping;
    [self addSubview:self.adTitleLabel];
    
    self.adIndicatorLabel = [[UILabel alloc] init];
    self.adIndicatorLabel.backgroundColor = [UIColor clearColor];
    self.adIndicatorLabel.numberOfLines = 1;
    self.adIndicatorLabel.font = [UIFont systemFontOfSize:11.0f];
    self.adIndicatorLabel.textColor = [UIColor colorWithHue:0.0f
                                                 saturation:0.0f
                                                 brightness:0.55f
                                                      alpha:1.0f];
    //TODO: Potentially change indicator label to "Ad", "Suggested Post" etc.
    self.adIndicatorLabel.text = @"Sponsored Post";
    [self addSubview:self.adIndicatorLabel];
    
    self.contentView.backgroundColor = [UIColor whiteColor];
    self.selectionStyle = UITableViewCellSelectionStyleNone;
  }
  return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
  [super setSelected:selected animated:animated];
  
  // Configure the view for the selected state
}

- (void)layoutSubviews {
  [super layoutSubviews];
  
  // Place content like this.
  //  -----------------------------------------------------
  // |             |  advertiser icon + name               |
  // |             |  indicator                            |
  // |    image    |  ad text                              |
  // |             |                                       |
  // |             |                                       |
  //  -----------------------------------------------------
  
  CGRect leftRect;
  CGRect rightRect;
  CGRectDivide(self.contentView.frame, &leftRect, &rightRect, 69.0f,
               CGRectMinXEdge);
  CGRect rightContentRect = UIEdgeInsetsInsetRect(rightRect,
                                                  UIEdgeInsetsMake(10.0f, 0.0f, 10.0f, 10.0f));
  
  CGRect adImageRect = CGRectMake(10.0,10.0,50.0,50.0);
  
  CGRect line1Rect;
  CGRect line2Rect;
  CGRect line3Rect;
  CGRectDivide(rightContentRect, &line1Rect, &line2Rect, 16.0f, CGRectMinYEdge);
  CGRectDivide(line2Rect, &line2Rect, &line3Rect, 18.0f, CGRectMinYEdge);
  
  CGRect advertiserIconRect;
  CGRect advertiserNameRect;
  CGRectDivide(line1Rect, &advertiserIconRect, &advertiserNameRect,
               16.0f, CGRectMinXEdge);
  
  // Set the sub view locations.
  self.adImageView.frame = adImageRect;
  self.advertiserIconImageView.frame = advertiserIconRect;
  self.advertiserNameLabel.frame = CGRectOffset(advertiserNameRect, 4.0f, 0.0f);
  self.adIndicatorLabel.frame = line2Rect;
  self.adTitleLabel.frame = line3Rect;
}

#pragma mark - NAMOAdCell implementation

- (void)setAdData:(NAMOAdData *)adData {
  [self.adImageView namo_bindAdImage:adData];
  [self.advertiserIconImageView namo_bindAdIcon:adData];
  self.advertiserNameLabel.text = adData.advertiserName;
  self.adTitleLabel.text = adData.text; //TODO(gabor): Our ads don't have titles, only text. We should change that.
}


@end
