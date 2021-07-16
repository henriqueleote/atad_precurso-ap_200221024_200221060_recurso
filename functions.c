#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "input.h"
#include "list.h"
#include "map.h"
#include "date.h"
#include <ctype.h>

#define NETFLIX_FILE "csv_data/netflix_titles.csv"
#define TYPE 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2

void sortRating(PtList titlesList)
{
    int titlesListSize;
    listSize(titlesList, &titlesListSize);
    printf("Please wait while sorting by Rating...\n");
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
    printf("Please wait while sorting by Title...\n");
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

void sortDuration(PtList titlesList)
{
    int titlesListSize;
    listSize(titlesList, &titlesListSize);
    printf("Please wait while sorting by Duration...\n");
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
    printf("Please wait while sorting by Year...\n");
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
    printf("Please wait while sorting by Year...\n");
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
    char line[10000];

    char path[] = "csv_data/";
    char fileName[50];

    printf("File name: ");
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

    return titlesList;
}

PtList LOADD(PtList titlesList)
{

    listClear(titlesList); //clears the list before inserting new data
    int count = -1; //starts the count at -1 to skip the first line from csv
    char line[10000];

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

    return titlesList;
}

void DEL(PtList list)
{
    char idTitle[10];
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
    char idTitle[10];
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
}

void LIST(PtList titlesList, int min, int max, int type)
{
    int titleSizeList;
    listSize(titlesList, &titleSizeList);
    Netflix netflix;
    char c;
    if (titlesList == NULL) //check if list isn't null
        printf("There are no titles.");
    else if (titleSizeList == 0) //check if list isn't empty
        printf("There are no titles.");
    else
    {
        printf("%6s| %10s | %100s | %28s | %15s |%21s |\n", "Show ID", "Type", "Title", "Date Added", "Rating", "Duration");
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
                    char id[8];
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
                    char id[8];
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
    char titleName[120];
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

        char netflixTitleName[640];
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
}

void SEARCHC(PtList mainList)
{
    char castName[1000];
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

        char netflixCastName[640];
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
}

PtList RATINGS(PtList titlesList, bool print)
{
    PtList ratingsList = listCreate(); //creates a new list only for the ratings
    int titleSizeList, ratingSizeList, count;
    char ratings[100] = " ";
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

void SEGMENT(PtList titlesList)
{
    printf("---------------------------------------\n");
    printf("Creating segment_by_rating.txt file\n");
    PtList ratingsList = RATINGS(titlesList, false); //gets all the unique ratings
    int ratingSizeList;
    int titleSizeList;
    listSize(titlesList, &titleSizeList);        //gets the titles list size
    listSize(ratingsList, &ratingSizeList);     //gets the ratings list size
    Netflix netflix;
    Netflix ratingsData;
    sortYear(titlesList); //sorts the titles list by year

    FILE *file = fopen("segment_by_rating.txt", "w+");  //creates a file in writing mode

    char str0[80];
    sprintf(str0, "%d shows imported\n", titleSizeList);
    fputs(str0, file);  //writes string in file

    for (int i = 0; i < ratingSizeList; i++) //"for" cicle to run the rating list
    {
        listGet(ratingsList, i, &ratingsData);
        char str1[80];
        sprintf(str1, "%s ------\n", ratingsData.rating);
        fputs(str1, file); //writes string in file

        for (int j = 0; j < titleSizeList; j++) //"for" cicle to run the title list
        {
            listGet(titlesList, j, &netflix);
            if (strcmp(ratingsData.rating, netflix.rating) == 0)
            {
                char str2[500];
                if (strcmp(netflix.type, "Movie") == 0) //if its a movie
                {
                    sprintf(str2, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d min.\n", 6, netflix.show_id, 10, netflix.type, 100, netflix.title, 20, netflix.release_year, 15, netflix.rating, 15, netflix.duration);
                    fputs(str2, file); //writes string in file
                }
                if (strcmp(netflix.type, "TV Show") == 0) //if its a movie
                {
                    sprintf(str2, "%*s  |  %*s  |  %*s  |  %*d  |  %*s  |  %*d season(s)\n", 6, netflix.show_id, 10, netflix.type, 100, netflix.title, 20, netflix.release_year, 15, netflix.rating, 15, netflix.duration);
                    fputs(str2, file); //writes string in file
                }
            }
        }
        char str3[2] = "\n";
        fputs(str3, file); //writes string in file
    }
    fclose(file);
}