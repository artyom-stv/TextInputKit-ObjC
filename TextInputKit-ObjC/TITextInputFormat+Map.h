//
//  TITextInputFormat+Map.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat.h"

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputFormat<ValueType> (Map)

- (TITextInputFormat<ValueType> *)map:(NSString *(^)(NSString *string, NSRange range, NSRange *mappedRange))transform;

@end

NS_ASSUME_NONNULL_END
