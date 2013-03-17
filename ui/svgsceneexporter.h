#ifndef SVGSCENEEXPORTER_H
#define SVGSCENEEXPORTER_H

#include "graphicssceneexporter.h"

class Ui::SvgSceneExporter : public Ui::SceneExporter
{
public:
    void exportScene(QGraphicsScene* scene, QString const& fileName) override;
};

#endif // SVGSCENEEXPORTER_H
