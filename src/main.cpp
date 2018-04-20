/**
 * @file     main.cpp
 * @encoding UTF-8
 * @date     18.4.18
 * @author   Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickView>
#include <QObject>

#include "SignalManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qmlRegisterType<SignalManager>("cz.vutbr.fit.team22", 1, 0, "SignalManager");

    QQmlApplicationEngine engine(QUrl("qrc:///main.qml"));

    return a.exec();
}
