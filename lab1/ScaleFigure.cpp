#include "ScaleFigure.h"

void ScalePoint(point &structPoint, scale coeff)
{
    structPoint.x *= coeff.kx;
    structPoint.y *= coeff.ky;
    structPoint.z *= coeff.kz;
}

int ScalePointsArray(figure myFigure, scale coeff)
{
    int CodeError = OK;

    if (myFigure.points.arrayStructpoints)
    {
        for (int i = 0; i < myFigure.points.amountDots; i++)
            ScalePoint(myFigure.points.arrayStructpoints[i], coeff);
    }
    else
    {
        CodeError = ERROR_EMPTY;
    }

    return CodeError;
}
