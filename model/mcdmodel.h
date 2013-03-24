#ifndef MCDMODEL_H
#define MCDMODEL_H

#include "namespace.h"
#include "logic/namespace.h"

// Qt
#include <QObject>
#include <QList>

/**
 * @brief La classe du modèle conceptuel de donnée Merise
 */
class Model::McdModel : public QObject
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

public slots:
    /**
     * @brief items
     * @return List des élements
     */
    QList<Logic::Item*> items() const;

    /**
     * @brief Ajoute une entité ou association au model
     * @param item Element à ajouter
     */
    void addItem(Logic::Item* item);

    /**
     * @brief Supprimer un element du model
     * @param item Element à supprimer
     */
    void removeItem(Logic::Item* item);

    /**
     * @brief Supprimer un element de la liste
     * @param index Indice de l'element à supprimer
     */
    void removeItem(int index);

signals:
    /**
     * @brief Emit lors de l'ajout d'un element
     */
    void itemAdded(Logic::Item* item);

    /**
     * @brief Emit lors de la supression d'un element
     */
    void itemRemoved(int index);

    // ATTRIBUTS
private:

    /**
     * @brief Les entités et les Associations
     */
    QList<Logic::Item*> m_items;

};

#endif // MCDMODEL_H
