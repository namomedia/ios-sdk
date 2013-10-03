//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOAdCell.h"
#import "NAMOAdPlacer.h"
#import "NAMOIndexPathAdjuster.h"

@interface NAMOTableViewDataSource : NSObject<UITableViewDataSource>
+ (NAMOTableViewDataSource *)tableViewDataSource:(id<UITableViewDataSource>)originalDataSource
                           withIndexPathAdjuster:(NAMOIndexPathAdjuster *)indexPathAdjuster
                                    withAdPlacer:(NAMOAdPlacer *)adPlacer;

- (NAMOAdPlacer *)getAdPlacer;

// Currently recently visible cells mapped to the ad data they were bound to.
@property(nonatomic, strong) NSMutableDictionary *cellToAdMap;
// TODO(joe): Explore if we can get better type checking.
@property(nonatomic, strong) Class adCellClass;
@end
