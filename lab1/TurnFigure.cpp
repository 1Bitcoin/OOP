#include "TurnFigure.h"

double RadianCos(double angle)
{
    return cos(angle * M_PI / 180);
}

double RadianSin(double angle)
{
    return sin(angle * M_PI / 180);
}

void TurnOX(point &structPoint, double angle)
{
    double cosAngle = RadianCos(angle);
    double sinAngle = RadianSin(angle);

    structPoint.y = structPoint.y + cosAngle + structPoint.z * sinAngle;
    structPoint.z = -structPoint.y * sinAngle + structPoint.z * cosAngle;
}

void TurnOY(point &structPoint, double angle)
{
    double cosAngle = RadianCos(angle);
    double sinAngle = RadianSin(angle);

    structPoint.x = structPoint.x * cosAngle + structPoint.z * sinAngle;
    structPoint.z = -structPoint.x * sinAngle + structPoint.z * cosAngle;
}

void TurnOZ(point &structPoint, double angle)
{
    double cosAngle = RadianCos(angle);
    double sinAngle = RadianSin(angle);

    structPoint.x = structPoint.x * cosAngle + structPoint.y * sinAngle;
    structPoint.y = -structPoint.x * sinAngle + structPoint.y * cosAngle;
}

int TurnPointsArray(figure myFigure, turn coeff)
{
    int codeError = OK;

    if (myFigure.points.arrayStructpoints)
    {
        for (int i = 0; i < myFigure.points.amountDots; i++)
        {
            TurnOX(myFigure.points.arrayStructpoints[i], coeff.ox);
            TurnOY(myFigure.points.arrayStructpoints[i], coeff.oy);
            TurnOZ(myFigure.points.arrayStructpoints[i], coeff.oz);
        }
    }
    else
        codeError = ERROR_EMPTY;

    return codeError;
}
