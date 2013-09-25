//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOAdPlacer.h"
#import "NAMOCollectionViewDataSource.h"
#import "NAMOIndexPathAdjuster.h"

/**
 Keep adding new delegate protocols to this delegate as we support more different kinds of layouts.
*/
@interface NAMOCollectionViewDelegate : NSObject<UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>
+ (NAMOCollectionViewDelegate *)collectionViewDelegate:(id<UICollectionViewDelegate>)originalDelegate
                                 withIndexPathAdjuster:(NAMOIndexPathAdjuster *)indexPathAdjuster
                                    withCollectionView:(UICollectionView *)collectionView
                                        withDataSource:(NAMOCollectionViewDataSource *)dataSource;
@end
