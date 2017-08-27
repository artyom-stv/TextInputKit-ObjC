//
//  TITextInputEventNotifier.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TITextInputEditingState<ValueType>;
@class TITextInputEvent<ValueType>;

@interface TITextInputEventNotifier<ValueType> : NSObject

@property (nonatomic, copy, nullable) void(^eventHandler)(TITextInputEvent<ValueType> *event);

- (void)onEvent:(TITextInputEvent<ValueType> *)event;

- (void)onEditingChangedFromState:(TITextInputEditingState<ValueType> *)oldState toState:(TITextInputEditingState<ValueType> *)newState;

@end

NS_ASSUME_NONNULL_END
