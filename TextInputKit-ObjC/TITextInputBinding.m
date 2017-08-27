//
//  TITextInputBinding.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputBinding.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputBinding

@dynamic text;
@dynamic selectedRange;
@dynamic value;
@dynamic eventHandler;

- (instancetype)initWithFormat:(TITextInputFormat *)format {
    self = [super init];
    if (self) {
        _format = format;
    }
    return self;
}

- (void)dealloc {
    [self unbind];
}

- (void)unbind {
    TIAbstractMethod();
}

@end

NS_ASSUME_NONNULL_END
