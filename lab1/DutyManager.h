#ifndef DUTYMANAGER_H
#define DUTYMANAGER_H

#include "MoveFigure.h"
#include "ScaleFigure.h"
#include "TurnFigure.h"
#include "LoadModel.h"
#include "QtForDrawing.h"
#include "AllocateMemory.h"

enum task
{
    FREE,
    LOAD_FILE,
    PAINT,
    MOVE,
    SCALE,
    TURN
};

struct loadFile
{
    const char *filename;
};

struct manager
{
    task currentTask;
    union
    {
        struct loadFile load;
        struct graphView view;
        struct move move;
        struct scale scale;
        struct turn turn;
    };
};

int DutyManager(manager myManager);

#endif // DUTYMANAGER_H
