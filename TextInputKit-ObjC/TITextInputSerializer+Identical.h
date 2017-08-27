//
//  TITextInputSerializer+Identical.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputSerializer.h"

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputSerializer<ValueType> (Identical)

@property (nonatomic, strong, readonly, class) TITextInputSerializer<NSString *> *identical;

@end

NS_ASSUME_NONNULL_END
