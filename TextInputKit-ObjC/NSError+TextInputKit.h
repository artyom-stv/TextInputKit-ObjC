//
//  NSError+TextInputKit.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (TextInputKit)

@property (nonatomic, strong, readonly, class) NSError *ti_unknown;
@property (nonatomic, strong, readonly, class) NSError *(^ti_missingFramework)(NSString *frameworkName);

@end

NS_ASSUME_NONNULL_END
