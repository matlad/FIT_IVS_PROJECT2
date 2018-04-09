/**
 * @file     Equation.h
 * @encoding UTF-8
 * @date     8.4.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_EQUATION_H
#define FIT_IVS_PROJECT2_EQUATION_H

#include "LexIdentificationObserver.h"
#include "LexicalAnalyzer.h"
#include "EquationObserver.h"
#include <string>
#include <vector>
#include <sstream>
#include <ostream>

namespace team22::Calc
{
    /**
     * @brief Třída reprezentující rovnici
     *
     * Třída přebírá znaky a předává je Lexikálnímu analyzátoru, dále pozoruje Identifikaci Lexému.
     * Při každé změně rovnice třída upozorní své pozorovatele o této změně.
     * Pokud příjme lexem Lex::BS odebere číslici(i beru jako číslici) či operátor z konce rovnice a rovnici přepočítá
     * Pokud příjme lexem Lex::CLEAR rovnice se smaže,
     * Operátory Lex::BS Lex::CLEAR a Lex::EVAL se do rovnice nezapisují.
     * Po Lex::EVAL pokud následuje číslo rovnice začíná tímto číslem a jinak začíná výsledkem předchozí rovnice pokud taková není 0.
     */
    class Equation: public LexIdentificationObserver, public ResultObserver
    {
        /**
         * Buffer pro rozepsané číslo
         * číslo v rovnici chceme zobrazovat ješte předním, než je celé identifikováno jako lexem
         * k tomu nám pomáhá tento buffer.
         */
        std::string numberBuffer;

        /**
         * Lexémy tvořící rovnici
         */
        std::vector<Lex *> data;

    private:

        /**
         * Lexikální analyzátor
         */
        LexicalAnalyzer lexicalAnalyzer;

        /**
         * Interpret
         */
        Interpret interpret;

        /**
         * Pozorovatele
         */
        std::set<EquationObserver *> equationObservers;

        /**
         * Poslední výsledek rovnice
         */
        Math::Number lastResult = {0};

    public:
        /**
         *
         * @param lexicalAnalyzer
         * @param interpret
         */
        Equation(LexicalAnalyzer &lexicalAnalyzer, Interpret &interpret);

        /**
         * Předání symbolu rovnici
         * @throw LexicalAnalyzerException
         */
        void pushSymbol(char symbol);

        /**
         * @inherit
         * @param lex
         */
        void sendIdentifiedLex(Lex lex) override;

        /**
         * @inherit
         * @param result
         */
        void onResultChange(Math::Number result) override;

        /**
         * @inherit
         * @param exception
         */
        void onError(InterpretException exception) override;

        /**
         * @brief Provede operaci backspace
         * Pokud je rovnice zakončena číslem odstraní poslední číslici
         * jinak poslední lexem (operator)
         * přepočítá rovnici
         */
        void backSpace();

        /**
         * Zaregistruje pozorovatele změny rovnice
         * @param equationObservers
         */
        void registrEquationObserver(EquationObserver * equationObservers);


        friend std::stringstream &operator<<(std::stringstream &os, const Equation &equation);
        friend std::ostream &operator<<(std::ostream &os, const Equation &equation);

    private:
        /**
         * přepočítá výsledek
         */
        void reComputeResult();

        /**
         * upozorní odebíratele na změnu rovnice
         */
        void notifyEquationObserver();

        /**
         * Jedná se o znak čísla tedy číslici nebo i
         */
        bool isNumberSymbol(char &symbol);

        /**
         * zpracuje příchozí Lexém
         * @param lex
         */
        void pushLex(Lex *lex);
    };


}

#endif //FIT_IVS_PROJECT2_EQUATION_H
