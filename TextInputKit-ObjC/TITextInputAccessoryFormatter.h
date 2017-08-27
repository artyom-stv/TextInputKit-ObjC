//
//  TITextInputAccessoryFormatter.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TITextInputValidationResult;

@interface TITextInputAccessoryFormatter : NSObject

- (TITextInputValidationResult *)validateEditingResult:(NSString *)editedString
                                         withSelection:(NSRange)resultingSelectedRange;

@end

NS_ASSUME_NONNULL_END
