//
//  TITextInputFormat+Formatter.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat+Formatter.h"
#import "TIFormatterObjectValue.h"
#import "TITextInputFormatter.h"
#import "TITextInputSerializer.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TIFormatterOptions

+ (instancetype)options {
    let options = (TIFormatterOptions *)[(id)[self alloc] init];
    return options;
}

- (id)copyWithZone:(nullable NSZone *)zone {
    let options = (TIFormatterOptions *)[(id)[TIFormatterOptions alloc] init];
#if TARGET_OS_OSX
    options->_tracksCurrentEditorSelection = _tracksCurrentEditorSelection;
#endif
    return options;
}

@end

@interface TIFormatterAdapter<ValueType> : NSFormatter

@property (nonatomic, strong, readonly) TITextInputFormat<ValueType> *format;
@property (nonatomic, copy, readonly) TIFormatterOptions *options;

- (instancetype)initWithFormat:(TITextInputFormat<ValueType> *)format options:(TIFormatterOptions *)options NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;

@end

@implementation TIFormatterAdapter

- (instancetype)initWithFormat:(TITextInputFormat *)format options:(TIFormatterOptions *)options {
    self = [super init];
    if (self) {
        _format = format;
        _options = [options copy];
    }
    return self;
}

- (nullable NSString *)stringForObjectValue:(nullable id)object {
    if (!object) {
        return nil;
    }

    let objectValue = (TIFormatterObjectValue *)object;
    if (![objectValue isMemberOfClass:[TIFormatterObjectValue class]]) {
        let reason = [NSString stringWithFormat:@"Unexpected type of an object passed to Formatter.string(for:) (expected: %@, actual: %@)", [TIFormatterObjectValue class], [object class]];
        @throw [NSException exceptionWithName:NSInternalInconsistencyException
                                       reason:reason
                                     userInfo:nil];
    }

    id const value = objectValue.value;
    if (value) {
        return [self.format.serializer stringForValue:value];
    }
    else {
        return objectValue.text;
    }
}

- (BOOL)getObjectValue:(out id _Nullable * _Nullable)objectPtr
             forString:(NSString *)string
      errorDescription:(out NSString * _Nullable * _Nullable)errorDescriptionPtr {

    var error = (NSError *)nil;
    id const value = [self.format.serializer valueForString:string error:&error];

    if (!value) {
        if (errorDescriptionPtr) {
            *errorDescriptionPtr = error.localizedDescription;
        }
    }

    if (objectPtr) {
        *objectPtr = [[TIFormatterObjectValue alloc] initWithValue:value text:string];
    }

    return YES;
}

- (BOOL)isPartialStringValid:(NSString *)partialString
            newEditingString:(NSString * _Nullable * _Nullable)newStringPtr
            errorDescription:(NSString * _Nullable * _Nullable)errorDescriptionPtr {

    let reason = [NSString stringWithFormat:@"%s isn't implemented. It is not supported by a `Formatter` created by `TextInputFormat`.", sel_getName(_cmd)];
    @throw [NSException exceptionWithName:NSInternalInconsistencyException
                                   reason:reason
                                 userInfo:nil];
}

- (BOOL)isPartialStringValid:(NSString **)partialStringPtr
       proposedSelectedRange:(nullable NSRangePointer)proposedSelectedRangePtr
              originalString:(NSString *)originalString
       originalSelectedRange:(NSRange)editedRange
            errorDescription:(NSString * _Nullable * _Nullable)errorDescriptionPtr {

    let originalSelectedRange = ({
        var range = editedRange;

#if TARGET_OS_OSX
        if (self.options.tracksCurrentEditorSelection) {
            let editor = [NSApplication sharedApplication].keyWindow.ti_currentEditor;
            if (editor) {
                range = editor.ti_selectedRange
            }
        }
#endif

        range;
    });

    let editedString = *partialStringPtr;

    let resultingSelectedRange = ({
        NSRange range;

        if (proposedSelectedRangePtr) {
            range = *proposedSelectedRangePtr;
        } else {
            range = (NSRange){
                .location = editedString.length - (originalString.length - NSMaxRange(editedRange)),
                .length = 0
            };
        }

        range;
    });

    NSAssert(resultingSelectedRange.length == 0,
             @"The proposed selected range after editing text should be empty (a blinking cursor).");
    NSAssert([[originalString substringToIndex:editedRange.location] isEqualToString:[editedString substringToIndex:editedRange.location]],
             @"The strings before and after the editing should have a common prefix.");
    NSAssert([[originalString substringFromIndex:NSMaxRange(editedRange)] isEqualToString:[editedString substringFromIndex:resultingSelectedRange.location]],
             @"The strings before and after the editing should have a common suffix.");

    let replacementString = ({
        let range = (NSRange){
            .location = editedRange.location,
            .length = resultingSelectedRange.location - editedRange.location
        };
        [editedString substringWithRange:range];
    });

    let validationResult = [self.format.formatter validateEditingString:originalString
                                                          withSelection:originalSelectedRange
                                                              replacing:replacementString
                                                                     at:editedRange];

    __block BOOL result = NO;

    [validationResult switch_accepted:^{
        result = YES;
    } changed:^(NSString *newEditedString, NSRange newSelectedRange) {
        *partialStringPtr = newEditedString;
        if (proposedSelectedRangePtr) {
            *proposedSelectedRangePtr = newSelectedRange;
        }
    } rejected:^{
        // Do nothing.
    }];

    return result;
}

@end

@implementation TITextInputFormat (Formatter)

- (NSFormatter *)toFormatterWithOptions:(TIFormatterOptions *)options {
    return [[TIFormatterAdapter alloc] initWithFormat:self options:options];
}

- (NSFormatter *)toFormatter {
    return [self toFormatterWithOptions:[TIFormatterOptions options]];
}

@end

NS_ASSUME_NONNULL_END
