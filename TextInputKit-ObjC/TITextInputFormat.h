//
//  TITextInputFormat.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TITextInputFormatter;
@class TITextInputSerializer<ValueType>;

@interface TITextInputFormat<ValueType> : NSObject

@property (nonatomic, strong, readonly) TITextInputSerializer<ValueType> *serializer;

@property (nonatomic, strong, readonly) TITextInputFormatter *formatter;

- (instancetype)initWithSerializer:(TITextInputSerializer<ValueType> *)serializer
                         formatter:(TITextInputFormatter *)formatter NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
