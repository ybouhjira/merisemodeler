#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "../graphicroundedrectobject.h"

class TestGraphicRoundedRectObject : public QObject
{
    Q_OBJECT

public:
    TestGraphicRoundedRectObject();

private Q_SLOTS:
    void paint();
    void paint_data();
};

TestGraphicRoundedRectObject::TestGraphicRoundedRectObject()
{
}

void TestGraphicRoundedRectObject::paint()
{
    QFETCH(qreal, radius);
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.resize(600,400);
    scene.addItem(new GraphicRoundedRectObject(0, 0, 400, 150, radius));
    view.setRenderHint(QPainter::Antialiasing, true);
    //qDebug("\n=========================================================\n"
    //       " PAINTING TEST FOR GraphicRoundedRectObject with radius %f \n"
    //       "=========================================================\n",
    //       radius);
    view.show();
    QTest::qWait(1000);
}

void TestGraphicRoundedRectObject::paint_data()
{
    QTest::addColumn<qreal>("radius");
    for(int i=0; i<100; i+=10){
        QTest::newRow(QString::number(i).toStdString().c_str()) << (qreal) i;
    }
}

QTEST_MAIN(TestGraphicRoundedRectObject)

#include "tst_testgraphicroundedrectobjecttest.moc"
