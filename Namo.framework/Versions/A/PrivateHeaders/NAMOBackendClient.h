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
 User agent attached to the web view on this device.
 */
@property(nonatomic, strong, readonly) NSString *userAgent;

/**
 Requests ads from the server
 */
- (void)requestAdsWithNumAds:(NSUInteger)numAds
                  formatType:(NSString *)formatType
                   targeting:(NAMOTargeting *)targeting
                      viewId:(NSUInteger)viewId
                  completion:(void (^)(NSArray *))callback;

/**
 Sends interaction information to the server by following the given interaction url.
*/
- (void)sendInteractionWithURL:(NSURL *)url
                        viewId:(NSUInteger)viewId;

/**
 Sends video interaction information to the server by following the given interaction url.
*/
- (void)sendInteractionWithURL:(NSURL *)url
                        viewId:(NSUInteger)viewId
               videoViewLength:(NSTimeInterval)videoView
              videoTotalLength:(NSTimeInterval)videoTotal;

/**
 Javascript that can be used to bind a webview to ad data.
*/
- (NSString *)webViewJavascript;

@end