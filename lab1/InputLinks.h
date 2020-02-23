#ifndef INPUTLINKS_H
#define INPUTLINKS_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "CodeErrors.h"
#include "WorkPoints.h"
#include "DrawingFigure.h"

int ReadAllLinks(figure myFigure, FILE *f);
int ReadLinks(link *arrayLinks, FILE *f);

#endif // INPUTLINKS_H
