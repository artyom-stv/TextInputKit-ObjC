//
//  TIFormatterObjectValue.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TIFormatterObjectValue<ValueType> : NSObject

/// The `ValueType` or nil.
@property (nonatomic, strong, readonly, nullable) ValueType value;

/// The text in the text input.
@property (nonatomic, copy, readonly) NSString *text;

- (instancetype)initWithValue:(nullable ValueType)value text:(NSString *)text NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
