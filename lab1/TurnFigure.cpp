#include "TurnFigure.h"

double DeltaCos(double angle)
{
    return cos(angle * M_PI / 180);
}

double DeltaSin(double angle)
{
    return sin(angle * M_PI / 180);
}

void XTurnPoint(point &dot, double angle)
{
    double cosAngle = DeltaCos(angle);
    double sinAngle = DeltaSin(angle);

    dot.y = dot.y + cosAngle + dot.z * sinAngle;
    dot.z = -dot.y * sinAngle + dot.z * cosAngle;
}

void YTurnPoint(point &dot, double angle)
{
    double cosAngle = DeltaCos(angle);
    double sinAngle = DeltaSin(angle);

    dot.x = dot.x * cosAngle + dot.z * sinAngle;
    dot.z = -dot.x * sinAngle + dot.z * cosAngle;
}

void ZTurnPoint(point &dot, double angle)
{
    double cosAngle = DeltaCos(angle);
    double sinAngle = DeltaSin(angle);

    dot.x = dot.x * cosAngle + dot.y * sinAngle;
    dot.y = -dot.x * sinAngle + dot.y * cosAngle;
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
