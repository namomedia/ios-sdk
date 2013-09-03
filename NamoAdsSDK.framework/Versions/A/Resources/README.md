iOS SDK Developer’s Guide
=============================

Welcome to the Namo iOS SDK, the new ad library by Namo Media. Our current release is an early beta version, available only to our launch partners.

Before you begin
----------------

To use the Namo Ads SDK, you must sign up for a Namo Media publisher account. We are currently making accounts available to our beta partners, and you will need to contact us to receive an account.

The latest version of our SDK can be found at the following GitHub location:

    git clone https://github.com/namomedia/ios-sdk.git

You can always reach out to us directly, or by using our help alias at support@namomedia.com. We are eager to help.


Getting started : Integrating the SDK
-------------------------------------

Requirements:

  * iOS 6.0 or higher
  * Xcode 4.3 or higher

The current SDK library requires you to compile using ARC. If you have an application that depends on manual reference counting, let us know and we’ll be happy to update our SDK.

1. Drag NamoAdsSDK.framework from cloned git repo into the Frameworks directory of your XCode project.

    <img src="docs/Images/ios-drag-framework.png" />

2. Make sure the "Copy items to destination's group folder" checkbox is checked.

3. Click on your project, then Targets → Your app name → 'Build Phases'. Expand 'Link Binary With Libraries' as shown.

    <img src="docs/Images/ios-link-binaries.jpeg" />

 Click the plus button in the bottom left of the 'Link Binary With Libraries' section, and add the following libraries:
    * ImageIO
    * AdSupport
    * SystemConfiguration
    * CoreTelephony
    * UIKit
    * Foundation
    * CoreGraphics

4. In your Application Delegate (typically AppDelegate.m), add the following import to the top of the file:

        #import <NamoAdsSDK/Namo.h>

    Then paste the following inside the `application:didFinishLaunchingWithOptions:` method

        [Namo setApplicationId:<your app id>];

    You must provide your application ID as found in your NamoMedia publisher account: [http://beta.namomedia.com/monetize](http://beta.namomedia.com/monetize)

5. Compile and run.

Including Ads in Your Stream
----------------------------

The simplest way to include Namo Media ads is to use a NAMOTableViewAdPlacer object to manage inserting ads into your UITableViewController. The placer works by intercepting calls to you table view delegate and datasource. To do this you will create the placer object in `viewDidLoad`, specify where and how often you want the ads to appear in the stream, register an ad cell and request ads with a set of targeting parameters. You can choose to register one of the ad cells available as part of the SDK or choose to implement your own.

A sample header file looks like this:

    #import <NamoAdsSDK/Namo.h>

And the corresponding implementation file:

    // Private category in implementation file.
    @interface FeedViewController()
    @property(nonatomic, strong) NAMOTableViewAdPlacer *adPlacer;
    @end

    - (void)viewDidLoad {
      self.adPlacer = [NAMOTableViewAdPlacer adPlacer];
      // Set the placement configurations here
      [self.adPlacer setAdPlacementWithFirstPosition:2 spacing:3 maxAds:10];
      // Bind your table view
      [self.adPlacer bindToTableView:self.tableView];
      // Register your ad cell
      [self.tableView namo_registerAdCellClass: [NAMOTableViewAdCellThumb class]];
    }

    - (void)viewWillAppear: (BOOL)animated {
      // Request ads.
      [self.adsProxy requestAds];
    }


**Important:** if your app calls methods on your table view that affect the row count, you must replace them with the corresponding namo_ method. Otherwise, the ad placer will not be able to correctly insert ads.
<table><tr>
  <th>Original</th>
  <th>Replacement</th>
</tr><tr>
  <td><code>reloadData</code></td>
  <td><code>namo_reloadData</code></td>
</tr><tr>
  <td><code>insertRowsAtIndexPaths:withRowAnimation</code></td>
  <td><code>namo_insertRowsAtIndexPaths:withRowAnimation</code></td>
</tr><tr>
  <td><code>deleteRowsAtIndexPaths:withRowAnimation</code></td>
  <td><code>namo_deleteRowsAtIndexPaths:withRowAnimation</code></td>
</tr><tr>
  <td><code>moveRowAtIndexPath:toIndexPath</code></td>
  <td><code>namo_moveRowAtIndexPath:toIndexPath</code></td>
</tr>
</table>
Compile and run your app. You should see ads in your stream.

Customize ads to your native format
-----------------------------------

[Include details about creating your own ad cell]


Changing the ad frequency and targeting
---------------------------------------

[Include more details]

By default, 1 ad will display every 6 lines. If you’d like fewer ads in your list, you can change the ad frequency:

    // Sets the number of normal table view items to display for each ad.
    self.namoAdProxy.itemToAdRatio = 10;

To provide targeting for you ads pass a NamoTargeting object to requestAdsWithTargeting. You can pass keywords, location, gender, age, and other information.

Thanks! And happy coding...
---------------------------

As engineers and app developers ourselves, we really appreciate your candid feedback. Please let us know if you have suggestions.

