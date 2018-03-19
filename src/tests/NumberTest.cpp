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
#include <limits>
#include <stack>
#include <ostream>

using team22::Math::Number;
using team22::Math::UndefinedException;

#define inf  std::numeric_limits<double>::infinity()

#define qNaN  std::numeric_limits<double>::quiet_NaN()

#define nan  std::numeric_limits<double>::quiet_NaN()

#define sNaN  std::numeric_limits<double>::signaling_NaN()

struct Params{
    Number number1;
    Number number2;
    Number expecting;

    friend std::ostream &operator<<(std::ostream &os, const Params &params)
    {
        os << "number1: " << params.number1 << " number2: " << params.number2 << " expecting: " << params.expecting;
        return os;
    }
};

struct UnariParams{
    Number number;
    Number expecting;
    friend std::ostream &operator<<(std::ostream &os, const UnariParams &params)
    {
        os << "number: " << params.number << " expecting: " << params.expecting;
        return os;
    }
};
struct ParamTest : testing::Test, testing::WithParamInterface<Params>{
    Params p{0,0,0};
    ParamTest()
    {p = GetParam();}
};

struct UParamTest : testing::Test, testing::WithParamInterface<UnariParams>{
    UnariParams p{0,0};
    UParamTest()
    {p = GetParam(); }
};
struct Sub: ParamTest {};
struct Add: ParamTest {};
struct Mul: ParamTest {};
struct Div: ParamTest {};
struct Exp: ParamTest {};
struct Root: ParamTest{};
struct Mode: ParamTest {};
struct Factorial: UParamTest {};


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
    Params{{-5.22,-6.22},{-.56,-6.52},{  2,   0}}));

