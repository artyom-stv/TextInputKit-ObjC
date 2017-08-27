//
//  TITextInputSerializer+Map.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputSerializer+Map.h"

NS_ASSUME_NONNULL_BEGIN

@interface TIMapTextInputSerializer<ValueType> : TITextInputSerializer<ValueType>


@property (nonatomic, strong, readonly) TITextInputSerializer<ValueType> *sourceSerializer;
@property (nonatomic, strong, readonly) id _Nullable(^directTransform)(id value, NSError * __autoreleasing _Nullable * _Nullable error);
@property (nonatomic, strong, readonly) id(^reverseTransform)(id value);

- (instancetype)initWithSourceSerializer:(TITextInputSerializer<ValueType> *)sourceSerializer
                         directTransform:(id _Nullable(^)(id value, NSError * __autoreleasing _Nullable * _Nullable error))directTransform
                        reverseTransform:(id(^)(id value))reverseTransform NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

@implementation TIMapTextInputSerializer

- (instancetype)initWithSourceSerializer:(TITextInputSerializer *)sourceSerializer
                         directTransform:(id _Nullable(^)(id value, NSError * __autoreleasing _Nullable * _Nullable error))directTransform
                        reverseTransform:(id(^)(id value))reverseTransform {
    self = [super init];
    if (self) {
        _sourceSerializer = sourceSerializer;
        _directTransform = directTransform;
        _reverseTransform = reverseTransform;
    }
    return self;
}

- (NSString *)stringForValue:(id)value {
    return [self.sourceSerializer stringForValue:self.reverseTransform(value)];
}

- (nullable id)valueForString:(NSString *)string error:(out NSError * _Nullable * _Nullable)error {
    if (error) {
        *error = nil;
    }

    id const value = [self.sourceSerializer valueForString:string error:error];
    if (!value) {
        return nil;
    }

    return self.directTransform(value, error);
}

@end

@implementation TITextInputSerializer (Map)

- (TITextInputSerializer *)mapWithDirectTransform:(id _Nullable(^)(id value, NSError * __autoreleasing _Nullable * _Nullable error))directTransform
                                 reverseTransform:(id(^)(id value))reverseTransform {
    return [[TIMapTextInputSerializer alloc] initWithSourceSerializer:self
                                                      directTransform:directTransform
                                                     reverseTransform:reverseTransform];
}

@end

NS_ASSUME_NONNULL_END
