//
//  TITextInputFormat+Bind.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat+Bind.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputFormat (Bind)

- (TITextInputBinding *)bindToTextField:(id<TITextInputFormatBindable>)textField {
    return [textField bindFormat:self];
}

@end

NS_ASSUME_NONNULL_END
