ios-sdk
=======

Namo Media iOS Ads SDK

Integration steps:

1. Check out the Namo Media iOS Ads SDK from github:

        git clone https://github.com/namomedia/ios-sdk.git

2. Drag and drop `NamoAdsSDK.framework` to `Frameworks` group.


3. Add the following frameworks if they are not already included: `ImageIO, AdSupport, SystemConfiguration, CoreTelephony, UIKit, Foundation, CoreGraphics`


4. Initialize the SDK.

  At this point we are ready to start writing some code to integrate the SDK.
  Initialize the SDK in `AppDelegate`.

  Include the relevant header file:

        #import <NamoAdsSDK/NamoAdsSDK.h>
    

  Initialize the SDK when the application launches:

        (BOOL) application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

          [NamoAds startWithAppId:<your app id>];
          
        }

  Where `<your app id>` is a string that represents the application ID you have registered with Namo Media.

5. Include Ads in your stream

  Create Ads Proxy and use it as your delegate and data source. Have your `TableViewController` implement `NamoAdCellProvider` protocol.
        
        #import <NamoAdsSDK/NamoAdsSDK.h>
        
        // declare a strong reference to NamoAdsControllerProxy object
        @property(nonatomic, strong) NamoAdsControllerProxy *adsProxy;


        -(void)ViewDidLoad {

          self.adsProxy = [NamoAds proxyForController:self adCellProvider:self];

          // Let the adsProxy handle cell interactions. It uses the delegate methods
          // defined in tableView for content rows and defines interactions for the ad rows.
          self.tableView.delegate = self.adsProxy;

          // Let the adsProxy be the data source for the tableView. It uses dataSource
          // methods from this tableView for content rows and ads data from Namo Media
          // ad servers to display get the relevant advertising content.
          self.tableView.dataSource = self.adsProxy;
        }
  

        -(void)viewWillAppear:(BOOL)animated {
          // Request the ads
          [self.adsProxy requestAdsWithTargeting:nil];
        }
        
        #pragma mark - NamoAdCellProvider
        
        // @required
        // Should return a custom cell identifier for caching your 
        // cells. The SDK uses the standard
        // UITableViewCell mechanism for reusing cells.
        - (NSString *)customAdCellIdentifier {
          // Return custom identifier for your ad cell
        }

5. Customize the look of your Ad Cell (Optional)

  To customize the look of your ad cell you need to implement the optional methods in NamoAdCellProvider in the relevant TableViewController. There are 3 common ways of doing this.
  
        #pragma mark - NamoAdCellProvider

        // @optional
        // Implement this method to return a completely custom ad 
        // cell. Your cell should be initialized with
        // the given identifier. If you simply wish to customize 
        // your layout, use layoutAdCell instead of implementing 
        // this method.
        - (NamoAdCell *)createCustomAdCell:(NSString *)identifier {
          // Implement this method if making a custom ad cell
        }

        // Implement this method to customize the height of your 
        // table view cell. Default is NamoAdCellDefaultHeight.
        - (CGFloat)adCellHeight {
          // Implement to specify custom height
        }

        // Implement this method to customize the height of your 
        // cell when expanded. This only applies to cells which 
        // support expansion. Default is NamoAdCellDefaultExpandedHeight.
        - (CGFloat)adCellExpandedHeight {
          // Implement to specify custom expanded height
        }

        // Implement this method to return the placeholder image 
        // for all ad image views while downloading from the server.
        - (UIImage *)placeHolderImage {
          // Implement to specify custom placeholder image
        }

        // Implement this method to customize the layout of an ad cell. 
        // See NamoAdCell.h for methods you can use to customize your cell.
        // One common pattern is to change the layout for the 
        // UIView properties of the NamoAdCell. You can also set 
        // supportsExpansion to allow the cell to expand when clicked.
        - (void)layoutAdCell:(NamoAdCell *)cell {
          // Implement this method if need to customize the
          // layout of NamoAdCell.
        }

        // Implement this method to customize an ad cell based on 
        // the content of the ad.
        - (void)fillAdCell:(NamoAdCell *)cell withAdContent:(NamoAd *)ad {
          // Implement to customize the content of the ad cell.
        }

  a. Use layoutAdCell method to customize the layout of the cell without having to create a custom cell.
  
  b. Use a custom xib file.
  Set the xib class to be NamoAdCell (or your own class that derives from NamoAdCell).
  
  c. Extend NamoAdCell to create a custom cell.
