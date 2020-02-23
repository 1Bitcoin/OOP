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

void DrawLinks(figure myFigure, draw arg, graphics a)
{
    coord_point p1, p2;
    for (int i = 0; i < myFigure.links.amountLinks; i++)
    {
        p1 = GetDot(myFigure.points.arrayStructpoints, myFigure.links.arrayStructlinks[i].from - 1);
        p2 = GetDot(myFigure.points.arrayStructpoints, myFigure.links.arrayStructlinks[i].to - 1);

        p1 = PointTransform(p1, arg);
        p2 = PointTransform(p2, arg);

        AddLine(a, p1.x, p2.x, p1.y, p2.y);
    }
}

coord_point GetDot(point *dots, int number)
{
    coord_point dot = {dots[number].x, dots[number].y, dots[number].z};
    return dot;
}

coord_point PointTransform(coord_point dot, draw arg)
{
    dot.z = sqrt(2)/2 * dot.z;

    dot.x = dot.x - dot.z;
    dot.x = dot.x + arg.width / 2;

    dot.y = dot.z - dot.y;
    dot.y = dot.y + arg.height / 2;

    return dot;
}

void AddLine(graphics a, int x1, int x2, int y1, int y2)
{
    //a.scene->addLine(x1 - z1, z1 - y1, x2 - z2, z2 - y2, a.pen);
    a.scene->addLine(x1, y1, x2, y2, a.pen);
}
