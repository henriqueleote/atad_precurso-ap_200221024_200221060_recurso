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
#define TYPE 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2

char *convertToLower(char *str){
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
    int titlesListSize;
    listSize(titlesList, &titlesListSize);
    printf("\nPlease wait while sorting by Rating...\n\n");
    for (int i = 0; i < titlesListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < titlesListSize - 1 - i; j++)
        {
            Netflix netflix1, netflix2, netflixTemp;
            listGet(titlesList, j, &netflix1);
            listGet(titlesList, j + 1, &netflix2);
            if (strcmp(netflix1.rating, netflix2.rating) > 0)
            {
                listSet(titlesList, j + 1, netflix1, &netflixTemp);
                listSet(titlesList, j, netflix2, &netflixTemp);
            }
        }
    }
}

void sortAlpha(PtList titlesList)
{
    int titlesListSize;
    listSize(titlesList, &titlesListSize);
    printf("\nPlease wait while sorting by Title...\n\n");
    for (int i = 0; i < titlesListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < titlesListSize - 1 - i; j++)
        {
            Netflix netflix1, netflix2, netflixTemp;
            listGet(titlesList, j, &netflix1);
            listGet(titlesList, j + 1, &netflix2);
            if (strcmp(netflix1.title, netflix2.title) > 0)
            {
                listSet(titlesList, j + 1, netflix1, &netflixTemp);
                listSet(titlesList, j, netflix2, &netflixTemp);
            }
        }
    }
}

void sortAlphaCategories(PtList titlesList)
{
    int titlesListSize;
    char *str1 = (char *)calloc(70, sizeof(char));
    char *str2 = (char *)calloc(70, sizeof(char));
    listSize(titlesList, &titlesListSize);
    printf("\nPlease wait while sorting by Title...\n\n");
    for (int i = 0; i < titlesListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < titlesListSize - 1 - i; j++)
        {
            Netflix netflix1, netflix2, netflixTemp;
            listGet(titlesList, j, &netflix1);
            listGet(titlesList, j + 1, &netflix2);
            
            strcpy(str1, netflix1.listed_in);
            strcpy(str2, netflix2.listed_in);
            convertToLower(str1);
            convertToLower(str2);
            if (strcmp(str1, str2) > 0)
            {
                listSet(titlesList, j + 1, netflix1, &netflixTemp);
                listSet(titlesList, j, netflix2, &netflixTemp);
            }
        }
    }
    free(str1);
    free(str2);
}

void sortAlphaDirectors(PtList titlesList)
{
    int titlesListSize;
    char *str1 = (char *)calloc(70, sizeof(char));
    char *str2 = (char *)calloc(70, sizeof(char));
    listSize(titlesList, &titlesListSize);
    printf("\nPlease wait while sorting by Title...\n\n");
    for (int i = 0; i < titlesListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < titlesListSize - 1 - i; j++)
        {
            Netflix netflix1, netflix2, netflixTemp;
            listGet(titlesList, j, &netflix1);
            listGet(titlesList, j + 1, &netflix2);

            strcpy(str1, netflix1.director);
            strcpy(str2, netflix2.director);
            convertToLower(str1);
            convertToLower(str2);
            if (strcmp(str1, str2) > 0)
            {
                listSet(titlesList, j + 1, netflix1, &netflixTemp);
                listSet(titlesList, j, netflix2, &netflixTemp);
            }
        }
    }
    free(str1);
    free(str2);
}

void sortDuration(PtList titlesList)
{
    int titlesListSize;
    listSize(titlesList, &titlesListSize);
    printf("\nPlease wait while sorting by Duration...\n\n");
    for (int i = 0; i < titlesListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < titlesListSize - 1 - i; j++)
        {
            Netflix netflix1, netflix2, netflixTemp;
            listGet(titlesList, j, &netflix1);
            listGet(titlesList, j + 1, &netflix2);
            if (netflix1.duration < netflix2.duration)
            {
                listSet(titlesList, j + 1, netflix1, &netflixTemp);
                listSet(titlesList, j, netflix2, &netflixTemp);
            }
        }
    }
}

