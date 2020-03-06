#include "InputLinks.h"

int ReadLinks(link &arrayLinks, FILE *file)
{
    int codeError = OK;

    if (fscanf(file, "%d %d", &arrayLinks.from, &arrayLinks.to) != 2)
        codeError = ERROR_FILE_FORMAT;

    return codeError;
}

int ReadAllLinks(link *arrayStructlinks, int amountLinks, FILE *file)
{
    int codeError = OK;

    for (int i = 0; i < amountLinks && !codeError; i++)
    {
        if (ReadLinks(arrayStructlinks[i], file))
            codeError = ERROR_FILE_FORMAT;
    }
    return codeError;
}
