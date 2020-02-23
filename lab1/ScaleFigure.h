#ifndef SCALEFIGURE_H
#define SCALEFIGURE_H

#include <cstdio>
#include <math.h>
#include "CodeErrors.h"
#include "InputCoords.h"
#include "DrawingFigure.h"

struct scale
{
    double kx;
    double ky;
    double kz;
};

int ScalePointsArray(figure myFigure, scale coeff);
void ScalePoint(point &structPoint, scale coeff);

#endif // SCALEFIGURE_H
