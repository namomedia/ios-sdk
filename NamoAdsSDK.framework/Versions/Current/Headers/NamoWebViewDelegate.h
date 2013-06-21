//
//  NamoWebViewDelegate.h
//  NamoAdsSDK
//
//  Created by Joe Blubaugh on 6/17/13.
//  Copyright (c) 2013 Namo Media. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NamoWebViewDelegate : NSObject<UIWebViewDelegate>
-(NamoWebViewDelegate *)initWithAppId: (NSString *)appId;
@end
