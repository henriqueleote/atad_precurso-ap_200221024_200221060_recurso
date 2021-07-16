#include "date.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

Date createDate(int day, int month, int year){
    Date d;
    d.day=day;
    d.month=month;
    d.year=year;
    return d;
}

int dateCompare(Date d1, Date d2)
{
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return 0;
    else if (d1.year > d2.year || d1.year == d2.year && d1.month > d2.month ||
             d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)
        return 1;
    else
        return -1;
}
