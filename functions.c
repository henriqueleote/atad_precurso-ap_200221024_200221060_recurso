#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "input.h"
#include "list.h"
#include "date.h"
#include <ctype.h>

#define NETFLIX_FILE "csv_data/netflix_titles.csv"
#define TYPE 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2
#define ORDER_ALPH_ASC 3
#define ORDER_DURATION_DESC 6
#define ORDER_RATING 5

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

                char **tokens2 = splitString(tokens[9], 2, " ");
                int duration = atoi(tokens2[0]);

                /*char **tokensDate = splitString(tokens[6], 3, " ");
                int month;
                int day = atoi(strtok(tokensDate[1], ","));
                if (strcmp(tokensDate[0], "January") == 0)
                    month = 1;
                if (strcmp(tokensDate[0], "February") == 0)
                    month = 2;
                if (strcmp(tokensDate[0], "March ") == 0)
                    month = 3;
                if (strcmp(tokensDate[0], "April ") == 0)
                    month = 4;
                if (strcmp(tokensDate[0], "May ") == 0)
                    month = 5;
                if (strcmp(tokensDate[0], "June") == 0)
                    month = 6;
                if (strcmp(tokensDate[0], "July") == 0)
                    month = 7;
                if (strcmp(tokensDate[0], "August") == 0)
                    month = 8;
                if (strcmp(tokensDate[0], "September") == 0)
                    month = 9;
                if (strcmp(tokensDate[0], "October") == 0)
                    month = 10;
                if (strcmp(tokensDate[0], "November") == 0)
                    month = 11;
                if (strcmp(tokensDate[0], "December") == 0)
                    month = 12;
                int year = atoi(tokensDate[2]);*/

                Date date = createDate(10, 10, 2000);

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], date, tokens[7], tokens[8], duration, tokens[10], tokens[11]);

                listAdd(list, count, netflix); // É count - 1 para descontar a primeira linha

                free(tokens);
                free(tokens2);
                //free(tokensDate);
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

                /*char **tokensDate = splitString(tokens[6], 3, " ");
                int month;
                int day = atoi(strtok(tokensDate[1], ","));
                if (strcmp(tokensDate[0], "January") == 0)
                    month = 1;
                if (strcmp(tokensDate[0], "February") == 0)
                    month = 2;
                if (strcmp(tokensDate[0], "March ") == 0)
                    month = 3;
                if (strcmp(tokensDate[0], "April ") == 0)
                    month = 4;
                if (strcmp(tokensDate[0], "May ") == 0)
                    month = 5;
                if (strcmp(tokensDate[0], "June") == 0)
                    month = 6;
                if (strcmp(tokensDate[0], "July") == 0)
                    month = 7;
                if (strcmp(tokensDate[0], "August") == 0)
                    month = 8;
                if (strcmp(tokensDate[0], "September") == 0)
                    month = 9;
                if (strcmp(tokensDate[0], "October") == 0)
                    month = 10;
                if (strcmp(tokensDate[0], "November") == 0)
                    month = 11;
                if (strcmp(tokensDate[0], "December") == 0)
                    month = 12;
                int year = atoi(tokensDate[2]);*/

                Date date = createDate(10, 10, 2000);

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], date, tokens[7], tokens[8], duration, tokens[10], tokens[11]);

                listAdd(list, count, netflix); // É count - 1 para descontar a primeira linha

                free(tokens);
                free(tokens2);
                //free(tokensDate);
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

PtList sort(PtList list, int order)
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
        if (order == ORDER_RATING){
            printf("Please wait while sorting...\n");
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size - 1 - i; j++)
                {
                    ListElem elem1, elem2, elem3;
                    listGet(list, j, &elem1);
                    listGet(list, j + 1, &elem2);
                    if (strcmp(elem1.rating, elem2.rating) > 0)
                    {
                        listSet(list, j + 1, elem1, &elem3);
                        listSet(list, j, elem2, &elem3);
                    }
                }
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
            else
            {
                if (type == TYPE)
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
    int min;
    int max;

    printf("Min: ");
    readInteger(&min);

    printf("Max: ");
    readInteger(&max);

    if(min<max){
        sort(list, ORDER_DURATION_DESC);
        LIST(list, min, max, TYPE_MOVIE);
    }
    else
    {
        printf("Min can't be bigger than max.\n");
    }
}

