#include "testmainwindow.h"
#include "../mainwindow.h"

void TestMainWindow::getInstance() {
    QCOMPARE(MainWindow::getInstance(), MainWindow::getInstance());
}
