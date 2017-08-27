//
//  TIObjectCache.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "TIObjectCache.h"

#if !TARGET_OS_OSX
#import <UIKit/UIKit.h>
#endif

@interface TIObjectCache ()

@property (nonatomic, strong, readonly) dispatch_queue_t dispatchQueue;

@property (nonatomic, strong, readonly) NSCache<NSObject *, id> *cache;
@property (nonatomic, strong, readonly) NSObject *cacheKey;

@end

@implementation TIObjectCache {
    __weak id _weakObject;
}

- (instancetype)initWithDispatchQueue:(dispatch_queue_t)dispatchQueue {
    self = [super init];
    if (self) {
        _dispatchQueue = dispatchQueue;

        _cache = [[NSCache alloc] init];
        _cacheKey = [[NSObject alloc] init];

#if !TARGET_OS_OSX
        [NSNotificationCenter.defaultCenter addObserver:self
                                               selector:@selector(didReceiveMemoryWarning:)
                                                   name:UIApplicationDidReceiveMemoryWarningNotification
                                                 object:nil];
#endif
    }
    return self;
}

- (void)dealloc {
    [NSNotificationCenter.defaultCenter removeObserver:self];
}

- (instancetype)init {
    return [self initWithDispatchQueue:dispatch_get_main_queue()];
}

- (id)object {
    return _weakObject;
}

- (void)setObject:(id)object {
    _weakObject = object;
    if (object) {
        [self.cache setObject:object forKey:self.cacheKey];
    } else {
        [self.cache removeAllObjects];
    }
}

#if !TARGET_OS_OSX
- (void)didReceiveMemoryWarning:(NSNotification *)notification {
    [self.cache removeAllObjects];
}
#endif

@end
