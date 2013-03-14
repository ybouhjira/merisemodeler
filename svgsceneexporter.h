#ifndef SVGSCENEEXPORTER_H
#define SVGSCENEEXPORTER_H

#include "graphicssceneexporter.h"

class SvgSceneExporter : public GraphicsSceneExporter
{
public:
    void exportScene(QGraphicsScene* scene, QString const& fileName) override;
};

#endif // SVGSCENEEXPORTER_H
