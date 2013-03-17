#include "testmcdui.h"
#include "../mcdui.h"

void TestMcdUi::mcdUi() {
    McdUi *mcdUi = new McdUi;
    mcdUi->show();
    QTest::qWait(5000);

    QVERIFY(mcdUi->isVisible());
}
