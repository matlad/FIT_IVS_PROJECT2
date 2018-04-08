/**
 * @file     Lex.cpp
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#include "Lex.h"
#include "LexException.h"

const team22::Calc::Lex::Value &team22::Calc::Lex::getValue() const
{
    return value;
}

team22::Calc::Lex::Types team22::Calc::Lex::getType() const
{
    return type;
}

bool team22::Calc::Lex::isNumber() const
{
    return type == team22::Calc::Lex::Types::NUMBER;
}

bool team22::Calc::Lex::isOperator() const
{
    return type == team22::Calc::Lex::Types::OPERATOR;
}

team22::Calc::Lex::Lex(team22::Calc::Lex::Operator oper)
    : type(OPERATOR)
{
    value.oper = oper;
}

team22::Calc::Lex::Lex(team22::Math::Number number)
    : type(NUMBER)
{
    value.number = number;
}

team22::Math::Number team22::Calc::Lex::getAsNumber() const
{
    if (!isNumber()) {
        throw LexException();
    }
    return value.number;
}

team22::Calc::Lex::Operator team22::Calc::Lex::getAsOperator() const
{
    if (!isOperator()) {
        throw LexException();
    }

    return value.oper;
}

bool team22::Calc::Lex::operator==(const team22::Calc::Lex &rhs) const
{
    return
        type == rhs.type &&
            (
                (isNumber() && getAsNumber() == rhs.getAsNumber()) ||
                    (isOperator() && getAsOperator() == rhs.getAsOperator())
            );
}

bool team22::Calc::Lex::operator!=(const team22::Calc::Lex &rhs) const
{
    return !(rhs == *this);
}
std::ostream &team22::Calc::operator<<(std::ostream &os, const team22::Calc::Lex &lex)
{
    if (lex.isNumber()) {
        os << "N(" << lex.getAsNumber() << ")";
    }
    else {
        os << "O(" << lex.OperatorNames[lex.getAsOperator()] << ")";
    }

    return os;
}

std::stringstream &team22::Calc::operator<<(std::stringstream &os, const team22::Calc::Lex &lex)
{
    if (lex.isNumber()) {
        os << "" << lex.getAsNumber();
    } else {
        os << lex.OperatorNames[lex.getAsOperator()];
    }

    return os;
}
