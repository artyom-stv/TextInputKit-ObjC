//
//  TIEnum.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TIMetaMacro.h"

#define ti_enum(enum_, ...) \
    ti_genericenum(enum_, enum_, __VA_ARGS__)

#define ti_genericenum(enum_, enumWithGenerics_, ...) \
    TI_ENUM(enum_, enumWithGenerics_, TI_DROP(1, __VA_ARGS__))

// http://www.openradar.me/23711954
#define ti_enumImplementation(enum_, cases_) \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Wmismatched-parameter-types\"") \
    _Pragma("clang diagnostic ignored \"-Wmismatched-return-types\"") \
    TI_ENUM_IMPLEMENTATION(enum_, TI_DROP(1, cases_)) \
    _Pragma("clang diagnostic pop")

#define ti_case(case_, ...) \
    , (case_, __VA_ARGS__)

// Implementation details

#define TI_ENUM(enum_, enumWithGenerics_, ...) \
    TI_ENUM_BASE_CLASS_DECLARATION(enum_, enumWithGenerics_, __VA_ARGS__)

#define TI_ENUM_IMPLEMENTATION(enum_, ...) \
    class enum_; \
    \
    TI_ENUM_CASE_ENUM(enum_, __VA_ARGS__) \
    \
    TI_FOREACH_CXT(TI_ENUM_CASE_CLASS_DECLARATION_ITER, , enum_, __VA_ARGS__) \
    \
    TI_FOREACH_CXT(TI_ENUM_CASE_CLASS_DEFINITION_ITER, , enum_, __VA_ARGS__) \
    \
    TI_ENUM_BASE_CLASS_DEFINITION(enum_, __VA_ARGS__)

#define TI_ENUM_BASE_CLASS_DECLARATION(enum_, enumWithGenerics_, ...) \
    interface enumWithGenerics_ : NSObject \
    \
    TI_FOREACH_CXT(TI_ENUM_CLASS_PROPERTY_DECLARATION_ITER, , enumWithGenerics_, __VA_ARGS__) \
    \
    - (instancetype)init NS_UNAVAILABLE; \
    \
    TI_IF_EMPTY(__VA_ARGS__)()(TI_ENUM_SWITCH_DECLARATION(__VA_ARGS__);) \
    \
    @end

#define TI_ENUM_BASE_CLASS_DEFINITION(enum_, ...) \
    @implementation enum_ { \
        @public \
        TI_ENUM_CASE_ENUM_NAME(enum_) _case;\
    } \
    \
    TI_FOREACH_CXT(TI_ENUM_CLASS_PROPERTY_DEFINITION_ITER, , enum_, __VA_ARGS__) \
    \
    TI_IF_EMPTY(__VA_ARGS__)()(TI_ENUM_SWITCH_DEFINITION(enum_, __VA_ARGS__)) \
    \
    @end

#define TI_ENUM_CASE_ENUM(enum_, ...) \
    typedef NS_ENUM(NSUInteger, TI_ENUM_CASE_ENUM_NAME(enum_)) { \
        TI_FOREACH_CXT(TI_ENUM_CASE_ENUM_CONSTANT_ITER, , enum_, __VA_ARGS__) \
    };
#define TI_ENUM_CASE_ENUM_NAME(enum_) \
    enum_##_Case
#define TI_ENUM_CASE_ENUM_CONSTANT(enum_, caseTuple_) \
    TI_CONCAT(TI_CONCAT(TI_ENUM_CASE_ENUM_NAME(enum_), _), TI_ENUM_CASE_NAME caseTuple_)
#define TI_ENUM_CASE_ENUM_CONSTANT_ITER(idx, enum_, caseTuple_) \
    TI_ENUM_CASE_ENUM_CONSTANT(enum_, caseTuple_),

#define TI_ENUM_CASE_CLASS_DECLARATION_ITER(idx_, enum_, caseTuple_) \
    @interface TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) : enum_ \
    @end

#define TI_ENUM_CASE_CLASS_DEFINITION_ITER(idx_, enum_, caseTuple_) \
    @implementation TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) { \
    @public \
        TI_ENUM_CASE_CLASS_IVARS caseTuple_ \
    } \
    @end

#define TI_ENUM_CLASS_PROPERTY_DECLARATION_ITER(idx_, enumWithGenerics_, caseTuple_) \
    TI_ENUM_CASE_IF_NO_ARGS caseTuple_ \
        (TI_ENUM_CLASS_PROPERTY_DECLARATION_OBJECT(enumWithGenerics_, caseTuple_))(TI_ENUM_CLASS_PROPERTY_DECLARATION_BLOCK(enumWithGenerics_, caseTuple_))
#define TI_ENUM_CLASS_PROPERTY_DECLARATION_BLOCK(enumWithGenerics_, caseTuple_) \
    @property (nonatomic, copy, readonly, class) enumWithGenerics_ *(^TI_ENUM_CASE_NAME caseTuple_)(TI_ENUM_BLOCK_ARGS caseTuple_);
#define TI_ENUM_CLASS_PROPERTY_DECLARATION_OBJECT(enumWithGenerics_, caseTuple_) \
    @property (nonatomic, strong, readonly, class) enumWithGenerics_ *TI_ENUM_CASE_NAME caseTuple_;

