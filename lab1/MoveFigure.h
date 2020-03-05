#ifndef MOVEFIGURE_H
#define MOVEFIGURE_H

#include <math.h>
#include "ErrorMessages.h"
#include "InputCoords.h"

struct move
{
    double dx;
    double dy;
    double dz;
};

int MovePointsArray(figure myFigure, move coeff);
void MovePoint(point &structPoint, move coeff);
int MoveFigure(figure &myFigure, move value);

#endif // MOVEFIGURE_H
