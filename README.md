ios-sdk
=======

Namo Media iOS Ads SDK

Integration steps:

1. Check out the Namo Media iOS Ads SDK from github:
   
   git clone https://github.com/namomedia/ios-sdk.git

2. Drag and drop NamoAdsSDK.framework to Frameworks group. Check the box where you need to copy
   the files the project.

3. Add the following frameworks if not already included:
   ImageIO, AdSupport, SystemConfiguration, CoreTelephony, UIKit, Foundation, CoreGraphics

4. Initialize the SDK.

   At this point we are ready to start writing some code to integrate the SDK.
   Initialize the SDK in AppDelegate. Include the relevant header file

   "
   // Namo Media start
   #import <NamoAdsSDK/NamoAds.h>
   // Namo Media end
   "

   And add the following code somewhere that will get triggered every time the app launches [we recomend "- (BOOL) application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions" method]

   "
   // Namo Media start
   [NamoAds startWithAppId:<your app id>];
   // Namo Media end
   "

   Where <your app id> is a string that represents the application ID you have registered with Namo Media.

5. Implement the NamoAdCellProvider protocol.

   The TableViewController that is integrating the ads needs to implement 
   NamoAdCellProvider protocol. In the header file for your TableViewController add the header file:

   "
   // Namo Media start
   #import <NamoAdsSDK/NamoAdsSDK.h>
   // Namo Media end
   "

   Add the following protocol to be implemented by the TableViewController: NamoAdCellProvider

   as a protocol implemented by this controller. In the '.m' file implement the following methods:

   "
   // Namo Media start

   #pragma mark - NamoAdCellProvider

   // Returns the cell identifier to use when reusing cells. The SDK uses the default
   // UITableView caching mechanism for caching cells.
   - (NSString *)adCellIdentifier {
     // TODO(tural) add more details how to implement this
     return <the same table view cell identifier>;
   }

   // Returns a newly allocated and initialized ad cell. Called if the table view is
   // unable to return a cached cell.
   - (UITableViewCell *)createAdCell {
     // return an instance of special Ad cell if there is one
     // else, return an instance of the cell used to display the content
   }
   
   // You must implement this method to fill the ad cell with ad content. Use the binder messages
   // fillCellContent and bindCellInteractions to fill your native ad format to setup interactive
   // behaviors.
   - (void)shouldFillAdCell:(UITableViewCell *)tableViewCell
                usingBinder:(NamoAdContentBinder *)binder {
     // provide the UITableViewCell fields for the binder to fill in
     // bind the click, expand target with callbacks
     // e.g.
     //     [binder bindClickTarget:cell.feedImageView callback:^(NSURL *url) {
     //       [self openUrl:url];
     //       return YES;
     //     }];
     //     [binder bindExpandTarget:cell callback:^(BOOL expand, BOOL animate) {
     //       [binder performDefaultExpand:expand withAnimations:animate];
     //       cell.isExpanded = expand;
     //       return YES;
     //     }];
   }

   // Returns the height of the table view cell.
   - (CGFloat)adCellHeight;

   // For expandable ad cells returns the height of the table view cell when expanded.
   - (CGFloat)expandedAdCellHeight;

   // Namo Media end
   "

6. Create Ads Proxy and assign the delegate and data source to it.

   Add a private property
   "
   // Namo Media start
   @property(nonatomic, strong) NamoAdsControllerProxy *adsProxy;
   // Namo Media end
   "

   to the current TableViewController. In viewDidLoad add

   "
   // Namo Media start

   self.adsProxy = [NamoAds proxyForController:self adCellProvider:self];

   // Let the adsProxy handle cell interactions. It uses the delegate methods
   // defined in tableView for content rows and defines interactions for the ad rows.
   self.tableView.delegate = self.adsProxy;

   // Let the adsProxy be the data source for the tableView. It uses dataSource
   // methods from this tableView for content rows and ads data from Namo Media
   // ad servers to display get the relevant advertising content.
   self.tableView.dataSource = self.adsProxy;

   // Namo Media end
   "

7. Request the ads

   In viewWillAppear add

   "
   // TODO(tural) add targeting info
   [self.adsProxy requestAdsWithTargeting:nil];
   "

8. Special cases to handle the expand properly.

   Add a property to the header file for Ad cell (i.e. the content cell is using the same cell)
   a property to remember the expanded state:

   "
   // Namo Media start
   @property(nonatomic, assign) BOOL isExpanded;
   // Namo Media end
   "

   In NamoAdCellProvider make sure to set that property for the cell when expand event happens.
   In bindExpandTarget:
   
   "
   // Namo Media start
   <cell>.isExpanded = expand;
   // Namo Media end
   "

   In layoutSubviews, add the following code to handle the expand properly:

   "
   // Namo Media start
   if (self.isExpanded) {
    [self.feedImageView setContentMode:UIViewContentModeScaleAspectFill];
    return;
   }
   [self.feedImageView setContentMode:<previous aspect>];
   // Namo Media end
   "
