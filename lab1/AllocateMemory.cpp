#include "AllocateMemory.h"

int PointsAlloc(pointsData &points, linksData &links)
{
    int codeError = OK;

    int countDots = points.amountDots;
    int countLinks = links.amountLinks;

    points.arrayStructpoints = (point*) calloc(countDots, sizeof(point));
    links.arrayStructlinks = (link*) calloc(countLinks, sizeof(link));

    if (!points.arrayStructpoints)
        codeError = ERROR_ALLOC_MEMORY;

    if (!links.arrayStructlinks)
        codeError = ERROR_ALLOC_MEMORY;

    return codeError;
}

void PointsFree(pointsData &points, linksData &links)
{
    if (points.arrayStructpoints)
        free(points.arrayStructpoints);

    if (links.arrayStructlinks)
        free(links.arrayStructlinks);
}
