#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "input.h"
#include "list.h"
#include <ctype.h>

#define NETFLIX_FILE "csv_data/netflix_titles.csv"
#define TYPE 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2
#define ORDER_ALPH_ASC 3
#define ORDER_DURATION_ASC 5
#define ORDER_DURATION_DESC 6

PtList LOADF(PtList list){

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

                char **tokens2 = splitString(tokens[9], 2, " ");
                int duration = atoi(tokens2[0]);

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], duration, tokens[10], tokens[11]);

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

                char **tokens2 = splitString(tokens[9], 2, " ");
                int duration = atoi(tokens2[0]);

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], duration, tokens[10], tokens[11]);

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

PtList sort(PtList list, int type, int order)
{
    int size;
    listSize(list, &size);
    if (list == NULL)
    {
        printf("(List NULL)\n");
    }
    else if (size == 0)
    {
        printf("(List EMPTY)\n");
    }
    else
    {
        if (type == TYPE)
        {
            if (order == ORDER_ALPH_ASC)
            {
                printf("Please wait while sorting...\n");
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size - 1 - i; j++)
                    {
                        ListElem elem1, elem2, elem3;
                        listGet(list, j, &elem1);
                        listGet(list, j + 1, &elem2);
                        if (strcmp(elem1.title, elem2.title) > 0)
                        {
                            listSet(list, j + 1, elem1, &elem3);
                            listSet(list, j, elem2, &elem3);
                        }
                    }
                }
            }
            if (order == ORDER_DURATION_ASC)
            {
            }
            if (order == ORDER_DURATION_DESC)
            {
            }
        }
        if (type == TYPE_MOVIE)
        {
            if (order == ORDER_ALPH_ASC)
            {
            }
            if (order == ORDER_DURATION_ASC)
            {
            }
            if (order == ORDER_DURATION_DESC)
            {
                printf("Please wait while sorting...\n");
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size - 1 - i; j++)
                    {
                        ListElem elem1, elem2, elem3;
                        listGet(list, j, &elem1);
                        listGet(list, j + 1, &elem2);
                        if (elem1.duration < elem2.duration)
                        {
                            listSet(list, j + 1, elem1, &elem3);
                            listSet(list, j, elem2, &elem3);
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
        if (type == TYPE_SHOW)
        {
            if (order == ORDER_ALPH_ASC)
            {
            }
            if (order == ORDER_DURATION_ASC)
            {
            }
            if (order == ORDER_DURATION_DESC)
            {
            }
        }
    }
    return list;
}

void LIST(PtList list, int min, int max, int type)
{
    printf("Show Id | Type | Title | Date Added | Rating | Duration\n");
    int size;
    listSize(list, &size);
    ListElem elem;
    char c;
    if (list == NULL)
        printf("(List NULL)\n");
    else if (size == 0)
        printf("(List EMPTY)\n");
    else
    {
        int count = 0;
        for (int rank = 0; rank < size; rank++)
        {
            listGet(list, rank, &elem);
            if (min != -1 && max != -1)
            {
                if (type == TYPE)
                {
                    if (elem.duration >= min && elem.duration <= max)
                    {
                        listElemPrint(elem);
                        count++;
                        if (count % 30 == 0)
                        {
                            printf("Do you want to show +30 titles? (y/n)? ");
                            readChar(&c);
                            if (c == 'Y' || c == 'y')
                                continue;
                            else
                                break;
                        }
                        if (count == size)
                            printf("There are no more netflix titles.\n");
                    }
                }
                if (type == TYPE_MOVIE || type == TYPE_SHOW)
                {
                    char id[8];
                    if (type == TYPE_MOVIE)
                    {
                        strcpy(id, "Movie");
                    }

                    if (type == TYPE_SHOW)
                    {
                        strcpy(id, "TV Show");
                    }

                    if (strcmp(elem.type, id) == 0)
                    {
                        if (elem.duration >= min && elem.duration <= max)
                        {
                            listElemPrint(elem);
                            count++;
                            if (count % 30 == 0)
                            {
                                printf("Do you want to show +30 titles? (y/n)? ");
                                readChar(&c);
                                if (c == 'Y' || c == 'y')
                                    continue;
                                else
                                    break;
                            }
                            if (count == size)
                                printf("There are no more netflix titles.\n");
                        }
                    }
                    else
                        continue;
                }
            }
        }
    }
    printf("\n");
}

void MTIME(PtList list)
{
    char min[4];
    char max[4];

    printf("Min: ");
    readString(min, 4);

    printf("Max: ");
    readString(max, 4);
}

void SEARCHT(PtList list)
{
    char titleLower[640];
    char title[640];
    int sizeList;
    Netflix netflix;
    printf("Please insert the netflix title: ");
    readString(title, 640);
    listSize(list, &sizeList);
    int i = 0;

    int size = strlen(title);

    while (i != size)
    {
        title[i] = tolower(title[i]);
        i++;
    }
    for (int i = 0; i < sizeList; i++)
    {
        listGet(list, i, &netflix);
        int i = 0;

        int size = strlen(netflix.cast);
        while (i != size)
        {
            titleLower[i] = tolower(netflix.cast[i]);
            i++;
        }
        if (strstr(titleLower, title) != NULL)
        {
            printf("\nTitles with that name:\n%s\n", netflix.title);
            break;
        }
    }
    // Falta ordenar pela data
}

void netflixPrint(Netflix *pNetflix)
{
    printf("%s  |  %s  |  %s  |  %s  |  %s  |  %d\n", pNetflix->show_id, pNetflix->type, pNetflix->title, pNetflix->date_added, pNetflix->rating, pNetflix->duration);
}

void STATS(PtList list)
{
    int size = 0, movieCount = 0, tvCount = 0, min = 300, max = 0, minS = 100, maxS = 0, totalMinutes = 0, totalSeasons = 0;
    listSize(list, &size);
    Netflix netflix;
    for (int i = 0; i < size; i++)
    {
        listGet(list, i, &netflix);
        if (strcmp(netflix.type, "Movie") == 0)
        {
            movieCount++;
            totalMinutes += netflix.duration;
            if (netflix.duration < min)
            {
                min = netflix.duration;
            }
            if (netflix.duration > max)
            {
                max = netflix.duration;
            }
        }
        if (strcmp(netflix.type, "TV Show") == 0)
        {
            tvCount++;
            totalSeasons += netflix.duration;
            if (netflix.duration < minS)
            {
                minS = netflix.duration;
            }
            if (netflix.duration > maxS)
            {
                maxS = netflix.duration;
            }
        }
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