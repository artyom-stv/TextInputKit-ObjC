//
//  TITextInputFormats+Plain.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormats.h"

NS_ASSUME_NONNULL_BEGIN

@class TITextInputFormat<ValueType>;

@interface TITextInputFormats (Plain)

@property (nonatomic, strong, readonly, class) TITextInputFormat<NSString *> *plain;

@end

NS_ASSUME_NONNULL_END
