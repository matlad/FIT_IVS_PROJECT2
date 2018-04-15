/**
 * @file     backendTest.cpp
 * @encoding UTF-8
 * @date     8.4.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 * Integrační test backendu
 */

#include "../Equation.h"
#include "../math/Number.h"
#include "TestContants.h"
#include <gtest/gtest.h>
#include <string>

using namespace team22::Calc;
using std::stringstream;
using team22::Math::Number;
using std::cout;
using std::endl;
using std::string;

class BackendTester: ResultObserver, EquationObserver
{
public:
    Interpret interpret;
    LexicalAnalyzer lexicalAnalyzer;
    Equation equation;
    stringstream strEquation;
    InterpretException *error = nullptr;
    Number result = {0};

    BackendTester()
        : equation(lexicalAnalyzer, interpret)
    {
        lexicalAnalyzer.registrLexCallback(&interpret);
        interpret.registrResultCallback(this);
        equation.registrEquationObserver(this);
    }

    void onEquationChange() override
    {
        strEquation.str("");
        strEquation << equation;
    }

    void onError(InterpretException exception) override
    {
        error = new InterpretException(exception);
    }

    void onResultChange(team22::Math::Number result) override
    {
        this->result = result;
    }

    virtual ~BackendTester()
    {
        delete error;
    }

};

TEST(test, test1)
{
    //12+34BS=BS5-BS*6=
    BackendTester testr;

    testr.equation.pushSymbol('1');
    EXPECT_EQ(testr.strEquation.str(),"1");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(0), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('2');
    EXPECT_EQ(testr.strEquation.str(),"12");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(0), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('+');
    EXPECT_EQ(testr.strEquation.str(),"12+");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(12), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('3');
    EXPECT_EQ(testr.strEquation.str(),"12+3");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(12), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('4');
    EXPECT_EQ(testr.strEquation.str(),"12+34");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(12), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('B');
    EXPECT_EQ(testr.strEquation.str(),"12+34");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(12), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('S');
    EXPECT_EQ(testr.strEquation.str(),"12+3");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(12), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('=');
    EXPECT_EQ(testr.strEquation.str(),"");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(15), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('B');
    EXPECT_EQ(testr.strEquation.str(),"");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(15), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('S');
    EXPECT_EQ(testr.strEquation.str(),"");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(12), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('5');
    EXPECT_EQ(testr.strEquation.str(),"5");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(12), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('-');
    EXPECT_EQ(testr.strEquation.str(),"5-");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(17), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('B');
    EXPECT_EQ(testr.strEquation.str(),"5-");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(17), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('S');
    EXPECT_EQ(testr.strEquation.str(),"5");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(12), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('*');
    EXPECT_EQ(testr.strEquation.str(),"5*");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(17), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('6');
    EXPECT_EQ(testr.strEquation.str(),"5*6");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(17), DELTA);
    EXPECT_EQ(testr.error, nullptr);

    testr.equation.pushSymbol('=');
    EXPECT_EQ(testr.strEquation.str(),"");
    T22_NUMBER_EXPECT_NEAR(testr.result, Number(102), DELTA);
    EXPECT_EQ(testr.error, nullptr);


}
