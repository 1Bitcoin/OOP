#include "QtForDrawing.h"
#include "WorkPoints.h"

void InitGraph(scene &canvas, graphView drawInfo)
{
    canvas.scene = new QGraphicsScene(drawInfo.graphView);
    canvas.pen = QPen(Qt::black);
}

void Set(graphView drawInfo, scene &canvas)
{
    canvas.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(drawInfo.width, drawInfo.height)));
    QGraphicsScene *prev = drawInfo.graphView->scene();
    delete prev;
    drawInfo.graphView->setScene(canvas.scene);
}

void DrawFigure(figure myFigure, graphView drawInfo)
{
    scene canvas;

    InitGraph(canvas, drawInfo);
    DrawLinks(myFigure, drawInfo, canvas);
    Set(drawInfo, canvas);
}
