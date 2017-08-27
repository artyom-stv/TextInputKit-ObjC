//
//  TITextInputSerializer.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputSerializer<ValueType> : NSObject

- (NSString *)stringForValue:(ValueType)value;

- (nullable ValueType)valueForString:(NSString *)string error:(out NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
