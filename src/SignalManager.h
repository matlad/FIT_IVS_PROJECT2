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

    Q_INVOKABLE void onButtonClick(const QString &value);
    void onEquationChange();
    void onError(InterpretException exception);
    void onResultChange(team22::Math::Number result);
    Q_INVOKABLE QString getEquation();
    Q_INVOKABLE QString getResult();
    Q_INVOKABLE void clearError();
    Q_INVOKABLE bool getError();
};

#endif // SIGNALMANAGER_H
