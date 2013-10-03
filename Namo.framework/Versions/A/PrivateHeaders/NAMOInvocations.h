//  Copyright (c) 2013 Namo Media, Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import "NAMOIndexPathAdjuster.h"

/**
 * Provides a set of static invocation methods useful for proxying methods.
 */
@interface NAMOInvocations : NSObject
+ (NSInvocation *)invokeForTarget:(id)target
                 with2ArgSelector:(SEL)selector
                         firstArg:(id)arg1
                        secondArg:(NSIndexPath *)indexPath
                indexPathAdjuster:(NAMOIndexPathAdjuster *)indexPathAdjuster;

+ (NSInvocation *)invokeForTarget:(id)target
                 with3ArgSelector:(SEL)selector
                         firstArg:(id)arg1
                        secondArg:(id)arg2
                         thirdArg:(NSIndexPath *)indexPath
                indexPathAdjuster:(NAMOIndexPathAdjuster *)indexPathAdjuster;

+ (NSInvocation *)invokeForTarget:(id)target
              with3ArgIntSelector:(SEL)selector
                         firstArg:(id)arg1
                        secondArg:(NSInteger)arg2
                         thirdArg:(NSIndexPath *)indexPath
                indexPathAdjuster:(NAMOIndexPathAdjuster *)indexPathAdjuster;

+ (BOOL)boolResultForInvocation:(NSInvocation *)invocation
                   defaultValue:(BOOL)defaultValue;

+ (CGSize)sizeResultForInvocation:(NSInvocation *)invocation
                     defaultValue:(CGSize)defaultValue;

+ (NSInteger)intResultForInvocation:(NSInvocation *)invocation
                       defaultValue:(NSInteger)defaultValue;

+ (id)resultForInvocation:(NSInvocation *)invocation defaultValue:(id)defaultValue;

+ (NSInvocation *)invocationForTarget:(id)target
                             selector:(SEL)selector
                            indexPath:(NSIndexPath *)indexPath
                    indexPathAdjuster:(NAMOIndexPathAdjuster *)indexPathAdjuster;
@end
