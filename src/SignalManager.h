/**
 * @file     SignalManager.h
 * @encoding UTF-8
 * @date     18.4.18
 * @author   Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */

#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include <QObject>
#include <string>

#include "Equation.h"
#include "math/Number.h"

using std::stringstream;
using std::string;

using namespace team22::Calc;
using team22::Math::Number;

class SignalManager : public QObject, ResultObserver, EquationObserver
{
    Q_OBJECT
public:
    Interpret interpret;
    LexicalAnalyzer lexicalAnalyzer;
    Equation equation;
    stringstream strEquation;
    InterpretException *error = nullptr;
    LexicalAnalyzerException *error2 = nullptr;
    Number result = {0};

    explicit SignalManager(QObject *parent = 0);
    ~SignalManager();

    /**
     * Voláno při stisku tlačítka v GUI. Předá znaky, tvořící hodnotu tlačítka, equation ke zpracování.
     * @param value řetězec tvořící hodnotu tlačítka
     */
    Q_INVOKABLE void onButtonClick(const QString &value);

    /**
     * Voláno při změně mezivýpočtu.
     */
    void onEquationChange();

    /**
     * Voláno při výskytu chyby ve výpočtu.
     * @param exception InterpretException
     */
    void onError(InterpretException exception);

    /**
     * Voláno při změně výsledku.
     * @param exception InterpretException
     */
    void onResultChange(team22::Math::Number result);

    /**
     * Vrátí současný mezivýsledek.
     */
    Q_INVOKABLE QString getEquation();

    /**
     * Vrátí současný výsledek.
     */
    Q_INVOKABLE QString getResult();

    /**
     * Odstraní uložený error.
     */
    Q_INVOKABLE void clearError();

    /**
     * Vrátí současný error.
     */
    Q_INVOKABLE bool getError();
};

#endif // SIGNALMANAGER_H
