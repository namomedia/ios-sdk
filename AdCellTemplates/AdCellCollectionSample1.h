//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <UIKit/UIKit.h>

#import <Namo/Namo.h>

/**
 Collection view ad cell sample #1.

 This sample is a _Photo Ad_ where the ad content is primarily based on a large photo. These ads are
 suitable to display in streams that have have image rich content and only a small amount of text,
 if any. For example, a Pinterest stream would typically display photo ads.

 You can use this cell as a template to build your own ad cell. See the
 <a href="https://github.com/namomedia/ios-sdk/tree/master/AdCellTemplates" target="_blank">
 the source code</a>.

 @available Namo 1.0 and later.
*/
@interface AdCellCollectionSample1 : UICollectionViewCell<NAMOAdCell>
@end
