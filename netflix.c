#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"

Netflix netflixCreate(char *show_id, char *type, char *title, char *director, char *cast, char *country, char *date_added, char *release_year, char *rating, char *duration, char *listed_in, char *description){
    
    Netflix netflix;

    strcpy(netflix.show_id, show_id);
    strcpy(netflix.type, type);
    strcpy(netflix.title, title);
    strcpy(netflix.director, director);
    strcpy(netflix.cast, cast);
    strcpy(netflix.country, country);
    strcpy(netflix.date_added, date_added);
    strcpy(netflix.release_year, release_year);
    strcpy(netflix.rating, rating);
    strcpy(netflix.duration, duration);
    strcpy(netflix.listed_in, listed_in);
    strcpy(netflix.description, description);

    return netflix;
}
