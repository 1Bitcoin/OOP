#ifndef MOVEFIGURE_H
#define MOVEFIGURE_H

#include <math.h>
#include "ErrorMessages.h"
#include "LoadModel.h"
#include "InputCoords.h"

struct move
{
    double dx;
    double dy;
    double dz;
};

int MovePointsArray(point *arrayStructpoints, int amountDots, move value);
void MovePoint(point &structPoint, move coeff);
int MoveFigure(figure &myFigure, move value);

#endif // MOVEFIGURE_H
