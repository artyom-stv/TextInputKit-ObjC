//
//  TITextInputEvent.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputEvent.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputEditingState

- (instancetype)initWithText:(NSString *)text
               selectedRange:(NSRange)selectedRange
                       value:(nullable id)value {
    self = [super init];
    if (self) {
        _text = [text copy];
        _selectedRange = selectedRange;
        _value = value;
    }
    return self;
}

@end

@ti_enumImplementation(TITextInputEvent,
     ti_case(editingDidBegin)
     ti_case(editingChanged, TITextInputEditingState *, state, TITextInputEditingChanges, changes)
     ti_case(editingDidEnd)
)

//@implementation TITextInputEvent
//
//+ (TITextInputEvent *)editingDidBegin {
//}
//
//+ (TITextInputEvent *(^)(TITextInputEditingState *, TITextInputEditingChanges))editingChanged {
//    return ^(TITextInputEditingState *state, TITextInputEditingChanges changes) {
//        return;
//    };
//}
//
//+ (TITextInputEvent *)editingDidEnd {
//}
//
//@end

NS_ASSUME_NONNULL_END
