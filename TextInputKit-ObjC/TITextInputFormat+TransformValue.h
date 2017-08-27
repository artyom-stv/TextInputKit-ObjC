//
//  TITextInputFormat+TransformValue.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat.h"

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputFormat<ValueType> (TransformValue)

- (TITextInputFormat *)transformValueWithDirectTransform:(id _Nullable(^)(ValueType value, NSError * _Nullable * _Nullable error))directTransform
                                        reverseTransform:(ValueType(^)(id value))reverseTransform;


@end

NS_ASSUME_NONNULL_END