#define TI_ENUM_CLASS_PROPERTY_DEFINITION_ITER(idx_, enum_, caseTuple_) \
    TI_ENUM_CASE_IF_NO_ARGS caseTuple_ \
        (TI_ENUM_CLASS_PROPERTY_DEFINITION_OBJECT(enum_, caseTuple_))(TI_ENUM_CLASS_PROPERTY_DEFINITION_BLOCK(enum_, caseTuple_))
#define TI_ENUM_CLASS_PROPERTY_DEFINITION_BLOCK(enum_, caseTuple_) \
    + (enum_ *(^)(TI_ENUM_BLOCK_ARGS caseTuple_))TI_ENUM_CASE_NAME caseTuple_ { \
        return ^(TI_ENUM_BLOCK_ARGS caseTuple_) { \
            TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) *obj_ = [(id)[TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) alloc] init]; \
            obj_->_case = TI_ENUM_CASE_ENUM_CONSTANT(enum_, caseTuple_); \
            TI_FOREACH_PAIR(TI_ENUM_CLASS_PROPERTY_DEFINITION_ASSIGN_IVAR_ITER, , TI_ENUM_CASE_ARGS caseTuple_) \
            return obj_; \
        }; \
    }
#define TI_ENUM_CLASS_PROPERTY_DEFINITION_OBJECT(enum_, caseTuple_) \
    + (enum_ *)TI_ENUM_CASE_NAME caseTuple_ { \
        TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) *obj_ = [(id)[TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) alloc] init]; \
        obj_->_case = TI_ENUM_CASE_ENUM_CONSTANT(enum_, caseTuple_); \
        return obj_; \
    }
#define TI_ENUM_CLASS_PROPERTY_DEFINITION_ASSIGN_IVAR_ITER(idx_, argType_, argName_) \
    TI_CONCAT(obj_->_, argName_) = argName_;

#define TI_ENUM_SWITCH_DECLARATION(...) \
    - (void)TI_CONCAT(switch_, TI_FOREACH(TI_ENUM_SWITCH_DECLARATION_ITER, ,__VA_ARGS__))
#define TI_ENUM_SWITCH_DECLARATION_ITER(idx_, caseTuple_) \
    TI_ENUM_SWITCH_DECLARATION_ARGUMENT(caseTuple_)
#define TI_ENUM_SWITCH_DECLARATION_ARGUMENT(caseTuple_) \
    TI_ENUM_CASE_NAME caseTuple_:(void(^ NS_NOESCAPE)(TI_ENUM_BLOCK_ARGS caseTuple_))TI_ENUM_SWITCH_BLOCK_NAME(caseTuple_)
#define TI_ENUM_SWITCH_BLOCK_NAME(caseTuple_) \
    TI_CONCAT(TI_ENUM_CASE_NAME caseTuple_, Case)

#define TI_ENUM_SWITCH_DEFINITION(enum_, ...) \
    TI_ENUM_SWITCH_DECLARATION(__VA_ARGS__) { \
        switch (_case) { \
            TI_FOREACH_CXT(TI_ENUM_SWITCH_DEFINITION_CASE_ITER, , enum_, __VA_ARGS__) \
        } \
    }
#define TI_ENUM_SWITCH_DEFINITION_CASE_ITER(idx_, enum_, caseTuple_) \
    case TI_ENUM_CASE_ENUM_CONSTANT(enum_, caseTuple_): {\
        TI_ENUM_CASE_IF_NO_ARGS caseTuple_ \
            ()(TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) *obj_ = (TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) *)self;) \
        TI_ENUM_SWITCH_BLOCK_NAME(caseTuple_)(TI_ENUM_SWITCH_BLOCK_INVOCATION_ARGS caseTuple_); \
        break; \
    }
#define TI_ENUM_SWITCH_BLOCK_INVOCATION_ARGS(caseName_, ...) \
    TI_IF_EMPTY(__VA_ARGS__)()(TI_DROP(1, TI_FOREACH_PAIR(TI_ENUM_SWITCH_BLOCK_INVOCATION_ARG_ITER, ,__VA_ARGS__)))
#define TI_ENUM_SWITCH_BLOCK_INVOCATION_ARG_ITER(idx_, argType_, argName_) \
    , TI_CONCAT(obj_->_, argName_)

#define TI_ENUM_CASE_CLASS_IVARS(caseName_, ...) \
    TI_FOREACH_PAIR(TI_ENUM_CASE_CLASS_IVAR_ITER, ,__VA_ARGS__)
#define TI_ENUM_CASE_CLASS_IVAR_ITER(idx_, argType_, argName_) \
    argType_ TI_CONCAT(_, argName_);
#define TI_ENUM_CASE_CLASS_NAME(enum_, caseTuple_) \
    TI_CONCAT(enum_##_CaseClass_, TI_ENUM_CASE_NAME caseTuple_)

#define TI_ENUM_CASE_NAME(caseName_, ...) \
    caseName_
#define TI_ENUM_CASE_ARGS(caseName_, ...) \
    __VA_ARGS__
#define TI_ENUM_CASE_IF_NO_ARGS(caseName_, ...) \
    TI_IF_EMPTY(__VA_ARGS__)

#define TI_ENUM_BLOCK_ARGS(caseName_, ...) \
    TI_IF_EMPTY(__VA_ARGS__)(void)(TI_DROP(1, TI_FOREACH_PAIR(TI_ENUM_BLOCK_ARG_ITER, ,__VA_ARGS__)))
#define TI_ENUM_BLOCK_ARG_ITER(idx_, argType_, argName_) \
    , argType_ argName_
