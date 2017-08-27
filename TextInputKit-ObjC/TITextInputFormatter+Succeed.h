//
//  TITextInputFormatter+Succeed.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormatter.h"

NS_ASSUME_NONNULL_BEGIN

@class TITextInputAccessoryFormatter;

@interface TITextInputFormatter (Succeed)

- (instancetype)succeedByFormatter:(TITextInputAccessoryFormatter *)successiveFormatter;

@end

NS_ASSUME_NONNULL_END
