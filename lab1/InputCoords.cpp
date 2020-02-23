#include "InputCoords.h"
#include "CodeErrors.h"
#include "WorkPoints.h"
#include "InputLinks.h"

int PointsAlloc(pointsData &points, linksData &links)
{
    int CodeError = OK;
    int countDots = points.amountDots;
    points.arrayStructpoints = (point*) calloc(countDots, sizeof(point));

    int countLinks = links.amountLinks;
    links.arrayStructlinks = (link*) calloc(countLinks, sizeof(link));

    if (!points.arrayStructpoints)
        CodeError = ERROR_ALLOC_MEMORY;

    if (!links.arrayStructlinks)
        CodeError = ERROR_ALLOC_MEMORY;

    return CodeError;
}

void PointsFree(pointsData &points, linksData &links)
{
    if (points.arrayStructpoints)
        free(points.arrayStructpoints);

    if (links.arrayStructlinks)
        free(links.arrayStructlinks);
}

int ReadPoint(point *dot, FILE *f)
{
    int CodeError = OK;
    if (fscanf(f, "%lf %lf %lf %d", &dot->x, &dot->y, &dot->z, &dot->number) != 4)
        CodeError = ERROR_FILE_FORMAT;

    return CodeError;
}

int ReadAllPoints(figure myFigure, FILE *f)
{
    int CodeError = OK;
    for (int i = 0; i < myFigure.points.amountDots && !CodeError; i++)
    {
        if (ReadPoint(&myFigure.points.arrayStructpoints[i], f))
            CodeError = ERROR_FILE_FORMAT;
    }
    return CodeError;
}
