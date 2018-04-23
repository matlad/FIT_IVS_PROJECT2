/**
 * @file     LexTest.cpp
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */


#include <vector>
#include <gtest/gtest.h>
#include <ostream>
#include "../Lex.h"
#include "../LexicalAnalyzer.h"
#include "../math/Number.h"
#include "../LexicalAnalyzerException.h"

using std::vector;
using std::string;
using team22::Math::Number;
using namespace team22::Calc;

namespace team22{ namespace Test {namespace lexicalAnalyzer {
struct LexicalAnalyzerTestParam
{
    string input;
    vector<Lex> lexems;
    friend std::ostream &operator<<(std::ostream &os, const LexicalAnalyzerTestParam &param)
    {
        os << "input: " << param.input << "lexs :{";
        for(auto lex:param.lexems){
            os << lex;
        }
        os << "}";
        return os;
    }
};

struct LexicalAnalyzerErrorTestParam
{
    string input;
    char error = '0';

    friend std::ostream &operator<<(std::ostream &os, const LexicalAnalyzerErrorTestParam &param)
    {
        os << "input: " << param.input << "error: " << param.error;
        return os;
    }
};

struct LexicalAnalyzerTestBase:
    public LexIdentificationObserver,
    public testing::Test
{
    LexicalAnalyzer analyzer;
    vector<Lex>::iterator expectedLexemsIter;

    LexicalAnalyzerTestBase()
    {
        analyzer.registrLexCallback(this);
    }

};

struct LexicalAnalyzerTest : LexicalAnalyzerTestBase,  public testing::WithParamInterface<LexicalAnalyzerTestParam>{

    LexicalAnalyzerTestParam param;

    void sendIdentifiedLex(Lex lex) override
    {
        auto expected = * expectedLexemsIter;
        EXPECT_EQ(expected,lex);
        expectedLexemsIter++;
    }

    LexicalAnalyzerTest()
    {
        param = GetParam();
        expectedLexemsIter = param.lexems.begin();
    }
};

struct LexicalAnalyzerErrorsTest : LexicalAnalyzerTestBase, testing::WithParamInterface<LexicalAnalyzerErrorTestParam>{

    LexicalAnalyzerErrorTestParam param;

    void sendIdentifiedLex(Lex lex) override
    {}

