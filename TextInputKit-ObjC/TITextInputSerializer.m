//
//  TITextInputSerializer.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputSerializer.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputSerializer

- (NSString *)stringForValue:(id)value {
    TIAbstractMethod();
}

- (nullable id)valueForString:(NSString *)string error:(out NSError * _Nullable * _Nullable)error {
    TIAbstractMethod();
}

@end

NS_ASSUME_NONNULL_END
