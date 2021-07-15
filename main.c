#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "functions.h"

#define TYPE 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2
#define ORDER_ALPH_ASC 3
#define ORDER_DURATION_ASC 5
#define ORDER_DURATION_DESC 6

int main()
{

    PtList list = listCreate();

    list = LOADD(list); //maximo que não dá erro

    list = sort(list, TYPE_MOVIE, ORDER_ALPH_ASC);
    LIST(list, 10, 90, TYPE_MOVIE);

    //netflixPrint(&list);

    /*for (int i = 0; i < n; i++){
        printf("Netflix[%d]: %s \n", i, netflix[i].show_id);
    }*/

    return EXIT_SUCCESS;
}