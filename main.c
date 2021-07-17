#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "functions.h"

#define NETFLIX_FILE "csv_data/netflix_titles.csv"
#define TYPE 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2

void mainMenu();

int main()
{
    //mainMenu();
    PtList list = listCreate();

    LOADD(list);
    getchar();  //carregar no enter antes de passar ao próximo
    /*LIST(list, -1, -1, TYPE);
    CLEAR(list);
    getchar();
    LOADF(list);
    getchar();
    DEL(list);
    getchar();
    GET(list);
    getchar();
    MTIME(list);
    getchar();
    STATS(list);
    getchar();
    SEARCHT(list);
    getchar();
    //SEARCHC(list);    //segmentation fault
    getchar();*/
    RATINGS(list,true); //não está a imprimir
    //getchar();
    /*CATEGORIES(list);
    getchar();
    SEGMENT(list);
    QUIT(list);*/
    return EXIT_SUCCESS;
}

/*void mainMenu()
{
    char *command = (char *)calloc(20, sizeof(char));

    printf("\n");
    printf(" ____________________________________________\n");
    printf("|               NETFLIX TITLES               |\n");
    printf("|                                            |\n");
    printf("|             Write a commmand:              |\n");
    printf("|                                            |\n");
    printf("|       LOADF                    LOADD       |\n");
    printf("|                                            |\n");
    printf("|        DEL                     CLEAR       |\n");
    printf("|                                            |\n");
    printf("|        GET                     LIST        |\n");
    printf("|                                            |\n");
    printf("|       STATS                    MTIME       |\n");
    printf("|                                            |\n");
    printf("|      SEARCHT                  SEARCHC      |\n");
    printf("|                                            |\n");
    printf("|      RATINGS                 CATEGORIES    |\n");
    printf("|                                            |\n");
    printf("|      SEGMENT                    QUIT       |\n");
    printf("|____________________________________________|\n");

    printf("Comando: ");
    readString(command, 20);

    convertToLower(command);

    PtList mainList = listCreate();

    if (strcmp(command, "loadf") == 0)
    {
        LOADF(mainList);
    }
    else if (strcmp(command, "loadd") == 0)
    {
        LOADD(mainList);
    }
    else if (strcmp(command, "del") == 0)
    {
        DEL(mainList);
    }
    else if (strcmp(command, "clear") == 0)
    {
        CLEAR(mainList);
    }
    else if (strcmp(command, "get") == 0)
    {
        GET(mainList);
    }
    else if (strcmp(command, "list") == 0)
    {
        LIST(mainList, -1, -1, TYPE);
    }
    else if (strcmp(command, "stats") == 0)
    {
        STATS(mainList);
    }
    else if (strcmp(command, "mtime") == 0)
    {
        MTIME(mainList);
    }
    else if (strcmp(command, "searcht") == 0)
    {
        SEARCHT(mainList);
    }
    else if (strcmp(command, "searchc") == 0)
    {
        SEARCHC(mainList);
    }
    else if (strcmp(command, "ratings") == 0)
    {
        RATINGS(mainList, true);
    }
    else if (strcmp(command, "categories") == 0)
    {
        CATEGORIES(mainList);
    }
    else if (strcmp(command, "segment") == 0)
    {
        SEGMENT(mainList);
    }
    else if (strcmp(command, "quit") == 0)
    {
        //exitMenu();
    }
}*/