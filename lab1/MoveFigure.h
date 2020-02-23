#ifndef MOVEFIGURE_H
#define MOVEFIGURE_H

#include <cstdio>
#include <math.h>
#include "CodeErrors.h"
#include "InputCoords.h"
#include "QtForDrawing.h"

struct move
{
    double dx;
    double dy;
    double dz;
};

int MovePointsArray(figure myFigure, move coeff);
void MovePoint(point &structPoint, move coeff);

#endif // MOVEFIGURE_H
