#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "input.h"
#include "list.h"

#define NETFLIX_FILE "csv_data/netflix_titles.csv"

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
        while (fgets(line, 10000, stream)!=NULL)
        {
            if (count == -1)   count++;

            else{
                char *tmp = strdup(line);

                char **tokens = splitString(tmp, 12, ";");

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], tokens[11]);

                listAdd(list, count, netflix); // É count - 1 para descontar a primeira linha

                free(tokens);
                free(tmp);
                count++;
            }
        }
        count--;

        printf("\n%d titles imported\n", count);
        fclose(stream);

        //printf("Sorting the list...\n");
        //orderListSelect(list);
        //return list;
    }

    return list;
}

PtList LOADD(PtList list){

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

                Netflix netflix = netflixCreate(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], tokens[11]);

                listAdd(list, count, netflix); // É count - 1 para descontar a primeira linha

                free(tokens);
                free(tmp);
                count++;
            }
        }
        count--;

        printf("\n%d titles imported\n", count);
        fclose(stream);

        //printf("Sorting the list...\n");
        //orderListSelect(list);
        //return list;
    }

    return list;
}

void DEL (PtList list){
    char idTitle[10];
    printf("Title ID: ");
    readString(idTitle, 10);

    int size, position;
    bool check = false;
    char c;
    listSize(list, &size);

    ListElem elem;

    for (int i = 0; i < size; i++){
        listGet(list, i, &elem);
        if (strcmp(elem.show_id,idTitle)==0){
            check = true;
            position = i;
        }
    }

    if(check ==  false)
        printf("Title not found.\n");
    else{
        printf("Delete %s, are you sure (y/n)? ", idTitle);
        scanf("%c", &c);

        if(c == 'Y' || c == 'y')
            listRemove(list, position, &elem);
        else
            printf("%s was not deleted.n", idTitle);
    }
}

void CLEAR(PtList list){
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

void LIST(PtList list){
    printf("Show Id | Type | Title | Date Added | Rating | Duration\n");
    listPrint(list);
}

void netflixPrint(Netflix *pNetflix){
    printf("%s  |  %s  |  %s  |  %s  |  %s  |  %s\n", pNetflix->show_id, pNetflix->type, pNetflix->title, pNetflix->date_added, pNetflix->rating, pNetflix->duration);
}

