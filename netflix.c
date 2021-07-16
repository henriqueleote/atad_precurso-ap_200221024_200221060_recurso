#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "date.h"

Netflix netflixCreate(char *show_id, char *type, char *title, char *director, char *cast, char *country, Date date_added, int release_year, char *rating, int duration, char *listed_in, char *description)
{

    Netflix netflix; //Creates a netflix struct object

    strcpy(netflix.show_id, show_id);           //Copy the string received to the netflix struct object
    strcpy(netflix.type, type);                 //Copy the string received to the netflix struct object
    strcpy(netflix.title, title);               //Copy the string received to the netflix struct object
    strcpy(netflix.director, director);         //Copy the string received to the netflix struct object
    strcpy(netflix.cast, cast);                 //Copy the string received to the netflix struct object
    strcpy(netflix.country, country);           //Copy the string received to the netflix struct object
    netflix.date_added = date_added;
    netflix.release_year = release_year;
    strcpy(netflix.rating, rating);             //Copy the string received to the netflix struct object
    netflix.duration = duration;
    strcpy(netflix.listed_in, listed_in);       //Copy the string received to the netflix struct object
    strcpy(netflix.description, description);   //Copy the string received to the netflix struct object

    return netflix; //Returns the netflix struct object
}