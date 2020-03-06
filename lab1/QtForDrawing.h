#ifndef QTFORDRAWING_H
#define QTFORDRAWING_H

#include "QGraphicsView"
#include "InputCoords.h"
#include "Figure.h"

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

int DrawFigure(figure myFigure, graphView drawInfo);
void CanvasPlace(QGraphicsView *graphView, scene &canvas);
int SceneInit(scene &canvas, QGraphicsView *graphView);

#endif // QTFORDRAWING_H
