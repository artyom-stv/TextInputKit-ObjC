//
//  TITextInputFormat+Bind.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat.h"

NS_ASSUME_NONNULL_BEGIN

@class TITextInputBinding<ValueType>;

@protocol TITextInputFormatBindable <NSObject>

- (TITextInputBinding *)bindFormat:(TITextInputFormat *)format;

@end

@interface TITextInputFormat<ValueType> (Bind)

- (TITextInputBinding<ValueType> *)bindToTextField:(id<TITextInputFormatBindable>)textField;

@end

NS_ASSUME_NONNULL_END
