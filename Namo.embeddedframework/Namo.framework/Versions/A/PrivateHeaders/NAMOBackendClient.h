// Copyright (c) 2013 Namo Media, Inc. All rights reserved.


#import <Foundation/Foundation.h>
#import "NAMORequest.h"
#import "NAMOAdData.h"

/**
 Monotonically increasing SDK version. This is used by the server to determine what
 features are supported by the SDK.
*/
extern NSUInteger const NamoSdkVersion;
/**
 The number of seconds an ad must be visible before counting as an impression.
*/
extern NSTimeInterval const NamoImpressionTimeInSecs;
/**
 The timeout interval for SDK server requests.
*/
extern NSTimeInterval const NamoRequestTimeoutInterval;

/**
 A singleton object responsible for storing application state and connecting to NamoMedia
 backend servers.
*/
@interface NAMOBackendClient : NSObject

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
@property(nonatomic, strong) NSString *baseAdServerURL;

/**
 Base image server URL.

 Defaults to http://i.namomedia.com. Can be changed for debugging purposes.
*/
@property(nonatomic, strong) NSString *baseImageServerURL;

/**
 User agent attached to the web view on this device.
 */
@property(nonatomic, strong, readonly) NSString* userAgent;

/**
 Requests ads from the server
 */
- (void)requestAdsWithNumAds:(NSUInteger) numAds
                      viewId:(NSUInteger)viewId
                  completion:(NamoAdsRequestCompletionBlock)callback;

/**
 Sends interaction information to the server by following the given interaction url.
*/
- (void)sendInteractionWithURL:(NSString *)url
                        viewId:(NSUInteger)viewId
                    actionType:(NAMOActionType)type;

/**
 Javascript that can be used to bind a webview to ad data.
*/
- (NSString *)webViewJavascript;

@end