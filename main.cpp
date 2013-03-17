#include "ui/mainwindow.h"
#include <QApplication>
#include <QMenuBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow *w = Ui::MainWindow::getInstance();
    w->show();
    return a.exec();
}
