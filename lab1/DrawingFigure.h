#ifndef DRAWINGFIGURE_H
#define DRAWINGFIGURE_H

#include "QGraphicsView"
#include "InputCoords.h"

struct draw
{
    QGraphicsView *gV;
    int height;
    int width;
};

struct graphics
{
    QGraphicsScene *scene;
    QPen pen;
};

void Del(graphics &a);
void DrawFigure(figure myFigure, draw arg);
void Set(QGraphicsView *gV, graphics &a);
void InitGraph(graphics &a, QGraphicsView *gV);

#endif // DRAWINGFIGURE_H
