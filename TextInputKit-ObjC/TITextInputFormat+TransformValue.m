//
//  TITextInputFormat+TransformValue.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat+TransformValue.h"
#import "TITextInputFormat+From.h"
#import "TITextInputSerializer+Map.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputFormat (TransformValue)

- (TITextInputFormat *)transformValueWithDirectTransform:(id _Nullable(^)(id value, NSError * _Nullable * _Nullable error))directTransform
                                        reverseTransform:(id(^)(id value))reverseTransform {
    return [TITextInputFormat fromSerializer:[self.serializer mapWithDirectTransform:directTransform reverseTransform:reverseTransform]
                                   formatter:self.formatter];
}

@end

NS_ASSUME_NONNULL_END
