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


#define NETFLIX_FILE "csv_data/netflix_titles.csv"
#define ALL 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2



void GET(PtList mainList)
{
    char *showID = (char *)calloc(10, sizeof(char));
    char *netflixShowID = (char *)calloc(10, sizeof(char));

    printf("\nTitle ID: ");
    readString(showID, 10);

    int getListSize = 0;
    int getPosition = 0;
    bool check = false;
    char c;
    listSize(mainList, &getListSize);
    Netflix getElem;

    convertToLower(showID);

    for (int i = 0; i < getListSize; i++) //"for" cicle to run the list and check if the inserted title matches
    {
        listGet(mainList, i, &getElem);
        strcpy(netflixShowID, getElem.show_id);
        convertToLower(netflixShowID);
        if (strcmp(netflixShowID, showID) == 0) //if its a match, "returns" the position and "returns" true
        {
            check = true;
            getPosition = i;
            break;
        }
    }

    if (check == false)
        printf("\nTitle not found.\n");
    else
    {
        listGet(mainList, getPosition, &getElem);
        printf("=======================================================\n");
        printf("Show Id: %s | Type: %s\n", getElem.show_id, getElem.type);
        printf("  Title: %s\n", getElem.title);
        if (strcmp(getElem.type, "Movie") == 0)
            printf("  Duration: %d min\n", getElem.duration);
        if (strcmp(getElem.type, "TV Show") == 0)
            printf("  Duration: %d season(s)\n", getElem.duration);
        printf("  Rating: %s\n", getElem.rating);
        printf("  Appears in: %s\n", getElem.listed_in);
        printf("  Date Added: %d/%d/%d | Release year: %d\n", getElem.date_added.day, getElem.date_added.month, getElem.date_added.year, getElem.release_year);
        printf("------------------------------\n");
        printf("  Director: %s\n", getElem.director);
        printf("  Country: %s\n", getElem.country);
        printf("------------------------------\n");
        printf("  Cast:\n  %s\n", getElem.cast);
        printf("------------------------------\n");
        printf("  Description:\n  %s\n", getElem.description);
        printf("=======================================================\n");
    }
    free(showID);
    free(netflixShowID);
}

void LIST(PtList list, int min, int max, int type)
{
    int listListSize = 0;
    int listCount = 0;
    listSize(list, &listListSize);
    Netflix listElem;
    char *id = (char *)calloc(50, sizeof(char));
    char c;
    printf("%6s| %10s | %100s | %28s | %15s |%21s |\n", "Show ID", "Type", "Title", "Date Added", "Rating", "Duration");
    printf("%6s| %10s | %100s | %28s | %15s |%21s |\n", "-------", "-------", "-------", "-------", "-------", "-------");
    for (int rank = 0; rank < listListSize; rank++)
    {
        listGet(list, rank, &listElem);
        if (min != -1 && max != -1) //if the asked list must have a min and max duration
        {
            if (type == ALL) //if the asked list must have both types
            {
                if (listElem.duration >= min && listElem.duration <= max)
                {
                    listElemPrint(listElem);
                    listCount++;
                    if (listCount % 30 == 0)
                    {
                        printf("\nContinue listing (Y/n)? ");
                        readChar(&c);
                        if (c == 'Y' || c == 'y')
                            continue;
                        else
                            break;
                    }
                    if (listCount == listListSize)
                        printf("\nThere are no more netflix titles.\n");
                }
            }
            if (type == TYPE_MOVIE || type == TYPE_SHOW) //if the asked list must have only one of the types
            {
                if (type == TYPE_MOVIE) // //if the asked list must have only movies
                {
                    strcpy(id, "Movie");
                }

                if (type == TYPE_SHOW) // //if the asked list must have only tv shows
                {
                    strcpy(id, "TV Show");
                }

                if (strcmp(listElem.type, id) == 0) //if its a match
                {
                    if (listElem.duration >= min && listElem.duration <= max)
                    {
                        listElemPrint(listElem);
                        listCount++;
                        if (listCount % 30 == 0)
                        {
                            printf("\nContinue listing (Y/n)? ");
                            readChar(&c);
                            if (c == 'Y' || c == 'y')
                                continue;
                            else
                                break;
                        }
                        if (listCount == listListSize)
                            printf("\nThere are no more netflix titles.\n");
                    }
                }
                else
                    continue;
            }
        }
        else //if the asked list doesn't have a min and max duration
        {
            if (type == ALL) //if the asked list must have both types
            {
                listElemPrint(listElem);
                listCount++;
                if (listCount % 30 == 0)
                {
                    printf("\nContinue listing (Y/n)? ");
                    readChar(&c);
                    if (c == 'Y' || c == 'y')
                        continue;
                    else
                        break;
                }
                if (listCount == listListSize)
                    printf("\nThere are no more netflix titles.\n");
            }
            if (type == TYPE_MOVIE || type == TYPE_SHOW) //if the asked list must have only one of the types
            {
                if (type == TYPE_MOVIE) // //if the asked list must have only movies
                {
                    strcpy(id, "Movie");
                }

                if (type == TYPE_SHOW) // //if the asked list must have only tv shows
                {
                    strcpy(id, "TV Show");
                }

                if (strcmp(listElem.type, id) == 0) //if its a match
                {
                    listElemPrint(listElem);
                    listCount++;
                    if (listCount % 30 == 0)
                    {
                        printf("\nContinue listing (Y/n)? ");
                        readChar(&c);
                        if (c == 'Y' || c == 'y')
                            continue;
                        else
                            break;
                    }
                    if (listCount == listListSize)
                        printf("\nThere are no more netflix titles.\n");
                }
                else
                    continue;
            }
        }
    }
    printf("\n");
    free(id);
}

