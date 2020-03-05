#ifndef LOADMODEL_H
#define LOADMODEL_H

#include <cstdlib>
#include "InputCoords.h"
#include "ErrorMessages.h"
#include "InputLinks.h"
#include "AllocateMemory.h"

figure &Init(figure &myFigure);
int LoadModelFromFile(figure &myFigure, const char *filename);
int ReadCount(figure &myFigure, FILE *file);

#endif // LOADMODEL_H
