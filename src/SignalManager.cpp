/**
 * @file     SignalManager.cpp
 * @encoding UTF-8
 * @date     18.4.18
 * @author   Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */

#include <iostream>
#include "SignalManager.h"

SignalManager::SignalManager(QObject *parent) : QObject(parent), equation(lexicalAnalyzer, &interpret)
{
    lexicalAnalyzer.registrLexCallback(&interpret);
    interpret.registrResultCallback(this);
    equation.registrEquationObserver(this);
    strEquation.str("0");
}

void SignalManager::onEquationChange()
{
    strEquation.str("");
    strEquation << equation;
}

void SignalManager::onError(InterpretException exception)
{
    error = new InterpretException(exception);
}

void SignalManager::onResultChange(team22::Math::Number result)
{
    this->result = result;
}

SignalManager::~SignalManager()
{
    delete error;
}

void SignalManager::onButtonClick(const QString &value)
{
	string convertedValue = value.toUtf8().constData();

	if (convertedValue == "H")
	{
		/*
		QWidget window;
		window.resize(300, 300);
		window.show();
		window.setWindowTitle(
					QApplication::translate("toplevel", "Nápověda"));
*/
	}
	else
	{
		try
		{
			for (unsigned int i = 0; i < convertedValue.length(); i++)
			{
				equation.pushSymbol(convertedValue[i]);
			}
		}
		catch (LexicalAnalyzerException e)
		{
             //TODO zobrazit chybu
		}
	}
}

QString SignalManager::getEquation()
{
    return QString::fromStdString(strEquation.str());
}

QString SignalManager::getResult()
{
    std::ostringstream stream;
    stream << result;

    return QString::fromStdString(stream.str());
}
