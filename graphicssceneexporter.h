#ifndef MODELEXPORTER_H
#define MODELEXPORTER_H

class QGraphicsScene;
class QString;

/**
 * @brief Une iterface définissant une méthode d'exportation d'un modéle
 */
class GraphicsSceneExporter
{
public:

    /**
     * @brief Exporte une QGraphicsScene
     * @param scene Instance de QGraphicsScene à exporter
     * @param fileName nom du fichier
     */
    virtual void exportScene(QGraphicsScene* scene, QString const& fileName) = 0;

    /**
     * @brief Destructeur
     */
    virtual ~GraphicsSceneExporter() ;
};

#endif // MODELEXPORTER_H
