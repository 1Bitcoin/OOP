#include <cstdio>
#include "mainwindow.h"
#include "InputCoords.h"
#include "CodeErrors.h"
#include "WorkPoints.h"
#include "QtForDrawing.h"

void InitGraph(graphics &canvas, QGraphicsView *graphView)
{
    canvas.scene = new QGraphicsScene(graphView);
    canvas.pen = QPen(Qt::black);
}

void Set(QGraphicsView *graphView, graphics &canvas)
{
    QGraphicsScene *prev = graphView->scene();
    delete prev;
    graphView->setScene(canvas.scene);
}

void DrawFigure(figure myFigure, draw drawInfo)
{
    graphics canvas;

    InitGraph(canvas, drawInfo.graphView);
    DrawLinks(myFigure, drawInfo, canvas);

    canvas.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(drawInfo.width, drawInfo.height)));
    Set(drawInfo.graphView, canvas);
}
