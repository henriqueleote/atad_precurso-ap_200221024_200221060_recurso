#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "functions.h"

int main() {

    PtList list = listCreate();

    list = LOADD(list); //maximo que não dá erro

    LIST(list);

    //netflixPrint(&list);

    /*for (int i = 0; i < n; i++){
        printf("Netflix[%d]: %s \n", i, netflix[i].show_id);
    }*/



    return EXIT_SUCCESS;
}