#include "netflix.h"
#include "list.h"
#include "map.h"

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
 * @return PtList returns the created list
 */
PtList RATINGS(PtList titlesList, bool print);

/**
 * @brief Print to screen all different title categories, sorted by name
 * @param list [in] the list from where the titles are going to be printed from
 */
void CATEGORIES(PtList mainList);