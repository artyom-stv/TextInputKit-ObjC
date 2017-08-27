//
//  NSRangeExtensions.m
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import "NSRangeExtensions.h"

BOOL TIRangeEqualToRange(NSRange lhs, NSRange rhs) {
    return lhs.location == rhs.location && lhs.length == rhs.length;
}
