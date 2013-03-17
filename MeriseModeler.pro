#-------------------------------------------------
#
# Project created by QtCreator 2013-01-21T20:32:10
#
#-------------------------------------------------

QT       += core widgets svg
CONFIG += c++11
CONFIG += object_parallel_to_source

TARGET = MeriseModeler
TEMPLATE = app

include(logic/logic.pri)
include(graphic/graphic.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
        mcdui.cpp \
        modelui.cpp \
    mcdmodel.cpp \
    mcdgraphicsscene.cpp \
    modelstabwidget.cpp \
    pdfsceneexporter.cpp \
    svgsceneexporter.cpp \
    entityeditwidget.cpp \
    entitytablemodel.cpp \
    graphicssceneexporter.cpp

HEADERS  += mainwindow.h \
    modelui.h \
    mcdui.h \
    mcdmodel.h \
    mcdgraphicsscene.h \
    modelstabwidget.h \
    pdfsceneexporter.h \
    svgsceneexporter.h \
    entityeditwidget.h \
    entitytablemodel.h \
    graphicssceneexporter.h

RESOURCES += \
    ressourceFile.qrc

