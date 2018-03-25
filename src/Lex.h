/**
 * @file     Lex.h
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_LEX_H
#define FIT_IVS_PROJECT2_LEX_H
#include <ostream>
#include "math/Number.h"

namespace team22::Calc
{

/**
 * @brief Reprezentace lexému kalkulačky tedy čísla nebo operace
 */
class Lex
{
public:
    /**
     * @brief Typy lexémů
     */
    enum Types
    {
        OPERATOR,
        NUMBER
    };

    /**
     * @brief Jednotlivé operace
     */
    enum Operator
    {
        ADD,
        SUB,
        DIV,
        MUL,
        EXP,
        ROOT,
        FACTORIAL,
        MOD,
        NEG,
        EVAL,
    };

    const char * OperatorNames[10] {
        "ADD",
        "SUB",
        "DIV",
        "MUL",
        "EXP",
        "ROOT",
        "FACTORIAL",
        "MOD",
        "NEG",
        "EVAL",
    };

    /**
     * @brief reprezentace hodnoty lexému
     */
    union Value
    {
        Math::Number number {0};
        Operator oper;
    };

protected:
    Value value;
    Types type;

public:
    /**
     * @brief Konstrukce lexému typu operátor
     * @param oper
     */
    Lex(Operator oper);

    /**
     * @brief Konstrukce lexému typu číslo
     * @param number
     */
    Lex(Math::Number number);

    /**
     * @brief vrací hodnotu lexému
     */
    const Value &getValue() const;

    /**
     * @brief vrací typ lexému
     * @return type
     */
    Types getType() const;

    /**
     * @brief Testuje zda je lexém číslo
     * @return true pokud je číslo
     */
    bool isNumber() const;

    /**
     * @brief Testuje zda je lexém operátor
     * @return true pokud je operátor
     */
    bool isOperator() const;

    /**
     * @throw LexException tento lexém pokud není číslo
     * @return number
     */
    Math::Number getAsNumber() const;

    /**
     * @throw LexException tento lexém pokud není Operator
     * @return operator
     */
    Operator getAsOperator() const;

    bool operator==(const Lex &rhs) const;
    bool operator!=(const Lex &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Lex &lex);
};
}

#endif //FIT_IVS_PROJECT2_LEX_H
