#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int main() {

    /* TODO: Complete code, just a basic command line */
    /* TODO: Commands are not currently case insensitive */

    char input[100];

    while (true)
    {
        printf("$>");
        readString(input, 100);

        if (strcmp(input, "QUIT") == 0)
        {
            printf("Exit.\n");
            break;
        }
        else if (strcmp(input, "LOADF") == 0)
        {
            
        }
        //...
        else
        {
            printf("\nUnknown command.\n");
        }
    }

    return EXIT_SUCCESS;
}