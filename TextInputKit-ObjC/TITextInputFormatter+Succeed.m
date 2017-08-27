//
//  TITextInputFormatter+Succeed.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormatter+Succeed.h"
#import "TITextInputAccessoryFormatter.h"

NS_ASSUME_NONNULL_BEGIN

@interface TISucceedTextInputFormatter : TITextInputFormatter

@property (nonatomic, strong, readonly) TITextInputFormatter *sourceFormatter;
@property (nonatomic, strong, readonly) TITextInputAccessoryFormatter *successiveFormatter;

- (instancetype)initWithSourceFormatter:(TITextInputFormatter *)sourceFormatter
                    successiveFormatter:(TITextInputAccessoryFormatter *)successiveFormatter NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

@implementation TISucceedTextInputFormatter

- (instancetype)initWithSourceFormatter:(TITextInputFormatter *)sourceFormatter
                    successiveFormatter:(TITextInputAccessoryFormatter *)successiveFormatter {
    self = [super init];
    if (self) {
        _sourceFormatter = sourceFormatter;
        _successiveFormatter = successiveFormatter;
    }
    return self;
}

- (TITextInputValidationResult *)validateEditingString:(NSString *)originalString
                                         withSelection:(NSRange)originalSelectedRange
                                             replacing:(NSString *)replacementString
                                                    at:(NSRange)editedRange {
    let sourceValidationResult = [self.sourceFormatter validateEditingString:originalString
                                                               withSelection:originalSelectedRange
                                                                   replacing:replacementString
                                                                          at:editedRange];

    __block var result = (TITextInputValidationResult *)nil;

    [sourceValidationResult switch_accepted:^{
        let editedString = [originalString stringByReplacingCharactersInRange:editedRange withString:replacementString];
        let resultingSelectedRange = (NSRange){
            .location = editedRange.location + replacementString.length,
            .length = 0
        };

        result = [self.successiveFormatter validateEditingResult:editedString withSelection:resultingSelectedRange];
    } changed:^(NSString *newEditedString, NSRange newSelectedRange) {
        result = [self.successiveFormatter validateEditingResult:newEditedString withSelection:newSelectedRange];
    } rejected:^{
        result = TITextInputValidationResult.rejected;
    }];

    return result;
}

@end

@implementation TITextInputFormatter (Succeed)

- (instancetype)succeedByFormatter:(TITextInputAccessoryFormatter *)successiveFormatter {
    NSParameterAssert(successiveFormatter);

    return [[TISucceedTextInputFormatter alloc] initWithSourceFormatter:self successiveFormatter:successiveFormatter];
}

@end

NS_ASSUME_NONNULL_END
