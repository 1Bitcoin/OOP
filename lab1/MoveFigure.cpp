#include "MoveFigure.h"

void MovePoint(point &structPoint, move coeff)
{
    structPoint.x += coeff.dx;
    structPoint.y += coeff.dy;
    structPoint.z += coeff.dz;
}

int MovePointsArray(figure myFigure, move coeff)
{
    int codeError = OK;

    if (myFigure.points.arrayStructpoints)
        for (int i = 0; i < myFigure.points.amountDots; i++)
            MovePoint(myFigure.points.arrayStructpoints[i], coeff);
    else
        codeError = ERROR_EMPTY;

    return codeError;
}
