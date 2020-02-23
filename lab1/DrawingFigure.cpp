#include <cstdio>
#include "mainwindow.h"
#include "InputCoords.h"
#include "CodeErrors.h"
#include "WorkPoints.h"
#include "DrawingFigure.h"

void InitGraph(graphics &a, QGraphicsView *gV)
{
    a.scene = new QGraphicsScene(gV);
    a.pen = QPen(Qt::black);
}

void Set(QGraphicsView *gV, graphics &a)
{
    QGraphicsScene *prev = gV->scene();
    delete prev;
    gV->setScene(a.scene);
}

void DrawFigure(figure myFigure, draw arg)
{
    graphics canvas;

    InitGraph(canvas, arg.gV);
    DrawLinks(myFigure, arg, canvas);

    Set(arg.gV, canvas);
}
