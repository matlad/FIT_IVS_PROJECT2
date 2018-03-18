/**
 * @file     NumberTest.cpp
 * @encoding UTF-8
 * @date     6.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 * @brief    Test pro Number z matematické knihovny
 */

#include <cmath>
#include "../math/Number.h"
#include "../math/UndefinedExeption.h"
#include "gtest/gtest.h"

using team22::Math::Number
using std::numeric_limits<double>::infinity;

struct Params{
    Number number1;
    Number number2;
    Number expecting;
};

struct UnariParams{
    Number number;
    Number expecting;
};

struct Sub: testing::WithParamInterface<Params> {};
struct Add: testing::WithParamInterface<Params> {};
struct Mul: testing::WithParamInterface<Params> {};
struct Div: testing::WithParamInterface<Params> {};
struct Exp: testing::WithParamInterface<Params> {};
struct Root: testing::WithParamInterface<Params> {};
struct Mode: testing::WithParamInterface<Params> {};
struct Factorial: testing::WithParamInterface<UnariParams> {};


INSTANTIATE_TEST_CASE_P(def, Sub, testing::Values(
    Params{{ 0},{ 0},{  0}},

    Params{{-5},{-7},{  2}},
    Params{{ 5},{-7},{ 12}},
    Params{{-5},{ 7},{-12}},
    Params{{ 5},{ 7},{ -2}},

    Params{{ 5, 6},{ 7, 6},{ -2,  0}},
    Params{{ 5, 6},{ 7,-6},{ -2,  12}},
    Params{{ 5, 6},{-7, 6},{ 12,  0}},
    Params{{ 5, 6},{-7,-6},{ 12,  12}},
    Params{{ 5,-6},{ 7, 6},{ -2, -12}},
    Params{{ 5,-6},{ 7,-6},{ -2,   0}},
    Params{{ 5,-6},{-7, 6},{ 12, -12}},
    Params{{ 5,-6},{-7,-6},{ 12,   0}},
    Params{{-5, 6},{ 7, 6},{-12,   0}},
    Params{{-5, 6},{ 7,-6},{-12,  12}},
    Params{{-5, 6},{-7, 6},{  2,   0}},
    Params{{-5, 6},{-7,-6},{  2,  12}},
    Params{{-5,-6},{ 7, 6},{-12, -12}},
    Params{{-5,-6},{ 7,-6},{-12,   0}},
    Params{{-5,-6},{-7, 6},{  2, -12}},
    Params{{-5,-6},{-7,-6},{  2,   0}},

    Params{{-5.6,-6.8},{-7.6,-6.54},{  2,   0}},
    Params{{-5.354,-6.33},{-0.6354, -.65},{  2,   0}},
    Params{{-5.22,-6.22},{-.56,-6.52},{  2,   0}},

    Params{{infinity()}, {0}, {infinity()}},
    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}},
    Params{{std::numeric_limits<double>::infinity(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::infinity()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::infinity()}, {0}},
    Params{{0}, {std::numeric_limits<double>::infinity(), 5}, {0}},
    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}}
));

