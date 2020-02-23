#ifndef IO_H
#define IO_H

#include <cstdio>
#include <cstdlib>

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

int LoadModelFromFile(figure &myFigure, const char *filename);
int PointsAlloc(pointsData &points, linksData &links);
int ReadAllPoints(figure myFigure, FILE *f);
int ReadPoint(point *dot, FILE *f);
void PointsFree(pointsData &points, linksData &links);
figure &Init();

#endif // IO_H
