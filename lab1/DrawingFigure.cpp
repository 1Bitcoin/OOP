#include <cstdio>
#include "mainwindow.h"
#include "InputCoords.h"
#include "CodeErrors.h"
#include "WorkPoints.h"
#include "DrawingFigure.h"

void InitGraph(graphics &canvas, QGraphicsView *graphicsView)
{
    canvas.scene = new QGraphicsScene(graphicsView);
    canvas.pen = QPen(Qt::black);
}

void Set(QGraphicsView *graphicsView, graphics &canvas)
{
    QGraphicsScene *prev = graphicsView->scene();
    delete prev;
    graphicsView->setScene(canvas.scene);
}

void DrawFigure(figure myFigure, draw arg)
{
    graphics canvas;

    InitGraph(canvas, arg.graphicsView);
    DrawLinks(myFigure, arg, canvas);

    Set(arg.graphicsView, canvas);
}
