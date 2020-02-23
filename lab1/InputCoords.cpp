#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "InputCoords.h"
#include "CodeErrors.h"
#include "WorkPoints.h"
#include "InputLinks.h"

using namespace std;

figure &Init()
{
    static figure myFigure;

    myFigure.points.amountDots = 0;
    myFigure.points.arrayStructpoints = NULL;

    myFigure.links.amountLinks = 0;
    myFigure.links.arrayStructlinks = NULL;

    return myFigure;
}

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

void TestWrite(figure &myFigure)
{
    cout << "Value n = " << myFigure.points.amountDots << endl;

    for (int i = 0; i < myFigure.points.amountDots; i++)
    {
        cout << " x = " << myFigure.points.arrayStructpoints[i].x << " y = " << myFigure.points.arrayStructpoints[i].y << " z = " << myFigure.points.arrayStructpoints[i].z << " number = " << myFigure.points.arrayStructpoints[i].number << endl;
        cout << "from = " << myFigure.links.arrayStructlinks[i].from << "to = "  << myFigure.links.arrayStructlinks[i].to << endl;
    }
}

int LoadModelFromFile(figure &myFigure, const char *filename)
{
    int CodeError = OK;
    FILE *f = fopen(filename, "r");
    if (f)
    {
        CodeError = ReadCount(myFigure, f);
        if (!CodeError)
        {
            PointsAlloc(myFigure.points, myFigure.links);
            CodeError = ReadAllPoints(myFigure, f);
            if (!CodeError)
            {
                CodeError = ReadAllLinks(myFigure, f);
            }
            TestWrite(myFigure);
        }

        fclose(f);
    }
    else
    {
        CodeError = ERROR_READING_FILE;
    }
    return CodeError;
}
