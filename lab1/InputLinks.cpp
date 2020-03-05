#include "InputLinks.h"

int ReadLinks(link &arrayLinks, FILE *file)
{
    int codeError = OK;

    if (fscanf(file, "%d %d", &arrayLinks.from, &arrayLinks.to) != 2)
        codeError = ERROR_FILE_FORMAT;

    return codeError;
}

int ReadAllLinks(figure myFigure, FILE *file)
{
    int codeError = OK;

    for (int i = 0; i < myFigure.links.amountLinks && !codeError; i++)
    {
        if (ReadLinks(myFigure.links.arrayStructlinks[i], file))
            codeError = ERROR_FILE_FORMAT;
    }
    return codeError;
}
