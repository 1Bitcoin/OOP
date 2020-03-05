#include "MoveFigure.h"

void MovePoint(point &structPoint, move value)
{
    structPoint.x += value.dx;
    structPoint.y += value.dy;
    structPoint.z += value.dz;
}

int MovePointsArray(figure myFigure, move value)
{
    int codeError = OK;

    if (myFigure.points.arrayStructpoints)
        for (int i = 0; i < myFigure.points.amountDots; i++)
            MovePoint(myFigure.points.arrayStructpoints[i], value);
    else
        codeError = ERROR_EMPTY;

    return codeError;
}

int MoveFigure(figure &myFigure, move value)
{
    return MovePointsArray(myFigure, value);
}