INSTANTIATE_TEST_CASE_P(Inf, Sub, testing::Values(
    Params{{    inf,      0}, {      0,      0}, {    inf,       0}},
    Params{{    inf,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{    inf,      5}, {      0,      0}, {    inf,       5}},
    Params{{      5,    inf}, {      0,      0}, {      5,     inf}},
    Params{{      0,      0}, {    inf,    inf}, {   -inf,    -inf}},
    Params{{      0,      0}, {      5,    inf}, {     -5,    -inf}},
    Params{{      0,      0}, {    inf,      5}, {   -inf,      -5}},
    Params{{   -inf,      0}, {      0,      0}, {   -inf,       0}},
    Params{{   -inf,   -inf}, {      0,      0}, {   -inf,    -inf}},
    Params{{   -inf,      5}, {      0,      0}, {   -inf,       5}},
    Params{{      5,   -inf}, {      0,      0}, {      5,    -inf}},
    Params{{      0,      0}, {   -inf,   -inf}, {    inf,     inf}},
    Params{{      0,      0}, {      5,   -inf}, {     -5,     inf}},
    Params{{      0,      0}, {   -inf,      5}, {    inf,      -5}},
    Params{{    inf,    inf}, {   -inf,   -inf}, {    inf,     inf}},
    Params{{    inf,   -inf}, {   -inf,    inf}, {    inf,    -inf}},
    Params{{   -inf,    inf}, {    inf,   -inf}, {   -inf,     inf}},
    Params{{   -inf,   -inf}, {    inf,    inf}, {   -inf,    -inf}}
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

INSTANTIATE_TEST_CASE_P(Inf, Add, testing::Values(
    Params{{    inf,      0}, {      0,      0}, {    inf,       0}},
    Params{{    inf,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{    inf,      5}, {      0,      0}, {    inf,       5}},
    Params{{      5,    inf}, {      0,      0}, {      5,     inf}},
    Params{{      0,      0}, {    inf,    inf}, {    inf,     inf}},
    Params{{      0,      0}, {      5,    inf}, {      5,     inf}},
    Params{{      0,      0}, {    inf,      5}, {    inf,       5}},
    Params{{    inf,    inf}, {    inf,    inf}, {    inf,     inf}},
    Params{{   -inf,      0}, {      0,      0}, {   -inf,       0}},
    Params{{   -inf,   -inf}, {      0,      0}, {   -inf,    -inf}},
    Params{{   -inf,      5}, {      0,      0}, {   -inf,       5}},
    Params{{      5,   -inf}, {      0,      0}, {      5,    -inf}},
    Params{{      0,      0}, {   -inf,   -inf}, {   -inf,    -inf}},
    Params{{      0,      0}, {      5,   -inf}, {      5,    -inf}},
    Params{{      0,      0}, {   -inf,      5}, {   -inf,       5}},
    Params{{    inf,    inf}, {    inf,    inf}, {    inf,     inf}},
    Params{{    inf,   -inf}, {    inf,   -inf}, {    inf,    -inf}},
    Params{{   -inf,    inf}, {   -inf,    inf}, {   -inf,     inf}},
    Params{{   -inf,   -inf}, {   -inf,   -inf}, {   -inf,    -inf}}
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

INSTANTIATE_TEST_CASE_P(Inf, Mul, testing::Values(
    Params{{    inf,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{    inf,      5}, {      0,      0}, {    inf,     inf}},
    Params{{      5,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{      0,      0}, {    inf,    inf}, {      0,       0}},
    Params{{      0,      0}, {      5,    inf}, {      0,       0}},
    Params{{      0,      0}, {    inf,      5}, {      0,       0}},
    Params{{   -inf,   -inf}, {      0,      0}, {   -inf,    -inf}},
    Params{{   -inf,      5}, {      0,      0}, {   -inf,     inf}},
    Params{{      5,   -inf}, {      0,      0}, {    inf,    -inf}},
    Params{{      0,      0}, {   -inf,   -inf}, {     -0,       0}},
    Params{{      0,      0}, {      5,   -inf}, {     -0,       0}},
    Params{{      0,      0}, {   -inf,      5}, {     -0,      -0}}
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

INSTANTIATE_TEST_CASE_P(Inf, Exp, testing::Values(
    Params{{   -inf,   -inf}, {   -inf,   -inf}, {      0,      -0}},
    Params{{      0,      0}, {    inf,    inf}, {      0,      -0}},
    Params{{      0,      0}, {    inf,      5}, {      0,      -0}},
    Params{{    inf,    inf}, {   -inf,    inf}, {      0,      -0}},
    Params{{    inf,   -inf}, {   -inf,   -inf}, {      0,      -0}},
    Params{{   -inf,    inf}, {   -inf,    inf}, {      0,      -0}}
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

INSTANTIATE_TEST_CASE_P(Inf, Mode, testing::Values(
    Params{{    inf,      5}, {      0,      0}, {    inf,     inf}},
    Params{{      5,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{      0,      0}, {    inf,    inf}, {      0,       0}},
    Params{{      0,      0}, {      5,    inf}, {      0,       0}},
    Params{{      0,      0}, {    inf,      5}, {      0,       0}},
    Params{{   -inf,   -inf}, {      0,      0}, {   -inf,    -inf}},
    Params{{   -inf,      5}, {      0,      0}, {   -inf,     inf}},
    Params{{      5,   -inf}, {      0,      0}, {    inf,    -inf}},
    Params{{      0,      0}, {   -inf,   -inf}, {     -0,       0}},
    Params{{      0,      0}, {      5,   -inf}, {     -0,       0}},
    Params{{      0,      0}, {   -inf,      5}, {     -0,      -0}}
));



INSTANTIATE_TEST_CASE_P(def, Factorial, testing::Values(
    UnariParams{{0},{1}},
    UnariParams{{5},{120}},
    UnariParams{{5.1},{142.451944065678}},
    UnariParams{{-5},{-120}},
    UnariParams{{5, -2},{4.0039686637632879, 0.30989965660362}},
    UnariParams{{5,  2},{5.9960313362367120, -0.30989965660362}},
    UnariParams{{-5,-2},{-5.9960313362367120, 0.30989965660362}},
    UnariParams{{-5, 2},{-4.0039686637632879, -0.30989965660362}}
));

INSTANTIATE_TEST_CASE_P(inf, Factorial, testing::Values(
    UnariParams{{inf}, {inf}},
    UnariParams{{5, inf}, {0}}
));


TEST_P(Add, oper){
    auto result = p.number1 + p.number2;
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Sub, oper){
    auto result = p.number1 - p.number2;
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Mul, oper){
    auto result = p.number1 * p.number2;
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Div, oper){
    auto result = p.number1 / p.number2;
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Exp, oper){
    auto result = p.number1 ^ p.number2;
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}


TEST_P(Mode, oper){
  
    auto result = p.number1 % p.number2;
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Factorial, oper){
    auto result = !p.number;
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Add, fce){
    auto result = p.number1.add(p.number2);
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Sub, fce){
    auto result = p.number1.sub(p.number2);
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Mul, fce){
    auto result = p.number1.mul(p.number2);
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Div, fce){
    auto result = p.number1.div(p.number2);
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Exp, fce){
  
    auto result = p.number1.pow(p.number2);
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}


TEST_P(Mode, fce){
  
    auto result = p.number1.mod(p.number2);
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Root, fce){
  
    auto result = p.number1.root(p.number2);
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}

TEST_P(Factorial, fce){
    auto result = p.number.fact();
    EXPECT_DOUBLE_EQ(p.expecting.getReal(), result.getReal());
    EXPECT_DOUBLE_EQ(p.expecting.getImaginary(), result.getImaginary());

}


/***********************************************************************************************************************
 * Udefined
 **********************************************************************************************************************/

struct UndefSub: ParamTest {};
struct UndefAdd: ParamTest {};
struct UndefMul: ParamTest {};
struct UndefDiv: ParamTest {};
struct UndefExp: ParamTest {};
struct UndefRoot: ParamTest {};
struct UndefMode: ParamTest {};
struct UndefFactorial: UParamTest {};

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




INSTANTIATE_TEST_CASE_P(Inf, UndefSub, testing::Values(
    Params{{   -inf,   -inf}, {    inf,   -inf}, {   -inf,    -nan}},
    Params{{   -inf,   -inf}, {   -inf,    inf}, {   -nan,    -inf}},
    Params{{   -inf,   -inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {    inf,   -inf}, {   -nan,     inf}},
    Params{{    inf,    inf}, {   -inf,    inf}, {    inf,    -nan}},
    Params{{    inf,   -inf}, {    inf,    inf}, {   -nan,    -inf}},
    Params{{    inf,   -inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {   -inf,   -inf}, {    inf,    -nan}},
    Params{{   -inf,    inf}, {    inf,    inf}, {   -inf,    -nan}},
    Params{{   -inf,    inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {   -inf,   -inf}, {   -nan,     inf}}
));

INSTANTIATE_TEST_CASE_P(Inf, UndefAdd, testing::Values(
    Params{{    inf,    inf}, {    inf,   -inf}, {    inf,    -nan}},
    Params{{    inf,    inf}, {   -inf,    inf}, {   -nan,     inf}},
    Params{{    inf,    inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {    inf,    inf}, {    inf,    -nan}},
    Params{{    inf,   -inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {   -inf,   -inf}, {   -nan,    -inf}},
    Params{{   -inf,    inf}, {    inf,    inf}, {   -nan,     inf}},
    Params{{   -inf,    inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {   -inf,   -inf}, {   -inf,    -nan}},
    Params{{   -inf,   -inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {    inf,   -inf}, {   -nan,    -inf}},
    Params{{   -inf,   -inf}, {   -inf,    inf}, {   -inf,    -nan}}
));

INSTANTIATE_TEST_CASE_P(Inf, UndefMul, testing::Values(
    Params{{    inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,      0}, {      0,      0}, {    inf,    -nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,      0}, {      0,      0}, {   -inf,    -nan}}
));

INSTANTIATE_TEST_CASE_P(Inf, UndefDiv, testing::Values(
    Params{{    inf,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{    inf,      5}, {      0,      0}, {    inf,     inf}},
    Params{{      5,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{      0,      0}, {    inf,    inf}, {      0,       0}},
    Params{{      0,      0}, {      5,    inf}, {      0,       0}},
    Params{{      0,      0}, {    inf,      5}, {      0,       0}},
    Params{{   -inf,   -inf}, {      0,      0}, {   -inf,    -inf}},
    Params{{   -inf,      5}, {      0,      0}, {   -inf,     inf}},
    Params{{      5,   -inf}, {      0,      0}, {    inf,    -inf}},
    Params{{      0,      0}, {   -inf,   -inf}, {     -0,       0}},
    Params{{      0,      0}, {      5,   -inf}, {     -0,       0}},
    Params{{      0,      0}, {   -inf,      5}, {     -0,      -0}},
    Params{{    inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,      0}, {      0,      0}, {    inf,    -nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,      0}, {      0,      0}, {   -inf,    -nan}}
));


INSTANTIATE_TEST_CASE_P(Inf, UndefExp, testing::Values(
    Params{{    inf,      0}, {      0,      0}, {    nan,     nan}},
    Params{{    inf,    inf}, {      0,      0}, {    nan,     nan}},
    Params{{    inf,      5}, {      0,      0}, {    nan,     nan}},
    Params{{      5,    inf}, {      0,      0}, {    nan,     nan}},
    Params{{      0,      0}, {      5,    inf}, {    nan,     nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {    nan,     nan}},
    Params{{   -inf,      0}, {      0,      0}, {    nan,     nan}},
    Params{{   -inf,   -inf}, {      0,      0}, {    nan,     nan}},
    Params{{   -inf,      5}, {      0,      0}, {    nan,     nan}},
    Params{{      5,   -inf}, {      0,      0}, {    nan,     nan}},
    Params{{      0,      0}, {   -inf,   -inf}, {    inf,     nan}},
    Params{{      0,      0}, {      5,   -inf}, {    nan,     nan}},
    Params{{      0,      0}, {   -inf,      5}, {    inf,     nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {    nan,     nan}},
    Params{{    inf,    inf}, {    inf,   -inf}, {    inf,     nan}},
    Params{{    inf,    inf}, {   -inf,   -inf}, {    nan,     nan}},
    Params{{    inf,   -inf}, {    inf,    inf}, {    inf,     nan}},
    Params{{    inf,   -inf}, {    inf,   -inf}, {    nan,     nan}},
    Params{{    inf,   -inf}, {   -inf,    inf}, {    nan,     nan}},
    Params{{   -inf,    inf}, {    inf,    inf}, {    nan,     nan}},
    Params{{   -inf,    inf}, {    inf,   -inf}, {    inf,     nan}},
    Params{{   -inf,    inf}, {   -inf,   -inf}, {    nan,     nan}},
    Params{{   -inf,   -inf}, {    inf,    inf}, {    inf,     nan}},
    Params{{   -inf,   -inf}, {    inf,   -inf}, {    nan,     nan}},
    Params{{   -inf,   -inf}, {   -inf,    inf}, {    nan,     nan}}
));

INSTANTIATE_TEST_CASE_P(Inf, UndefRoot, testing::Values(
    Params{{    inf,      0}, {      0,      0}, {    inf,     nan}},
    Params{{    inf,    inf}, {      0,      0}, {    inf,     nan}},
    Params{{    inf,      5}, {      0,      0}, {    inf,     nan}},
    Params{{      5,    inf}, {      0,      0}, {    inf,     nan}},
    Params{{      0,      0}, {    inf,    inf}, {    nan,     nan}},
    Params{{      0,      0}, {      5,    inf}, {    nan,     nan}},
    Params{{      0,      0}, {    inf,      5}, {    nan,     nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {    nan,     nan}},
    Params{{   -inf,      0}, {      0,      0}, {    inf,     nan}},
    Params{{   -inf,   -inf}, {      0,      0}, {    inf,     nan}},
    Params{{   -inf,      5}, {      0,      0}, {    inf,     nan}},
    Params{{      5,   -inf}, {      0,      0}, {    inf,     nan}},
    Params{{      0,      0}, {   -inf,   -inf}, {    nan,     nan}},
    Params{{      0,      0}, {      5,   -inf}, {    nan,     nan}},
    Params{{      0,      0}, {   -inf,      5}, {    nan,     nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {    nan,     nan}},
    Params{{    inf,    inf}, {    inf,   -inf}, {    nan,     nan}},
    Params{{    inf,    inf}, {   -inf,    inf}, {    nan,     nan}},
    Params{{    inf,    inf}, {   -inf,   -inf}, {    nan,     nan}},
    Params{{    inf,   -inf}, {    inf,    inf}, {    nan,     nan}},
    Params{{    inf,   -inf}, {    inf,   -inf}, {    nan,     nan}},
    Params{{    inf,   -inf}, {   -inf,    inf}, {    nan,     nan}},
    Params{{    inf,   -inf}, {   -inf,   -inf}, {    nan,     nan}},
    Params{{   -inf,    inf}, {    inf,    inf}, {    nan,     nan}},
    Params{{   -inf,    inf}, {    inf,   -inf}, {    nan,     nan}},
    Params{{   -inf,    inf}, {   -inf,    inf}, {    nan,     nan}},
    Params{{   -inf,    inf}, {   -inf,   -inf}, {    nan,     nan}},
    Params{{   -inf,   -inf}, {    inf,    inf}, {    nan,     nan}},
    Params{{   -inf,   -inf}, {    inf,   -inf}, {    nan,     nan}},
    Params{{   -inf,   -inf}, {   -inf,    inf}, {    nan,     nan}},
    Params{{   -inf,   -inf}, {   -inf,   -inf}, {    nan,     nan}}
));

INSTANTIATE_TEST_CASE_P(Inf, UndefMode, testing::Values(
    Params{{    inf,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{    inf,      5}, {      0,      0}, {    inf,     inf}},
    Params{{      5,    inf}, {      0,      0}, {    inf,     inf}},
    Params{{      0,      0}, {    inf,    inf}, {      0,       0}},
    Params{{      0,      0}, {      5,    inf}, {      0,       0}},
    Params{{      0,      0}, {    inf,      5}, {      0,       0}},
    Params{{   -inf,   -inf}, {      0,      0}, {   -inf,    -inf}},
    Params{{   -inf,      5}, {      0,      0}, {   -inf,     inf}},
    Params{{      5,   -inf}, {      0,      0}, {    inf,    -inf}},
    Params{{      0,      0}, {   -inf,   -inf}, {     -0,       0}},
    Params{{      0,      0}, {      5,   -inf}, {     -0,       0}},
    Params{{      0,      0}, {   -inf,      5}, {     -0,      -0}},
    Params{{    inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,    inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{    inf,   -inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,    inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {    inf,   -inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {   -inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,   -inf}, {   -inf,   -inf}, {   -nan,    -nan}},
    Params{{    inf,      0}, {      0,      0}, {    inf,    -nan}},
    Params{{    inf,    inf}, {    inf,    inf}, {   -nan,    -nan}},
    Params{{   -inf,      0}, {      0,      0}, {   -inf,    -nan}}
));


INSTANTIATE_TEST_CASE_P(Inf, UndefFactorial, testing::Values(
  UnariParams{{inf, inf}, {0}}
));


INSTANTIATE_TEST_CASE_P(quietNan, UndefSub, testing::Values(
    Params{{qNaN}, {0}, {0}},
    Params{{qNaN, qNaN}, {0}, {0}},
    Params{{qNaN, 5}, {0}, {0}},
    Params{{5, qNaN}, {0}, {0}},
    Params{{0}, {qNaN, qNaN}, {0}},
    Params{{0}, {5, qNaN}, {0}},
    Params{{0}, {qNaN, 5}, {0}},
    Params{{qNaN, qNaN}, {qNaN, qNaN}, {0}}
));

INSTANTIATE_TEST_CASE_P(quietNan, UndefAdd, testing::Values(
    Params{{qNaN}, {0}, {0}},
    Params{{qNaN, qNaN}, {0}, {0}},
    Params{{qNaN, 5}, {0}, {0}},
    Params{{5, qNaN}, {0}, {0}},
    Params{{0}, {qNaN, qNaN}, {0}},
    Params{{0}, {5, qNaN}, {0}},
    Params{{0}, {qNaN, 5}, {0}},
    Params{{qNaN, qNaN}, {qNaN, qNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefMul, testing::Values(
    Params{{qNaN}, {0}, {0}},
    Params{{qNaN, qNaN}, {0}, {0}},
    Params{{qNaN, 5}, {0}, {0}},
    Params{{5, qNaN}, {0}, {0}},
    Params{{0}, {qNaN, qNaN}, {0}},
    Params{{0}, {5, qNaN}, {0}},
    Params{{0}, {qNaN, 5}, {0}},
    Params{{qNaN, qNaN}, {qNaN, qNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefExp, testing::Values(
    Params{{qNaN}, {0}, {0}},
    Params{{qNaN, qNaN}, {0}, {0}},
    Params{{qNaN, 5}, {0}, {0}},
    Params{{5, qNaN}, {0}, {0}},
    Params{{0}, {qNaN, qNaN}, {0}},
    Params{{0}, {5, qNaN}, {0}},
    Params{{0}, {qNaN, 5}, {0}},
    Params{{qNaN, qNaN}, {qNaN, qNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefRoot, testing::Values(
    Params{{qNaN}, {0}, {0}},
    Params{{qNaN, qNaN}, {0}, {0}},
    Params{{qNaN, 5}, {0}, {0}},
    Params{{5, qNaN}, {0}, {0}},
    Params{{0}, {qNaN, qNaN}, {0}},
    Params{{0}, {5, qNaN}, {0}},
    Params{{0}, {qNaN, 5}, {0}},
    Params{{qNaN, qNaN}, {qNaN, qNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefMode, testing::Values(
    Params{{qNaN}, {0}, {0}},
    Params{{qNaN, qNaN}, {0}, {0}},
    Params{{qNaN, 5}, {0}, {0}},
    Params{{5, qNaN}, {0}, {0}},
    Params{{0}, {qNaN, qNaN}, {0}},
    Params{{0}, {5, qNaN}, {0}},
    Params{{0}, {qNaN, 5}, {0}},
    Params{{qNaN, qNaN}, {qNaN, qNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(quietNan, UndefFactorial, testing::Values(
    UnariParams{{qNaN}, {0}},
    UnariParams{{qNaN, qNaN}, {0}},
    UnariParams{{5, qNaN}, {0}}
));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefSub, testing::Values(
    Params{{sNaN}, {0}, {0}},
    Params{{sNaN, sNaN}, {0}, {0}},
    Params{{sNaN, 5}, {0}, {0}},
    Params{{5, sNaN}, {0}, {0}},
    Params{{0}, {sNaN, sNaN}, {0}},
    Params{{0}, {5, sNaN}, {0}},
    Params{{0}, {sNaN, 5}, {0}},
    Params{{sNaN, sNaN}, {sNaN, sNaN}, {0}}
));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefAdd, testing::Values(
    Params{{sNaN}, {0}, {0}},
    Params{{sNaN, sNaN}, {0}, {0}},
    Params{{sNaN, 5}, {0}, {0}},
    Params{{5, sNaN}, {0}, {0}},
    Params{{0}, {sNaN, sNaN}, {0}},
    Params{{0}, {5, sNaN}, {0}},
    Params{{0}, {sNaN, 5}, {0}},
    Params{{sNaN, sNaN}, {sNaN, sNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefMul, testing::Values(
    Params{{sNaN}, {0}, {0}},
    Params{{sNaN, sNaN}, {0}, {0}},
    Params{{sNaN, 5}, {0}, {0}},
    Params{{5, sNaN}, {0}, {0}},
    Params{{0}, {sNaN, sNaN}, {0}},
    Params{{0}, {5, sNaN}, {0}},
    Params{{0}, {sNaN, 5}, {0}},
    Params{{sNaN, sNaN}, {sNaN, sNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefExp, testing::Values(
    Params{{sNaN}, {0}, {0}},
    Params{{sNaN, sNaN}, {0}, {0}},
    Params{{sNaN, 5}, {0}, {0}},
    Params{{5, sNaN}, {0}, {0}},
    Params{{0}, {sNaN, sNaN}, {0}},
    Params{{0}, {5, sNaN}, {0}},
    Params{{0}, {sNaN, 5}, {0}},
    Params{{sNaN, sNaN}, {sNaN, sNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefRoot, testing::Values(
    Params{{sNaN}, {0}, {0}},
    Params{{sNaN, sNaN}, {0}, {0}},
    Params{{sNaN, 5}, {0}, {0}},
    Params{{5, sNaN}, {0}, {0}},
    Params{{0}, {sNaN, sNaN}, {0}},
    Params{{0}, {5, sNaN}, {0}},
    Params{{0}, {sNaN, 5}, {0}},
    Params{{sNaN, sNaN}, {sNaN, sNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefMode, testing::Values(
    Params{{sNaN}, {0}, {0}},
    Params{{sNaN, sNaN}, {0}, {0}},
    Params{{sNaN, 5}, {0}, {0}},
    Params{{5, sNaN}, {0}, {0}},
    Params{{0}, {sNaN, sNaN}, {0}},
    Params{{0}, {5, sNaN}, {0}},
    Params{{0}, {sNaN, 5}, {0}},
    Params{{sNaN, sNaN}, {sNaN, sNaN}, {0}}

));

INSTANTIATE_TEST_CASE_P(signalingNan, UndefFactorial, testing::Values(
    UnariParams{{sNaN}, {0}},
    UnariParams{{sNaN, sNaN}, {0}},
    UnariParams{{5, sNaN}, {0}}
));

TEST_P(UndefAdd, oper)
{
    EXPECT_THROW(p.number1 + p.number2, UndefinedException);
}

TEST_P(UndefSub, oper)
{
    EXPECT_THROW(p.number1 - p.number2, UndefinedException);
}

TEST_P(UndefMul, oper)
{
    EXPECT_THROW(p.number1 * p.number2, UndefinedException);
}

TEST_P(UndefDiv, oper)
{
    EXPECT_THROW(p.number1 / p.number2, UndefinedException);
}

TEST_P(UndefExp, oper)
{
    EXPECT_THROW(p.number1 ^p.number2, UndefinedException);
}

TEST_P(UndefMode, oper)
{
    EXPECT_THROW(p.number1 % p.number2, UndefinedException);
}

TEST_P(UndefFactorial, oper)
{
    EXPECT_THROW(!p.number, UndefinedException);
}

TEST_P(UndefAdd, fce)
{
    EXPECT_THROW(p.number1.add(p.number2), UndefinedException);
}

TEST_P(UndefSub, fce)
{
    EXPECT_THROW(p.number1.sub(p.number2), UndefinedException);
}

TEST_P(UndefMul, fce)
{
    EXPECT_THROW(p.number1.mul(p.number2), UndefinedException);
}

TEST_P(UndefDiv, fce)
{
    EXPECT_THROW(p.number1.div(p.number2), UndefinedException);
}

TEST_P(UndefExp, fce)
{
    EXPECT_THROW(p.number1.pow(p.number2), UndefinedException);
}

TEST_P(UndefMode, fce)
{
    EXPECT_THROW(p.number1.mod(p.number2), UndefinedException);
}

TEST_P(UndefRoot, fce)
{
    EXPECT_THROW(p.number1.root(p.number2), UndefinedException);
}

TEST_P(UndefFactorial, fce)
{
    EXPECT_THROW(p.number.fact(), UndefinedException);
}
