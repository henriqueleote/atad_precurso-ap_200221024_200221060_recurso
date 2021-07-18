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
#include "auxiliarFuncs.h"

#define NETFLIX_FILE "csv_data/netflix_titles.csv"
#define ALL 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2

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