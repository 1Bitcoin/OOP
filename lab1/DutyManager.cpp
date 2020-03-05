#include "DutyManager.h"

int DutyManager(manager myManager)
{
    static figure myFigure = Init(myFigure);
    int codeError = OK;

    switch (myManager.currentTask)
    {
        case FREE:
            FreeMemory(myFigure);
            break;
        case LOAD_FILE:
            codeError = LoadModelFromFile(myFigure, myManager.load.filename);
            break;
        case PAINT:
            DrawFigure(myFigure, myManager.view);
            break;
        case MOVE:
            codeError = MoveFigure(myFigure, myManager.move);
            break;
        case SCALE:
            codeError = ScaleFigure(myFigure, myManager.scale);
            break;
        case TURN:
            codeError = TurnFigure(myFigure, myManager.turn);
            break;
        default:
            codeError = ERROR_COMMAND;
    }

    return codeError;
}
