#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T11:16:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Huffman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    huffman.cpp

HEADERS  += mainwindow.h \
    huffman.h \
    huffnode.h \
    leafnode.h \
    intnode.h \
    heap.h

FORMS    += mainwindow.ui
