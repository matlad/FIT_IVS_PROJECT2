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
using namespace team22::Math;
namespace team22::Calc
{
/**
 * Po přijetí min počtu lexemů pro interpretaci je interpretace provedena
 * a výsledek předá pomocí callbacku `ResultObserver::onResultChange`.
 * Objekty na kterých bude callback volán lze registrovat pomocí `Interpret::registrResultCallback`
 *
 * Lexem `Lex::EVAL` po eval  pokud příjde číslo přepíše výsledek číslem,
 * pokud operator stejné chování jako eval nepřišlo
 *
 * Lexemi `Lex::BS` a `Lex::CLEAR` provedou vynulování výsledku (a notifikaci o změně)
 *
 * Ostatní lexémy budou vyhodnoceny jako matematické operace
 *
 * Pořadí provázení operací je totožné s pořadím jejich předání.
 * Pokud sekvence začíná operátorem předpokládá se první operátor 0
 *
 * Pokud je předaná chybná sekvence lexému je oznámena chyba callback `ResultObserver::onError`.
 *
 * @example
 *  Auto i = Interpret;
 *  i.sendIdentifiedLex(Number(5));
 *  // Informování o změně výsledků na 5 pomocí callbacků
 *  i.sendIdentifiedLex(Lex(Lex::ADD));
 *  i.sendIdentifiedLex(Number(4));
 *  // Provedení operace => 5+4 výsledek 9
 *  // Informování o změně výsledků na 9 pomocí callbacků
 *  i.sendIdentifiedLex(Lex(Lex::ADD));
 *  i.sendIdentifiedLex(Number(4));
 *  // Provedení operace => (předchozí výsledek)9+4 výsledek 13
 *  // Informování o změně výsledků na 13 pomocí callbacků
 *
 */
class Interpret: public LexIdentificationObserver
{
    /**
     * Předá informaci o změně výsledků pozorovatelům
     */
    void notifyResultChanged();

    /**
     * Předá informaci o změně výsledků pozorovatelům
     */
    void notifyAboutError();

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
    void registrResultCallback(ResultObserver *resultCallbackObject);

    /**
     * Příjme lexém k interpretaci
     * @see Interpret popis postupu interpretace
     * @param lex
     */
    void sendIdentifiedLex(Lex lex) override;

private:
    Number result = Number(0);
    Lex::Operator oper;
    bool unprocessedOperator = false;
};
}


#endif //FIT_IVS_PROJECT2_INTERPRET_H
