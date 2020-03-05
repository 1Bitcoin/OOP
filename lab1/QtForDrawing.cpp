#include "QtForDrawing.h"
#include "WorkPoints.h"

void SceneInit(scene &canvas, graphView drawInfo)
{
    canvas.scene = new QGraphicsScene(drawInfo.graphView);
    canvas.pen = QPen(Qt::black);
}

void CanvasPlace(graphView drawInfo, scene &canvas)
{
    canvas.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(drawInfo.width, drawInfo.height)));
    QGraphicsScene *prev = drawInfo.graphView->scene();
    delete prev;
    drawInfo.graphView->setScene(canvas.scene);
}

void DrawFigure(figure myFigure, graphView drawInfo)
{
    scene canvas;

    SceneInit(canvas, drawInfo);
    DrawLinks(myFigure, drawInfo, canvas);
    CanvasPlace(drawInfo, canvas);
}
