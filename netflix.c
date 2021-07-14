#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"

Netflix netflixCreate(char *show_id, char *type, char *title, char *director, char *cast, char *country, char *date_added, char *release_year, char *rating, char *duration, char *listed_in, char *description){
    
    Netflix netflix;                                    //Creates a netflix struct object

    strcpy(netflix.show_id, show_id);                   //Copy the string received to the netflix struct object
    strcpy(netflix.type, type);                         //Copy the string received to the netflix struct object
    strcpy(netflix.title, title);                       //Copy the string received to the netflix struct object
    strcpy(netflix.director, director);                 //Copy the string received to the netflix struct object
    strcpy(netflix.cast, cast);                         //Copy the string received to the netflix struct object
    strcpy(netflix.country, country);                   //Copy the string received to the netflix struct object
    strcpy(netflix.date_added, date_added);             //Copy the string received to the netflix struct object
    strcpy(netflix.release_year, release_year);         //Copy the string received to the netflix struct object
    strcpy(netflix.rating, rating);                     //Copy the string received to the netflix struct object
    strcpy(netflix.duration, duration);                 //Copy the string received to the netflix struct object
    strcpy(netflix.listed_in, listed_in);               //Copy the string received to the netflix struct object
    strcpy(netflix.description, description);           //Copy the string received to the netflix struct object

    return netflix; //Returns the netflix struct object
}