INSTANTIATE_TEST_CASE_P(def, Add, testing::Values(
    Params{{      0        }, {      0        }, {      0         }},

    Params{{     -5        }, {     -7        }, {    -12         }},
    Params{{      5        }, {     -7        }, {     -2         }},
    Params{{     -5        }, {      7        }, {      2         }},
    Params{{      5        }, {      7        }, {     12         }},

    Params{{      5,      6}, {      7,      6}, {     12,      12}},
    Params{{      5,      6}, {      7,     -6}, {     12,       0}},
    Params{{      5,      6}, {     -7,      6}, {     -2,      12}},
    Params{{      5,      6}, {     -7,     -6}, {     -2,       0}},
    Params{{      5,     -6}, {      7,      6}, {     12,       0}},
    Params{{      5,     -6}, {      7,     -6}, {     12,     -12}},
    Params{{      5,     -6}, {     -7,      6}, {     -2,       0}},
    Params{{      5,     -6}, {     -7,     -6}, {     -2,     -12}},
    Params{{     -5,      6}, {      7,      6}, {      2,      12}},
    Params{{     -5,      6}, {      7,     -6}, {      2,       0}},
    Params{{     -5,      6}, {     -7,      6}, {    -12,      12}},
    Params{{     -5,      6}, {     -7,     -6}, {    -12,       0}},
    Params{{     -5,     -6}, {      7,      6}, {      2,       0}},
    Params{{     -5,     -6}, {      7,     -6}, {      2,     -12}},
    Params{{     -5,     -6}, {     -7,      6}, {    -12,       0}},
    Params{{     -5,     -6}, {     -7,     -6}, {    -12,     -12}},
    Params{{   -5.6,   -6.8}, {   -7.6,  -6.54}, {  -13.2,  -13.34}},
    Params{{ -5.354,  -6.33}, { -0.634,  -0.65}, { -5.988,   -6.98}},
    Params{{  -5.22,  -6.22}, {  -0.56,  -6.52}, {  -5.78,  -12.74}}
));

INSTANTIATE_TEST_CASE_P(def, Mul, testing::Values(
    Params{{      0,      0}, {      0,      0}, {      0,       0}},

    Params{{     -5,      0}, {     -7,      0}, {     35,      -0}},
    Params{{      5,      0}, {     -7,      0}, {    -35,       0}},
    Params{{     -5,      0}, {      7,      0}, {    -35,       0}},
    Params{{      5,      0}, {      7,      0}, {     35,       0}},

    Params{{      5,      6}, {      7,      6}, {     -1,      72}},
    Params{{      5,      6}, {      7,     -6}, {     71,      12}},
    Params{{      5,      6}, {     -7,      6}, {    -71,     -12}},
    Params{{      5,      6}, {     -7,     -6}, {      1,     -72}},
    Params{{      5,     -6}, {      7,      6}, {     71,     -12}},
    Params{{      5,     -6}, {      7,     -6}, {     -1,     -72}},
    Params{{      5,     -6}, {     -7,      6}, {      1,      72}},
    Params{{      5,     -6}, {     -7,     -6}, {    -71,      12}},
    Params{{     -5,      6}, {      7,      6}, {    -71,      12}},
    Params{{     -5,      6}, {      7,     -6}, {      1,      72}},
    Params{{     -5,      6}, {     -7,      6}, {     -1,     -72}},
    Params{{     -5,      6}, {     -7,     -6}, {     71,     -12}},
    Params{{     -5,     -6}, {      7,      6}, {      1,     -72}},
    Params{{     -5,     -6}, {      7,     -6}, {    -71,     -12}},
    Params{{     -5,     -6}, {     -7,      6}, {     71,      12}},
    Params{{     -5,     -6}, {     -7,     -6}, {     -1,      72}},

    Params{{   -5.6,   -6.8}, {   -7.6,  -6.54}, { -1.912,  88.304}},
    Params{{ -5.354,  -6.33}, { -0.634,  -0.65}, { -0.720064,  7.49332}},
    Params{{  -5.22,  -6.22}, {  -0.56,  -6.52}, { -37.6312,  37.5176}}
));

