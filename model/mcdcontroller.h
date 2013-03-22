#ifndef MCDCONTROLLER_H
#define MCDCONTROLLER_H

#include "namespace.h"

// Qt
#include <QObject>
class QUndoStack;

/**
 * @brief Controleur du modèle Mcd::McdModel
 */
class Model::McdController : public QObject
{
    // METHODES
    Q_OBJECT
public:
    /**
     * @brief McdController
     * @param mcd
     * @param parent
     */
    explicit McdController(
            Model::McdModel* mcd,
            QObject *parent = nullptr);

    /**
     * @brief Destructeur
     */
    virtual ~McdController();

public slots:

    void pushCommand

    // PRIVATES
private:
    /**
     * @brief Pile des commandes appliqué sur le modèle
     */
    QUndoStack *m_commandsStack;

    /**
     * @brief modèle cible
     */
    Model::McdModel* m_mcd;
    
};

#endif // MCDCONTROLLER_H
