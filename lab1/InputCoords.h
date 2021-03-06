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

struct pointsData
{
    int amountDots;
    point *arrayStructpoints;
};

int ReadAllPoints(point *arrayStructpoints, int amountDots, FILE *file);
int ReadPoint(point &dot, FILE *file);

#endif // IO_H
