//
//  TITextInputSerializer+Formatter.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputSerializer.h"

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputSerializer<ValueType> (Formatter)

- (instancetype)fromFormatter:(NSFormatter *)formatter valueClass:(Class)valueClass;

@end

NS_ASSUME_NONNULL_END
