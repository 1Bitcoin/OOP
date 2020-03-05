#ifndef IO_H
#define IO_H

#include <cstdio>
#include "ErrorMessages.h"

struct point
{
    double x;
    double y;
    double z;
    int number;
};

struct link
{
    int from;
    int to;
};

struct linksData
{
    int amountLinks;
    link *arrayStructlinks;
};

struct pointsData
{
    int amountDots;
    point *arrayStructpoints;
};

struct figure
{
    pointsData points;
    linksData links;
};

int ReadAllPoints(figure myFigure, FILE *file);
int ReadPoint(point &dot, FILE *file);

#endif // IO_H
