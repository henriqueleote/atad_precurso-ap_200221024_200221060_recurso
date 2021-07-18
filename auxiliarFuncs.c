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

#define NETFLIX_FILE "csv_data/netflix_titles.csv"
#define ALL 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2

bool listEmpty(PtList list){
    bool check = false;
    if (listIsEmpty(list))
    {
        printf("\nList is empty. Press enter to continue.\n");
        getchar();
        return true;
    }
    if (list == NULL)
    {
        printf("\nList is null. Press enter to continue.\n");
        getchar();
        return true;
    }
    return false;
}

char *convertToLower(char *str)
{
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
}

char *trimWhiteSpace(char *str)
{
    int len = strlen(str);
    if (str[0] == ' ')
    {
        for (int i = 0; i < len; i++)
        {
            str[i] = str[i + 1];
            if (str[i] == '\0')
            {
                break;
            }
        }
    }
    int len1 = strlen(str);
    if (str[len1 - 1] == ' ')
    {
        str[len1 - 1] = '\0';
    }
    return str;
}

void sortRating(PtList titlesList)
{
    int ratingSortListSize = 0;
    listSize(titlesList, &ratingSortListSize);
    printf("\nPlease wait while sorting by Rating...\n\n");
    for (int i = 0; i < ratingSortListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < ratingSortListSize - 1 - i; j++)
        {
            Netflix ratingElem1, ratingElem2, ratingElemTemp;
            listGet(titlesList, j, &ratingElem1);
            listGet(titlesList, j + 1, &ratingElem2);
            if (strcmp(ratingElem1.rating, ratingElem2.rating) > 0)
            {
                listSet(titlesList, j + 1, ratingElem1, &ratingElemTemp);
                listSet(titlesList, j, ratingElem2, &ratingElemTemp);
            }
        }
    }
}

void sortAlpha(PtList titlesList)
{
    int alphaSortListSize = 0;
    listSize(titlesList, &alphaSortListSize);
    printf("\nPlease wait while sorting by Title...\n\n");
    for (int i = 0; i < alphaSortListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < alphaSortListSize - 1 - i; j++)
        {
            Netflix alphaElem1, alphaElem2, alphaElemTemp;
            listGet(titlesList, j, &alphaElem1);
            listGet(titlesList, j + 1, &alphaElem2);
            if (strcmp(alphaElem1.title, alphaElem2.title) > 0)
            {
                listSet(titlesList, j + 1, alphaElem1, &alphaElemTemp);
                listSet(titlesList, j, alphaElem2, &alphaElemTemp);
            }
        }
    }
}

void sortCategory(PtList titlesList)
{
    int categoriesSortListSize = 0;
    char *str1 = (char *)calloc(70, sizeof(char));
    char *str2 = (char *)calloc(70, sizeof(char));
    listSize(titlesList, &categoriesSortListSize);
    printf("\nPlease wait while sorting by Title...\n\n");
    for (int i = 0; i < categoriesSortListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < categoriesSortListSize - 1 - i; j++)
        {
            Netflix categoryElem1, categoryElem2, categoryElemTemp;
            listGet(titlesList, j, &categoryElem1);
            listGet(titlesList, j + 1, &categoryElem2);

            strcpy(str1, categoryElem1.listed_in);
            strcpy(str2, categoryElem2.listed_in);
            convertToLower(str1);
            convertToLower(str2);
            if (strcmp(str1, str2) > 0)
            {
                listSet(titlesList, j + 1, categoryElem1, &categoryElemTemp);
                listSet(titlesList, j, categoryElem2, &categoryElemTemp);
            }
        }
    }
    free(str1);
    free(str2);
}

