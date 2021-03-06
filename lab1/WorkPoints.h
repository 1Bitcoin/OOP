#ifndef WORKPOINTS_H
#define WORKPOINTS_H

#include <math.h>
#include "ErrorMessages.h"
#include "InputCoords.h"
#include "QtForDrawing.h"
#include "LoadModel.h"

struct coordPoint
{
    double x;
    double y;
    double z;
};

coordPoint GetDot(point *arrayPoints, int number);
coordPoint PointTransform(coordPoint &structPoint, graphView &drawInfo);
void DrawLinks(pointsData &points, linksData &links, graphView &drawInfo, scene &canvas);
void DrawLine(scene a, int x1, int x2, int y1, int y2);

#endif // WORKPOINTS_H
