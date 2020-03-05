#ifndef INPUTLINKS_H
#define INPUTLINKS_H

#include "ErrorMessages.h"
#include "InputCoords.h" // figure

int ReadAllLinks(figure myFigure, FILE *file);
int ReadLinks(link &arrayLinks, FILE *file);

#endif // INPUTLINKS_H
