// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "NamoAdPlacer.h"

@class NAMOIndexPathAdjuster;
@class NAMOWebViewController;

/**
 This class places ads into your table view stream by proxying calls to the tables
 underlying dataSource and delegate.

 You can configure the frequency and location of ads in your stream using the setAdPlacement
 methods. Typically, you will use a placer in your TableViewController. For example:
 
     - (id)init {
       self = [super initWithNibName:@"TestTableViewController" bundle:nil];
       if (self) {
         self.adPlacer = [NAMOTableViewAdPlacer adPlacer];
       }
       return self;
     }

     - (void)viewDidLoad {
       [super viewDidLoad];
       [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"Cell"];
       [self.adPlacer setAdPlacementWithFirstPosition:1 spacing:6 maxAds:10];
       [self.adPlacer bindToTableView:self.tableView];
       [self.tableView namo_registerAdCellClass:[NAMOTableViewAdCellThumb class]];
     }

     - (void)viewWillAppear:(BOOL)animated {
       [self.adPlacer requestAds];
     }

 @available NamoAds 1.0 and later.
*/
@interface NAMOTableViewAdPlacer : NSObject<NAMOAdPlacer, UITableViewDataSource, UITableViewDelegate>

/// @name Initializing a NAMOTableViewAdPlacer object

/**
 Creates and returns a new ad placer.

 @return The new ad placer.
 @available NamoAds 1.0 and later.
*/
+ (NAMOTableViewAdPlacer *)adPlacer;

/// @name Binding to a UITableView

/**
 Binds this placer to your table view.

 The placer will replace the tableView's delegate and dataSource objects with a proxy version
 that can insert ads into the stream according to your placement rules. In addition binding
 to a placer makes a number of new methods available on your UITableView that are convenient for
 dealing with the modified NSIndexPath's for your table rows. See NAMOTableView+NAMOAdPlacer.h.

 A placer instance can only be bound to one table view. Calling bindToTableView on another table
 view results in the placer being removed from the original table view and the table view's original
 dataSource and delegate properties being restored. You can also bind to nil to remove a placer from
 a table view.

 @param tableView The table view to bind.
 @available NamoAds 1.0 and later.
*/
- (void)bindToTableView:(UITableView *)tableView;

@end
