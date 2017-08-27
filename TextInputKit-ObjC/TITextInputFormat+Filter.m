//
//  TITextInputFormat+Filter.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat+Filter.h"
#import "TITextInputFormat+From.h"
#import "TITextInputFormatter+Filter.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputFormat (Filter)

- (TITextInputFormat *)filter:(TITextInputFormatFilterPredicate)predicate {
    return [TITextInputFormat fromSerializer:self.serializer
                                   formatter:[self.formatter filter:predicate]];
}

@end

NS_ASSUME_NONNULL_END
