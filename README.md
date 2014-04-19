Namo iOS SDK
=======

This SDK by Namo Media facilitates inserting native mobile ads into a TableView or other content stream in your iOS application. The SDK uses native iOS APIs to display ads, and will automatically adapt ad images and text to match your cell format. You can choose one of our pre-built sample formats, reuse your existing content cells, or create a new custom format.

See our [Quickstart Guide](http://docs.namomedia.com/quickstart) to get started.

![Sample ad format](http://docs.namomedia.com/images/ios-readme-image.png)

Change Log
========

**Version 3.0.0 - April 18, 2014**

Major release with updated API. See our 
[migration guide](http://localhost:4000/docs-staging/upgrade/) for upgrade instructions.

* NAMOCustomStreamAdPlacer to support streams other than UITableView and UICollectionView.
* NAMOAdView to support a stand-alone native ad format.
* Delegate methods to know when ads have loaded.
* Support for app store ratings.
* Support for hierarchical ad units.
* Simplified API for easy integration.

**Version 2.2.1 - March 4, 2014**
* Fix a bug where an empty UICollectionView would display one ad.
* Fix a bug to stop displaying the "ad loading" spinner when there is an error.
* Fix a bug where reloadRowsAtIndexPaths would modify the data source.

**Version 2.2.0 - January 24, 2014**
* Deprecate NAMOAdCell cellHeightWithData:andWidth: and NAMOAdCell cellSizeWithData: in favor of NAMOAdCell cellHeightWithWidth: and NAMOAdCell cellSize
* Don't show an ad when it would be the last item in a stream.
* Fix a bug that could cause an awkward animation when calling namo_insertRowsAtIndexPaths.

**Version 2.1.2** - *January 17, 2014*
* Bug fix - fix bug that could cause duplicate impression counting.

**Version 2.1.1** - *January 16, 2014*
* Bug fix - fix App Install cancel button appearance in uncommon cases.

**Version 2.1.0** - *January 15, 2014*
* Improve App Install & URL Ads UX

**Version 2.0.1** - *December 18, 2013*
* Fix bugs that prevented infinite scrolling for performing correctly

**Version 2.0.0** - *December 13, 2013*
* Support adapting ad text to match your layout
* Revamp image loader methods
* Support for server side ad placement
* Rewrite ad cell templates
* Support for infinitely scrolling streams 
* Support for test mode

**Version 1.0.0** - *October 31, 2013*
* Ad cell templates compute their height dynamically
* Support for keyword targeting
* Improved documentation
* Fix NAMOAdCell cellHeightWithData:andWidth to be called with the correct width for tables with margins
* Fix problems detecting the user agent that could occur on the first ad request

**Version 0.9.10** - *October 8, 2013*
* Add methods to UIImageView+NamoAdPlacer.h that allow running a block on completion of image download.
* Out of beta!

**Version 0.9.9** - *October 4, 2013*
* Add methods to UICollectionView & UITableView categories to support programmatic calls to select & deselect items.
* Fix collection view delegate to not correctly propagate cell selection events

**Version 0.9.8** - *October 2nd, 2013*
* Performance and memory leak fixes

**Version 0.9.7** - *September 26, 2013*
* Rewrite ad cell templates
* Documentation overhaul
* Removal of experimental Targeting enum values in favor of free text
* Image scaling fixes for various UIViewContentMode constants

**Version 0.9.6** - *September 24, 2013*
* Support UICollectionViews
* Changes to the UITableView ad placer API
* New ad cell templates
* First public release!
