/**
 * @file     LexicalAnalyzer.cpp
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#include "LexicalAnalyzer.h"

void team22::Calc::LexicalAnalyzer::pushSymbol(char symbol)
{
    for (auto callBack:this->lexCallbackObjects)
    {
        callBack->sendIdentifiedLex(Lex(2));
    }
}

void team22::Calc::LexicalAnalyzer::registLexemCalback(team22::Calc::LexIdentificationObserver *lexCallbackObject)
{
    lexCallbackObjects.emplace(lexCallbackObject);
}

team22::Calc::LexicalAnalyzer::LexicalAnalyzer()
{

}
