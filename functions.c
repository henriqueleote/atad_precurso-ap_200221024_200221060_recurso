#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "input.h"
#include "list.h"
#include "map.h"
#include "date.h"
#include "StringWrap.h"
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

void sortAlphaCategories(PtList titlesList)
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

void sortAlphaDirectors(PtList titlesList)
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

PtList LOADF(PtList mainList)
{
    listClear(mainList);   //clears the list before inserting new data
    int loadFCount = -1;   //starts the count at -1 to skip the first line from csv
    char *line = (char *)calloc(10000, sizeof(char));

    char path[] = "csv_data/";
    char *fileName = (char *)calloc(50, sizeof(char));

    printf("\nFile name (without path): ");
    readString(fileName, 50);

    strncat(path, fileName, strlen(fileName));

    FILE *stream = fopen(path, "r");

    if (stream == NULL)
        printf("File not found.\n");

    else
    {
        while (fgets(line, 10000, stream) != NULL) //"while" cicle to run all the file until it meets the end of it
        {
            if (loadFCount == -1)
                loadFCount++;

            else
            {
                char *tmp = strdup(line);

                char **tokens = splitString(tmp, 12, ";");
                char **tokens2 = splitString(tokens[9], 2, " ");

                int duration = atoi(tokens2[0]);
                int release_year = atoi(tokens[7]);

                int day = 0;
                int month = 0;
                int year = 0;

                char cMonth[20], cDay[20], cYear[20];
                sscanf(tokens[6], "%s %s %s", cMonth, cDay, cYear);
                strtok(cDay, ",");

                if (strcmp(cMonth, "January") == 0)
                    month = 1;
                if (strcmp(cMonth, "February") == 0)
                    month = 2;
                if (strcmp(cMonth, "March") == 0)
                    month = 3;
                if (strcmp(cMonth, "April") == 0)
                    month = 4;
                if (strcmp(cMonth, "May") == 0)
                    month = 5;
                if (strcmp(cMonth, "June") == 0)
                    month = 6;
                if (strcmp(cMonth, "July") == 0)
                    month = 7;
                if (strcmp(cMonth, "August") == 0)
                    month = 8;
                if (strcmp(cMonth, "September") == 0)
                    month = 9;
                if (strcmp(cMonth, "October") == 0)
                    month = 10;
                if (strcmp(cMonth, "November") == 0)
                    month = 11;
                if (strcmp(cMonth, "December") == 0)
                    month = 12;

                Date date = createDate(atoi(cDay), month, atoi(cYear)); //creates a date from struct Date

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], date, release_year, tokens[8], duration, tokens[10], tokens[11]);

                listAdd(mainList, loadFCount, netflix); //adds to list

                free(tmp);
                free(tokens);
                free(tokens2);
                loadFCount++;
            }
        }

        if (loadFCount == -1)
            printf("\nNo titles imported.\n");
        else
            printf("\n%d titles imported.\n", loadFCount);

        fclose(stream);
    }

    free(line);
    free(fileName);

    return mainList;
}

PtList LOADD(PtList mainList)
{
    listClear(mainList);   //clears the list before inserting new data
    int loadDCount = -1;   //starts the count at -1 to skip the first line from csv
    char *line = (char *)calloc(10000, sizeof(char));

    FILE *stream = fopen(NETFLIX_FILE, "r");

    if (stream == NULL)
        printf("File not found.\n");

    else
    {
        while (fgets(line, 10000, stream) != NULL) //"while" cicle to run all the file until it meets the end of it
        {
            if (loadDCount == -1)
                loadDCount++;

            else
            {
                char *tmp = strdup(line);

                char **tokens = splitString(tmp, 12, ";");
                char **tokens2 = splitString(tokens[9], 2, " ");

                int duration = atoi(tokens2[0]);
                int release_year = atoi(tokens[7]);

                int day = 0;
                int month = 0;
                int year = 0;

                char cMonth[20], cDay[20], cYear[20];
                sscanf(tokens[6], "%s %s %s", cMonth, cDay, cYear);
                strtok(cDay, ",");

                if (strcmp(cMonth, "January") == 0)
                    month = 1;
                if (strcmp(cMonth, "February") == 0)
                    month = 2;
                if (strcmp(cMonth, "March") == 0)
                    month = 3;
                if (strcmp(cMonth, "April") == 0)
                    month = 4;
                if (strcmp(cMonth, "May") == 0)
                    month = 5;
                if (strcmp(cMonth, "June") == 0)
                    month = 6;
                if (strcmp(cMonth, "July") == 0)
                    month = 7;
                if (strcmp(cMonth, "August") == 0)
                    month = 8;
                if (strcmp(cMonth, "September") == 0)
                    month = 9;
                if (strcmp(cMonth, "October") == 0)
                    month = 10;
                if (strcmp(cMonth, "November") == 0)
                    month = 11;
                if (strcmp(cMonth, "December") == 0)
                    month = 12;

                Date date = createDate(atoi(cDay), month, atoi(cYear)); //creates a date from struct Date

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], date, release_year, tokens[8], duration, tokens[10], tokens[11]);

                listAdd(mainList, loadDCount, netflix); //adds to list

                free(tmp);
                free(tokens);
                free(tokens2);
                loadDCount++;
            }
        }

        if (loadDCount == -1)
            printf("\nNo titles imported.\n");
        else
            printf("\n%d titles imported.\n", loadDCount);

        fclose(stream);
    }

    free(line);
    return mainList;
}

