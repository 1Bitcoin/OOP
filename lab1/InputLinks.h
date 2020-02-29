#ifndef INPUTLINKS_H
#define INPUTLINKS_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "WorkPoints.h"
#include "QtForDrawing.h"

int ReadAllLinks(figure myFigure, FILE *file);
int ReadLinks(link *arrayLinks, FILE *file);

#endif // INPUTLINKS_H
