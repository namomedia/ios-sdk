// Copyright (c) 2013 Namo Media, Inc. All rights reserved.


#import <Foundation/Foundation.h>
#import "NAMORequest.h"
#import "NAMOAdData.h"

@class NAMOTargeting;

/**
 The number of seconds an ad must be visible before counting as an impression.
*/
extern NSTimeInterval const NAMOImpressionTimeInSecs;
/**
 The timeout interval for SDK server requests.
*/
extern NSTimeInterval const NAMORequestTimeoutInterval;

/**
 A block called when an ad request completes.
 */
typedef void (^NAMORequestSuccessBlock)(
    NSArray *adData, NSArray *positions, NSString *continuationToken);

/**
 A block called when an ad request fails.
 */
typedef void (^NAMORequestFailureBlock)(NSError *);

/**
 A singleton object responsible for storing application state and connecting to Namo Media
 backend servers.
*/
@interface NAMOBackendClient : NSObject<UIWebViewDelegate>

/**
 Singleton backend client object.
*/
+ (NAMOBackendClient *)sharedSingleton;

/**
 The current application id.
*/
@property(nonatomic, strong) NSString *applicationId;

/**
 Whether the client is currently active.
*/
@property(nonatomic, assign) BOOL active;

/**
 Base ad server URL.

 Defaults to http://r.namomedia.com. Can be changed for debugging purposes.
*/
@property(nonatomic, strong) NSURL *baseAdServerURL;

/**
 Base image server URL.

 Defaults to http://i.namomedia.com. Can be changed for debugging purposes.
*/
@property(nonatomic, strong) NSURL *baseImageServerURL;

/**
 A campaign ID for debugging specific ads. When set to a number other than 0, only ads from the
 campaign will be returned from the ad server. When set to 0, normal ad serving occurs, returning
 ads from any running campaign.
*/
@property(nonatomic) NSInteger debugCampaignId;

/**
 User agent attached to the web view on this device.
 */
@property(nonatomic, strong, readonly) NSString *userAgent;

/**
 Device ids for which to send a test_mode parameter.
*/
@property(nonatomic, strong) NSArray *testDeviceIds;

/**
 Whether being in the simulator forces the test_mode parameter to be set. Defaults to YES.
*/
@property(nonatomic) BOOL isSimulatorInTestMode;

/**
 Requests ads from the server
 */
- (NAMORequest *)requestAdsWithNumAds:(NSUInteger)numAds
                           formatType:(NSString *)formatType
                            targeting:(NAMOTargeting *)targeting
                               viewId:(NSUInteger)viewId
                    continuationToken:(NSString *)continuationToken
                         failureBlock:(NAMORequestFailureBlock)failureBlock
                         successBlock:(NAMORequestSuccessBlock)successBlock;

/**
 Sends interaction information to the server by following the given interaction url.
*/
- (void)sendInteractionWithURL:(NSURL *)url
                        viewId:(NSUInteger)viewId;

/**
 Overload with layout info.
*/
- (void)sendInteractionWithURL:(NSURL *)url
                        viewId:(NSUInteger)viewId
                    layoutInfo:(NSData *)layoutInfo;

/**
 Overload with video info.
*/
- (void)sendInteractionWithURL:(NSURL *)url
                        viewId:(NSUInteger)viewId
                    layoutInfo:(NSData *)layoutInfo
               videoViewLength:(NSTimeInterval)videoView
              videoTotalLength:(NSTimeInterval)videoTotal;

/**
 Javascript that can be used to bind a webview to ad data.
*/
- (NSString *)webViewJavascript;

- (BOOL)isInTestMode;
@end