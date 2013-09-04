/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Jamie Pinkham
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <TargetConditionals.h>

#ifdef __OBJC_GC__
#error NAMO_SDWebImage does not support Objective-C Garbage Collection
#endif

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
#error NAMO_SDWebImage doesn't support Deployement Target version < 5.0
#endif

#if !TARGET_OS_IPHONE
#import <AppKit/AppKit.h>
#ifndef UIImage
#define UIImage NSImage
#endif
#ifndef UIImageView
#define UIImageView NSImageView
#endif
#else
#import <UIKit/UIKit.h>
#endif

#if OS_OBJECT_USE_OBJC
    #define NAMO_SDDispatchQueueRelease(q)
    #define NAMO_SDDispatchQueueSetterSementics strong
#else
    #define NAMO_SDDispatchQueueRelease
    #define NAMO_SDDispatchQueueSetterSementics
#endif

extern inline UIImage *namo_SDScaledImageForPath(NSString *path, NSObject *imageOrData);
