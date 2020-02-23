#include "TurnFigure.h"

double DeltaCos(double angle)
{
    return cos(angle * M_PI / 180);
}

double DeltaSin(double angle)
{
    return sin(angle * M_PI / 180);
}

void XTurnPoint(point &structPoint, double angle)
{
    double cosAngle = DeltaCos(angle);
    double sinAngle = DeltaSin(angle);

    structPoint.y = structPoint.y + cosAngle + structPoint.z * sinAngle;
    structPoint.z = -structPoint.y * sinAngle + structPoint.z * cosAngle;
}

void YTurnPoint(point &structPoint, double angle)
{
    double cosAngle = DeltaCos(angle);
    double sinAngle = DeltaSin(angle);

    structPoint.x = structPoint.x * cosAngle + structPoint.z * sinAngle;
    structPoint.z = -structPoint.x * sinAngle + structPoint.z * cosAngle;
}

void ZTurnPoint(point &structPoint, double angle)
{
    double cosAngle = DeltaCos(angle);
    double sinAngle = DeltaSin(angle);

    structPoint.x = structPoint.x * cosAngle + structPoint.y * sinAngle;
    structPoint.y = -structPoint.x * sinAngle + structPoint.y * cosAngle;
}

int TurnPointsArray(figure myFigure, turn coeff)
{
    int CodeError = OK;
    if(myFigure.points.arrayStructpoints)
    {
        for(int i = 0; i < myFigure.points.amountDots; i++)
        {
            XTurnPoint(myFigure.points.arrayStructpoints[i], coeff.ox);
            YTurnPoint(myFigure.points.arrayStructpoints[i], coeff.oy);
            ZTurnPoint(myFigure.points.arrayStructpoints[i], coeff.oz);
        }
    }
    else
    {
        CodeError = ERROR_EMPTY;
    }
    return CodeError;
}
