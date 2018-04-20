#-------------------------------------------------
#
# Project created by QtCreator 2018-03-09T10:36:19
#
#-------------------------------------------------

QT_VERSION = 5

QT       += core gui
QT       += qml
QT       += quick

CONFIG += console
CONFIG += c++17

QMAKE_CXXFLAGS += -std=c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    LexicalAnalyzer.cpp \
    Lex.cpp \
    Equation.cpp \
    Interpret.cpp \
    math/Number.cpp \
    SignalManager.cpp

HEADERS += \
    ResultObserver.h \
    LexIdentificationObserver.h \
    LexicalAnalyzerException.h \
    LexicalAnalyzer.h \
    LexException.h \
    Lex.h \
    InterpretException.h \
    Interpret.h \
    EquationObserver.h \
    Equation.h \
    math/Number.h \
    math/UndefinedException.h \
    SignalManager.h

FORMS +=

DISTFILES += \
    main.qml \
    constants.js \
    Button.qml \
    backspace1.png \
    backspace2.png

RESOURCES += \
    qml.qrc
