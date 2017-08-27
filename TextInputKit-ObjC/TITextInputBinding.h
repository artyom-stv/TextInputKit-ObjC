//
//  TITextInputBinding.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TITextInputEvent<ValueType>;

@interface TITextInputBinding<ValueType> : NSObject

@property (nonatomic, strong) NSString *text;

@property (nonatomic, assign) NSRange selectedRange;

@property (nonatomic, strong, nullable) ValueType value;

@property (nonatomic, copy, nullable) void(^eventHandler)(TITextInputEvent<ValueType> *event);

@end

NS_ASSUME_NONNULL_END
