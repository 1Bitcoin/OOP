#include "LoadModel.h"

int ReadCount(figure &myFigure, FILE *file)
{
    int codeError = OK;
    int countDots, countLinks = 0;

    if (fscanf(file, "%d %d", &countDots, &countLinks) != 2)
        codeError = ERROR_FILE_FORMAT;

    if (countDots <= 0 || countLinks <= 0 )
        codeError = ERROR_FILE_FORMAT;

    if (!codeError)
    {
        myFigure.points.amountDots = countDots;
        myFigure.links.amountLinks = countLinks;
    }

    return codeError;
}

figure &Init(figure &myFigure)
{

    myFigure.points.amountDots = 0;
    myFigure.points.arrayStructpoints = NULL;

    myFigure.links.amountLinks = 0;
    myFigure.links.arrayStructlinks = NULL;

    return myFigure;
}

int LoadModelFromFile(figure &myFigure, const char *filename)
{
    int codeError = OK;
    FILE *file = fopen(filename, "r");

    if (file)
    {
        codeError = ReadCount(myFigure, file);
        if (!codeError)
        {
            PointsAlloc(myFigure.points, myFigure.links);
            codeError = ReadAllPoints(myFigure, file);
            if (!codeError)
                codeError = ReadAllLinks(myFigure, file);
        }

        fclose(file);
    }
    else
        codeError = ERROR_READING_FILE;

    return codeError;
}
