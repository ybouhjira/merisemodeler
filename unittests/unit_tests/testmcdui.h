#ifndef TESTMCDUI_H
#define TESTMCDUI_H

#include "AutoTest.h"

class TestMcdUi : public QObject
{
    Q_OBJECT
    
private slots:
    void mcdUi();
};

DECLARE_TEST(TestMcdUi)

#endif // TESTMCDUI_H
