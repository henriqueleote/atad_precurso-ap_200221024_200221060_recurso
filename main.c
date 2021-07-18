#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "functions.h"

#define NETFLIX_FILE "csv_data/netflix_titles.csv"
#define ALL 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2

void exitMenu();

int main()
{
    PtList mainList = listCreate();

    char *command = (char *)calloc(20, sizeof(char));

    while (true)
    {

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

        
        printf("\nCommand -> ");
        readString(command, 20);

        convertToLower(command);

        if (strcmp(command, "quit") == 0)
        {
            QUIT(mainList);
            exitMenu();
        }
        else if (strcmp(command, "loadf") == 0)
        {
            mainList = LOADF(mainList);
        }
        else if (strcmp(command, "loadd") == 0)
        {
            mainList = LOADD(mainList);
        }
        else if (strcmp(command, "del") == 0)
        {
            if (!listEmpty(mainList))
                mainList = DEL(mainList);
        }
        else if (strcmp(command, "clear") == 0)
        {
                CLEAR(mainList);
        }
        else if (strcmp(command, "get") == 0)
        {
            if (!listEmpty(mainList))
                GET(mainList);
        }
        else if (strcmp(command, "list") == 0)
        {
            if (!listEmpty(mainList)){
                sortAlpha(mainList); //sorts titles by title
                LIST(mainList, -1, -1, ALL);
            }  
        }
        else if (strcmp(command, "stats") == 0)
        {
            if (!listEmpty(mainList))
                STATS(mainList);
        }
        else if (strcmp(command, "mtime") == 0)
        {
            if (!listEmpty(mainList))
                MTIME(mainList);
        }
        else if (strcmp(command, "searcht") == 0)
        {
            if (!listEmpty(mainList))
                SEARCHT(mainList);
        }
        else if (strcmp(command, "searchc") == 0)
        {
            if (!listEmpty(mainList))
                SEARCHC(mainList);
        }
        else if (strcmp(command, "ratings") == 0)
        {
            if (!listEmpty(mainList))
                RATINGS(mainList, true);
        }
        else if (strcmp(command, "categories") == 0)
        {
            if (!listEmpty(mainList))
                CATEGORIES(mainList);
        }
        else if (strcmp(command, "segment") == 0)
        {
            if (!listEmpty(mainList))
                SEGMENT(mainList);
        }
        else
        {
            printf("\nCommand not valid.\n");
        }
    }
    return EXIT_SUCCESS;
}


void exitMenu()
{
    system("clear");
    printf(" ____________________________________________\n");
    printf("|                  Made by:                  |\n");
    printf("|                                            |\n");
    printf("|         Gonçalo Mendes - 200221024         |\n");
    printf("|                                            |\n");
    printf("|         Henrique Leote - 200221060         |\n");
    printf("|____________________________________________|\n");
    printf("\n");
    exit(0);
}