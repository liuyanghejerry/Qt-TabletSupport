#-------------------------------------------------
#
# Project created by QtCreator 2012-10-19T23:35:51
#
#-------------------------------------------------

QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PainterTest
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        widget.cpp \
    ../tabletsupport.cpp

HEADERS  += widget.h \
    ../tabletsupport.h \
    ../wintabapi.h \
    ../wintab.h \
    ../pktdef.h \
