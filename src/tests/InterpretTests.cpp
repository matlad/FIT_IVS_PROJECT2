/**
 * @file     InterpretTests.cpp
 * @encoding UTF-8
 * @date     29.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */

#include <gtest/gtest.h>
#include <ostream>
#include "../math/Number.h"
#include "../Lex.h"
#include "../Interpret.h"
#include "TestContants.h"

using std::vector;
using std::string;
using team22::Math::Number;
using namespace team22::Calc;

struct InterpretTestParams
{
    vector<Lex> lexems;
    Number result;

    friend std::ostream &operator<<(std::ostream &os, const InterpretTestParams &params)
    {
        os << "lexems: {";

        for (auto lex: params.lexems) {
            os << " " << lex;
        }

        os << " } result: " << params.result;
        return os;
    }
};


struct InterpretTest:
    ResultObserver,
    testing::Test,
    testing::WithParamInterface<InterpretTestParams>
{
    Interpret interpret;
    Number result = {0};
    InterpretException *error = nullptr;

    InterpretTest()
    {
        interpret.registrResultCallback(this);
    }

    void onError(InterpretException exception) override
    {
        error = new InterpretException(exception);
    }

    void onResultChange(Number result) override
    {
        this->result = result;
    }

    virtual ~InterpretTest()
    {
        delete error;
    }

};

INSTANTIATE_TEST_CASE_P(def_p, InterpretTest, testing::Values(
    InterpretTestParams{{Number(5), Lex::ADD, Number(4)}, Number(9)},
    InterpretTestParams{{Number(5), Lex::SUB, Number(4)}, Number(1)},
    InterpretTestParams{{Number(8), Lex::DIV, Number(4)}, Number(2)},
    InterpretTestParams{{Number(2), Lex::MUL, Number(4)}, Number(8)},
    InterpretTestParams{{Number(16),Lex::ROOT, Number(2)}, Number(4)},
    InterpretTestParams{{Number(4), Lex::EXP, Number(3)}, Number(64)},
    InterpretTestParams{{Number(2), Lex::MUL, Number(4)}, Number(8)},
    InterpretTestParams{{Number(5), Lex::FACTORIAL}, Number(120)},
    InterpretTestParams{{Number(5), Lex::MOD, Number(4)}, Number(1)},
    InterpretTestParams{{Number(5), Lex::CLEAR}, Number(0)},
    InterpretTestParams{{Number(5), Lex::BS}, Number(0)},
    InterpretTestParams{{Number(5), Lex::ADD, Number(4), Lex::ADD, Number(-3)}, Number(6)},
    InterpretTestParams{{Number(5), Lex::ADD, Number(4), Lex::ADD, Number(-3), Lex::EVAL}, Number(6)},
    InterpretTestParams{{Number(5), Lex::ADD, Number(4), Lex::FACTORIAL, Lex::DIV, Number(-3)}, Number(-120960)},
    InterpretTestParams{{Number(5), Lex::ADD, Number(4), Lex::FACTORIAL, Lex::DIV, Number(-3), Lex::EVAL, Lex::SUB, Number(-60) }, Number(-120900)},
    InterpretTestParams{{Number(5), Lex::ADD, Number(4), Lex::FACTORIAL, Lex::DIV, Number(-3), Lex::EVAL, Number(-60) }, Number(-60)}
));

TEST_P(InterpretTest, def)
{

    for (auto lex : GetParam().lexems) {
        interpret.sendIdentifiedLex(lex);
        EXPECT_EQ(nullptr,error);
    }

    T22_NUMBER_EXPECT_NEAR(GetParam().result, result, DELTA);
}

TEST_F(InterpretTest, clear_1)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(5));
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Lex::CLEAR);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

TEST_F(InterpretTest, clear_2)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(5));
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Lex::CLEAR);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::CLEAR);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::CLEAR);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

TEST_F(InterpretTest, clear_3)
{
    interpret.sendIdentifiedLex(Lex::CLEAR);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::CLEAR);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::CLEAR);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

TEST_F(InterpretTest, bs_1)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(5));
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Lex::BS);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

TEST_F(InterpretTest, bs_2)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(5));
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::BS);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::BS);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::BS);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

TEST_F(InterpretTest, bs_3)
{
    interpret.sendIdentifiedLex(Lex::BS);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::BS);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::BS);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

TEST_F(InterpretTest, AddStartWithNumber)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(5));
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(5), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(9), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(9), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(13), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

TEST_F(InterpretTest, AddStartWithOperator)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

TEST_F(InterpretTest, Mix)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
    interpret.sendIdentifiedLex(Number(3));
    EXPECT_NE(nullptr,error);
    error = nullptr;
    interpret.sendIdentifiedLex(Lex::BS);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(3));
    T22_NUMBER_EXPECT_NEAR(Number(7), result, DELTA);
    EXPECT_EQ(nullptr,error);
}

/******************************************************************************
 * Errors
 *****************************************************************************/

TEST_F(InterpretTest, DivByZero)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Lex::DIV);
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(0));
    EXPECT_NE(nullptr, error);
}

TEST_F(InterpretTest, UnexpectedLexem_2xNumber)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    T22_NUMBER_EXPECT_NEAR(Number(4), result, DELTA);
    interpret.sendIdentifiedLex(Number(4));
    EXPECT_NE(nullptr, error);
}

TEST_F(InterpretTest, UnexpectedLexem_2xOperator)
{
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::ADD);
    T22_NUMBER_EXPECT_NEAR(Number(0), result, DELTA);
    interpret.sendIdentifiedLex(Lex::DIV);
    EXPECT_NE(nullptr, error);
}
