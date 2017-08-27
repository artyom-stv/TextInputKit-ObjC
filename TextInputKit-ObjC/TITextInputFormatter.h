//
//  TITextInputFormatter.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TIEnum.h"

NS_ASSUME_NONNULL_BEGIN

@ti_enum(TITextInputValidationResult,

    ti_case(accepted)

    ti_case(changed, NSString *, newEditedString, NSRange, newSelectedRange)

    ti_case(rejected)

)

@interface TITextInputFormatter : NSObject

- (TITextInputValidationResult *)validateEditingString:(NSString *)originalString
                                         withSelection:(NSRange)originalSelectedRange
                                             replacing:(NSString *)replacementString
                                                    at:(NSRange)editedRange;

@end

NS_ASSUME_NONNULL_END
