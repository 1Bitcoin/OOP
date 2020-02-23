#ifndef TURNFIGURE_H
#define TURNFIGURE_H

#include <cstdio>
#include <math.h>
#include "CodeErrors.h"
#include "InputCoords.h"
#include "QtForDrawing.h"

struct turn
{
    double ox;
    double oy;
    double oz;
};

double DeltaCos(double angle);
double DeltaSin(double angle);
void XTurnPoint(point &structPoint, double angle);
void YTurnPoint(point &structPoint, double angle);
void ZTurnPoint(point &structPoint, double angle);
int TurnPointsArray(figure myFigure, turn coeff);

#endif // TURNFIGURE_H
