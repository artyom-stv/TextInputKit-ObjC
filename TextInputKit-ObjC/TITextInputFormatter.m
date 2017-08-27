//
//  TITextInputFormatter.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormatter.h"

NS_ASSUME_NONNULL_BEGIN

@ti_enumImplementation(TITextInputValidationResult,

    ti_case(accepted)

    ti_case(changed, NSString *, newEditedString, NSRange, newSelectedRange)

    ti_case(rejected)

)

@implementation TITextInputFormatter

- (TITextInputValidationResult *)validateEditingString:(NSString *)originalString
                                         withSelection:(NSRange)originalSelectedRange
                                             replacing:(NSString *)replacementString
                                                    at:(NSRange)editedRange {
    TIAbstractMethod();
}

@end

NS_ASSUME_NONNULL_END
