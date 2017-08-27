//
//  TITextInputAccessoryFormatter.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputAccessoryFormatter.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputAccessoryFormatter

- (TITextInputValidationResult *)validateEditingResult:(NSString *)editedString
                                         withSelection:(NSRange)resultingSelectedRange {
    TIAbstractMethod();
}

@end

NS_ASSUME_NONNULL_END
