#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "input.h"
#include "list.h"
#include "map.h"
#include "date.h"
#include "stringWrap.h"
#include <ctype.h>
#include "auxiliarFuncs.h"
#include "import.h"
#include "search.h"


PtList DIRECTORS(PtList mainList, bool print)
{
    Netflix dirElem1, dirElem2;
    PtMap directorMap = mapCreate();
    int directorsSize = 0;
    int dirSizeMap = 0;
    listSize(mainList, &directorsSize);

    for (int i = 0; i < directorsSize; i++) //"for" cicle to run the list and add to the map to retain duplicates
    {
        listGet(mainList, i, &dirElem1);
        char *token = strtok(dirElem1.director, ",");
        while (token != NULL)
        {
            token = trimWhiteSpace(token);
            StringWrap help1 = stringWrapCreate(token);
            mapPut(directorMap, help1, help1);
            token = strtok(NULL, ",");
        }
    }
    PtList directorsList = listCreate();

    MapKey *directors = mapKeys(directorMap);

    mapSize(directorMap, &dirSizeMap);
    for (int z = 0; z < dirSizeMap; z++) //"for" cicle to run the map and put the elements in a list
    {

        strcpy(dirElem1.director, directors[z].text);
        listAdd(directorsList, z, dirElem1);
    }

    sortCategory(directorsList);

    for (int k = 0; k < dirSizeMap; k++) //"for" cicle to run the map and put the elements in a list
    {
        listGet(directorsList, k, &dirElem2);
        if (print == true)
            printf("%s\n", dirElem2.director);
    }

    free(directors);
    mapDestroy(&directorMap);

    return directorsList;
}

void SEGMENT(PtList mainList)
{
    printf("---------------------------------------\n");
    //RATINGS
    printf("Creating segment_by_rating.txt file\n");
    PtList segmentRatingList = RATINGS(mainList, false); //gets all the unique ratings
    int segmentRatingSizeList = 0;
    int segmentMainListSize = 0;
    Netflix ratingElem1;
    listSize(mainList, &segmentMainListSize);            //gets the titles list size
    listSize(segmentRatingList, &segmentRatingSizeList); //gets the ratings list size
    Netflix segmentRatingsData;
    sortYear(mainList); //sorts the titles list by year

    FILE *fileR = fopen("segment_by_rating.txt", "w+"); //creates a file in writing mode

    char *str0 = (char *)calloc(80, sizeof(char));
    char *str1 = (char *)calloc(80, sizeof(char));
    char *str2 = (char *)calloc(500, sizeof(char));
    char *str3 = (char *)calloc(2, sizeof(char));
    sprintf(str0, "%d shows imported\n", segmentMainListSize);
    fputs(str0, fileR); //writes string in file

    for (int i = 0; i < segmentRatingSizeList; i++) //"for" cicle to run the rating list
    {
        listGet(segmentRatingList, i, &segmentRatingsData);
        sprintf(str1, "%s ------\n", segmentRatingsData.rating);
        fputs(str1, fileR); //writes string in file

        for (int j = 0; j < segmentMainListSize; j++) //"for" cicle to run the title list
        {
            listGet(mainList, j, &ratingElem1);
            if (strcmp(segmentRatingsData.rating, ratingElem1.rating) == 0)
            {
                if (strcmp(ratingElem1.type, "Movie") == 0) //if its a movie
                {
                    sprintf(str2, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d min.\n", 6, ratingElem1.show_id, 10, ratingElem1.type, 100, ratingElem1.title, 20, ratingElem1.release_year, 15, ratingElem1.rating, 15, ratingElem1.duration);
                    fputs(str2, fileR); //writes string in file
                }
                if (strcmp(ratingElem1.type, "TV Show") == 0) //if its a movie
                {
                    sprintf(str2, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d season(s)\n", 6, ratingElem1.show_id, 10, ratingElem1.type, 100, ratingElem1.title, 20, ratingElem1.release_year, 15, ratingElem1.rating, 15, ratingElem1.duration);
                    fputs(str2, fileR); //writes string in file
                }
            }
        }
        fputs(str3, fileR); //writes string in file
    }
    fclose(fileR);
    free(str0);
    free(str1);
    free(str2);
    free(str3);
    listDestroy(&segmentRatingList);

    printf("---------------------------------------\n");
    //DIRECTORS
    printf("Creating segment_by_directors.txt file\n");
    PtList directorsList = DIRECTORS(mainList, false); //gets all the unique ratings
    int directorSizeList = 0;
    Netflix directorElem1;
    listSize(mainList, &segmentMainListSize);   //gets the titles list size
    listSize(directorsList, &directorSizeList); //gets the ratings list size
    Netflix segmentDirectorsData;
    sortYear(mainList); //sorts the titles list by year

    FILE *fileD = fopen("segment_by_directors.txt", "w+"); //creates a file in writing mode

    char *str4 = (char *)calloc(80, sizeof(char));
    char *str5 = (char *)calloc(80, sizeof(char));
    char *str6 = (char *)calloc(500, sizeof(char));
    char *str7 = (char *)calloc(2, sizeof(char));
    sprintf(str4, "%d shows imported\n", segmentMainListSize);
    fputs(str4, fileD); //writes string in file

    for (int i = 0; i < directorSizeList; i++) //"for" cicle to run the rating list
    {
        listGet(directorsList, i, &segmentDirectorsData);
        sprintf(str5, "%s ------\n", segmentDirectorsData.director);
        fputs(str5, fileD); //writes string in file

        for (int j = 0; j < segmentMainListSize; j++) //"for" cicle to run the title list
        {
            listGet(mainList, j, &directorElem1);
            if (strstr(directorElem1.director, segmentDirectorsData.director) != NULL)
            {
                if (strcmp(directorElem1.type, "Movie") == 0) //if its a movie
                {
                    sprintf(str6, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d min.\n", 6, directorElem1.show_id, 10, directorElem1.type, 100, directorElem1.title, 20, directorElem1.release_year, 15, directorElem1.rating, 15, directorElem1.duration);
                    fputs(str6, fileD); //writes string in file
                }
                if (strcmp(directorElem1.type, "TV Show") == 0) //if its a movie
                {
                    sprintf(str6, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d season(s)\n", 6, directorElem1.show_id, 10, directorElem1.type, 100, directorElem1.title, 20, directorElem1.release_year, 15, directorElem1.rating, 15, directorElem1.duration);
                    fputs(str6, fileD); //writes string in file
                }
            }
        }
        fputs(str7, fileD); //writes string in file
    }
    fclose(fileD);
    free(str4);
    free(str5);
    free(str6);
    free(str7);
    listDestroy(&directorsList);
    printf("---------------------------------------\n");
}