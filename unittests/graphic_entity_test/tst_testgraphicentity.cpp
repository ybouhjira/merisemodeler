#include <QString>
#include <QtTest>

#include "../graphicentity.h"
#include "../entity.h"
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>

class TestGraphicEntity : public QObject
{
    Q_OBJECT
    
public:
    TestGraphicEntity();
    
private Q_SLOTS:
    void paint();
    void setEntity();
    void entity();
};

TestGraphicEntity::TestGraphicEntity()
{
}

void TestGraphicEntity::paint()
{
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(scene);
    Entity *entity = new Entity(
                "Employee",
                nullptr,
                QList<Entity*>(),
                QList<UniqueConstraint*>()
                );
    GraphicEntity *gEntity = new GraphicEntity(entity);
    scene->addItem(gEntity);


    view->show();
    auto response = QMessageBox::question(nullptr, "Test",
                          "est ce que vous voyez une entité dans la fenetre ?");
    QVERIFY2(response == QMessageBox::Yes, "Entite non affichee");
}

void TestGraphicEntity::setEntity() {
    Entity *entity = new Entity(
                "Employee",
                nullptr,
                QList<Entity*>(),
                QList<UniqueConstraint*>()
                );

    GraphicEntity *gEntity = new GraphicEntity(entity);

    Entity *newEntity = new Entity(
                "Employee",
                nullptr,
                QList<Entity*>(),
                QList<UniqueConstraint*>()
                );

    gEntity->setEntity(newEntity);
    QCOMPARE(gEntity->m_entity, newEntity);
}

void TestGraphicEntity::entity() {
    Entity *entity = new Entity(
                "Employee",
                nullptr,
                QList<Entity*>(),
                QList<UniqueConstraint*>()
                );

    GraphicEntity *gEntity = new GraphicEntity(entity);

    QCOMPARE(gEntity->entity(), entity);
}

QTEST_MAIN(TestGraphicEntity)

#include "tst_testgraphicentity.moc"
