/**
 * @file     LexicalAnalyzer.h
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_LEXICALANALYZER_H
#define FIT_IVS_PROJECT2_LEXICALANALYZER_H

#include "Lex.h"
#include "Interpret.h"

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
     * Interpret jemuž jsou předávaný identifikované lexémy
     */
    Interpret interpret;

    /**
     * object callbacku
     */
    void * object = nullptr;

    /**
     * callback metoda
     */
    void (*method)(Lex) = nullptr;

public:
    /**
     * Předá znak k analýze
     * @param symbol symbol abecedy přijímané lexikálním analyzátorem
     */
    void pushSymbol(char symbol);


    /**
     * Registrace metody jako callbacku volaného při identifikaci lexemu
     * @param object
     * @param method
     */
    void registLexemCalback(void * object, void * method(Lex));

    /**
     *
     * @param interpret
     */
    explicit LexicalAnalyzer(Interpret &interpret);

};
}

#endif //FIT_IVS_PROJECT2_LEXICALANALYZER_H
