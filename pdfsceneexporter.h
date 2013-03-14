#ifndef PDFSCENEEXPORTER_H
#define PDFSCENEEXPORTER_H

#include "graphicssceneexporter.h"

class PdfSceneExporter : public GraphicsSceneExporter
{
public:

    /**
     * @reimp
     */
    void exportScene(QGraphicsScene *scene, const QString &fileName) override;

};

#endif // PDFSCENEEXPORTER_H