void STATS(PtList mainList)
{
    int statsListSize = 0, min = 300, max = 0, minS = 100, maxS = 0;
    double movieCount = 0, totalMinutes = 0, totalSeasons = 0, tvCount = 0;

    listSize(mainList, &statsListSize); //gets the list size
    Netflix netflix;
    for (int i = 0; i < statsListSize; i++) //"for" cicle to run the list
    {
        listGet(mainList, i, &netflix);
        if (strcmp(netflix.type, "Movie") == 0) //if its a movie
        {
            movieCount++;
            totalMinutes += netflix.duration;
            if (netflix.duration < min) //checks min duration
            {
                min = netflix.duration;
            }
            if (netflix.duration > max) //checks max duration
            {
                max = netflix.duration;
            }
        }
        if (strcmp(netflix.type, "TV Show") == 0) //if its a tv show
        {
            tvCount++;
            totalSeasons += netflix.duration;
            if (netflix.duration < minS) //checks min seasons
            {
                minS = netflix.duration;
            }
            if (netflix.duration > maxS) //checks max seasons
            {
                maxS = netflix.duration;
            }
        }
    }
    double averageDuration = totalMinutes / movieCount;
    double averageSeasons = totalSeasons / tvCount;
    printf("\nMovie count: <%.0f> | Min. duration: <%d> | Max. duration: <%d> | Avg. duration: <%.0f> \nTV Show count: <%.0f> | Min. seasons <%d> | Max. seasons <%d> | Avg. seasons: <%.0f> \n\nTotals:\n <%.0f> total minutes of movie time \n <%.0f> total seasons of tv shows\n", movieCount, min, max, averageDuration, tvCount, minS, maxS, averageSeasons, totalMinutes, totalSeasons);
}

void MTIME(PtList mainList)
{
    int min = 0;
    int max = 0;

    printf("\nMin: ");
    readInteger(&min); //asks the min duration value

    printf("Max: ");
    readInteger(&max); //asks the max duration value

    if (min <= max) //check if the min is lower or equal than the max duration
    {
        sortDuration(mainList);
        LIST(mainList, min, max, TYPE_MOVIE); //prints the list
    }
    else
        printf("Min can't be bigger than max.\n");
}

