//
//  TITextInputFormatter+Plain.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormatter+Plain.h"

NS_ASSUME_NONNULL_BEGIN

@interface TIPlainTextInputFormatter : TITextInputFormatter

@end

@implementation TIPlainTextInputFormatter

- (TITextInputValidationResult *)validateEditingString:(NSString *)originalString
                                         withSelection:(NSRange)originalSelectedRange
                                             replacing:(NSString *)replacementString
                                                    at:(NSRange)editedRange {
    return [TITextInputValidationResult accepted];
}

@end

@implementation TITextInputFormatter (Plain)

+ (TITextInputFormatter *)plain {
    return [[TIPlainTextInputFormatter alloc] init];
}

@end

NS_ASSUME_NONNULL_END
