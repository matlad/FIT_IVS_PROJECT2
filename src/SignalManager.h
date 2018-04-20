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

#include "BackendManager.cpp"

class SignalManager : public QObject
{
    Q_OBJECT
public:
    BackendManager backendManager;

    explicit SignalManager(QObject *parent = 0);

    Q_INVOKABLE void onButtonClick(const QString &value);
};

#endif // SIGNALMANAGER_H
