//
//  NSWindow+TextInputKit.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 28/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "NSWindow+TextInputKit.h"

NS_ASSUME_NONNULL_BEGIN

@implementation NSWindow (TextInputKit)

- (nullable NSText *)ti_currentEditor {
    let editor = [self fieldEditor:NO forObject:nil];

    return self.firstResponder == editor ? editor : nil;
}

@end

NS_ASSUME_NONNULL_END