INSTANTIATE_TEST_CASE_P(def, Div, testing::Values(
    Params{{     -5,      0}, {     -7,      0}, { 0.714286,      -0}},
    Params{{      5,      0}, {     -7,      0}, { -0.714286,      -0}},
    Params{{     -5,      0}, {      7,      0}, { -0.714286,       0}},
    Params{{      5,      0}, {      7,      0}, { 0.714286,       0}},
    Params{{      5,      6}, {      7,      6}, { 0.835294,  0.141176}},
    Params{{      5,      6}, {      7,     -6}, { -0.0117647,  0.847059}},
    Params{{      5,      6}, {     -7,      6}, { 0.0117647,  -0.847059}},
    Params{{      5,      6}, {     -7,     -6}, { -0.835294,  -0.141176}},
    Params{{      5,     -6}, {      7,      6}, { -0.0117647,  -0.847059}},
    Params{{      5,     -6}, {      7,     -6}, { 0.835294,  -0.141176}},
    Params{{      5,     -6}, {     -7,      6}, { -0.835294,  0.141176}},
    Params{{      5,     -6}, {     -7,     -6}, { 0.0117647,  0.847059}},
    Params{{     -5,      6}, {      7,      6}, { 0.0117647,  0.847059}},
    Params{{     -5,      6}, {      7,     -6}, { -0.835294,  0.141176}},
    Params{{     -5,      6}, {     -7,      6}, { 0.835294,  -0.141176}},
    Params{{     -5,      6}, {     -7,     -6}, { -0.0117647,  -0.847059}},
    Params{{     -5,     -6}, {      7,      6}, { -0.835294,  -0.141176}},
    Params{{     -5,     -6}, {      7,     -6}, { 0.0117647,  -0.847059}},
    Params{{     -5,     -6}, {     -7,      6}, { -0.0117647,  0.847059}},
    Params{{     -5,     -6}, {     -7,     -6}, { 0.835294,  0.141176}},
    Params{{   -5.6,   -6.8}, {   -7.6,  -6.54}, { 0.865718,  0.149764}},
    Params{{ -5.354,  -6.33}, { -0.634,  -0.65}, { 9.10775,  0.646632}},
    Params{{  -5.22,  -6.22}, {  -0.56,  -6.52}, { 1.01526,  -0.713413}}
));

INSTANTIATE_TEST_CASE_P(def, Exp, testing::Values(
    Params{{     -5,      0}, {     -7,      0}, { -1.28e-05,  -1.09728e-20}},
    Params{{      5,      0}, {     -7,      0}, { 1.28e-05,       0}},
    Params{{     -5,      0}, {      7,      0}, { -78125,  6.69729e-11}},
    Params{{      5,      0}, {      7,      0}, {  78125,       0}},
    Params{{      5,      6}, {      7,      6}, { 8568.79,  -3467.56}},
    Params{{      5,      6}, {      7,     -6}, { 3.38814e+08,  2.81761e+07}},
    Params{{      5,      6}, {     -7,      6}, { 2.9312e-09,  -2.43762e-10}},
    Params{{      5,      6}, {     -7,     -6}, { 0.000100281,  4.05808e-05}},
    Params{{      5,     -6}, {      7,      6}, { 3.38814e+08,  -2.81761e+07}},
    Params{{      5,     -6}, {      7,     -6}, { 8568.79,  3467.56}},
    Params{{      5,     -6}, {     -7,      6}, { 0.000100281,  -4.05808e-05}},
    Params{{      5,     -6}, {     -7,     -6}, { 2.9312e-09,  2.43762e-10}},
    Params{{     -5,      6}, {      7,      6}, { -2.20649,  0.183494}},
    Params{{     -5,      6}, {      7,     -6}, { -1.31576e+12,  -5.32453e+11}},
    Params{{     -5,      6}, {     -7,      6}, { -6.53069e-13,  2.64279e-13}},
    Params{{     -5,      6}, {     -7,     -6}, { -0.450095,  -0.0374303}},
    Params{{     -5,     -6}, {      7,      6}, { -1.31576e+12,  5.32453e+11}},
    Params{{     -5,     -6}, {      7,     -6}, { -2.20649,  -0.183494}},
    Params{{     -5,     -6}, {     -7,      6}, { -0.450095,  0.0374303}},
    Params{{     -5,     -6}, {     -7,     -6}, { -6.53069e-13,  -2.64279e-13}},
    Params{{   -5.6,   -6.8}, {   -7.6,  -6.54}, { -2.46468e-14,  4.92796e-15}},
    Params{{ -5.354,  -6.33}, { -0.634,  -0.65}, { 0.0595741,  0.00394717}},
    Params{{  -5.22,  -6.22}, {  -0.56,  -6.52}, { 1.14423e-07,  2.10415e-08}}
));

