//
//  TITextInputFormat.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputFormat

- (instancetype)initWithSerializer:(TITextInputSerializer *)serializer formatter:(TITextInputFormatter *)formatter {
    self = [super init];
    if (self) {
        _serializer = serializer;
        _formatter = formatter;
    }
    return self;
}

@end

NS_ASSUME_NONNULL_END