void sortYear(PtList titlesList)
{
    int titlesListSize;
    listSize(titlesList, &titlesListSize);
    printf("Please wait while sorting by Year...\n\n");
    for (int i = 0; i < titlesListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < titlesListSize - 1 - i; j++)
        {
            Netflix netflix1, netflix2, netflixTemp;
            listGet(titlesList, j, &netflix1);
            listGet(titlesList, j + 1, &netflix2);
            if (netflix1.release_year > netflix2.release_year)
            {
                listSet(titlesList, j + 1, netflix1, &netflixTemp);
                listSet(titlesList, j, netflix2, &netflixTemp);
            }
        }
    }
}

void sortDate(PtList titlesList)
{
    int titlesListSize;
    listSize(titlesList, &titlesListSize);
    printf("\nPlease wait while sorting by Date...\n\n");
    for (int i = 0; i < titlesListSize; i++) //"for" cicle to run the list and change after comparation
    {
        for (int j = 0; j < titlesListSize - 1 - i; j++)
        {
            Netflix netflix1, netflix2, netflixTemp;
            listGet(titlesList, j, &netflix1);
            listGet(titlesList, j + 1, &netflix2);
            int compare = dateCompare(netflix1.date_added, netflix2.date_added);
            if (compare > 0)
            {
                listSet(titlesList, j + 1, netflix1, &netflixTemp);
                listSet(titlesList, j, netflix2, &netflixTemp);
            }
        }
    }
}

