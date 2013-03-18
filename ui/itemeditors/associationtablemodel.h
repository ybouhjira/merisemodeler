#ifndef ASSOCIATIONTABLEMODEL_H
#define ASSOCIATIONTABLEMODEL_H

#include "itemtablemodel.h"
#include "logic/namespace.h"
#include "logic/association.h"

class Ui::AssociationTableModel : public Ui::ItemTableModel
{
    // METHODES
public:
    /**
     * @brief Constructeur
     * @param association Association
     * @param parent QObject parent
     */
    explicit AssociationTableModel(
            Logic::Association *association = nullptr,
            QObject* parent = nullptr);

    Logic::Association* item() const;

public slots:
    /**
     * @brief Accesseur
     * @param assoc Association
     */
    void setAssociation(Logic::Association* assoc);

    // ATTRIBUTS
private:
    /**
     * @brief m_association
     */
    Logic::Association* m_association;
};

#endif // ASSOCIATIONTABLEMODEL_H
