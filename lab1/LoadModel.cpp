#include "LoadModel.h"

figure &Init()
{
    static figure myFigure;

    myFigure.points.amountDots = 0;
    myFigure.points.arrayStructpoints = NULL;

    myFigure.links.amountLinks = 0;
    myFigure.links.arrayStructlinks = NULL;

    return myFigure;
}

int LoadModelFromFile(figure &myFigure, const char *filename)
{
    int CodeError = OK;
    FILE *f = fopen(filename, "r");
    if (f)
    {
        CodeError = ReadCount(myFigure, f);
        if (!CodeError)
        {
            PointsAlloc(myFigure.points, myFigure.links);
            CodeError = ReadAllPoints(myFigure, f);
            if (!CodeError)
            {
                CodeError = ReadAllLinks(myFigure, f);
            }
        }

        fclose(f);
    }
    else
    {
        CodeError = ERROR_READING_FILE;
    }
    return CodeError;
}
