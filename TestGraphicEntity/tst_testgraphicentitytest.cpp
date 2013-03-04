#include <QString>
#include <QtTest>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "../graphicentity.h"
#include "../entity.h"

class TestGraphicEntityTest : public QObject
{
    Q_OBJECT
    
public:
    TestGraphicEntityTest();
    
private Q_SLOTS:
    void show();
    void show_data();
};

TestGraphicEntityTest::TestGraphicEntityTest()
{
}

void TestGraphicEntityTest::show()
{
    QFETCH(qreal, width);

    QGraphicsScene scene(0, 0, 1000,1000);
    QGraphicsView view(&scene);

    Entity ent(
                "MyEntity"
                ,nullptr
                ,QList<Entity*>()
                ,QList<UniqueConstraint*>()
                );

    ent.addProperty(new Property("name",Type("CHAR")));
    ent.addProperty(new Property("address",Type("CHAR")));
    ent.addProperty(new Property("e-mail",Type("CHAR")));
    ent.addProperty(new Property("phone",Type("CHAR")));

    GraphicEntity entity(&ent,200,200,width);
    scene.addItem(&entity);
    view.setGeometry(50,50,888,600);
    view.show();

    QTest::qWait(50000);
}

void TestGraphicEntityTest::show_data() {
    QTest::addColumn<qreal>("width");

    QTest::newRow("100") << (qreal) 100;

}

QTEST_MAIN(TestGraphicEntityTest)

#include "tst_testgraphicentitytest.moc"
