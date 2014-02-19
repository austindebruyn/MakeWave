#-------------------------------------------------
#
# Project created by QtCreator 2014-01-31T00:57:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MakeWave
TEMPLATE = app


SOURCES += main.cpp\
        makewave.cpp \
    tunenote.cpp \
    write_headers.cpp

HEADERS  += makewave.h \
    tunenote.h \
    write_headers.h

FORMS    += makewave.ui