void sortDirector(PtList titlesList)
{
    int directorsSortListSize = 0;
    char *str1 = (char *)calloc(70, sizeof(char));
    char *str2 = (char *)calloc(70, sizeof(char));
    listSize(titlesList, &directorsSortListSize);
    printf("\nPlease wait while sorting by Title...\n\n");
    for (int i = 0; i < directorsSortListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < directorsSortListSize - 1 - i; j++)
        {
            Netflix directorsElem1, directorsElem2, directorsElemTemp;
            listGet(titlesList, j, &directorsElem1);
            listGet(titlesList, j + 1, &directorsElem2);

            strcpy(str1, directorsElem1.director);
            strcpy(str2, directorsElem2.director);
            convertToLower(str1);
            convertToLower(str2);
            if (strcmp(str1, str2) > 0)
            {
                listSet(titlesList, j + 1, directorsElem1, &directorsElemTemp);
                listSet(titlesList, j, directorsElem2, &directorsElemTemp);
            }
        }
    }
    free(str1);
    free(str2);
}

void sortDuration(PtList titlesList)
{
    int durationSortListSize = 0;
    listSize(titlesList, &durationSortListSize);
    printf("\nPlease wait while sorting by Duration...\n\n");
    for (int i = 0; i < durationSortListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < durationSortListSize - 1 - i; j++)
        {
            Netflix durationElem1, durationElem2, durationElemTemp;
            listGet(titlesList, j, &durationElem1);
            listGet(titlesList, j + 1, &durationElem2);
            if (durationElem1.duration < durationElem2.duration)
            {
                listSet(titlesList, j + 1, durationElem1, &durationElemTemp);
                listSet(titlesList, j, durationElem2, &durationElemTemp);
            }
        }
    }
}

void sortYear(PtList titlesList)
{
    int yearSortListSize = 0;
    listSize(titlesList, &yearSortListSize);
    printf("Please wait while sorting by Year...\n\n");
    for (int i = 0; i < yearSortListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < yearSortListSize - 1 - i; j++)
        {
            Netflix yearElem1, yearElem2, yearElemTemp;
            listGet(titlesList, j, &yearElem1);
            listGet(titlesList, j + 1, &yearElem2);
            if (yearElem1.release_year > yearElem2.release_year)
            {
                listSet(titlesList, j + 1, yearElem1, &yearElemTemp);
                listSet(titlesList, j, yearElem2, &yearElemTemp);
            }
        }
    }
}

void sortDate(PtList titlesList)
{
    int dateSortListSize = 0;
    listSize(titlesList, &dateSortListSize);
    printf("\nPlease wait while sorting by Date...\n\n");
    for (int i = 0; i < dateSortListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < dateSortListSize - 1 - i; j++)
        {
            Netflix dateElem1, dateElem2, dateElemTemp;
            listGet(titlesList, j, &dateElem1);
            listGet(titlesList, j + 1, &dateElem2);
            int compare = dateCompare(dateElem1.date_added, dateElem2.date_added);
            if (compare > 0)
            {
                listSet(titlesList, j + 1, dateElem1, &dateElemTemp);
                listSet(titlesList, j, dateElem2, &dateElemTemp);
            }
        }
    }
}

bool ratingExists(PtList ratingsList, char *str)
{
    int ratingExistsList = 0;
    int x = 0;
    listSize(ratingsList, &ratingExistsList);
    Netflix ratingEElem1;

    while (x < ratingExistsList) //"while" cicle to run the list and check if the string already exists there
    {
        listGet(ratingsList, x, &ratingEElem1);
        if (strcmp(str, ratingEElem1.rating) == 0)
        {
            return true;
        }
        x++;
    }
    return false;
}

void netflixPrint(Netflix *pNetflix)
{
    if (strcmp(pNetflix->type, "Movie") == 0) //"if" condition to check if the title is a movie
        printf("%*s | %*s | %*s | %*d/%d/%d | %*s | %*d min. |\n", 6, pNetflix->show_id, 10, pNetflix->type, 100, pNetflix->title, 20, pNetflix->date_added.day, pNetflix->date_added.month, pNetflix->date_added.year, 15, pNetflix->rating, 15, pNetflix->duration);

    if (strcmp(pNetflix->type, "TV Show") == 0) //"if" condition to check if the title is a tv show
        printf("%*s | %*s | %*s | %*d/%d/%d | %*s | %*d season(s) |\n", 6, pNetflix->show_id, 10, pNetflix->type, 100, pNetflix->title, 20, pNetflix->date_added.day, pNetflix->date_added.month, pNetflix->date_added.year, 15, pNetflix->rating, 10, pNetflix->duration);
}
