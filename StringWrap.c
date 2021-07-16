#include "StringWrap.h"
#include "string.h"

StringWrap stringWrapCreate(char *str)
{
    StringWrap string;

    strcpy(string.text, str);

    return string;
}