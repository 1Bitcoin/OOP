#include <cstdio>
#include "mainwindow.h"
#include "InputCoords.h"
#include "ErrorMessages.h"
#include "WorkPoints.h"
#include "QtForDrawing.h"

void InitGraph(graphics &canvas, draw drawInfo)
{
    canvas.scene = new QGraphicsScene(drawInfo.graphView);
    canvas.pen = QPen(Qt::black);
}

void Set(draw drawInfo, graphics &canvas)
{
    canvas.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(drawInfo.width, drawInfo.height)));
    QGraphicsScene *prev = drawInfo.graphView->scene();
    delete prev;
    drawInfo.graphView->setScene(canvas.scene);
}

void DrawFigure(figure myFigure, draw drawInfo)
{
    graphics canvas;

    InitGraph(canvas, drawInfo);
    DrawLinks(myFigure, drawInfo, canvas);
    Set(drawInfo, canvas);
}
