#include "MoveFigure.h"

void MovePoint(point &structPoint, move value)
{
    structPoint.x += value.dx;
    structPoint.y += value.dy;
    structPoint.z += value.dz;
}

int MovePointsArray(point *arrayStructpoints, int amountDots, move value)
{
    int codeError = OK;

    if (arrayStructpoints)
        for (int i = 0; i < amountDots; i++)
            MovePoint(arrayStructpoints[i], value);
    else
        codeError = ERROR_EMPTY;

    return codeError;
}

int MoveFigure(figure &myFigure, move value)
{
    return MovePointsArray(myFigure.points.arrayStructpoints, myFigure.points.amountDots, value);
}
