#ifndef MCDMODEL_H
#define MCDMODEL_H

class Item;
class McdGraphicsScene;
class Entity;
class Association;

// Qt
#include <QObject>
#include <QList>

/**
 * @brief La classe du modèle conceptuel de donnée Merise
 */
class McdModel : public QObject
{
    Q_OBJECT
    //METHODES
public:
    /**
     * @brief Constructeur
     * @param parent Object parent
     */
    explicit McdModel(QObject *parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~McdModel();

    /**
     * @brief Accesseur
     * @return
     */
    McdGraphicsScene* scene() const;

public slots:
    /**
     * @brief items
     * @return List des élements
     */
    QList<Item*> items() const;

    /**
     * @brief Ajoute une entité ou association au model
     * @param item Element à ajouter
     */
    void addItem(Item* item);

    /**
     * @brief Supprimer un element du model
     * @param item Element à supprimer
     */
    void removeItem(Item* item);

    /**
     * @brief Supprimer un element du model
     * @param index Indice de l'element à supprimer
     */
    void removeItem(int index);

    /**
     * @brief Crée une nouvelle entité et l'ajoute au model.
     * cette entité sera nommée Entity, si le model contient un elemnt du
     * meme nom. Alors un siffix numerique sera ajouté au nom de l'entité,
     * exemple : Entity1, Entity2, ... etc
     * @return L'entité creée
     */
    Entity* createEntity();

    /**
     * @brief Crée une association nommée Association et l'ajoute au model.
     * si ce nom existe déja une suffix numérique sera ajouté.
     * @param first Entité liée avec cette association
     * @param second Entité liée avec cette association
     * @return L'association creée
     */
    Association* createAssociation(Entity* first, Entity* second);

signals:
    /**
     * @brief Emit lors de l'ajout d'un element
     */
    void itemAdded(Item* item);

    /**
     * @brief Emit lors de la supression d'un element
     */
    void itemRemoved(int index);

    // ATTRIBUTS
private:

    /**
     * @brief Les entités et les Associations
     */
    QList<Item*> m_items;

    /**
     * @brief Respresentation graphique du Model MCD
     * Cette attribut est en lecture seul, il n'a pas de mutateur
     */
    McdGraphicsScene *m_scene;
};

#endif // MCDMODEL_H
