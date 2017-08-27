//
//  TITextInputSerializer+Map.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputSerializer.h"

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputSerializer<ValueType> (Map)

- (TITextInputSerializer *)mapWithDirectTransform:(id _Nullable(^)(ValueType value, NSError * __autoreleasing _Nullable * _Nullable error))directTransform
                                 reverseTransform:(ValueType(^)(id value))reverseTransform;

@end

NS_ASSUME_NONNULL_END
