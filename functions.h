#include "netflix.h"
#include "list.h"

/**
 * @brief Sorts a given list by rating
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void sortRating(PtList titlesList);

/**
 * @brief Sorts a given list by title
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void sortAlpha(PtList titlesList);

/**
 * @brief Sorts a given list by duration
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void sortDuration(PtList titlesList);

/**
 * @brief Sorts a given list by year
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void sortYear(PtList titlesList);

/**
 * @brief Sorts a given list by date
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void sortDate(PtList titlesList);

/**
 * @brief Checks if a string exists in a given list
 * @param ratingsList [in] the list from where the titles are going to be printed from
 * @param str [in] the string array to check if exists in the list
 */
bool ratingExists(PtList ratingsList, char *str);

/**
 * @brief Checks if a string exists in a given list
 * @param categoriesList [in] the list from where the titles are going to be printed from
 * @param str [in] the string array to check if exists in the list
 */
bool categoryExists(PtList categoriesList, char *str);

/**
 * @brief Prints all netflix titles.
 * @param pNetflix [in] pointer from Netflix struct
 */
void netflixPrint(Netflix *pNetflix);

/**
 * @brief Populates the list with netflix titles from a specific given file
 * @param titlesList [in] the list to be populated
 * @return PtList The list with all netflix titles.
 */
PtList LOADF(PtList titlesList);

/**
 * @brief Populates the list with netflix titles from a default file
 * @param titlesList [in] the list to be populated
 * @return PtList The list with all netflix titles.
 */
PtList LOADD(PtList titlesList);

/**
 * @brief Deletes a specific given title from the netflix list
 * @param list [in] the list from where the title is going to be removed
 */
void DEL(PtList list);

/**
 * @brief Clear all the used lists in order to clear used memory
 * @param list [in] the list to be cleared
 */
void CLEAR(PtList list);

/**
 * @brief Clear all the used lists and exits the program
 * @param list [in] the list to be cleared
 */
void QUIT(PtList list);

/**
 * @brief Returns a specific given title from the netflix list
 * @param titlesList [in] the list from where the title is going to be returned from
 */
void GET(PtList titlesList);

/**
 * @brief Print to screen all the netflix titles in the list
 * @param titlesList [in] the list from where the titles are going to be printed from
 * @param min [in] the min duration value
 * @param max [in] the max duration value
 * @param type [in] the type of titles
 */
void LIST(PtList titlesList, int min, int max, int type);

/**
 * @brief Print to screen stats about all netflix titles
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void STATS(PtList titlesList);

/**
 * @brief Print to screen all netflix titles between a interval of duration [min,max]
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void MTIME(PtList titlesList);

/**
 * @brief Print to screen all netflix title from a given title name, sorted by the added date to the platform
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void SEARCHT(PtList mainList);

/**
 * @brief Print to screen all netflix title from a given cast name, sorted by the added date to the platform
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void SEARCHC(PtList mainList);

/**
 * @brief Print to screen all different title ratings, sorted by name
 * @param titlesList [in] the list from where the titles are going to be printed from
 * @param print [in] boolean to check if it's going to print the ratings
 */
PtList RATINGS(PtList titlesList, bool print);

/**
 * @brief Creates a file with all data from netflix titles, sorted by rating and year. And a file with all the movies sorted by director
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void SEGMENT(PtList titlesList);