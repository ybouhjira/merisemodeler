#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "../graphicresizehandel.h"

class TestGraphicResizeHandelTest : public QObject
{
    Q_OBJECT
    
public:
    TestGraphicResizeHandelTest();
    
private Q_SLOTS:
    void testCase1();
};

TestGraphicResizeHandelTest::TestGraphicResizeHandelTest()
{
}

void TestGraphicResizeHandelTest::testCase1()
{
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    scene.addItem(new GraphicResizeHandel);

    view.show();
    QTest::qWait(60000);
}

QTEST_MAIN(TestGraphicResizeHandelTest)

#include "tst_testgraphicresizehandeltest.moc"