INSTANTIATE_TEST_CASE_P(def, Root, testing::Values(

    Params{{-5},{-7},{  2}},
    Params{{ 5},{-7},{ 12}},
    Params{{-5},{ 7},{-12}},
    Params{{ 5},{ 7},{ -2}},

    Params{{ 5, 6},{ 7, 6},{ 0,  0}},
    Params{{ 5, 6},{ 7,-6},{ -2,  12}},
    Params{{ 5, 6},{-7, 6},{ 12,  0}},
    Params{{ 5, 6},{-7,-6},{ 12,  12}},
    Params{{ 5,-6},{ 7, 6},{ -2, -12}},
    Params{{ 5,-6},{ 7,-6},{ -2,   0}},
    Params{{ 5,-6},{-7, 6},{ 12, -12}},
    Params{{ 5,-6},{-7,-6},{ 12,   0}},
    Params{{-5, 6},{ 7, 6},{-12,   0}},
    Params{{-5, 6},{ 7,-6},{-12,  12}},
    Params{{-5, 6},{-7, 6},{  2,   0}},
    Params{{-5, 6},{-7,-6},{  2,  12}},
    Params{{-5,-6},{ 7, 6},{-12, -12}},
    Params{{-5,-6},{ 7,-6},{-12,   0}},
    Params{{-5,-6},{-7, 6},{  2, -12}},
    Params{{-5,-6},{-7,-6},{  2,   0}},

    Params{{-5.6,-6.8},{-7.6,-6.54},{  2,   0}},
    Params{{-5.354,-6.33},{-0.6354, -.65},{  2,   0}},
    Params{{-5.22,-6.22},{-.56,-6.52},{  2,   0}}
));

INSTANTIATE_TEST_CASE_P(def, Mode, testing::Values(
    Params{{ 0},{ 0},{  0}},

    Params{{-5},{-7},{  2}},
    Params{{ 5},{-7},{ 12}},
    Params{{-5},{ 7},{-12}},
    Params{{ 5},{ 7},{ -2}},

    Params{{ 5, 6},{ 7, 6},{ -2,  0}},
    Params{{ 5, 6},{ 7,-6},{ -2,  12}},
    Params{{ 5, 6},{-7, 6},{ 12,  0}},
    Params{{ 5, 6},{-7,-6},{ 12,  12}},
    Params{{ 5,-6},{ 7, 6},{ -2, -12}},
    Params{{ 5,-6},{ 7,-6},{ -2,   0}},
    Params{{ 5,-6},{-7, 6},{ 12, -12}},
    Params{{ 5,-6},{-7,-6},{ 12,   0}},
    Params{{-5, 6},{ 7, 6},{-12,   0}},
    Params{{-5, 6},{ 7,-6},{-12,  12}},
    Params{{-5, 6},{-7, 6},{  2,   0}},
    Params{{-5, 6},{-7,-6},{  2,  12}},
    Params{{-5,-6},{ 7, 6},{-12, -12}},
    Params{{-5,-6},{ 7,-6},{-12,   0}},
    Params{{-5,-6},{-7, 6},{  2, -12}},
    Params{{-5,-6},{-7,-6},{  2,   0}},

    Params{{-5.6,-6.8},{-7.6,-6.54},{  2,   0}},
    Params{{-5.354,-6.33},{-0.6354, -.65},{  2,   0}},
    Params{{-5.22,-6.22},{-.56,-6.52},{  2,   0}}
));

INSTANTIATE_TEST_CASE_P(def, Factorial, testing::Values(
    UnariParams{{0},{1}},
    UnariParams{{5},{120}},
    UnariParams{{5.1},{142.451944065678}},
    UnariParams{{-5},{-120}},
    UnariParams{{5, -2},{4.0039686637632879, 0.30989965660362}},
    UnariParams{{5,  2},{5.9960313362367120, -0.30989965660362}},
    UnariParams{{-5,-2},{-5.9960313362367120, 0.30989965660362}},
    UnariParams{{-5, 2},{-4.0039686637632879, -0.30989965660362}},
    UnariParams{{std::numeric_limits<double>::infinity()}, {std::numeric_limits<double>::infinity()}},
//  UnariParams{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {?}},
    UnariParams{{5, std::numeric_limits<double>::infinity()}, {0}}
));


