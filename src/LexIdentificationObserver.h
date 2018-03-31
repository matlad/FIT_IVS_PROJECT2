/**
 * @file     LexCallBackInterface.h
 * @encoding UTF-8
 * @date     24.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_LEXCALLBACKINTERFACE_H
#define FIT_IVS_PROJECT2_LEXCALLBACKINTERFACE_H

#include "Lex.h"

namespace team22::Calc
{

class LexIdentificationObserver
{
public:
    virtual void sendIdentifiedLex(Lex lex) = 0;
};
}

#endif //FIT_IVS_PROJECT2_LEXCALLBACKINTERFACE_H
