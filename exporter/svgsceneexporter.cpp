#include "svgsceneexporter.h"

#include <QSvgGenerator>
#include <QGraphicsScene>
#include <QPainter>

using namespace Exporter;

void SvgSceneExporter::exportScene(QGraphicsScene *scene, const QString &fileName)
{
    QSizeF sizeF = scene->itemsBoundingRect().size();

    // Adding the extension to the fileName
    QString fileNameCopy = fileName;
    QRegExp regexp("*.svg");
    regexp.setPatternSyntax(QRegExp::Wildcard);
    if(!regexp.exactMatch(fileName))
        fileNameCopy.append(".svg");

    // Setting up the QPaintDevice
    QSvgGenerator svgGen;
    svgGen.setFileName(fileName);
    svgGen.setSize(sizeF.toSize());
    svgGen.setTitle("");
    svgGen.setDescription("");

    //painting on the device
    QPainter painter(&svgGen);
    scene->render(&painter);
    painter.end();
}
