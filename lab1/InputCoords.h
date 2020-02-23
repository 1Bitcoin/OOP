#ifndef IO_H
#define IO_H

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
figure &Init();

#endif // IO_H
