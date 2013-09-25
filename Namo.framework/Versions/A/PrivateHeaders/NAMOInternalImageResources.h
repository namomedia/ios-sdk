// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

/** A class that returns image resources from Base64 encoding in an effort to avoid
    having to drag in the Artwork folder to the SDK.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NAMOInternalImageResources : NSObject

+(UIImage*)namoAdIndicatorLight;
+(UIImage*)namoAdIndicator;
+(UIImage*)namoSample3Button;

@end
