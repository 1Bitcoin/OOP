#ifndef TURNFIGURE_H
#define TURNFIGURE_H

#include <cstdio>
#include <math.h>
#include "CodeErrors.h"
#include "InputCoords.h"
#include "DrawingFigure.h"

struct turn
{
    int ox;
    int oy;
    int oz;
};

double DeltaCos(double angle);
double DeltaSin(double angle);
void XTurnPoint(point &dot, double angle);
void YTurnPoint(point &dot, double angle);
void ZTurnPoint(point &dot, double angle);
int TurnPointsArray(figure myFigure, turn coeff);

#endif // TURNFIGURE_H
