//
//  TIMacro.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 17/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#define let __auto_type const
#define var __auto_type

#define TIAbstractMethod() \
    @throw [NSException exceptionWithName:NSInternalInconsistencyException \
                                   reason:[NSString stringWithFormat:@"Call to abstract method %s", sel_getName(_cmd)] \
                                 userInfo:nil];

#define TICallBlock(block_, ...) \
    do { \
        let block = (block_); \
        if (block) block(__VA_ARGS__); \
    } while (NO)

#define TICallBlockAndReturn(block_, defaultValue_, ...) \
    ({ \
        let block = (block_); \
        block ? block(__VA_ARGS__) : (defaultValue_); \
    })
