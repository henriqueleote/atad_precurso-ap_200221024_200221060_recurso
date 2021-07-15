#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "input.h"
#include "list.h"
#include "math.h"
#include <ctype.h>

#define NETFLIX_FILE "csv_data/netflix_titles.csv"

PtList LOADF(PtList list)
{

    listClear(list); //limpa a lista
    char path[] = "csv_data/";
    char fileName[50];

    printf("Nome do ficheiro: ");
    readString(fileName, 50);

    strncat(path, fileName, strlen(fileName));

    int count = -1;
    char line[10000];

    FILE *stream = fopen(path, "r");

    if (stream == NULL)
        printf("Ficheiro não encontrado\n");

    else
    {
        while (fgets(line, 10000, stream) != NULL)
        {
            if (count == -1)
                count++;

            else
            {
                char *tmp = strdup(line);

                char **tokens = splitString(tmp, 12, ";");

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], tokens[11]);

                listAdd(list, count, netflix); // É count - 1 para descontar a primeira linha

                free(tokens);
                free(tmp);
                count++;
            }
        }

        printf("\n%d titles imported\n", count);
        fclose(stream);

        //printf("Sorting the list...\n");
        //orderListSelect(list);
        //return list;
    }

    return list;
}

PtList LOADD(PtList list)
{

    listClear(list); //limpa a lista
    int count = -1;
    char line[10000];

    FILE *stream = fopen(NETFLIX_FILE, "r");

    if (stream == NULL)
        printf("File not found\n");

    else
    {
        while (fgets(line, 10000, stream) != NULL)
        {
            if (count == -1)
                count++;

            else
            {
                char *tmp = strdup(line);

                char **tokens = splitString(tmp, 12, ";");

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], tokens[11]);

                listAdd(list, count, netflix); // É count - 1 para descontar a primeira linha

                free(tokens);
                free(tmp);
                count++;
            }
        }

        printf("\n%d titles imported\n", count);
        fclose(stream);

        //printf("Sorting the list...\n");
        //orderListSelect(list);
        //return list;
    }

    return list;
}

void DEL(PtList list)
{
    char idTitle[10];
    printf("Title ID: ");
    readString(idTitle, 10);

    int size, position;
    bool check = false;
    char c;
    listSize(list, &size);

    ListElem elem;

    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &elem);
        if (strcmp(elem.show_id, idTitle) == 0)
        {
            check = true;
            position = i;
        }
    }

    if (check == false)
        printf("Title not found.\n");
    else
    {
        printf("Delete %s, are you sure (y/n)? ", idTitle);
        scanf("%c", &c);

        if (c == 'Y' || c == 'y')
            listRemove(list, position, &elem);
        else
            printf("%s was not deleted.n", idTitle);
    }
}

void CLEAR(PtList list)
{
    int size;
    listSize(list, &size);
    listClear(list);
    printf("%d shows deleted.\n", size);
}

void QUIT(PtList list)
{
    listClear(list);
    exit(0);
}

void GET(PtList list)
{
    char idTitle[10];
    printf("Title ID: ");
    readString(idTitle, 10);

    int size, position;
    bool check = false;
    char c;
    listSize(list, &size);

    ListElem elem;

    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &elem);
        if (strcmp(elem.show_id, idTitle) == 0)
            check = true;
    }

    if (check == false)
        printf("Title not found.\n");
    else
        listElemPrint(elem);
}

void LIST(PtList list)
{
    printf("Show Id | Type | Title | Date Added | Rating | Duration\n");
    listPrint(list);
}

void netflixPrint(Netflix *pNetflix)
{
    printf("%s  |  %s  |  %s  |  %s  |  %s  |  %s\n", pNetflix->show_id, pNetflix->type, pNetflix->title, pNetflix->date_added, pNetflix->rating, pNetflix->duration);
}

void STATS(PtList list)
{
    int size = 0, movieCount = 0, tvCount = 0, min = 300, max = 0, minS = 100, maxS = 0, totalMinutes = 0, totalSeasons = 0, duration = 0;
    listSize(list, &size);
    Netflix netflix;
    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &netflix);
        char **tokens = splitString(netflix.duration, 2, " ");
        duration = atoi(tokens[0]);
        if (strcmp(netflix.type, "Movie") == 0)
        {
            movieCount++;
            totalMinutes += duration;
            if (duration < min)
            {
                min = duration;
            }
            if (duration > max)
            {
                max = duration;
            }
        }
        if (strcmp(netflix.type, "TV Show") == 0)
        {
            tvCount++;
            totalSeasons += duration;
            if (duration < minS)
            {
                minS = duration;
            }
            if (duration > maxS)
            {
                maxS = duration;
            }
        }

        free(tokens);
    }
    double averageDuration = totalMinutes / movieCount;
    double averageSeasons = totalSeasons / tvCount;
    printf("Movie count: <%d> | Min. duration: <%d> | Max. duration: <%d> | Avg. duration: <%.0f> \nTV Show count: <%d> | Min. seasons <%d> | Max. seasons <%d> | Avg. seasons: <%.0f> \n\nTotals:\n <%d> total minutes of movie time \n <%d> total seasons of tv shows\n", movieCount, min, max, averageDuration, tvCount, minS, maxS, averageSeasons, totalMinutes, totalSeasons);
}

void SEARCHC(PtList list)
{
    char castNameLower[640];
    char castName[640];
    int sizeList;
    Netflix netflix;
    printf("Please insert the cast member(s) name: ");
    readString(castName, 640);
    listSize(list, &sizeList);
    int i = 0;

    int size = strlen(castName);

    while (i != size)
    {
        castName[i] = tolower(castName[i]);
        i++;
    }
    for (int i = 0; i < sizeList; i++)
    {
        listGet(list, i, &netflix);
        int i = 0;

        int size = strlen(netflix.cast);
        while (i != size)
        {
            castNameLower[i] = tolower(netflix.cast[i]);
            i++;
        }
        if (strstr(castNameLower, castName) != NULL)
        {
            printf("\nTitles with that cast:\n%s\n", netflix.title);
            break;
        }
    }
    // Falta ordenar pela data
}

void RATINGS(PtList list)
{
    PtList resultList;
    int size, count;
    char ratings[100] = " ";
    listSize(list, &size);
    Netflix netflix;

    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &netflix);
        if (strstr(ratings, netflix.rating) == NULL)
        {
            strcat(ratings, strcat(netflix.rating, " "));
            //listAdd(resultList, count++, netflix);
        }
    }

    printf("All ratings: \n %s \n", ratings);
}