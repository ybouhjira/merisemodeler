#-------------------------------------------------
#
# Project created by QtCreator 2013-02-23T18:51:46
#
#-------------------------------------------------

QT       += testlib widgets
CONFIG += c++11

TARGET = tst_testgraphicentity
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_testgraphicentity.cpp \
    ../graphicentity.cpp \
    ../entity.cpp \
    ../association.cpp \
    ../cardinality.cpp \
    ../enumtype.cpp \
    ../identifier.cpp \
    ../item.cpp \
    ../mainwindow.cpp \
    ../maxsizetype.cpp \
    ../mcdui.cpp \
    ../modelui.cpp \
    ../multipropertyconstraint.cpp \
    ../numeriquetype.cpp \
    ../property.cpp \
    ../resizehandler.cpp \
    ../type.cpp \
    ../uniqueconstraint.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../graphicentity.h \
    ../entity.h \
    ../association.h \
    ../cardinality.h \
    ../enumtype.h \
    ../identifier.h \
    ../item.h \
    ../mainwindow.h \
    ../maxsizetype.h \
    ../mcdui.h \
    ../modelui.h \
    ../multipropertyconstraint.h \
    ../numeriquetype.h \
    ../property.h \
    ../resizehandler.h \
    ../type.h \
    ../uniqueconstraint.h
