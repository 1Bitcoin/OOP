#ifndef INPUTLINKS_H
#define INPUTLINKS_H

#include "ErrorMessages.h"

struct link
{
    int from;
    int to;
};

struct linksData
{
    int amountLinks;
    link *arrayStructlinks;
};

int ReadAllLinks(link *arrayStructlinks, int amountLinks, FILE *file);
int ReadLinks(link &arrayLinks, FILE *file);

#endif // INPUTLINKS_H
