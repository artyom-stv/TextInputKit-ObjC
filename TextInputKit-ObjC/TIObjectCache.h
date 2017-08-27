//
//  TIObjectCache.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 16/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TIObjectCache<ObjectType> : NSObject

@property (nonatomic, weak, nullable) ObjectType object;

@end
