#include "WorkPoints.h"

int ReadCount(figure &myFigure, FILE *f)
{
    int CodeError = OK;
    int countDots, countLinks = 0;

    if (fscanf(f, "%d %d", &countDots, &countLinks) != 2)
        CodeError = ERROR_FILE_FORMAT;

    if (countDots <= 0 || countLinks <= 0 )
        CodeError = ERROR_FILE_FORMAT;

    if (!CodeError)
    {
        myFigure.points.amountDots = countDots;
        myFigure.links.amountLinks = countLinks;
    }

    return CodeError;
}

void DrawLinks(figure myFigure, draw drawInfo, graphics canvas)
{
    coordPoint p1, p2;
    for (int i = 0; i < myFigure.links.amountLinks; i++)
    {
        p1 = GetDot(myFigure.points.arrayStructpoints, myFigure.links.arrayStructlinks[i].from - 1);
        p2 = GetDot(myFigure.points.arrayStructpoints, myFigure.links.arrayStructlinks[i].to - 1);

        p1 = PointTransform(p1, drawInfo);
        p2 = PointTransform(p2, drawInfo);

        AddLine(canvas, p1.x, p2.x, p1.y, p2.y);
    }
}

coordPoint GetDot(point *arrayPoints, int number)
{
    coordPoint dot = {arrayPoints[number].x, arrayPoints[number].y, arrayPoints[number].z};
    return dot;
}

coordPoint PointTransform(coordPoint structPoint, draw drawInfo)
{
    structPoint.z = sqrt(2)/2 * structPoint.z;

    structPoint.x = structPoint.x - structPoint.z;
    structPoint.x = structPoint.x + drawInfo.width / 2;

    structPoint.y = structPoint.z - structPoint.y;
    structPoint.y = structPoint.y + drawInfo.height / 2;

    return structPoint;
}

void AddLine(graphics canvas, int x1, int x2, int y1, int y2)
{
    canvas.scene->addLine(x1, y1, x2, y2, canvas.pen);
}
