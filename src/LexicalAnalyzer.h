/**
 * @file     LexicalAnalyzer.h
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_LEXICALANALYZER_H
#define FIT_IVS_PROJECT2_LEXICALANALYZER_H

#include <set>
#include "Lex.h"
#include "Interpret.h"
#include "LexIdentificationObserver.h"

namespace team22::Calc
{
/**
 *  Třída sloužící k lexikální analyze vstupů
 *  přebírá znaky pomocí fce pushSymbol() a ve chvíli identifikace lexému
 *  předá tento interpretu a pokud byl registrovaný volá callback kterému tento lexém předá.
 */
class LexicalAnalyzer
{
    /**
     * Množina Objektů na nichž bude volán callback při rozeznání lexemů
     */
    std::set<LexIdentificationObserver *> lexCallbackObject;


public:
    /**
     * Předá znak k analýze
     * @param symbol symbol abecedy přijímané lexikálním analyzátorem
     */
    void pushSymbol(char symbol);


    /**
     * Registruje objekt k odběru rozeznaných lexémů
     * vícenásobná registrace stejné instance odběratele neprovede nic
     *
     * @param lexCallbackObject objekt na němž
     */
    void registLexemCalback(LexIdentificationObserver * lexCallbackObject);

    /**
     *
     * @param interpret
     */
    explicit LexicalAnalyzer();

};
}

#endif //FIT_IVS_PROJECT2_LEXICALANALYZER_H
