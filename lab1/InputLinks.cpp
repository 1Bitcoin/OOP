#include "InputLinks.h"

using namespace std;

int ReadLinks(link *arrayLinks, FILE *f)
{
    int CodeError = OK;
    if (fscanf(f, "%d %d", &arrayLinks->from, &arrayLinks->to) != 2)
        CodeError = ERROR_FILE_FORMAT;

    return CodeError;
}

int ReadAllLinks(figure myFigure, FILE *f)
{
    int CodeError = OK;
    for (int i = 0; i < myFigure.links.amountLinks && !CodeError; i++)
    {
        if (ReadLinks(&myFigure.links.arrayStructlinks[i], f))
            CodeError = ERROR_FILE_FORMAT;
    }
    return CodeError;
}
