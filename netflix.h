#pragma once

typedef struct netflix
{
    char show_id[10];      //- id único [string]
    char type[10];         // - tipo de título [string] - apenas dois valores possíveis: “Movie” ou “TV Show”;
    char title[110];       // - nome do título [string];
    char director[210];    // - nome(s) do(s) director(es) [string]; -- ARRAY
    char cast[700];        // - nomes dos atores [string]; -- ARRAY
    char country[100];     // - país de origem [string];
    char date_added[30];   // - data de disponibilização na plataforma Netflix [string no formato “%M %d, %Y];
    char release_year[10]; // - ano de publicação [string que contém um número inteiro];
    char rating[10];       // - classificação etária [string];
    char duration[20];     // - duração (em minutos ou temporadas) [string];
    char listed_in[100];   // - categorização do título [string];
    char description[300]; // - descrição [string]
} Netflix;

//typedef struct netflix *PtNetflix;
typedef Netflix *PtNetflix;

/**
 * @brief Creates and initializes a netflix title
 * 
 * @param show_id [in] netflix show id
 * @param type [in] netflix show type
 * @param title  [in] netflix show title
 * @param director  [in] netflix show director
 * @param cast  [in] netflix show cast
 * @param country  [in] netflix show country
 * @param date_added  [in] netflix show added date
 * @param release_year  [in] netflix show release year
 * @param rating  [in] netflix show rating
 * @param listed_in  [in] netflix show categories
 * @param description  [in] netflix show description
 * @return Netflix struct
 */
Netflix netflixCreate(char *show_id, char *type, char *title, char *director, char *cast, char *country, char *date_added, char *release_year, char *rating, char *duration, char *listed_in, char *description);
