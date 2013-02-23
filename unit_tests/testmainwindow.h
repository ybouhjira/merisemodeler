#ifndef TEST1_H
#define TEST1_H

#include "AutoTest.h"

class TestMainWindow : public QObject
{
    Q_OBJECT

private slots:
    void getInstance();
};

DECLARE_TEST(TestMainWindow)

#endif // TEST1_H
