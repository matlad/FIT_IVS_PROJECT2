/**
 * @file     SignalManager.cpp
 * @encoding UTF-8
 * @date     18.4.18
 * @author   Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */

#include <iostream>
#include "SignalManager.h"

SignalManager::SignalManager(QObject *parent) : QObject(parent)
{
}

void SignalManager::onButtonClick(const QString &value)
{
    string convertedValue = value.toUtf8().constData();

    //std::cout << convertedValue << std::endl;

    for (unsigned int i = 0; i < convertedValue.length(); i++)
    {
        backendManager.equation.pushSymbol(convertedValue[i]);
    }
}
