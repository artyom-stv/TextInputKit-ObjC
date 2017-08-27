//
//  TITextInputFormat+Filter.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat.h"

NS_ASSUME_NONNULL_BEGIN

typedef BOOL(^TITextInputFormatFilterPredicate)(NSString *);

@interface TITextInputFormat<ValueType> (Filter)

- (TITextInputFormat<ValueType> *)filter:(TITextInputFormatFilterPredicate)predicate;

@end

NS_ASSUME_NONNULL_END
