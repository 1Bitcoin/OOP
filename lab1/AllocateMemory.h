#ifndef ALLOCATEMEMORY_H
#define ALLOCATEMEMORY_H

#include <stdlib.h>
#include "InputCoords.h"
#include "ErrorMessages.h"

int PointsAlloc(pointsData &points, linksData &links);
void PointsFree(pointsData &points, linksData &links);
void FreeMemory(figure &Myfigure);

#endif // ALLOCATEMEMORY_H
