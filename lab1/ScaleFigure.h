#ifndef SCALEFIGURE_H
#define SCALEFIGURE_H

#include "ErrorMessages.h"
#include "InputCoords.h"

struct scale
{
    double kx;
    double ky;
    double kz;
};

int ScalePointsArray(figure myFigure, scale coeff);
void ScalePoint(point &structPoint, scale coeff);
int ScaleFigure(figure &myFigure, scale value);

#endif // SCALEFIGURE_H
