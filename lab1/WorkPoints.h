#ifndef WORKPOINTS_H
#define WORKPOINTS_H

#include <cstdio>
#include <math.h>
#include "CodeErrors.h"
#include "InputCoords.h"
#include "QtForDrawing.h"

struct coordPoint
{
    double x;
    double y;
    double z;
};

int ReadCount(figure &myFigure, FILE *f);
coordPoint GetDot(point *arrayPoints, int number);
coordPoint PointTransform(coordPoint structPoint, draw drawInfo);
void DrawLinks(figure myFigure, draw drawInfo, graphics canvas);
void AddLine(graphics a, int x1, int x2, int y1, int y2);

#endif // WORKPOINTS_H