#include "QtForDrawing.h"
#include "WorkPoints.h"

int SceneInit(scene &canvas, graphView &drawInfo)
{
    int codeError = OK;

    canvas.scene = new QGraphicsScene(drawInfo.graphView);
    if (!canvas.scene)
        codeError = ERROR_ALLOC_MEMORY;

    canvas.pen = QPen(Qt::black);

    return codeError;
}

void CanvasPlace(graphView &drawInfo, scene &canvas)
{
    canvas.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(drawInfo.width, drawInfo.height)));
    QGraphicsScene *prev = drawInfo.graphView->scene();
    delete prev;
    drawInfo.graphView->setScene(canvas.scene);
}

int DrawFigure(figure &myFigure, graphView &drawInfo)
{
    int codeError = OK;
    scene canvas;

    codeError = SceneInit(canvas, drawInfo);
    DrawLinks(myFigure.points, myFigure.links, drawInfo, canvas);
    CanvasPlace(drawInfo, canvas);

    return codeError;
}
