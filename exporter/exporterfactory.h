#ifndef EXPORTERFACTORY_H
#define EXPORTERFACTORY_H

#include "namespace.h"
#include <memory>
#include <QString>

class ExporterFactory
{
public:
    static Exporter::SceneExporter* create(QString const& type);
};

#endif // EXPORTERFACTORY_H
