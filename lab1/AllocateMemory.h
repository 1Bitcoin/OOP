#ifndef ALLOCATEMEMORY_H
#define ALLOCATEMEMORY_H

#include <stdlib.h>
#include "InputCoords.h"
#include "InputLinks.h"
#include "Figure.h"
#include "ErrorMessages.h"

int PointsAlloc(pointsData &points, linksData &links);
void PointsFree(pointsData &points, linksData &links);
void FreeMemory(figure &myfigure);
void FreePreviousFigure(figure &myFigure);

#endif // ALLOCATEMEMORY_H
