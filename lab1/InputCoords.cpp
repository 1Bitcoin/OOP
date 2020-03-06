#include "InputCoords.h"

int ReadPoint(point &dot, FILE *file)
{
    int codeError = OK;

    if (fscanf(file, "%lf %lf %lf %d", &dot.x, &dot.y, &dot.z, &dot.number) != 4)
        codeError = ERROR_FILE_FORMAT;

    return codeError;
}

int ReadAllPoints(point *arrayStructpoints, int amountDots, FILE *file)
{
    int codeError = OK;

    for (int i = 0; i < amountDots && !codeError; i++)
    {
        if (ReadPoint(arrayStructpoints[i], file))
            codeError = ERROR_FILE_FORMAT;
    }
    return codeError;
}
