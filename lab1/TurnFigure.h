#ifndef TURNFIGURE_H
#define TURNFIGURE_H

#include <cstdio>
#include <math.h>
#include "ErrorMessages.h"
#include "InputCoords.h"
#include "QtForDrawing.h"

struct turn
{
    double ox;
    double oy;
    double oz;
};

double RadianCos(double angle);
double RadianSin(double angle);
void TurnOX(point &structPoint, double angle);
void TurnOY(point &structPoint, double angle);
void TurnOZ(point &structPoint, double angle);
int TurnPointsArray(figure myFigure, turn coeff);

#endif // TURNFIGURE_H
