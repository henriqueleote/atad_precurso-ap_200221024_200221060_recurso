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
#define ORDER_YEAR_ASC 7
#define ORDER_DATE_ASC 8

int main()
{
    PtList mainList = listCreate();

    mainList = LOADD(mainList); //CARREGA O FICHEIRO DEFAULT
    //mainList = LOADF(mainList); //CARREGA UM FICHEIRO COM O NOME DADO

    //mainList = sort(mainList, ORDER_ALPH_ASC);    //ORDENA POR NOME CRESCENTE A->Z
    //sortAlpha(mainList); //ORDENA POR NOME CRESCENTE A->Z
    //mainList = sort(mainList, ORDER_DURATION_DESC);   /ORDENA POR DURAÇÃO DECRESCENTE 312->0

    //RATINGS(mainList, true);
    //CATEGORIES(mainList);

    //LIST(mainList, -1, -1, TYPE); //APRESENTA TODOS OS TITULOS SEM LIMITES
    //LIST(mainList, -1, -1, TYPE_SHOW); //APRESENTA TODOS AS SERIES SEM LIMITES
    //LIST(mainList, -1, -1, TYPE_MOVIE); //APRESENTA TODOS OS FILMES SEM LIMITES
    //LIST(mainList, 10, 20, TYPE); //APRESENTA TODOS OS TITULOS COM LIMITES

    //SEARCHT(mainList);  //APRESENTA OS FILMES COM A ORDENAÇÃO DE DURAÇÃO DECRESCENTE
    //CATEGORIES(mainList);
    //DIRECTORS(mainList, false);
    //MTIME(mainList);

    SEGMENT(mainList);
    SEGMENT2(mainList);

    return EXIT_SUCCESS;
}