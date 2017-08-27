//
//  TITextInputEvent.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TIEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputEditingState<ValueType> : NSObject

@property (nonatomic, copy, readonly) NSString *text;
@property (nonatomic, assign, readonly) NSRange selectedRange;
@property (nonatomic, strong, readonly, nullable) ValueType value;

- (instancetype)initWithText:(NSString *)text
               selectedRange:(NSRange)selectedRange
                       value:(nullable ValueType)value NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

typedef NS_OPTIONS(NSUInteger, TITextInputEditingChanges) {
    TITextInputEditingChangeText          = 1 << 0,
    TITextInputEditingChangeSelectedRange = 1 << 1,
    TITextInputEditingChangeValue         = 1 << 2,
};

@ti_genericenum(TITextInputEvent, TITextInputEvent<ValueType>,

    ti_case(editingDidBegin)

    ti_case(editingChanged, TITextInputEditingState<ValueType> *, state, TITextInputEditingChanges, changes)

    ti_case(editingDidEnd)
                
)

NS_ASSUME_NONNULL_END
