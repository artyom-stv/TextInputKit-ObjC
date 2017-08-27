//
//  TITextInputFormat+Map.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat+Map.h"
#import "TITextInputFormat+From.h"
#import "TITextInputFormatter+Map.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputFormat (Map)

- (TITextInputFormat *)map:(NSString *(^)(NSString *string, NSRange range, NSRange *mappedRange))transform {
    return [TITextInputFormat fromSerializer:self.serializer
                                   formatter:[self.formatter map:transform]];
}

@end

NS_ASSUME_NONNULL_END