TEST_P(Add, oper){
    auto result = GetParam().number1 + GetParam().number2;
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Sub, oper){
    auto result = GetParam().number1 - GetParam().number2;
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Mul, oper){
    auto result = GetParam().number1 * GetParam().number2;
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Div, oper){
    auto result = GetParam().number1 / GetParam().number2;
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Exp, oper){
    auto result = GetParam().number1 ^ GetParam().number2;
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}


TEST_P(Mode, oper){
    auto result = GetParam().number1 % GetParam().number2;
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Factorial, oper){
    auto result = !GetParam().number;
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Add, fce){
    auto result = GetParam().number1.add(GetParam().number2);
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Sub, fce){
    auto result = GetParam().number1.sub(GetParam().number2);
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Mul, fce){
    auto result = GetParam().number1.mul(GetParam().number2);
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Div, fce){
    auto result = GetParam().number1.div(GetParam().number2);
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Exp, fce){
    auto result = GetParam().number1.pow(GetParam().number2);
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}


TEST_P(Mode, fce){
    auto result = GetParam().number1.mod(GetParam().number2);
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Root, fce){
    auto result = GetParam().number1.root(GetParam().number2);
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}

TEST_P(Factorial, fce){
    auto result = GetParam().number.fact();
    EXPECT_DOUBLE_EQ(GetParam().expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(GetParam().expecting.getImaginary(), result.getImaginary());

}


/***********************************************************************************************************************
 * Udefined
 **********************************************************************************************************************/

struct UndefSub: testing::WithParamInterface<Params> {};
struct UndefAdd: testing::WithParamInterface<Params> {};
struct UndefMul: testing::WithParamInterface<Params> {};
struct UndefDiv: testing::WithParamInterface<Params> {};
struct UndefExp: testing::WithParamInterface<Params> {};
struct UndefRoot: testing::WithParamInterface<Params> {};
struct UndefMode: testing::WithParamInterface<Params> {};
struct UndefFactorial: testing::WithParamInterface<UnariParams> {};

INSTANTIATE_TEST_CASE_P(divWithZero, UndefDiv, testing::Values(
    Params{{5}, {0}, {0}}
));

INSTANTIATE_TEST_CASE_P(divWithZero, UndefMode, testing::Values(
    Params{{5}, {0}, {0}}
));

INSTANTIATE_TEST_CASE_P(zero, UndefExp, testing::Values(
    Params{{0}, {0}, {0}}
));

INSTANTIATE_TEST_CASE_P(zero, UndefRoot, testing::Values(
    Params{{5}, {0}, {0}}
));



//
//INSTANTIATE_TEST_CASE_P(inf, UndefAdd, testing::Values(
//    Params{{std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), 5}, {0}, {0}},
//    Params{{5, std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {5, std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), 5}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}}
//
//));
//
//INSTANTIATE_TEST_CASE_P(inf, UndefMul, testing::Values(
//    Params{{std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), 5}, {0}, {0}},
//    Params{{5, std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {5, std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), 5}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}}
//
//));
//
//INSTANTIATE_TEST_CASE_P(inf, UndefExp, testing::Values(
//    Params{{std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), 5}, {0}, {0}},
//    Params{{5, std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {5, std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), 5}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}}
//
//));
//
//INSTANTIATE_TEST_CASE_P(inf, UndefRoot, testing::Values(
//    Params{{std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), 5}, {0}, {0}},
//    Params{{5, std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {5, std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), 5}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}}
//
//));
//
//INSTANTIATE_TEST_CASE_P(inf, UndefMode, testing::Values(
//    Params{{std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), 5}, {0}, {0}},
//    Params{{5, std::numeric_limits<double>::infinity()}, {0}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {5, std::numeric_limits<double>::infinity()}, {0}},
//    Params{{0}, {std::numeric_limits<double>::infinity(), 5}, {0}},
//    Params{{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()}, {0}}
//
//));


INSTANTIATE_TEST_CASE_P(quietNan, UndefSub, testing::Values(
    Params{{std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}}
));

INSTANTIATE_TEST_CASE_P(quietNan, UndefAdd, testing::Values(
    Params{{std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefMul, testing::Values(
    Params{{std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefExp, testing::Values(
    Params{{std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefRoot, testing::Values(
    Params{{std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefMode, testing::Values(
    Params{{std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::quiet_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::quiet_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::quiet_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefFactorial, testing::Values(
    UnariParams{{std::numeric_limits<double>::quiet_NaN()}, {0}},
    UnariParams{{std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()}, {0}},
    UnariParams{{5, std::numeric_limits<double>::quiet_NaN()}, {0}}
));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefSub, testing::Values(
    Params{{std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}}
));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefAdd, testing::Values(
    Params{{std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefMul, testing::Values(
    Params{{std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefExp, testing::Values(
    Params{{std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefRoot, testing::Values(
    Params{{std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefMode, testing::Values(
    Params{{std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), 5}, {0}, {0}},
    Params{{5, std::numeric_limits<double>::signaling_NaN()}, {0}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {5, std::numeric_limits<double>::signaling_NaN()}, {0}},
    Params{{0}, {std::numeric_limits<double>::signaling_NaN(), 5}, {0}},
    Params{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefFactorial, testing::Values(
    UnariParams{{std::numeric_limits<double>::signaling_NaN()}, {0}},
    UnariParams{{std::numeric_limits<double>::signaling_NaN(), std::numeric_limits<double>::signaling_NaN()}, {0}},
    UnariParams{{5, std::numeric_limits<double>::signaling_NaN()}, {0}}
));

TEST_P(UndefAdd, oper)
{
    EXPECT_THROW(GetParam().number1 + GetParam().number2, team22::Math::UndefinedException);
}

TEST_P(UndefSub, oper)
{
    EXPECT_THROW(GetParam().number1 - GetParam().number2, team22::Math::UndefinedException);
}

TEST_P(UndefMul, oper)
{
    EXPECT_THROW(GetParam().number1 * GetParam().number2, team22::Math::UndefinedException);
}

TEST_P(UndefDiv, oper)
{
    EXPECT_THROW(GetParam().number1 / GetParam().number2, team22::Math::UndefinedException);
}

TEST_P(UndefExp, oper)
{
    EXPECT_THROW(GetParam().number1 ^GetParam().number2, team22::Math::UndefinedException);
}

TEST_P(UndefMode, oper)
{
    EXPECT_THROW(GetParam().number1 % GetParam().number2, team22::Math::UndefinedException);
}

TEST_P(UndefFactorial, oper)
{
    EXPECT_THROW(!GetParam().number, team22::Math::UndefinedException);
}

TEST_P(UndefAdd, fce)
{
    EXPECT_THROW(GetParam().number1.add(GetParam().number2), team22::Math::UndefinedException);
}

TEST_P(UndefSub, fce)
{
    EXPECT_THROW(GetParam().number1.sub(GetParam().number2), team22::Math::UndefinedException);
}

TEST_P(UndefMul, fce)
{
    EXPECT_THROW(GetParam().number1.mul(GetParam().number2), team22::Math::UndefinedException);
}

TEST_P(UndefDiv, fce)
{
    EXPECT_THROW(GetParam().number1.div(GetParam().number2), team22::Math::UndefinedException);
}

TEST_P(UndefExp, fce)
{
    EXPECT_THROW(GetParam().number1.pow(GetParam().number2), team22::Math::UndefinedException);
}

TEST_P(UndefMode, fce)
{
    EXPECT_THROW(GetParam().number1.mod(GetParam().number2), team22::Math::UndefinedException);
}

TEST_P(UndefRoot, fce)
{
    EXPECT_THROW(GetParam().number1.root(GetParam().number2), team22::Math::UndefinedException);
}

TEST_P(UndefFactorial, fce)
{
    EXPECT_THROW(GetParam().number.fact(), team22::Math::UndefinedException);
}
