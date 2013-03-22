#ifndef SVGSCENEEXPORTER_H
#define SVGSCENEEXPORTER_H

#include "namespace.h"
#include "graphicssceneexporter.h"

class Exporter::SvgSceneExporter : public Exporter::SceneExporter
{
public:
    void exportScene(QGraphicsScene* scene, QString const& fileName) override;
};

#endif // SVGSCENEEXPORTER_H
