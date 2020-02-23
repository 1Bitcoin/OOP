#ifndef MOVEFIGURE_H
#define MOVEFIGURE_H

#include <cstdio>
#include <math.h>
#include "CodeErrors.h"
#include "InputCoords.h"
#include "DrawingFigure.h"

struct move
{
    int dx;
    int dy;
    int dz;
};

int MovePointsArray(figure myFigure, move coeff);
void MovePoint(point &structPoint, move coeff);

#endif // MOVEFIGURE_H