PtList DEL(PtList mainList)
{
    char *showID = (char *)calloc(10, sizeof(char));
    char *netflixShowID = (char *)calloc(10, sizeof(char));

    printf("\nTitle ID: ");
    readString(showID, 10);

    int delListSize = 0;
    int delPosition = 0;
    bool check = false;
    char c;
    listSize(mainList, &delListSize);
    Netflix delElem;

    convertToLower(showID);

    for (int i = 0; i < delListSize; i++) //"for" cicle to run the list and check if the inserted title matches
    {
        listGet(mainList, i, &delElem);
        strcpy(netflixShowID, delElem.show_id);
        convertToLower(netflixShowID);
        if (strcmp(netflixShowID, showID) == 0) //if its a match, "returns" the position and "returns" true
        {
            check = true;
            delPosition = i;
            break;
        }
    }

    if (check == false)
        printf("\nTitle not found.\n");
    else
    {
        printf("\nAre you sure you want to delete %s? (y/n) ", showID); //asks the user from confirmation
        readChar(&c);

        if (c == 'Y' || c == 'y'){
            listRemove(mainList, delPosition, &delElem); //removes the specific rank from the list
            printf("\n%s was deleted.\n", showID);
        }  
        else
            printf("\n%s was not deleted.\n", showID);
    }

    free(showID);
    free(netflixShowID);
    return mainList;
}

void CLEAR(PtList list)
{
    int clearListSize = 0;
    listSize(list, &clearListSize); //check the list size
    listClear(list);           //clears the list
    printf("\n%d shows deleted.\n", clearListSize);
}

void QUIT(PtList list)
{
    listDestroy(&list); //destroys the list
}

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
    {
        printf("Min can't be bigger than max.\n");
    }
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
    //sortDate(titlesList); //sorts the list by date
    printf("Query is \"%s\" -----\n", titleName);
    free(titleName);
    free(netflixTitleName);
    LIST(titlesList, -1, -1, ALL); //prints the list
}

void SEARCHC(PtList mainList)
{
    char *castName = (char *)calloc(700, sizeof(char));
    char *netflixCastName = (char *)calloc(700, sizeof(char));
    int mainSizeList = 0;
    int cCount = 0;
    Netflix netflix;
    listSize(mainList, &mainSizeList);
    PtList titlesList = listCreate(); //creates a list
    
    printf("Please insert the cast name: ");
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
    //sortDate(titlesList); //sorts the list by date
    printf("Query is \"%s\" -----\n", castName);
    free(castName);
    free(netflixCastName);
    LIST(titlesList, -1, -1, ALL); //prints the list
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

    sortAlphaCategories(categoriesList);

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

PtList DIRECTORS(PtList mainList, bool print)
{
    Netflix dirElem1, dirElem2;
    PtMap directorMap = mapCreate();
    int directorsSize = 0;
    int dirSizeMap = 0;
    listSize(mainList, &directorsSize);

    for (int i = 0; i < directorsSize; i++)
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
    for (int z = 0; z < dirSizeMap; z++)
    {

        strcpy(dirElem1.director, directors[z].text);
        listAdd(directorsList, z, dirElem1);
    }

    sortAlphaCategories(directorsList);

    for (int k = 0; k < dirSizeMap; k++)
    {
        listGet(directorsList, k, &dirElem2);
        if (print == true)
            printf("%s\n", dirElem2.director);
    }

    free(directors);
    mapDestroy(&directorMap);

    return directorsList;
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