bool ratingExists(PtList ratingsList, char *str)
{
    int ratingsListSize, i = 0;
    listSize(ratingsList, &ratingsListSize);
    Netflix netflix;

    while (i < ratingsListSize) //"while" cicle to run the list and check if the string already exists there
    {
        listGet(ratingsList, i, &netflix);
        if (strcmp(str, netflix.rating) == 0)
        {
            return true;
        }
        i++;
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

PtList LOADF(PtList titlesList)
{
    listClear(titlesList); //clears the list before inserting new data
    int count = -1;  //starts the count at -1 to skip the first line from csv
    char *line = (char *)calloc(10000, sizeof(char));

    char path[] = "csv_data/";
    char *fileName = (char *)calloc(50, sizeof(char));

    printf("\nFile name: ");
    readString(fileName, 50);

    strncat(path, fileName, strlen(fileName));

    FILE *stream = fopen(path, "r");

    if (stream == NULL)
        printf("File not found.\n");

    else
    {
        while (fgets(line, 10000, stream) != NULL) //"while" cicle to run all the file until it meets the end of it
        {
            if (count == -1)
                count++;

            else
            {
                char *tmp = strdup(line);

                char **tokens = splitString(tmp, 12, ";");
                char **tokens2 = splitString(tokens[9], 2, " ");

                int duration = atoi(tokens2[0]);
                int release_year = atoi(tokens[7]);

                int day, month, year;
                char cMonth[20], cDay[20], cYear[20];
                sscanf(tokens[6], "%s %s %s", cMonth, cDay, cYear);
                strtok(cDay, ",");

                if (strcmp(cMonth, "January") == 0)
                    month = 1;
                if (strcmp(cMonth, "February") == 0)
                    month = 2;
                if (strcmp(cMonth, "March ") == 0)
                    month = 3;
                if (strcmp(cMonth, "April ") == 0)
                    month = 4;
                if (strcmp(cMonth, "May ") == 0)
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

                listAdd(titlesList, count, netflix); //adds to list

                free(tmp);
                free(tokens);
                free(tokens2);
                count++;
            }
        }

        printf("\n%d titles imported.\n", count);
        fclose(stream);
    }

    free(line);
    free(fileName);

    return titlesList;
}

PtList LOADD(PtList titlesList)
{
    listClear(titlesList); //clears the list before inserting new data
    int count = -1; //starts the count at -1 to skip the first line from csv
    char *line = (char *)calloc(10000, sizeof(char));

    FILE *stream = fopen(NETFLIX_FILE, "r");

    if (stream == NULL)
        printf("File not found.\n");

    else
    {
        while (fgets(line, 10000, stream) != NULL) //"while" cicle to run all the file until it meets the end of it
        {
            if (count == -1)
                count++;

            else
            {
                char *tmp = strdup(line);

                char **tokens = splitString(tmp, 12, ";");
                char **tokens2 = splitString(tokens[9], 2, " ");

                int duration = atoi(tokens2[0]);
                int release_year = atoi(tokens[7]);

                int day, month, year;
                char cMonth[20], cDay[20], cYear[20];
                sscanf(tokens[6], "%s %s %s", cMonth, cDay, cYear);
                strtok(cDay, ",");

                if (strcmp(cMonth, "January") == 0)
                    month = 1;
                if (strcmp(cMonth, "February") == 0)
                    month = 2;
                if (strcmp(cMonth, "March ") == 0)
                    month = 3;
                if (strcmp(cMonth, "April ") == 0)
                    month = 4;
                if (strcmp(cMonth, "May ") == 0)
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

                listAdd(titlesList, count, netflix); //adds to list

                free(tmp);
                free(tokens);
                free(tokens2);
                count++;
            }
        }

        printf("\n%d titles imported.\n", count);
        fclose(stream);
    }

    free(line);
    return titlesList;
}

void DEL(PtList list)
{
    char *idTitle = (char *)calloc(10, sizeof(char));
    printf("Title ID: ");
    readString(idTitle, 10);

    int sizeList, position;
    bool check = false;
    char c;
    listSize(list, &sizeList);

    Netflix netflix;

    for (int i = 0; i < sizeList; i++) //"for" cicle to run the list and check if the inserted title matches
    {
        listGet(list, i, &netflix);
        if (strcmp(netflix.show_id, idTitle) == 0) //if its a match, "returns" the position and "returns" true
        {
            check = true;
            position = i;
        }
    }

    if (check == false)
        printf("Title not found.\n");
    else
    {
        printf("Are you sure you want to delete %s? (y/n) ", idTitle);  //asks the user from confirmation
        scanf("%c", &c);

        if (c == 'Y' || c == 'y')
            listRemove(list, position, &netflix);   //removes the specific rank from the list
        else
            printf("%s was not deleted.\n", idTitle);
    }

    free(idTitle);
}

void CLEAR(PtList list)
{
    int sizeList;
    listSize(list, &sizeList); //check the list size
    listClear(list);        //clears the list
    printf("%d shows deleted.\n", sizeList);
}

void QUIT(PtList list)
{
    listDestroy(&list);    //destroys the list
    exit(0);
}

void GET(PtList titlesList)
{
    char *idTitle = (char *)calloc(10, sizeof(char));
    printf("Title ID: ");
    readString(idTitle, 10);

    int titlesListSize, position;
    bool check = false;
    char c;
    listSize(titlesList, &titlesListSize);

    Netflix netflix;

    for (int i = 0; i < titlesListSize; i++) //"for" cicle to run the list and check if the inserted title matches
    {
        listGet(titlesList, i, &netflix);
        if (strcmp(netflix.show_id, idTitle) == 0) //if its a match, "returns" the position and "returns" true
        {
            check = true;
            break;
        }
    }

    if (check == false)
        printf("Title not found.\n");
    else
    {
        printf("=======================================================\n");
        printf("Show Id: %s | Type: %s\n", netflix.show_id, netflix.type);
        printf("  Title: %s\n", netflix.title);
        if (strcmp(netflix.type, "Movie") == 0)
            printf("  Duration: %d min\n", netflix.duration);
        if (strcmp(netflix.type, "TV Show") == 0)
            printf("  Duration: %d season(s)\n", netflix.duration);
        printf("  Rating: %s\n", netflix.rating);
        printf("  Appears in: %s\n", netflix.listed_in);
        printf("  Date Added: %d/%d/%d | Release year: %d\n", netflix.date_added.day, netflix.date_added.month, netflix.date_added.year, netflix.release_year);
        printf("------------------------------\n");
        printf("  Director: %s\n", netflix.director);
        printf("  Country: %s\n", netflix.country);
        printf("------------------------------\n");
        printf("  Cast:\n  %s\n", netflix.cast);
        printf("------------------------------\n");
        printf("  Description:\n  %s\n", netflix.description);
        printf("=======================================================\n");
    }
    free(idTitle);
}

void LIST(PtList titlesList, int min, int max, int type)
{
    int titleSizeList;
    listSize(titlesList, &titleSizeList);
    Netflix netflix;
    char c;
    char *id = (char *)calloc(8, sizeof(char));
    if (titlesList == NULL) //check if list isn't null
        printf("There are no titles.");
    else if (titleSizeList == 0) //check if list isn't empty
        printf("There are no titles.");
    else
    {
        printf("%6s| %10s | %100s | %28s | %15s |%21s |\n", "Show ID", "Type", "Title", "Date Added", "Rating", "Duration");
        printf("%6s| %10s | %100s | %28s | %15s |%21s |\n", "-------", "-------", "-------", "-------", "-------", "-------");
        int count = 0;
        for (int rank = 0; rank < titleSizeList; rank++)
        {
            listGet(titlesList, rank, &netflix);
            if (min != -1 && max != -1) //if the asked list must have a min and max duration
            {
                if (type == TYPE) //if the asked list must have both types
                {
                    if (netflix.duration >= min && netflix.duration <= max)
                    {
                        listElemPrint(netflix);
                        count++;
                        if (count % 30 == 0)
                        {
                            printf("Continue listing (Y/n)? ");
                            readChar(&c);
                            if (c == 'Y' || c == 'y')
                                continue;
                            else
                                break;
                        }
                        if (count == titleSizeList)
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

                    if (strcmp(netflix.type, id) == 0) //if its a match
                    {
                        if (netflix.duration >= min && netflix.duration <= max)
                        {
                            listElemPrint(netflix);
                            count++;
                            if (count % 30 == 0)
                            {
                                printf("Continue listing (Y/n)? ");
                                readChar(&c);
                                if (c == 'Y' || c == 'y')
                                    continue;
                                else
                                    break;
                            }
                            if (count == titleSizeList)
                                printf("\nThere are no more netflix titles.\n");
                        }
                    }
                    else
                        continue;
                }
            }
            else //if the asked list doesn't have a min and max duration
            {
                if (type == TYPE) //if the asked list must have both types
                {
                    listElemPrint(netflix);
                    count++;
                    if (count % 30 == 0)
                    {
                        printf("Continue listing (Y/n)? ");
                        readChar(&c);
                        if (c == 'Y' || c == 'y')
                            continue;
                        else
                            break;
                    }
                    if (count == titleSizeList)
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

                    if (strcmp(netflix.type, id) == 0) //if its a match
                    {
                        listElemPrint(netflix);
                        count++;
                        if (count % 30 == 0)
                        {
                            printf("Continue listing (Y/n)? ");
                            readChar(&c);
                            if (c == 'Y' || c == 'y')
                                continue;
                            else
                                break;
                        }
                        if (count == titleSizeList)
                            printf("\nThere are no more netflix titles.\n");
                    }
                    else
                        continue;
                }
            }
        }
    }
    printf("\n");
    free(id);
}

void STATS(PtList titlesList)
{
    int titleSizeList = 0, min = 300, max = 0, minS = 100, maxS = 0;
    double movieCount = 0, totalMinutes = 0, totalSeasons = 0, tvCount = 0;

    listSize(titlesList, &titleSizeList); //gets the list size
    Netflix netflix;
    for (int i = 0; i < titleSizeList; i++) //"for" cicle to run the list
    {
        listGet(titlesList, i, &netflix);
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
    printf("Movie count: <%.0f> | Min. duration: <%d> | Max. duration: <%d> | Avg. duration: <%.0f> \nTV Show count: <%.0f> | Min. seasons <%d> | Max. seasons <%d> | Avg. seasons: <%.0f> \n\nTotals:\n <%.0f> total minutes of movie time \n <%.0f> total seasons of tv shows\n", movieCount, min, max, averageDuration, tvCount, minS, maxS, averageSeasons, totalMinutes, totalSeasons);
}

void MTIME(PtList titlesList)
{
    int min;
    int max;

    printf("Min: ");
    readInteger(&min);      //asks the min duration value

    printf("Max: ");
    readInteger(&max);      //asks the max duration value

    if (min <= max)     //check if the min is lower or equal than the max duration
    {
        sortDuration(titlesList);            //sorts the list by duration
        LIST(titlesList, min, max, TYPE_MOVIE); //prints the list
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
    int mainSizeList;
    Netflix netflix;
    listSize(mainList, &mainSizeList);
    PtList titlesList = listCreate();    //creates a list
    int count = 0;

    printf("Please insert the title name: ");
    readString(titleName, 100);

    int titleNameCount = 0;
    while (titleNameCount < strlen(titleName))  //turns the string into lowercase
    {
        titleName[titleNameCount] = tolower(titleName[titleNameCount]);
        titleNameCount++;
    }

    for (int i = 0; i < mainSizeList; i++) //"for" cicle to run the main list
    {
        listGet(mainList, i, &netflix);

        strcpy(netflixTitleName, netflix.title);

        int netflixTitleNameCount = 0;
        while (netflixTitleNameCount < strlen(netflixTitleName)) //turns the string into lowercase
        {
            netflixTitleName[netflixTitleNameCount] = tolower(netflixTitleName[netflixTitleNameCount]);
            netflixTitleNameCount++;
        }

        if (strstr(netflixTitleName, titleName) != NULL) //if the title string is in the title
        {
            listAdd(titlesList, count, netflix); //adds to the list
            count++;
        }
    }
    sortDate(titlesList);    //sorts the list by date
    printf("Query is \"%s\" -----\n", titleName);   
    LIST(titlesList, -1, -1, TYPE);  //prints the list
    free(titleName);
    free(netflixTitleName);
}

void SEARCHC(PtList mainList)
{
    char *castName = (char *)calloc(640, sizeof(char));
    char *netflixCastName = (char *)calloc(640, sizeof(char));
    int mainSizeList;
    Netflix netflix;
    listSize(mainList, &mainSizeList);
    PtList titlesList = listCreate(); //creates a list
    int count = 0;

    printf("Please insert cast name: ");
    readString(castName, 500);

    int castNameCount = 0;
    while (castNameCount < strlen(castName))    //turns the string into lowercase
    {
        castName[castNameCount] = tolower(castName[castNameCount]);
        castNameCount++;
    }

    for (int i = 0; i < mainSizeList; i++) //"for" cicle to run the main list
    {
        listGet(mainList, i, &netflix);

        strcpy(netflixCastName, netflix.cast);

        int netflixCastNameCount = 0;
        while (netflixCastNameCount < strlen(netflixCastName)) //turns the string into lowercase
        {
            netflixCastName[netflixCastNameCount] = tolower(netflixCastName[netflixCastNameCount]);
            netflixCastNameCount++;
        }

        if (strstr(netflixCastName, castName) != NULL) //if the cast string is in the cast
        {
            listAdd(titlesList, count, netflix); //adds to the list
            count++;
        }
    }
    sortDate(titlesList); //sorts the list by date
    printf("Query is \"%s\" -----\n", castName);
    LIST(titlesList, -1, -1, TYPE); //prints the list
    free(castName);
    free(netflixCastName);
}

PtList RATINGS(PtList titlesList, bool print)
{
    PtList ratingsList = listCreate(); //creates a new list only for the ratings
    int titleSizeList, ratingSizeList, count;
    listSize(titlesList, &titleSizeList);
    Netflix netflix;
    Netflix ratingsData;

    for (int i = 0; i < titleSizeList; i++) //"for" cicle to run the list
    {
        listGet(titlesList, i, &netflix);

        if (!ratingExists(ratingsList, netflix.rating)) //if doesnt exist
        {
            listAdd(ratingsList, count, netflix);   //adds to list
            count++;
        }
    }

    sortRating(ratingsList);    //sorts the list by rating

    listSize(ratingsList, &ratingSizeList);

    for (int k = 0; k < ratingSizeList; k++) //"for" cicle to run the list
    {
        listGet(ratingsList, k, &ratingsData);
        if (print == true)  //only prints the list if necessary
            printf("%s\n", ratingsData.rating);
    }

    return ratingsList;
}

void CATEGORIES(PtList list)
{
    Netflix netflix, netflix1, netflix2;
    PtMap resultMap = mapCreate();
    int size, resultSize, count = 0;
    listSize(list, &size);

    char *help;

    printf("Please wait while processing all categories...\n");
    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &netflix);
        char *token = strtok(netflix.listed_in, ",");
        while (token != NULL)
        {
            token = trimWhiteSpace(token);
            StringWrap help1 = stringWrapCreate(token);
            mapPut(resultMap, help1, help1);
            token = strtok(NULL, ",");
        }
    }
    PtList resultList = listCreate();

    MapKey *categorias = mapKeys(resultMap);

    mapSize(resultMap, &resultSize);
    for (int z = 0; z < resultSize; z++)
    {

        strcpy(netflix.listed_in, categorias[z].text);
        listAdd(resultList, z, netflix);
    }

    sortAlphaCategories(resultList);

    printf("\nAll categories:\n");
    for (int k = 0; k < resultSize; k++)
    {
        listGet(resultList, k, &netflix2);
        printf("%s\n", netflix2.listed_in);
    }

    free(categorias);
    listDestroy(&resultList);
    mapDestroy(&resultMap);
}

PtList DIRECTORS(PtList list, bool print)
{
    Netflix netflix, netflix1, netflix2;
    PtMap resultMap = mapCreate();
    int size, resultSize, count = 0;
    listSize(list, &size);

    char *help;

    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &netflix);
        char *token = strtok(netflix.director, ",");
        while (token != NULL)
        {
            token = trimWhiteSpace(token);
            StringWrap help1 = stringWrapCreate(token);
            mapPut(resultMap, help1, help1);
            token = strtok(NULL, ",");
        }
    }
    PtList directorsList = listCreate();

    MapKey *categorias = mapKeys(resultMap);

    mapSize(resultMap, &resultSize);
    for (int z = 0; z < resultSize; z++)
    {

        strcpy(netflix.director, categorias[z].text);
        listAdd(directorsList, z, netflix);
    }

    sortAlphaCategories(directorsList);

    for (int k = 0; k < resultSize; k++)
    {
        listGet(directorsList, k, &netflix2);
        if(print == true)
        printf("%s\n", netflix2.director);
    }

    free(categorias);
    mapDestroy(&resultMap);

    return directorsList;
}

void SEGMENT(PtList titlesList)
{

    printf("---------------------------------------\n");
    //RATINGS
    printf("Creating segment_by_rating.txt file\n");
    PtList ratingsList = RATINGS(titlesList, false); //gets all the unique ratings
    int ratingSizeList;
    int titleSizeList;
    Netflix netflix;
    listSize(titlesList, &titleSizeList);   //gets the titles list size
    listSize(ratingsList, &ratingSizeList); //gets the ratings list size
    Netflix ratingsData;
    sortYear(titlesList); //sorts the titles list by year

    FILE *fileR = fopen("segment_by_rating.txt", "w+"); //creates a file in writing mode

    char *str0 = (char *)calloc(80, sizeof(char));
    char *str1 = (char *)calloc(80, sizeof(char));
    char *str2 = (char *)calloc(500, sizeof(char));
    char *str3 = (char *)calloc(2, sizeof(char));
    sprintf(str0, "%d shows imported\n", titleSizeList);
    fputs(str0, fileR); //writes string in file

    for (int i = 0; i < ratingSizeList; i++) //"for" cicle to run the rating list
    {
        listGet(ratingsList, i, &ratingsData);
        sprintf(str1, "%s ------\n", ratingsData.rating);
        fputs(str1, fileR); //writes string in file

        for (int j = 0; j < titleSizeList; j++) //"for" cicle to run the title list
        {
            listGet(titlesList, j, &netflix);
            if (strcmp(ratingsData.rating, netflix.rating) == 0)
            {
                if (strcmp(netflix.type, "Movie") == 0) //if its a movie
                {
                    sprintf(str2, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d min.\n", 6, netflix.show_id, 10, netflix.type, 100, netflix.title, 20, netflix.release_year, 15, netflix.rating, 15, netflix.duration);
                    fputs(str2, fileR); //writes string in file
                }
                if (strcmp(netflix.type, "TV Show") == 0) //if its a movie
                {
                    sprintf(str2, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d season(s)\n", 6, netflix.show_id, 10, netflix.type, 100, netflix.title, 20, netflix.release_year, 15, netflix.rating, 15, netflix.duration);
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

    printf("---------------------------------------\n");
    //DIRECTORS
    printf("Creating segment_by_directors.txt file\n");
    PtList directorsList = DIRECTORS(titlesList, false); //gets all the unique ratings
    int directorSizeList;
    listSize(titlesList, &titleSizeList);       //gets the titles list size
    listSize(directorsList, &directorSizeList); //gets the ratings list size
    Netflix directorsData;
    sortYear(titlesList); //sorts the titles list by year

    FILE *fileD = fopen("segment_by_directors.txt", "w+"); //creates a file in writing mode

    char *str4 = (char *)calloc(80, sizeof(char));
    char *str5 = (char *)calloc(80, sizeof(char));
    char *str6 = (char *)calloc(500, sizeof(char));
    char *str7 = (char *)calloc(2, sizeof(char));
    sprintf(str4, "%d shows imported\n", titleSizeList);
    fputs(str4, fileD); //writes string in file

    for (int i = 0; i < directorSizeList; i++) //"for" cicle to run the rating list
    {
        listGet(directorsList, i, &directorsData);
        sprintf(str5, "%s ------\n", directorsData.director);
        fputs(str5, fileD); //writes string in file

        for (int j = 0; j < titleSizeList; j++) //"for" cicle to run the title list
        {
            listGet(titlesList, j, &netflix);
            if (strcmp(directorsData.director, netflix.director) == 0)
            {
                if (strcmp(netflix.type, "Movie") == 0) //if its a movie
                {
                    sprintf(str6, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d min.\n", 6, netflix.show_id, 10, netflix.type, 100, netflix.title, 20, netflix.release_year, 15, netflix.rating, 15, netflix.duration);
                    fputs(str6, fileD); //writes string in file
                }
                if (strcmp(netflix.type, "TV Show") == 0) //if its a movie
                {
                    sprintf(str6, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d season(s)\n", 6, netflix.show_id, 10, netflix.type, 100, netflix.title, 20, netflix.release_year, 15, netflix.rating, 15, netflix.duration);
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
}

void SEGMENT2(PtList titlesList)
{
    
}