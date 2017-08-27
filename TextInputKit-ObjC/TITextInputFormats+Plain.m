//
//  TITextInputFormats+Plain.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormats+Plain.h"
#import "TITextInputFormat+From.h"
#import "TITextInputFormatter+Plain.h"
#import "TITextInputSerializer+Identical.h"

NS_ASSUME_NONNULL_BEGIN

@implementation TITextInputFormats (Plain)

+ (TITextInputFormat<NSString *> *)plain {
    return [TITextInputFormat fromSerializer:TITextInputSerializer.identical formatter:TITextInputFormatter.plain];
}

@end

NS_ASSUME_NONNULL_END
