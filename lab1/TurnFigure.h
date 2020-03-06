#ifndef TURNFIGURE_H
#define TURNFIGURE_H

#include <math.h>
#include "ErrorMessages.h"
#include "InputCoords.h"
#include "Figure.h"

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

int TurnPointsArray(point *arrayStructpoints, int amountDots, turn coeff);
int TurnFigure(figure &Myfigure, turn value);

#endif // TURNFIGURE_H
