//
//  TIError.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const TIErrorDomain;

extern NSString *const TIErrorFrameworkNameErrorKey;

typedef NS_ENUM(NSUInteger, TIErrorCode) {
    TIErrorCodeUnknown,
    TIErrorCodeMissingFramework
};

NS_ASSUME_NONNULL_END
