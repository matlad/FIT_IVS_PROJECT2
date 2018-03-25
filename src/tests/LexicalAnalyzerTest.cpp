/**
 * @file     LexTest.cpp
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */


#include <queue>
#include <vector>
#include <gtest/gtest.h>
#include "../Lex.h"
#include "../LexicalAnalyzer.h"
#include "../math/Number.h"

using std::vector;
using std::string;
using std::queue;
using team22::Math::Number;
using namespace team22::Calc;


struct LexicalAnalyzerTestParam
{
    string input;
    vector<Lex> lexems;
};

struct LexicalAnalyzerTest:
    public LexIdentificationObserver,
    public testing::Test,
    public testing::WithParamInterface<LexicalAnalyzerTestParam>
{
    LexicalAnalyzer analyzer;
    LexicalAnalyzerTestParam param;
    vector<Lex>::iterator expectedLexemsIter;

    LexicalAnalyzerTest()
    {
        param = GetParam();
        analyzer.registLexemCalback(this);
        expectedLexemsIter = param.lexems.begin();

        auto lex = Lex(1);
    }

    void sendIdentifiedLex(Lex lex) override
    {
        auto expected = expectedLexemsIter;
        EXPECT_EQ(expected,lex);
        expectedLexemsIter++;
    }
};

INSTANTIATE_TEST_CASE_P(def, LexicalAnalyzerTest, testing::Values(
    LexicalAnalyzerTestParam{"1+2",{Lex(Lex::ADD)}}
));


TEST_P(LexicalAnalyzerTest, symbol)
{
    for(auto symbol:param.input)
    {
        analyzer.pushSymbol(symbol);
    }
}
