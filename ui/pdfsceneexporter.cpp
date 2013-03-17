#include "pdfsceneexporter.h"

#include <QScopedPointer>
#include <QPdfWriter>
#include <QRegExp>
#include <QGraphicsScene>
#include <QPainter>

void Ui::PdfSceneExporter::exportScene
(QGraphicsScene *scene, const QString &fileName) {

    QSizeF sizeF = scene->itemsBoundingRect().size();

    // Adding the extension to the fileName
    QString fileNameCopy = fileName;
    QRegExp regexp("*.pdf");
    regexp.setPatternSyntax(QRegExp::Wildcard);
    if(!regexp.exactMatch(fileName))
        fileNameCopy.append(".pdf");

    // Setting up the QPaintDevice
    QPdfWriter pdfWriter(fileNameCopy);
    pdfWriter.setPageSizeMM(sizeF);

    //painting on the device
    QPainter painter(&pdfWriter);
    scene->render(&painter);
    painter.end();
}
