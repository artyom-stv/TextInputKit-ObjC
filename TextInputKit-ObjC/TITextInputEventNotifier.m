//
//  TITextInputEventNotifier.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputEventNotifier.h"
#import "TITextInputEvent.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputEventNotifier

- (void)onEvent:(TITextInputEvent *)event {
    TICallBlock(self.eventHandler, event);
}

- (void)onEditingChangedFromState:(TITextInputEditingState *)oldState toState:(TITextInputEditingState *)newState {
    let eventHandler = self.eventHandler;
    if (!eventHandler) {
        return;
    }

    var changes = (TITextInputEditingChanges)0;

    if (![oldState.text isEqualToString:newState.text]) {
        changes |= TITextInputEditingChangeText;
    }
    if (!TIRangeEqualToRange(oldState.selectedRange, newState.selectedRange)) {
        changes |= TITextInputEditingChangeSelectedRange;
    }
    if (oldState.value != newState.value && ![oldState.value isEqual:newState.value]) {
        changes |= TITextInputEditingChangeValue;
    }

    eventHandler(TITextInputEvent.editingChanged(newState, changes));
}

@end

NS_ASSUME_NONNULL_END
