#include "AutoTest.h"
#include <QDebug>

#if 0
TEST_MAIN
#else

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AutoTest::run(argc, argv);
    return app.exec();
}

#endif
