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
include(ui/ui.pri)

RESOURCES += \
    ressourceFile.qrc

SOURCES += \
    main.cpp
