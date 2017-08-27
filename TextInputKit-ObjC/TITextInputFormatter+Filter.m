//
//  TITextInputFormatter+Filter.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormatter+Filter.h"
#import "TITextInputFormatter+Succeed.h"
#import "TITextInputAccessoryFormatter.h"

NS_ASSUME_NONNULL_BEGIN

@interface TIFilterTextInputFormatter : TITextInputAccessoryFormatter

@property (nonatomic, copy, readonly) BOOL(^predicate)(NSString *);

- (instancetype)initWithPredicate:(BOOL(^)(NSString *))predicate NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

@implementation TIFilterTextInputFormatter

- (instancetype)initWithPredicate:(BOOL(^)(NSString *))predicate {
    self = [super init];
    if (self) {
        _predicate = predicate;
    }
    return self;
}

- (TITextInputValidationResult *)validateEditingResult:(NSString *)editedString withSelection:(NSRange)resultingSelectedRange {
    return self.predicate(editedString)
        ? TITextInputValidationResult.accepted
        : TITextInputValidationResult.rejected;
}

@end

@implementation TITextInputFormatter (Filter)

- (TITextInputFormatter *)filter:(BOOL(^)(NSString *))predicate {
    return [self succeedByFormatter:[[TIFilterTextInputFormatter alloc] initWithPredicate:predicate]];
}

@end

NS_ASSUME_NONNULL_END
