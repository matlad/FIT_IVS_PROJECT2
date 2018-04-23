/**
 * @file     LexicalAnalyzer.cpp
 * @encoding UTF-8
 * @date     28.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>, Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */
#include "LexicalAnalyzer.h"

namespace team22{ namespace Calc
{


void LexicalAnalyzer::sendLex(Lex lex)
{
    for (auto callBack:this->lexCallbackObjects)
        callBack->sendIdentifiedLex(lex);
}

Lex LexicalAnalyzer::getCharLex(char c)
{
    switch (c) {
        case '+':
            return Lex(Lex::ADD);
        case '-':
            return Lex(Lex::SUB);
        case '/':
            return Lex(Lex::DIV);
        case '*':
            return Lex(Lex::MUL);
        case '=':
            return Lex(Lex::EVAL);
        case '^':
            return Lex(Lex::EXP);
        case '!':
            return Lex(Lex::FACTORIAL);
        case '%':
            return Lex(Lex::MOD);
        case 'C':
            return Lex(Lex::CLEAR);
        default:
            throw LexicalAnalyzerException();
    }
}

Math::Number LexicalAnalyzer::savedToNumber()
{
    std::stringstream stringStream;
    double number;

    stringStream << saved;
    stringStream >> number;

    if(saved.back() == 'i')
    {
        return Math::Number(0.,number);
    }

    return Math::Number(number);
}

void LexicalAnalyzer::pushSymbol(char symbol)
{
    if (isNumberSymbol(symbol)) {
        processNumberSymbol(symbol);
    } else {
        // Náme rozpracované číslo odešleme
        if (state == Number) {
            sendLex(savedToNumber());
            clear();
        }

        if (ispunct(symbol) || symbol == 'C') {
            sendLex(getCharLex(symbol));
        } else {
            processOperator(symbol);
        }
    }
}

void LexicalAnalyzer::processOperator(char symbol)
{
    state = Operator;
    // Víceznakový operátor
    switch (symbol) {
            // ROOT
            case 'R':
                if (saved.empty()) {
                    saved.push_back(symbol);
                    break;
                }

            case 'O':
                if ((saved == "R" || saved == "RO")) {
                    saved.push_back(symbol);
                    break;
                }
            case 'T':
                if (saved == "ROO") {
                    clear();
                    sendLex(Lex(Lex::ROOT));
                    break;
                }
            // NEG
            case 'N':
                if (saved.empty()) {
                    saved.push_back(symbol);
                    break;
                }
            case 'E':
                if (saved == "N") {
                    saved.push_back(symbol);
                    break;
                }
            case 'G':
                if (saved == "NE"){
                    clear();
                    sendLex(Lex(Lex::NEG));
                    break;
                }
            // BS
            case 'B':
                if (saved.empty()) {
                    saved.push_back(symbol);
                    break;
                }
            case 'S':
                if (saved == "B") {
                    clear();
                    sendLex(Lex(Lex::BS));
                    break;
                }

            // Není Symbolem Víceznakového operátoru
            default:
                throw LexicalAnalyzerException();
        }
}
bool LexicalAnalyzer::isNumberSymbol(char symbol) const
{
    return isdigit(symbol) || symbol == 'i' || symbol == '.';
}

void LexicalAnalyzer::registrLexCallback(LexIdentificationObserver *lexCallbackObject)
{
    lexCallbackObjects.emplace(lexCallbackObject);
}

void LexicalAnalyzer::processNumberSymbol(char symbol)
{
    if(state != Number && state != Init)
        throw LexicalAnalyzerException();

    state = Number;
    // Dvakrát .
    if (symbol == '.' && saved.find('.') != std::string::npos)
        throw LexicalAnalyzerException();

    saved.push_back(symbol);

    // i je vždy jen na konci čísla
    if (symbol == 'i'){
        sendLex(savedToNumber());
        clear();
    }
}

void LexicalAnalyzer::clear()
{
    saved.clear();
    state = Init;
}

}}


