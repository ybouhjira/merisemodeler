#ifndef PDFSCENEEXPORTER_H
#define PDFSCENEEXPORTER_H

#include "namespace.h"
#include "graphicssceneexporter.h"

class Ui::PdfSceneExporter : public Ui::SceneExporter
{
public:

    /**
     * @reimp
     */
    void exportScene(QGraphicsScene *scene, const QString &fileName) override;

};

#endif // PDFSCENEEXPORTER_H
