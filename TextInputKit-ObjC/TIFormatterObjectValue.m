//
//  TIFormatterObjectValue.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TIFormatterObjectValue.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TIFormatterObjectValue

- (instancetype)initWithValue:(nullable id)value text:(NSString *)text {
    self = [super init];
    if (self) {
        _value = value;
        _text = [text copy];
    }
    return self;
}

@end

NS_ASSUME_NONNULL_END
