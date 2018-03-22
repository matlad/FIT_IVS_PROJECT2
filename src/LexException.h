/**
 * @file     LexException.h
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_LEXEXCEPTION_H
#define FIT_IVS_PROJECT2_LEXEXCEPTION_H

#include <exception>

namespace team22::Calc
{

/**
 * Víjymka pro Lexikální analyzátor
 */
class LexException: std::exception
{


private:
    const char *what() const noexcept override
    {
        return "Lexem je jiného typu";
    }
};
}

#endif //FIT_IVS_PROJECT2_LEXEXCEPTION_H
