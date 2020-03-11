#ifndef SCALEFIGURE_H
#define SCALEFIGURE_H

#include "ErrorMessages.h"
#include "InputCoords.h"
#include "Figure.h"

struct scale
{
    double kx;
    double ky;
    double kz;
};

int ScalePointsArray(point *arrayStructpoints, int amountDots, scale &value);
void ScalePoint(point &structPoint, scale &coeff);
int ScaleFigure(figure &myFigure, scale &value);

#endif // SCALEFIGURE_H
