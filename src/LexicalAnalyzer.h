/**
 * @file     LexicalAnalyzer.h
 * @encoding UTF-8
 * @date     28.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>, Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */
#ifndef FIT_IVS_PROJECT2_LEXICALANALYZER_H
#define FIT_IVS_PROJECT2_LEXICALANALYZER_H

#include <set>
#include <cctype>
#include <sstream>
#include "Lex.h"
#include "math/Number.h"
#include "Interpret.h"
#include "LexIdentificationObserver.h"
#include "LexicalAnalyzerException.h"

namespace team22::Calc
{
/**
 *  Třída sloužící k lexikální analyze vstupů
 *  přebírá znaky pomocí fce pushSymbol() a ve chvíli identifikace lexému
 *  předá tento interpretu a pokud byl registrovaný volá callback kterému tento lexém předá.
 */
class LexicalAnalyzer
{
    enum State {
        Number,
        Operator,
        Init
    };

    State state = Init;

    /**
     * Množina Objektů na nichž bude volán callback při rozeznání lexemů
     */
    std::set<LexIdentificationObserver *> lexCallbackObjects;

    /**
     * Řetězec, který obsahuje znaky, které ještě nebyly rozeznány jako lexém
     */
    std::string saved = "";

    /**
     * Předá lexém všem registrovaným objektům
     * @param lex lexém k předání
     */
    void sendLex(Lex lex);

    /**
     * Vrací lexém daného znaku
     * @param c znak nebo číslice k převodu na lexém
     */
    Lex getCharLex(char c);

    /**
     * Vrací číslo typu double převedené z textového řetězce
     * @param s textový řetězec pro převod
     */
    Math::Number savedToNumber();

public:
    /**
     * Předá znak k analýze
     * @param symbol symbol abecedy přijímané lexikálním analyzátorem
     * @throw LexicalAnalyserException
     */
    void pushSymbol(char symbol);


    /**
     * Registruje objekt k odběru rozeznaných lexémů
     * vícenásobná registrace stejné instance odběratele neprovede nic
     *
     * @param lexCallbackObject objekt na němž
     */
    void registrLexCallback(LexIdentificationObserver *lexCallbackObject);

    /**
     * Zpracuje uložený řetězec saved a vrátí jej jako číslo
     * @param symbol
     */
    void processNumberSymbol(char symbol);

    /**
     * Jedná se o symbol tvořící číslo tedy číslice, . nebo i
     * @param symbol
     * @return
     */
    bool isNumberSymbol(char symbol) const;

    /**
     * Vyresetuje lexikální analyzátor
     */
    void clear();

    /**
     * Zpracuje výceznakový operátor
     * @param symbol
     */
    void processOperator(char symbol);
};
}

#endif //FIT_IVS_PROJECT2_LEXICALANALYZER_H
