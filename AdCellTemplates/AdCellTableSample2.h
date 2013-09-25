// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <UIKit/UIKit.h>

#import <Namo/Namo.h>

/**
 A table view cell for displaying a photo ad format.

 A _Photo Ad_ is an ad whose information is primarily based on a large photo. These ads are
 suitable to display in streams that have have image rich content and only a small amount of text,
 if any. For example, a Pinterest stream would typically display photo ads.

 You can use this photo cell as a template to build your own ad cell. You can either build your
 cell as a nib with matching UIView outlets for this cell, or you can copy this cell implementation
 and create your own cell.

 @available Namo 1.0 and later.
*/
@interface AdCellTableSample2 : UITableViewCell<NAMOAdCell>

@end
