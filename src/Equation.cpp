/**
 * @file     Equation.cpp
 * @encoding UTF-8
 * @date     8.4.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */


#include "Equation.h"
using namespace team22::Calc;
using std::vector;
using std::string;
using std::stringstream;

void Equation::sendIdentifiedLex(Lex lex)
{
    if (lex.isOperator()) {
        switch (lex.getAsOperator()) {
            case Lex::CLEAR:
                data.clear();
                lastResult = Math::Number(0);
                notifyEquationObserver();
                break;
            case Lex::BS:
                backSpace();
                break;
            case Lex::EVAL:
                data.clear();
                break;
            default:
                if(data.empty())
                    pushLex(new Lex(lastResult));
                pushLex(new Lex(lex));
                break;
        }
    }
    else {
        numberBuffer.clear();
        pushLex(new Lex(lex));
    }
    notifyEquationObserver();
    interpret.sendIdentifiedLex(lex);
}

void Equation::pushSymbol(char symbol)
{
    lexicalAnalyzer.pushSymbol(symbol);

    // Číslice vypisujeme i když ještě nebyl identifikován lexém čísla
    if (isNumberSymbol(symbol)) {
        numberBuffer.push_back(symbol);
        notifyEquationObserver();
    }
}

void Equation::backSpace()
{
    // Vycházíme s toho, že aby mohl bý identifikovaný lexem BS
    // veškerá rozpracovaná čísla už jsou identifikována a tudíž nas nemusí zajímat numberBuffer.

    if(data.empty())
        return;

    auto last = data.back();
    data.pop_back();

    // Pokud je poslední lexém číslo Nechceme odstranit cele číslo ale jen číslici
    // To provedeme tak že lexem odebraný z konce rovnice převedeme na řetězec a
    // odebereme poslední znak a obět necháme zpracovat lexikálním analyzátorem.
    if (last->isNumber()) {
        auto lastNumber = last->getAsNumber();
        stringstream ssLastNumber;
        ssLastNumber << "" << lastNumber;
        numberBuffer = ssLastNumber.str();
        numberBuffer.pop_back();

        for (auto symbol:numberBuffer)
            lexicalAnalyzer.pushSymbol(symbol);
    }

    reComputeResult();
}

void Equation::registrEquationObserver(EquationObserver *equationObserver)
{
    equationObservers.insert(equationObserver);
}

void Equation::notifyEquationObserver()
{
    for (auto observer:equationObservers)
        observer->onEquationChange();
}

bool Equation::isNumberSymbol(char &symbol)
{
    return symbol == 'i' || isdigit(symbol);
}

void Equation::reComputeResult()
{
    for (auto lex : data)
        interpret.sendIdentifiedLex(*lex);
}

Equation::Equation(LexicalAnalyzer &lexicalAnalyzer, Interpret &interpret):
  interpret(interpret),lexicalAnalyzer(lexicalAnalyzer)
{
    this->lexicalAnalyzer.registrLexCallback(this);
}

void Equation::pushLex(Lex *lex)
{
    data.push_back(lex);
}

void Equation::onResultChange(Math::Number result)
{
    lastResult = result;
}

void Equation::onError(InterpretException exception)
{
    //Nezajímá nás
}

std::ostream &team22::Calc::operator<<(std::ostream &os, const Equation &equation)
{
    for (auto &symbol : equation.data)
        os << *symbol;

    for (auto symbol : equation.numberBuffer)
        os << symbol;

    return os;
}

std::stringstream &team22::Calc::operator<<(std::stringstream &stringStream, const Equation &equation)
{
    for (auto &symbol : equation.data)
        stringStream << *symbol;

    for (auto symbol : equation.numberBuffer)
        stringStream << symbol;

    return stringStream;
}
