//
//  TIMetaMacro.h
//  TextInputKit-ObjC
//
//  Created by Artem Starosvetskiy on 27/08/2017.
//  Copyright © 2017 Artem Starosvetskiy. All rights reserved.
//

// TI_IF_EMPTY

#define TI_IF_EMPTY(...) \
    TI_IF_EQ(1, TI_ARGCOUNT(0, ##__VA_ARGS__))

// TI_CONCAT

#define TI_CONCAT(a_, b_) \
    TI_CONCAT_(a_, b_)

#define TI_CONCAT_(a_, b_) a_ ## b_

// TI_AT

#define TI_AT(N, ...) \
    TI_CONCAT(TI_AT, N)(__VA_ARGS__)

#define TI_AT0(...) TI_HEAD(__VA_ARGS__)
#define TI_AT1(_0, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT2(_0, _1, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT3(_0, _1, _2, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT4(_0, _1, _2, _3, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT5(_0, _1, _2, _3, _4, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT6(_0, _1, _2, _3, _4, _5, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT7(_0, _1, _2, _3, _4, _5, _6, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT8(_0, _1, _2, _3, _4, _5, _6, _7, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT9(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...) TI_HEAD(__VA_ARGS__)
#define TI_AT20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) TI_HEAD(__VA_ARGS__)

// TI_ARGCOUNT

#define TI_ARGCOUNT(...) \
    TI_AT(20, __VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

// TI_FOREACH

#define TI_FOREACH(macro_, sep_, ...) \
    TI_FOREACH_CXT(TI_FOREACH_iter, sep_, macro_, __VA_ARGS__)

#define TI_FOREACH_iter(INDEX, macro_, ARG) macro_(INDEX, ARG)

// TI_FOREACH_CXT

#define TI_FOREACH_CXT(macro_, sep_, context_, ...) \
    TI_CONCAT(TI_FOREACH_CXT, TI_ARGCOUNT(__VA_ARGS__))(macro_, sep_, context_, __VA_ARGS__)

#define TI_FOREACH_CXT0(macro_, sep_, CONTEXT)
#define TI_FOREACH_CXT1(macro_, sep_, context_, _0) macro_(0, context_, _0)

#define TI_FOREACH_CXT2(macro_, sep_, context_, _0, _1) \
    TI_FOREACH_CXT1(macro_, sep_, context_, _0) \
    sep_ \
    macro_(1, context_, _1)

#define TI_FOREACH_CXT3(macro_, sep_, context_, _0, _1, _2) \
    TI_FOREACH_CXT2(macro_, sep_, context_, _0, _1) \
    sep_ \
    macro_(2, context_, _2)

#define TI_FOREACH_CXT4(macro_, sep_, context_, _0, _1, _2, _3) \
    TI_FOREACH_CXT3(macro_, sep_, context_, _0, _1, _2) \
    sep_ \
    macro_(3, context_, _3)

#define TI_FOREACH_CXT5(macro_, sep_, context_, _0, _1, _2, _3, _4) \
    TI_FOREACH_CXT4(macro_, sep_, context_, _0, _1, _2, _3) \
    sep_ \
    macro_(4, context_, _4)

#define TI_FOREACH_CXT6(macro_, sep_, context_, _0, _1, _2, _3, _4, _5) \
    TI_FOREACH_CXT5(macro_, sep_, context_, _0, _1, _2, _3, _4) \
    sep_ \
    macro_(5, context_, _5)

#define TI_FOREACH_CXT7(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6) \
    TI_FOREACH_CXT6(macro_, sep_, context_, _0, _1, _2, _3, _4, _5) \
    sep_ \
    macro_(6, context_, _6)

#define TI_FOREACH_CXT8(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7) \
    TI_FOREACH_CXT7(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6) \
    sep_ \
    macro_(7, context_, _7)

#define TI_FOREACH_CXT9(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    TI_FOREACH_CXT8(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7) \
    sep_ \
    macro_(8, context_, _8)

#define TI_FOREACH_CXT10(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    TI_FOREACH_CXT9(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
    sep_ \
    macro_(9, context_, _9)

#define TI_FOREACH_CXT11(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    TI_FOREACH_CXT10(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    sep_ \
    macro_(10, context_, _10)

#define TI_FOREACH_CXT12(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    TI_FOREACH_CXT11(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    sep_ \
    macro_(11, context_, _11)

#define TI_FOREACH_CXT13(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    TI_FOREACH_CXT12(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    sep_ \
    macro_(12, context_, _12)

#define TI_FOREACH_CXT14(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    TI_FOREACH_CXT13(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    sep_ \
    macro_(13, context_, _13)

#define TI_FOREACH_CXT15(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    TI_FOREACH_CXT14(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    sep_ \
    macro_(14, context_, _14)

#define TI_FOREACH_CXT16(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    TI_FOREACH_CXT15(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
    sep_ \
    macro_(15, context_, _15)

#define TI_FOREACH_CXT17(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    TI_FOREACH_CXT16(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    sep_ \
    macro_(16, context_, _16)

#define TI_FOREACH_CXT18(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    TI_FOREACH_CXT17(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
    sep_ \
    macro_(17, context_, _17)

#define TI_FOREACH_CXT19(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    TI_FOREACH_CXT18(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    sep_ \
    macro_(18, context_, _18)

#define TI_FOREACH_CXT20(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
    TI_FOREACH_CXT19(macro_, sep_, context_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
    sep_ \
    macro_(19, context_, _19)

// TI_HEAD

#define TI_HEAD(...) \
    TI_HEAD_(__VA_ARGS__, 0)

#define TI_HEAD_(first_, ...) first_

// TI_TAIL

#define TI_TAIL_(first_, ...) __VA_ARGS__

#define TI_TAIL(...) \
    TI_TAIL_(__VA_ARGS__)

// TI_DROP

#define TI_DROP(n_, ...) \
    TI_CONCAT(TI_DROP, n_)(__VA_ARGS__)

#define TI_DROP0(...) __VA_ARGS__
#define TI_DROP1(...) TI_TAIL(__VA_ARGS__)
#define TI_DROP2(...) TI_DROP1(TI_TAIL(__VA_ARGS__))
#define TI_DROP3(...) TI_DROP2(TI_TAIL(__VA_ARGS__))
#define TI_DROP4(...) TI_DROP3(TI_TAIL(__VA_ARGS__))
#define TI_DROP5(...) TI_DROP4(TI_TAIL(__VA_ARGS__))
#define TI_DROP6(...) TI_DROP5(TI_TAIL(__VA_ARGS__))
#define TI_DROP7(...) TI_DROP6(TI_TAIL(__VA_ARGS__))
#define TI_DROP8(...) TI_DROP7(TI_TAIL(__VA_ARGS__))
#define TI_DROP9(...) TI_DROP8(TI_TAIL(__VA_ARGS__))
#define TI_DROP10(...) TI_DROP9(TI_TAIL(__VA_ARGS__))
#define TI_DROP11(...) TI_DROP10(TI_TAIL(__VA_ARGS__))
#define TI_DROP12(...) TI_DROP11(TI_TAIL(__VA_ARGS__))
#define TI_DROP13(...) TI_DROP12(TI_TAIL(__VA_ARGS__))
#define TI_DROP14(...) TI_DROP13(TI_TAIL(__VA_ARGS__))
#define TI_DROP15(...) TI_DROP14(TI_TAIL(__VA_ARGS__))
#define TI_DROP16(...) TI_DROP15(TI_TAIL(__VA_ARGS__))
#define TI_DROP17(...) TI_DROP16(TI_TAIL(__VA_ARGS__))
#define TI_DROP18(...) TI_DROP17(TI_TAIL(__VA_ARGS__))
#define TI_DROP19(...) TI_DROP18(TI_TAIL(__VA_ARGS__))
#define TI_DROP20(...) TI_DROP19(TI_TAIL(__VA_ARGS__))

// TI_DEC

#define TI_DEC(value_) \
    TI_AT(value_, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19)

#define TI_CONSUME_(...)
#define TI_EXPAND_(...) __VA_ARGS__

// TI_IF_EQ

#define TI_IF_EQ(a_, b_) \
    TI_CONCAT(TI_IF_EQ, a_)(b_)

#define TI_IF_EQ0(value_) \
    TI_CONCAT(TI_IF_EQ0_, value_)

#define TI_IF_EQ0_0(...) __VA_ARGS__ TI_CONSUME_
#define TI_IF_EQ0_1(...) TI_EXPAND_
#define TI_IF_EQ0_2(...) TI_EXPAND_
#define TI_IF_EQ0_3(...) TI_EXPAND_
#define TI_IF_EQ0_4(...) TI_EXPAND_
#define TI_IF_EQ0_5(...) TI_EXPAND_
#define TI_IF_EQ0_6(...) TI_EXPAND_
#define TI_IF_EQ0_7(...) TI_EXPAND_
#define TI_IF_EQ0_8(...) TI_EXPAND_
#define TI_IF_EQ0_9(...) TI_EXPAND_
#define TI_IF_EQ0_10(...) TI_EXPAND_
#define TI_IF_EQ0_11(...) TI_EXPAND_
#define TI_IF_EQ0_12(...) TI_EXPAND_
#define TI_IF_EQ0_13(...) TI_EXPAND_
#define TI_IF_EQ0_14(...) TI_EXPAND_
#define TI_IF_EQ0_15(...) TI_EXPAND_
#define TI_IF_EQ0_16(...) TI_EXPAND_
#define TI_IF_EQ0_17(...) TI_EXPAND_
#define TI_IF_EQ0_18(...) TI_EXPAND_
#define TI_IF_EQ0_19(...) TI_EXPAND_
#define TI_IF_EQ0_20(...) TI_EXPAND_

#define TI_IF_EQ1(VALUE) TI_IF_EQ0(TI_DEC(VALUE))
#define TI_IF_EQ2(VALUE) TI_IF_EQ1(TI_DEC(VALUE))
#define TI_IF_EQ3(VALUE) TI_IF_EQ2(TI_DEC(VALUE))
#define TI_IF_EQ4(VALUE) TI_IF_EQ3(TI_DEC(VALUE))
#define TI_IF_EQ5(VALUE) TI_IF_EQ4(TI_DEC(VALUE))
#define TI_IF_EQ6(VALUE) TI_IF_EQ5(TI_DEC(VALUE))
#define TI_IF_EQ7(VALUE) TI_IF_EQ6(TI_DEC(VALUE))
#define TI_IF_EQ8(VALUE) TI_IF_EQ7(TI_DEC(VALUE))
#define TI_IF_EQ9(VALUE) TI_IF_EQ8(TI_DEC(VALUE))
#define TI_IF_EQ10(VALUE) TI_IF_EQ9(TI_DEC(VALUE))
#define TI_IF_EQ11(VALUE) TI_IF_EQ10(TI_DEC(VALUE))
#define TI_IF_EQ12(VALUE) TI_IF_EQ11(TI_DEC(VALUE))
#define TI_IF_EQ13(VALUE) TI_IF_EQ12(TI_DEC(VALUE))
#define TI_IF_EQ14(VALUE) TI_IF_EQ13(TI_DEC(VALUE))
#define TI_IF_EQ15(VALUE) TI_IF_EQ14(TI_DEC(VALUE))
#define TI_IF_EQ16(VALUE) TI_IF_EQ15(TI_DEC(VALUE))
#define TI_IF_EQ17(VALUE) TI_IF_EQ16(TI_DEC(VALUE))
#define TI_IF_EQ18(VALUE) TI_IF_EQ17(TI_DEC(VALUE))
#define TI_IF_EQ19(VALUE) TI_IF_EQ18(TI_DEC(VALUE))
#define TI_IF_EQ20(VALUE) TI_IF_EQ19(TI_DEC(VALUE))

// TI_FOREACH_PAIR

#define TI_FOREACH_PAIR(macro_, sep_, ...) \
    TI_IF_EMPTY(__VA_ARGS__)()(TI_CONCAT(TI_FOREACH_PAIR, TI_ARGCOUNT(__VA_ARGS__))(macro_, sep_, __VA_ARGS__))

#define TI_FOREACH_PAIR2(macro_, sep_, _0, _1) macro_(0, _0, _1)

#define TI_FOREACH_PAIR4(macro_, sep_, _0, _1, _2, _3) \
    TI_FOREACH_PAIR2(macro_, sep_, _0, _1) \
    sep_ \
    macro_(1, _2, _3)

#define TI_FOREACH_PAIR6(macro_, sep_, _0, _1, _2, _3, _4, _5) \
    TI_FOREACH_PAIR4(macro_, sep_, _0, _1, _2, _3) \
    sep_ \
    macro_(2, _4, _5)

#define TI_FOREACH_PAIR8(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7) \
    TI_FOREACH_PAIR6(macro_, sep_, _0, _1, _2, _3, _4, _5) \
    sep_ \
    macro_(3, _6, _7)

#define TI_FOREACH_PAIR10(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    TI_FOREACH_PAIR8(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7) \
    sep_ \
    macro_(4, _8, _9)

#define TI_FOREACH_PAIR12(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    TI_FOREACH_PAIR10(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
    sep_ \
    macro_(5, _10, _11)

#define TI_FOREACH_PAIR14(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    TI_FOREACH_PAIR12(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
    sep_ \
    macro_(6, _12, _13)

#define TI_FOREACH_PAIR16(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    TI_FOREACH_PAIR14(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
    sep_ \
    macro_(7, _14, _15)

#define TI_FOREACH_PAIR18(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    TI_FOREACH_PAIR16(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
    sep_ \
    macro_(8, _16, _17)

#define TI_FOREACH_PAIR20(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
    TI_FOREACH_PAIR18(macro_, sep_, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    sep_ \
    macro_(9, _18, _19)
