#-------------------------------------------------
#
# Project created by QtCreator 2013-01-21T20:32:10
#
#-------------------------------------------------

QT       += core widgets svg
CONFIG += c++11

TARGET = MeriseModeler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        mcdui.cpp \
        modelui.cpp \
    uniqueconstraint.cpp \
    type.cpp \
    property.cpp \
    numeriquetype.cpp \
    maxsizetype.cpp \
    item.cpp \
    enumtype.cpp \
    entity.cpp \
    association.cpp \
    graphicentity.cpp \
    graphicobject.cpp \
    graphicroundedrectobject.cpp \
    graphicassociation.cpp \
    graphicstyle.cpp \
    graphicresizableroundedrectobject.cpp \
    mcdmodel.cpp \
    mcdgraphicsscene.cpp \
    modelstabwidget.cpp \
    associationlink.cpp \
    graphicarrow.cpp \
    graphiccardinalityarrow.cpp \
    graphiccardinaltytextitem.cpp \
    graphicinheritencearrowobject.cpp \
    pdfsceneexporter.cpp \
    graphicssceneexporter.cpp \
    svgsceneexporter.cpp

HEADERS  += mainwindow.h \
    modelui.h \
    mcdui.h \
    uniqueconstraint.h \
    type.h \
    property.h \
    numeriquetype.h \
    maxsizetype.h \
    item.h \
    enumtype.h \
    entity.h \
    association.h \
    graphicentity.h \
    graphicobject.h \
    graphicroundedrectobject.h \
    graphicassociation.h \
    graphicstyle.h \
    graphicresizableroundedrectobject.h \
    mcdmodel.h \
    mcdgraphicsscene.h \
    modelstabwidget.h \
    associationlink.h \
    graphicarrow.h \
    graphiccardinalityarrow.h \
    graphiccardinaltytextitem.h \
    graphicinheritencearrowobject.h \
    graphicssceneexporter.h \
    pdfsceneexporter.h \
    svgsceneexporter.h

RESOURCES += \
    ressourceFile.qrc