    LexicalAnalyzerErrorsTest()
    {
        param = GetParam();
    }
};

INSTANTIATE_TEST_CASE_P(operators, LexicalAnalyzerTest, testing::Values(
    LexicalAnalyzerTestParam{"+",{Lex::ADD}},
    LexicalAnalyzerTestParam{"/",{Lex::DIV}},
    LexicalAnalyzerTestParam{"^",{Lex::EXP}},
    LexicalAnalyzerTestParam{"!",{Lex::FACTORIAL}},
    LexicalAnalyzerTestParam{"%",{Lex::MOD}},
    LexicalAnalyzerTestParam{"*",{Lex::MUL}},
    LexicalAnalyzerTestParam{"NEG",{Lex::NEG}},
    LexicalAnalyzerTestParam{"ROOT",{Lex::ROOT}},
    LexicalAnalyzerTestParam{"-",{Lex::SUB}},
    LexicalAnalyzerTestParam{"=",{Lex::EVAL}},
    LexicalAnalyzerTestParam{"C",{Lex::CLEAR}},
    LexicalAnalyzerTestParam{"BS",{Lex::BS}}
));

INSTANTIATE_TEST_CASE_P(Numbers, LexicalAnalyzerTest, testing::Values(
    LexicalAnalyzerTestParam{"1=", {Number(1), Lex::EVAL}},
    LexicalAnalyzerTestParam{"1321321654351=", {Number(1321321654351), Lex::EVAL}},
    LexicalAnalyzerTestParam{"121.321=", {Number(121.321), Lex::EVAL}},
    LexicalAnalyzerTestParam{"121.321i=", {Number(0,121.321), Lex::EVAL}},
    LexicalAnalyzerTestParam{"0=", {Number(0), Lex::EVAL}},
    LexicalAnalyzerTestParam{"123.=", {Number(123.), Lex::EVAL}},
    LexicalAnalyzerTestParam{"654.i=", {Number(0,654.), Lex::EVAL}},
    LexicalAnalyzerTestParam{".654i=", {Number(0,.654), Lex::EVAL}},
    LexicalAnalyzerTestParam{".654=", {Number(.654), Lex::EVAL}},
    LexicalAnalyzerTestParam{"1654646464654654.6546546546546546=", {Number(1654646464654654.6546546546546546), Lex::EVAL}}
));

INSTANTIATE_TEST_CASE_P(Seqention, LexicalAnalyzerTest, testing::Values(
    LexicalAnalyzerTestParam{"1+2*6i+3-9=", {Number(1), Lex::ADD, Number(2), Lex::MUL, Number(0,6), Lex::ADD, Number(3), Lex::SUB, Number(9), Lex::EVAL}},
    LexicalAnalyzerTestParam{"+654-6", {Lex::ADD, Number(654), Lex::SUB, Number(6)}},
    LexicalAnalyzerTestParam{"*--/=", {Lex::MUL, Lex::SUB, Lex::SUB, Lex::DIV, Lex::EVAL}},
    LexicalAnalyzerTestParam{"CCBS==**", {Lex::CLEAR, Lex::CLEAR, Lex::BS, Lex::EVAL, Lex::EVAL, Lex::MUL, Lex::MUL}},
    LexicalAnalyzerTestParam{"416465i5=",{Number(0,416465),Number(5),Lex::EVAL}},
    LexicalAnalyzerTestParam{"0i3=",{Number(0),Number(3),Lex::EVAL}},
    LexicalAnalyzerTestParam{"4165465.321i1=",{Number(0,4165465.321), Number(1),Lex::EVAL}},
    LexicalAnalyzerTestParam{"2BS21C2ROOT6", {Number(2), Lex::BS, Number(21), Lex::CLEAR, Number(2), Lex::ROOT,Number(6)}},
    LexicalAnalyzerTestParam{"12+34BS=BS5-BS*6", {Number(12),Lex::ADD,Number(34),Lex::BS,Lex::EVAL,Lex::BS, Number(5), Lex::SUB, Lex::BS, Lex::MUL, Number(6)}},
    LexicalAnalyzerTestParam{"12+34BS3=BS5-BS*6", {Number(12),Lex::ADD,Number(34),Lex::BS,Number(3),Lex::EVAL,Lex::BS, Number(5), Lex::SUB, Lex::BS, Lex::MUL, Number(6)}}
));

INSTANTIATE_TEST_CASE_P(Default, LexicalAnalyzerErrorsTest, testing::Values(
    LexicalAnalyzerErrorTestParam{"", 'f'},
    LexicalAnalyzerErrorTestParam{"", 'g'},
    //Case sensitive
    LexicalAnalyzerErrorTestParam{"", 'b'},
    LexicalAnalyzerErrorTestParam{"", 'r'},
    LexicalAnalyzerErrorTestParam{"", 'n'},
    LexicalAnalyzerErrorTestParam{"654", 'r'},
    LexicalAnalyzerErrorTestParam{"654.6584", 'n'},
    LexicalAnalyzerErrorTestParam{"6584.6854i", 'r'},
    LexicalAnalyzerErrorTestParam{"+", 'n'},
    LexicalAnalyzerErrorTestParam{"ROOT", 'n'},
    LexicalAnalyzerErrorTestParam{"RO", 'o'},
    LexicalAnalyzerErrorTestParam{"B", 'n'}
));


TEST_P(LexicalAnalyzerTest, symbol)
{
    auto input = param.input;
    for(auto symbol:input)
    {
        analyzer.pushSymbol(symbol);
    }
}

TEST_P(LexicalAnalyzerErrorsTest, symbol)
{

    for(auto symbol : param.input)
    {
        analyzer.pushSymbol(symbol);
    }

    EXPECT_THROW(analyzer.pushSymbol(param.error), LexicalAnalyzerException);

}
}}}
