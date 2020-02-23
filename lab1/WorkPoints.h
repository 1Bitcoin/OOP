#ifndef WORKPOINTS_H
#define WORKPOINTS_H

#include <cstdio>
#include <math.h>
#include "CodeErrors.h"
#include "InputCoords.h"
#include "DrawingFigure.h"

struct coord_point
{
    double x;
    double y;
    double z;
};

int ReadCount(figure &myFigure, FILE *f);
coord_point GetDot(point *dots, int number);
coord_point PointTransform(coord_point dot, draw arg);
void DrawLinks(figure myFigure, draw arg, graphics a);
void AddLine(graphics a, int x1, int x2, int y1, int y2);
coord_point CalculationZ(coord_point dot);

#endif // WORKPOINTS_H
