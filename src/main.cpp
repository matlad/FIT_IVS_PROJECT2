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

    QQmlApplicationEngine engine(QUrl("qrc:///main.qml"));

    QQuickView view(QUrl::fromLocalFile("Button.qml"));
    QObject *button = (QObject *)view.rootObject();

    SignalManager signalManager;
    QObject::connect(button, SIGNAL(clicked(QString)), &signalManager, SLOT(onButtonClick(QString)));

    return a.exec();
}
