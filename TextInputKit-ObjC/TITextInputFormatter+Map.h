//
//  TITextInputFormatter+Map.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormatter.h"

NS_ASSUME_NONNULL_BEGIN

@interface TITextInputFormatter (Map)

- (TITextInputFormatter *)map:(NSString *(^)(NSString *string, NSRange range, NSRange *mappedRange))transform;

@end

NS_ASSUME_NONNULL_END
