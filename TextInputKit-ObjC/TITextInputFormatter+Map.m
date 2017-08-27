//
//  TITextInputFormatter+Map.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormatter+Map.h"
#import "TITextInputFormatter+Succeed.h"
#import "TITextInputAccessoryFormatter.h"

NS_ASSUME_NONNULL_BEGIN

@interface TIMapTextInputFormatter : TITextInputAccessoryFormatter

@property (nonatomic, copy, readonly) NSString *(^transform)(NSString *string, NSRange range, NSRange *mappedRange);

- (instancetype)initWithTransform:(NSString *(^)(NSString *string, NSRange range, NSRange *mappedRange))transform NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

@implementation TIMapTextInputFormatter

- (instancetype)initWithTransform:(NSString *(^)(NSString *string, NSRange range, NSRange *mappedRange))transform {
    self = [super init];
    if (self) {
        _transform = transform;
    }
    return self;
}

- (TITextInputValidationResult *)validateEditingResult:(NSString *)editedString withSelection:(NSRange)resultingSelectedRange {
    var newSelectedRange = (NSRange){ 0, 0 };
    let newEditedString = self.transform(editedString, resultingSelectedRange, &newSelectedRange);

    return TIRangeEqualToRange(resultingSelectedRange, newSelectedRange) && [editedString isEqualToString:newEditedString]
        ? TITextInputValidationResult.accepted
        : TITextInputValidationResult.changed(newEditedString, newSelectedRange);
}

@end

@implementation TITextInputFormatter (Map)

- (TITextInputFormatter *)map:(NSString *(^)(NSString *string, NSRange range, NSRange *mappedRange))transform {
    return [self succeedByFormatter:[[TIMapTextInputFormatter alloc] initWithTransform:transform]];
}

@end

NS_ASSUME_NONNULL_END
