#pragma once

typedef struct stringWrap
{
    char text[256];
} StringWrap;

StringWrap stringWrapCreate(char *str);