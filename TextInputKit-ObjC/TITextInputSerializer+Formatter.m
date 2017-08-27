//
//  TITextInputSerializer+Formatter.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputSerializer+Formatter.h"
#import "NSError+TextInputKit.h"

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputSerializerFromFormatter : TITextInputSerializer

@property (nonatomic, strong, readonly) NSFormatter *formatter;
@property (nonatomic, unsafe_unretained, readonly) Class valueClass;

- (instancetype)initWithFormatter:(NSFormatter *)formatter valueClass:(Class)valueClass NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

@implementation TITextInputSerializerFromFormatter

- (instancetype)initWithFormatter:(NSFormatter *)formatter valueClass:(Class)valueClass {
    self = [super init];
    if (self) {
        _formatter = formatter;
        _valueClass = valueClass;
    }
    return self;
}

- (NSString *)stringForValue:(id)value {
    return [self.formatter editingStringForObjectValue:value] ?: @"";
}

- (nullable id)valueForString:(NSString *)string error:(out NSError * _Nullable * _Nullable)error {
    if (error) {
        *error = nil;
    }

    var value = (NSObject *)nil;
    var errorDescription = (NSString *)nil;
    if (![self.formatter getObjectValue:&value forString:string errorDescription:&errorDescription]) {
        if (error) {
            *error = NSError.ti_unknown;
        }
        return nil;
    }

    if (!value) {
        let reason = @"Formatter.getObjectValue(_:for:errorDescription:) returned true but didn't assign an object.";
        @throw [NSException exceptionWithName:NSInternalInconsistencyException
                                       reason:reason
                                     userInfo:nil];
    }

    if (![value isKindOfClass:self.valueClass]) {
        let reason = [NSString stringWithFormat:@"Unexpected type of an object assigned by Formatter.getObjectValue(_:for:errorDescription:) (expected: %@, actual: %@)", self.valueClass, [value class]];
        @throw [NSException exceptionWithName:NSInternalInconsistencyException
                                       reason:reason
                                     userInfo:nil];
    }

    return value;
}

@end

@implementation TITextInputSerializer (Formatter)

- (instancetype)fromFormatter:(NSFormatter *)formatter valueClass:(Class)valueClass {
    return [[TITextInputSerializerFromFormatter alloc] initWithFormatter:formatter valueClass:valueClass];
}

@end

NS_ASSUME_NONNULL_END
