#ifndef QTFORDRAWING_H
#define QTFORDRAWING_H

#include "QGraphicsView"
#include "InputCoords.h"

struct graphView
{
    QGraphicsView *graphView;
    int height;
    int width;
};

struct scene
{
    QGraphicsScene *scene;
    QPen pen;
};

void DrawFigure(figure myFigure, graphView drawInfo);
void Set(QGraphicsView *graphView, scene &canvas);
void InitGraph(scene &canvas, QGraphicsView *graphView);

#endif // QTFORDRAWING_H
