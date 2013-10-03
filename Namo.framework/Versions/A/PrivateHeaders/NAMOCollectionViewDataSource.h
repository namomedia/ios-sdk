//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOAdPlacer.h"
#import "NAMOIndexPathAdjuster.h"

@interface NAMOCollectionViewDataSource : NSObject<UICollectionViewDataSource>
+ (NAMOCollectionViewDataSource *)collectionViewDataSource:(id<UICollectionViewDataSource>)originalDataSource
                                     withIndexPathAdjuster:(NAMOIndexPathAdjuster *)indexPathAdjuster
                                              withAdPlacer:(NAMOAdPlacer *)adPlacer;

- (NAMOAdPlacer *)AdPlacer;

// Currently recently visible cells mapped to the ad data they were bound to.
@property(nonatomic, strong) NSMutableDictionary *cellToAdMap;
@property(nonatomic, strong) Class adCellClass;
@end
