#ifndef PDFSCENEEXPORTER_H
#define PDFSCENEEXPORTER_H

#include "namespace.h"
#include "graphicssceneexporter.h"

class Exporter::PdfSceneExporter : public Exporter::SceneExporter
{
public:

    /**
     * @reimp
     */
    void exportScene(QGraphicsScene *scene, const QString &fileName) override;

};

#endif // PDFSCENEEXPORTER_H
