#ifndef ALLOCATEMEMORY_H
#define ALLOCATEMEMORY_H

#include "InputCoords.h"
#include "ErrorMessages.h"
#include "WorkPoints.h"

int PointsAlloc(pointsData &points, linksData &links);
void PointsFree(pointsData &points, linksData &links);

#endif // ALLOCATEMEMORY_H
