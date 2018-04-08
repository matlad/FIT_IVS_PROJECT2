/**
 * @file     LexicalAnalyzer.cpp
 * @encoding UTF-8
 * @date     28.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>, Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */
#include "LexicalAnalyzer.h"

namespace team22::Calc
{
bool LexicalAnalyzer::isNumber(std::string s)
{
    if (s.empty())
        return false;

    for (const char c : s) {
        if (!isdigit(c))
            return false;
    }

    return true;
}

bool LexicalAnalyzer::isNumberWithDot(std::string s)
{
    bool flag = true;

    if (s.empty())
        return false;

    unsigned int i = 0;
    for (const char c : s) {
        if (!isdigit(c) && (((!flag || i == 0) && c == '.') || c != '.'))
            return false;

        if (c == '.')
            flag = false;

        i++;
    }

    return true;
}

void LexicalAnalyzer::sendLex(Lex lex) {
    for (auto callBack:this->lexCallbackObjects)
        callBack->sendIdentifiedLex(lex);
}

Lex LexicalAnalyzer::getCharLex(char c) {
    switch(c) {
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
        if (isdigit(c)) {
            std::string digit;
            digit.push_back(c);
            return Lex(team22::Math::Number(stringToDouble(digit)));
        }

        throw LexicalAnalyzerException();
    }
}

double LexicalAnalyzer::stringToDouble(std::string s) {
    std::stringstream stringStream;
    double number;

    stringStream << s;
    stringStream >> number;

    return number;
}

void LexicalAnalyzer::saveSymbol(char c) {
    saved += c;
    last = c;
}

void LexicalAnalyzer::pushSymbol(char symbol)
{
    switch(symbol) {
    case '+':
    case '-':
    case '/':
    case '*':
    case '=':
    case '^':
    case '!':
    case '%':
    case 'C':
    case 'T':
    case 'G':
    case 'S':
    case 'i':
        if ((saved == "ROO" && symbol == 'T') ||
                (saved == "NE" && symbol == 'G') ||
                (saved == "B" && symbol == 'S') ||
                (isNumberWithDot(saved) && saved[saved.length() - 1] != '.' && symbol == 'i')) {
            switch (symbol) {
            case 'T':
                sendLex(Lex(Lex::ROOT));
                break;
            case 'G':
                sendLex(Lex(Lex::NEG));
                break;
            case 'S':
                sendLex(Lex(Lex::BS));
                break;
            default:
                sendLex(Lex(team22::Math::Number(0, stringToDouble(saved))));
                break;
            }
        } else {
            if (saved.empty())
                sendLex(getCharLex(symbol));
            else if (isNumberWithDot(saved) && saved[saved.length() - 1] != '.') {
                sendLex(Lex(team22::Math::Number(stringToDouble(saved))));
                sendLex(getCharLex(symbol));
            }
        }

        saved.clear();
        last = symbol;
        return;
    case 'R':
    case 'N':
    case 'B':
    case 'O':
    case 'E':
        if (!saved.empty() && isNumberWithDot(saved) && saved[saved.length() - 1] != '.') {
            sendLex(Lex(team22::Math::Number(stringToDouble(saved))));
            saved.clear();
        }
        if ((saved.empty() && (symbol == 'R' || symbol == 'N' || symbol == 'B')) ||
                ((saved == "R" || saved == "RO") && symbol == 'O') ||
                (saved == "N" && symbol == 'E')) {
            saveSymbol(symbol);
            return;
        }
        break;
    default:
        if (saved.empty() && isdigit(symbol)) {
            if (last == 'i')
                throw LexicalAnalyzerException();
            saveSymbol(symbol);
            return;
        } else if (!saved.empty()) {
            if ((isNumber(saved) && (isdigit(symbol) || symbol == '.')) ||
                    (isNumberWithDot(saved) && isdigit(symbol))) {
                saveSymbol(symbol);
                return;
            }
        }
        break;
    }

    throw LexicalAnalyzerException();
}

void LexicalAnalyzer::registrLexCallback(LexIdentificationObserver *lexCallbackObject)
{
    lexCallbackObjects.emplace(lexCallbackObject);
}

}
