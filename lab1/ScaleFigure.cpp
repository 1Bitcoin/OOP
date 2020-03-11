#include "ScaleFigure.h"

void ScalePoint(point &structPoint, scale &value)
{
    structPoint.x *= value.kx;
    structPoint.y *= value.ky;
    structPoint.z *= value.kz;
}

int ScalePointsArray(point *arrayStructpoints, int amountDots, scale &value)
{
    int codeError = OK;

    if (arrayStructpoints)
        for (int i = 0; i < amountDots; i++)
            ScalePoint(arrayStructpoints[i], value);
    else
        codeError = ERROR_EMPTY;

    return codeError;
}

int ScaleFigure(figure &myFigure, scale &value)
{
    return ScalePointsArray(myFigure.points.arrayStructpoints, myFigure.points.amountDots, value);
}