void SEARCHT(PtList list)
{
    char titleName[640];
    int sizeList;
    Netflix netflix;
    listSize(list, &sizeList);
    PtList titleList = listCreate();
    int count = 0;

    printf("Please insert the title name: ");
    readString(titleName, 640);

    for (int i = 0; i < sizeList; i++)
    {
        listGet(list, i, &netflix);
        if (strstr(netflix.title, titleName) != NULL)
        {
            listAdd(titleList, count, netflix);
            count++;
        }
    }
    LIST(titleList, -1, -1, TYPE);
}

void netflixPrint(Netflix *pNetflix)
{
    if (strcmp(pNetflix->type,"Movie")==0)
        printf("%s  |  %s  |  %s  |  %d/%d/%d  |  %s  |  %d min.\n", pNetflix->show_id, pNetflix->type, pNetflix->title, pNetflix->date_added.day, pNetflix->date_added.month, pNetflix->date_added.year, pNetflix->rating, pNetflix->duration);
    if (strcmp(pNetflix->type, "TV Show") == 0)
        printf("%s  |  %s  |  %s  |  %d/%d/%d  |  %s  |  %d seasons\n", pNetflix->show_id, pNetflix->type, pNetflix->title, pNetflix->date_added.day, pNetflix->date_added.month, pNetflix->date_added.year, pNetflix->rating, pNetflix->duration);
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
    char castName[640];
    int sizeList;
    Netflix netflix;
    listSize(list, &sizeList);
    PtList castList = listCreate();
    int count = 0;

    printf("Please insert the cast member(s) name: ");
    readString(castName, 640);

    for (int i = 0; i < sizeList; i++)
    {
        listGet(list, i, &netflix);
        if (strstr(netflix.cast, castName) != NULL)
        {
            listAdd(castList, count, netflix);
            count++;
        }
    }
    LIST(castList, -1, -1, TYPE);
}

void RATINGS(PtList list)
{
    PtList resultList = listCreate();
    int sizeList, sizeResultList, count;
    char ratings[100] = " ";
    listSize(list, &sizeList);
    Netflix netflix;
    Netflix ratingsData;

    for (int i = 0; i < sizeList; i++)
    {
        listGet(list, i, &netflix);
        if (strstr(ratings, netflix.rating) == NULL)
        {
            strcat(ratings, strcat(netflix.rating, " "));
            listAdd(resultList, count, netflix);
            count++;
        }
    }
    sort(resultList, ORDER_RATING);

    listSize(resultList, &sizeResultList);

    for (int k = 0; k < sizeResultList; k++)
    {
        listGet(resultList, k, &ratingsData);
        printf("%s\n", ratingsData.rating);
    }
}

void CATEGORIES(PtList list)
{
    PtList resultList = listCreate();
    int sizeList, sizeResultList, count;
    char categories[1500] = " ";
    listSize(list, &sizeList);
    Netflix netflix;
    Netflix categoriesData;

    for (int i = 0; i < sizeList; i++)
    {
        listGet(list, i, &netflix);
        if (strstr(categories, netflix.listed_in) == NULL)
        {
            strcat(categories, strcat(netflix.listed_in, " "));
            listAdd(resultList, count, netflix);
            count++;
        }
    }
    /*sort(resultList, ORDER_RATING);

    listSize(resultList, &sizeResultList);

    for (int k = 0; k < sizeResultList; k++)
    {
        listGet(resultList, k, &ratingsData);
        printf("%s\n", ratingsData.rating);
    }*/
}