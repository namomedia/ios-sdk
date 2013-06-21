//
//  NamoWebAdsHelper.h
//  NamoAdsSDK
//
//  Created by Joe Blubaugh on 6/17/13.
//  Copyright (c) 2013 Namo Media. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NamoWebAdsHelper : NSObject
+(void) injectDataToWebView: (UIWebView*)webView withAppId:(NSString *) appId;
+(id <UIWebViewDelegate>) uiWebViewDelegate:(NSString *) appId;
@end
