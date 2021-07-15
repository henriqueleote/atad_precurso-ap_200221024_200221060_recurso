#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "functions.h"

#define TYPE 0
#define TYPE_MOVIE 1
#define TYPE_SHOW 2
#define ORDER_ALPH_ASC 3
#define ORDER_DURATION_DESC 6
#define ORDER_RATING 5

int main()
{

    PtList list = listCreate();

    list = LOADD(list); //CARREGA O FICHEIRO DEFAULT
    //list = LOADF(list); //CARREGA UM FICHEIRO COM O NOME DADO

    //list = sort(list, ORDER_ALPH_ASC);    //ORDENA POR NOME CRESCENTE A->Z
    //list = sort(list, ORDER_DURATION_DESC);   /ORDENA POR DURAÇÃO DECRESCENTE 312->0

    //LIST(list, -1, -1, TYPE); //APRESENTA TODOS OS TITULOS SEM LIMITES
    //LIST(list, -1, -1, TYPE_SHOW); //APRESENTA TODOS AS SERIES SEM LIMITES
    //LIST(list, -1, -1, TYPE_MOVIE); //APRESENTA TODOS OS FILMES SEM LIMITES
    //LIST(list, 10, 20, TYPE); //APRESENTA TODOS OS TITULOS COM LIMITES

    //MTIME(list);  //APRESENTA OS FILMES COM A ORDENAÇÃO DE DURAÇÃO DECRESCENTE

    RATINGS(list);

    return EXIT_SUCCESS;
}