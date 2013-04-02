#include "exporterfactory.h"
#include "exporterfactory.h"
#include "pdfsceneexporter.h"
#include "svgsceneexporter.h"
#include "command/remove/unsupporteditemexception.h"

using namespace Exporter;

SceneExporter* ExporterFactory::create(QString const& type) {
    if(type.toLower().contains("pdf"))
        return new PdfSceneExporter();
    else if(type.toLower().contains("svg"))
        return new SvgSceneExporter();
    else
        Q_ASSERT(false);
}
