/**
 * @file     Interpret.h
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_INTERPRET_H
#define FIT_IVS_PROJECT2_INTERPRET_H

#include <set>
#include "LexIdentificationObserver.h"
#include "Lex.h"
#include "ResultObserver.h"
#include "math/Number.h"
namespace team22::Calc
{
class Interpret: public LexIdentificationObserver
{
    /**
     * Předá informaci o změně výsledků pozorovatelům
     */
    void notifyResultChanged();

    /**
     * Předá informaci o změně výsledků pozorovatelům
     */
    void notifyAboutError(InterpretException exception);

public:
    /**
     * Množina Objektů na nichž bude volán callback při změně výsledku nebo chybě
     */
    std::set<ResultObserver *> resultCallbackObjects;

    /**
     * Registruje objekt k odběru rozeznaných lexémů
     * vícenásobná registrace stejné instance odběratele neprovede nic
     *
     * @param resultCallbackObject objekt na němž bude volán callback při změně výsledku nebo chybě
     */
    void registResultCalback(ResultObserver * resultCallbackObject);

    /**
     * Příjme lexém k interpretaci
     *
     * @param lex
     */
    void sendIdentifiedLex(Lex lex) override;
};
}


#endif //FIT_IVS_PROJECT2_INTERPRET_H
