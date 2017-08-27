//
//  TITextInputSerializer+Identical.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputSerializer+Identical.h"

NS_ASSUME_NONNULL_BEGIN

@interface TIIdenticalTextInputSerializer : TITextInputSerializer<NSString *>

@end

@implementation TIIdenticalTextInputSerializer

- (NSString *)stringForValue:(NSString *)value {
    return value;
}

- (nullable NSString *)valueForString:(NSString *)string error:(out NSError * _Nullable * _Nullable)error {
    if (error) {
        *error = nil;
    }
    return string;
}

@end

@implementation TITextInputSerializer (Identical)

+ (TITextInputSerializer *)identical {
    return [[TIIdenticalTextInputSerializer alloc] init];
}

@end

NS_ASSUME_NONNULL_END
