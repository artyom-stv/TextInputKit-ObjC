//
//  TITextInputFormat+From.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat+From.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputFormat (From)

+ (TITextInputFormat *)fromSerializer:(TITextInputSerializer *)serializer formatter:(TITextInputFormatter *)formatter {
    return [[TITextInputFormat alloc] initWithSerializer:serializer formatter:formatter];
}

@end

NS_ASSUME_NONNULL_END
