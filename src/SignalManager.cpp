/**
 * @file     SignalManager.cpp
 * @encoding UTF-8
 * @date     18.4.18
 * @author   Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */

#include "SignalManager.h"

SignalManager::SignalManager()
{

}

void SignalManager::onButtonClick(const QString &value)
{
    string convertedValue = value.toUtf8().constData();

    for (unsigned int i = 0; i < convertedValue.length(); i++)
    {
        backendManager.equation.pushSymbol(convertedValue[i]);
    }
}

// #include "moc_SignalManager.cpp"
