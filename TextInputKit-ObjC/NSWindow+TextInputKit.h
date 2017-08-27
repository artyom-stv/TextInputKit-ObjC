//
//  NSWindow+TextInputKit.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 28/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSWindow (TextInputKit)

@property (nonatomic, strong, readonly, nullable) NSText *ti_currentEditor;

@end

NS_ASSUME_NONNULL_END
