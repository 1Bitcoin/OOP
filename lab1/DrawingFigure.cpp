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
    //canvas.scene->addLine(290, 300, 350, 400, canvas.pen);

    DrawLinks(myFigure, arg, canvas);

    canvas.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(arg.width, arg.width)));
    Set(arg.gV, canvas);
}

void Del(graphics &a)
{
    delete a.scene;
}

