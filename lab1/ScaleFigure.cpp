#include "ScaleFigure.h"

void ScalePoint(point &structPoint, scale value)
{
    structPoint.x *= value.kx;
    structPoint.y *= value.ky;
    structPoint.z *= value.kz;
}

int ScalePointsArray(figure myFigure, scale value)
{
    int codeError = OK;

    if (myFigure.points.arrayStructpoints)
        for (int i = 0; i < myFigure.points.amountDots; i++)
            ScalePoint(myFigure.points.arrayStructpoints[i], value);
    else
        codeError = ERROR_EMPTY;

    return codeError;
}

int ScaleFigure(figure &myFigure, scale value)
{
    return ScalePointsArray(myFigure, value);
}

