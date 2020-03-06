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

int TurnPointsArray(point *arrayStructpoints, int amountDots, turn coeff)
{
    int codeError = OK;

    if (arrayStructpoints)
    {
        for (int i = 0; i < amountDots; i++)
        {
            TurnOX(arrayStructpoints[i], coeff.ox);
            TurnOY(arrayStructpoints[i], coeff.oy);
            TurnOZ(arrayStructpoints[i], coeff.oz);
        }
    }
    else
        codeError = ERROR_EMPTY;

    return codeError;
}

int TurnFigure(figure &Myfigure, turn value)
{
    return TurnPointsArray(Myfigure.points.arrayStructpoints, Myfigure.points.amountDots, value);
}
