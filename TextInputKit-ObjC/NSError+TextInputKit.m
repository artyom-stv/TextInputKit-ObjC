//
//  NSError+TextInputKit.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "NSError+TextInputKit.h"

NS_ASSUME_NONNULL_BEGIN

@implementation NSError (TextInputKit)

+ (NSError *)ti_unknown {
    return [NSError ti_errorWithCode:TIErrorCodeUnknown userInfo:nil];
}

+ (NSError *(^)(NSString *))ti_missingFramework {
    return ^(NSString *frameworkName) {
        let userInfo = @{
            TIErrorFrameworkNameErrorKey: frameworkName
        };
        return [NSError ti_errorWithCode:TIErrorCodeMissingFramework userInfo:userInfo];
    };
}

+ (instancetype)ti_errorWithCode:(TIErrorCode)code userInfo:(nullable NSDictionary<NSString *, id> *)userInfo {
    return [self errorWithDomain:TIErrorDomain code:code userInfo:userInfo];
}

@end

NS_ASSUME_NONNULL_END
