#-------------------------------------------------
#
# Project created by QtCreator 2013-01-21T20:32:10
#
#-------------------------------------------------

QT       += core widgets svg
CONFIG += c++11

TARGET = MeriseModeler
TEMPLATE = app

include(logic/logic.pri)

SUBDIRS += logic

SOURCES += main.cpp\
        mainwindow.cpp \
        mcdui.cpp \
        modelui.cpp \
    graphicentity.cpp \
    graphicobject.cpp \
    graphicroundedrectobject.cpp \
    graphicassociation.cpp \
    graphicstyle.cpp \
    graphicresizableroundedrectobject.cpp \
    mcdmodel.cpp \
    mcdgraphicsscene.cpp \
    modelstabwidget.cpp \
    graphicarrow.cpp \
    graphiccardinalityarrow.cpp \
    graphiccardinaltytextitem.cpp \
    graphicinheritencearrowobject.cpp \
    pdfsceneexporter.cpp \
    graphicssceneexporter.cpp \
    svgsceneexporter.cpp \
    entityeditwidget.cpp \
    entitytablemodel.cpp

HEADERS  += mainwindow.h \
    modelui.h \
    mcdui.h \
    graphicentity.h \
    graphicobject.h \
    graphicroundedrectobject.h \
    graphicassociation.h \
    graphicstyle.h \
    graphicresizableroundedrectobject.h \
    mcdmodel.h \
    mcdgraphicsscene.h \
    modelstabwidget.h \
    graphicarrow.h \
    graphiccardinalityarrow.h \
    graphiccardinaltytextitem.h \
    graphicinheritencearrowobject.h \
    graphicssceneexporter.h \
    pdfsceneexporter.h \
    svgsceneexporter.h \
    entityeditwidget.h \
    entitytablemodel.h \

RESOURCES += \
    ressourceFile.qrc

