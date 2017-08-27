//
//  TITextInputFormat+Formatter.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TITextInputFormat.h"

NS_ASSUME_NONNULL_BEGIN

@interface TIFormatterOptions : NSObject <NSCopying>

#if TARGET_OS_OSX
@property (nonatomic, assign) BOOL tracksCurrentEditorSelection;
#endif

+ (instancetype)options;

- (instancetype)init NS_UNAVAILABLE;

@end

@interface TIFormatterOptions (TypedCopy)

- (TIFormatterOptions *)copy;

@end

@interface TITextInputFormat<ValueType> (Formatter)

- (NSFormatter *)toFormatterWithOptions:(TIFormatterOptions *)options;

- (NSFormatter *)toFormatter;

@end

NS_ASSUME_NONNULL_END
