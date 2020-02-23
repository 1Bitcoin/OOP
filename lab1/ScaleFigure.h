#ifndef SCALEFIGURE_H
#define SCALEFIGURE_H

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

struct scale
{
    double kx;
    double ky;
    double kz;
};

struct turn
{
    int ox;
    int oy;
    int oz;
};

#endif // SCALEFIGURE_H