void SEARCHT(PtList mainList)
{
    char *titleName = (char *)calloc(120, sizeof(char));
    char *netflixTitleName = (char *)calloc(120, sizeof(char));
    int mainSizeList = 0;
    int tCount = 0;
    Netflix netflix;
    listSize(mainList, &mainSizeList);
    PtList titlesList = listCreate(); //creates a list

    printf("\nPlease insert the title name: ");
    readString(titleName, 100);

    convertToLower(titleName);

    for (int i = 0; i < mainSizeList; i++) //"for" cicle to run the main list
    {
        listGet(mainList, i, &netflix);

        strcpy(netflixTitleName, netflix.title);

        convertToLower(netflixTitleName);

        if (strstr(netflixTitleName, titleName) != NULL) //if the title string is in the title
        {
            listAdd(titlesList, tCount, netflix); //adds to the list
            tCount++;
        }
    }
    sortDate(titlesList); //sorts the list by date
    printf("Query is \"%s\" -----\n", titleName);
    free(titleName);
    free(netflixTitleName);
    LIST(titlesList, -1, -1, ALL); //prints the list
}

void SEARCHC(PtList mainList)
{
    char *castName = (char *)calloc(650, sizeof(char));
    char *netflixCastName = (char *)calloc(800, sizeof(char));


    int mainSizeList = 0;
    int cCount = 0;
    Netflix netflix;
    listSize(mainList, &mainSizeList);
    PtList titlesList = listCreate(); //creates a list

    printf("Please insert the cast member(s) name: ");
    readString(castName, 650);

    convertToLower(castName);

    for (int i = 0; i < mainSizeList; i++) //"for" cicle to run the main list
    {
        listGet(mainList, i, &netflix);

        strcpy(netflixCastName, netflix.cast);

        convertToLower(netflixCastName);

        if (strstr(netflixCastName, castName) != NULL) //if the cast string is in the cast
        {
            listAdd(titlesList, cCount, netflix); //adds to the list
            cCount++;
        }
    }
    sortDate(titlesList); //sorts the list by date
    printf("Query is \"%s\" -----\n", castName);
    free(castName);
    free(netflixCastName);
    LIST(titlesList, -1, -1, ALL); //prints the list
}

PtList RATINGS(PtList mainList, bool print)
{
    PtList ratingsList = listCreate(); //creates a new list only for the ratings
    int ratingsMainSizeList = 0;
    int ratingSizeList = 0;
    int rCount = 0;
    listSize(mainList, &ratingsMainSizeList);
    Netflix ratingElem1;
    Netflix ratingsElemData;

    for (int i = 0; i < ratingsMainSizeList; i++) //"for" cicle to run the list
    {
        listGet(mainList, i, &ratingElem1);

        if (!ratingExists(ratingsList, ratingElem1.rating)) //if doesnt exist
        {
            listAdd(ratingsList, rCount, ratingElem1); //adds to list
            rCount++;
        }
    }

    sortRating(ratingsList); //sorts the list by rating

    listSize(ratingsList, &ratingSizeList);

    for (int k = 0; k < ratingSizeList; k++) //"for" cicle to run the list
    {
        listGet(ratingsList, k, &ratingsElemData);
        if (print==true)
            printf("%s\n", ratingsElemData.rating);
        }
        return ratingsList;
}

void CATEGORIES(PtList mainList)
{
    Netflix catElem1, catElem2;
    PtMap catMap = mapCreate();
    int categoriesSize = 0;
    int catSizeMap = 0;
    listSize(mainList, &categoriesSize);

    printf("Please wait while processing all categories...\n");
    for (int i = 0; i < categoriesSize; i++)
    {
        listGet(mainList, i, &catElem1);
        char *token = strtok(catElem1.listed_in, ",");
        while (token != NULL)
        {
            token = trimWhiteSpace(token);
            StringWrap help1 = stringWrapCreate(token);
            mapPut(catMap, help1, help1);
            token = strtok(NULL, ",");
        }
    }
    PtList categoriesList = listCreate();

    MapKey *categories = mapKeys(catMap);

    mapSize(catMap, &catSizeMap);
    for (int z = 0; z < catSizeMap; z++)
    {

        strcpy(catElem1.listed_in, categories[z].text);
        listAdd(categoriesList, z, catElem1);
    }

    sortCategory(categoriesList);

    printf("\nAll categories:\n");
    for (int k = 0; k < catSizeMap; k++)
    {
        listGet(categoriesList, k, &catElem2);
        printf("%s\n", catElem2.listed_in);
    }

    free(categories);
    listDestroy(&categoriesList);
    mapDestroy(&catMap);
}