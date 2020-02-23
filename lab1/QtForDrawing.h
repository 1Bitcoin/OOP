#ifndef QTFORDRAWING_H
#define QTFORDRAWING_H

#include "QGraphicsView"
#include "InputCoords.h"

struct draw
{
    QGraphicsView *graphView;
    int height;
    int width;
};

struct graphics
{
    QGraphicsScene *scene;
    QPen pen;
};

void Del(graphics &canvas);
void DrawFigure(figure myFigure, draw drawInfo);
void Set(QGraphicsView *graphView, graphics &canvas);
void InitGraph(graphics &canvas, QGraphicsView *graphView);

#endif // QTFORDRAWING_H
