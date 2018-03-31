/**
 * @file     Interpret.cpp
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#include "Interpret.h"

using namespace team22::Calc;
using team22::Math::Number;

void Interpret::sendIdentifiedLex(Lex lex)
{

}

void Interpret::registrResultCallback(ResultObserver *resultCallbackObject)
{
    resultCallbackObjects.emplace(resultCallbackObject);
}

void Interpret::notifyResultChanged()
{
    for (auto callBack: this->resultCallbackObjects)
        callBack->onResultChange(Number(0));
}

void Interpret::notifyAboutError(InterpretException exception)
{
    for (auto callBack: this->resultCallbackObjects)
        callBack->onError(exception);
}
