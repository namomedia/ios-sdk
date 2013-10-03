//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NAMOIndexPathAdjuster.h"
#import "NAMOTableViewDataSource.h"

@interface NAMOTableViewDelegate : NSObject<UITableViewDelegate>
+ (NAMOTableViewDelegate *)tableViewDelegate:(id<UITableViewDelegate>)originalDelegate
                       withIndexPathAdjuster:(NAMOIndexPathAdjuster *)indexPathAdjuster
                               withTableView:(UITableView *)tableView
                              withDataSource:(NAMOTableViewDataSource *)dataSource;
@end
