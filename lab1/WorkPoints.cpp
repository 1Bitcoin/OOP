#include "WorkPoints.h"

void DrawLinks(figure myFigure, graphView drawInfo, scene canvas)
{
    coordPoint firstPoint, secondPoint;

    for (int i = 0; i < myFigure.links.amountLinks; i++)
    {
        firstPoint = GetDot(myFigure.points.arrayStructpoints, myFigure.links.arrayStructlinks[i].from - 1);
        secondPoint = GetDot(myFigure.points.arrayStructpoints, myFigure.links.arrayStructlinks[i].to - 1);

        firstPoint = PointTransform(firstPoint, drawInfo);
        secondPoint = PointTransform(secondPoint, drawInfo);

        DrawLine(canvas, firstPoint.x, secondPoint.x, firstPoint.y, secondPoint.y);
    }
}

coordPoint GetDot(point *arrayPoints, int number)
{
    coordPoint dot = {arrayPoints[number].x, arrayPoints[number].y, arrayPoints[number].z};
    return dot;
}

coordPoint PointTransform(coordPoint structPoint, graphView drawInfo)
{
    structPoint.z = sqrt(2)/2 * structPoint.z;

    structPoint.x = structPoint.x - structPoint.z;
    structPoint.x = structPoint.x + drawInfo.width / 2;

    structPoint.y = structPoint.z - structPoint.y;
    structPoint.y = structPoint.y + drawInfo.height / 2;

    return structPoint;
}

void DrawLine(scene canvas, int x1, int x2, int y1, int y2)
{
    canvas.scene->addLine(x1, y1, x2, y2, canvas.pen);
}
