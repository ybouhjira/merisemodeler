# -------------------------------------------------
# Project created by QtCreator 2010-04-28T20:25:30
# -------------------------------------------------

QT += testlib widgets

QT -= gui

TARGET = Test

CONFIG += console c++11

CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    testmainwindow.cpp \
    ../modelui.cpp \
    ../mcdui.cpp \
    ../mainwindow.cpp \
    testmcdui.cpp

HEADERS += AutoTest.h \
    testmainwindow.h \
    ../modelui.h \
    ../mcdui.h \
    ../mainwindow.h \
    testmcdui.h
