//
//  TIObjectCache.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TIObjectCache<ObjectType> : NSObject

@property (nonatomic, weak, nullable) ObjectType object;

- (instancetype)initWithDispatchQueue:(dispatch_queue_t)dispatchQueue NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
