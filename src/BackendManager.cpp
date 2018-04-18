/**
 * @file     BackendManager.cpp
 * @encoding UTF-8
 * @date     18.4.18
 * @author   Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */

#include <string>

#include "Equation.h"
#include "math/Number.h"

using std::stringstream;
using std::string;

using namespace team22::Calc;
using team22::Math::Number;

class BackendManager : ResultObserver, EquationObserver
{
public:
    Interpret interpret;
    LexicalAnalyzer lexicalAnalyzer;
    Equation equation;
    stringstream strEquation;
    InterpretException *error = nullptr;
    Number result = {0};

    BackendManager() : equation(lexicalAnalyzer, interpret)
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

    virtual ~BackendManager()
    {
        delete error;
    }
};
