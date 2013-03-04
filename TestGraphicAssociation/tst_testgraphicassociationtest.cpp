#include <QString>
#include <QtTest>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "../graphicassociation.h"
#include "../association.h"
#include "../entity.h"
#include "../cardinality.h"

class TestGraphicAssociation : public QObject
{
    Q_OBJECT
    
public:
    TestGraphicAssociation();
    
private Q_SLOTS:
    void show();
    void show_data();
};

TestGraphicAssociation::TestGraphicAssociation()
{
}

void TestGraphicAssociation::show()
{
    QFETCH(qreal, width);

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);

    Association assoc("Manger",
                      new Cardinality(Cardinality::One, Cardinality::One),
                      nullptr,
                      nullptr);

    assoc.addProperty(new Property("name",Type("CHAR")));
    assoc.addProperty(new Property("address",Type("CHAR")));
    assoc.addProperty(new Property("e-mail",Type("CHAR")));
    assoc.addProperty(new Property("phone",Type("CHAR")));

    GraphicAssociation entity(&assoc, 0, 0, width);
    scene.addItem(&entity);
    view.setGeometry(10,10,1000,600);
    view.show();

    QTest::qWait(50000);
}

void TestGraphicAssociation::show_data() {
    QTest::addColumn<qreal>("width");

    QTest::newRow("100") << (qreal) 100;
}

QTEST_MAIN(TestGraphicAssociation)

#include "tst_testgraphicassociationtest.moc"
