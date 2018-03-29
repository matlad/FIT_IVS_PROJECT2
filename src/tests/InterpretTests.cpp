/**
 * @file     InterpretTests.cpp
 * @encoding UTF-8
 * @date     29.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */

#include <gtest/gtest.h>
#include "../math/Number.h"
#include "../Lex.h"
#include "../Interpret.h"

using std::vector;
using std::string;
using team22::Math::Number;
using namespace team22::Calc;

struct InterpretTestParams
{
    vector<Lex> lexems;
    Number result;
};

struct InterpretTestErrorsParams
{
    vector<Lex> lexems;
    Lex error;
};

struct InterpretTest:
    ResultObserver,
    testing::Test,
    testing::WithParamInterface<InterpretTestParams>
{
    Interpret interpret;
    Number result = {0};

    InterpretTest()
    {
        interpret.registResultCalback(this);
    }

    void onError(InterpretException exception) override
    {
        ADD_FAILURE();
    }

    void onResultChange(Number result) override
    {
        this->result = result;
    }


};

INSTANTIATE_TEST_CASE_P(def, InterpretTest, testing::Values(
   InterpretTestParams{{Number(5), Lex::ADD, Number(4)}, Number(9)},
   InterpretTestParams{{Number(5), Lex::ADD, Number(4), Lex::ADD, Number(-3) }, Number(6)},
   InterpretTestParams{{Number(5), Lex::ADD, Number(4)}, Number(9)},
   InterpretTestParams{{Number(5), Lex::ADD, Number(4)}, Number(9)},
   InterpretTestParams{{Number(5), Lex::ADD, Number(4)}, Number(9)},
   InterpretTestParams{{Number(5), Lex::ADD, Number(4)}, Number(9)},
   InterpretTestParams{{Number(5), Lex::ADD, Number(4)}, Number(9)}
));

TEST_P(InterpretTest, def)
{

    for(auto lex : GetParam().lexems){
        interpret.sendIdentifiedLex(lex);
    }

    EXPECT_EQ(GetParam().result,result);
}
