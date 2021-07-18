#include "netflix.h"
#include "list.h"
#include "map.h"


/**
 * @brief Print to screen all different title directors, sorted by name
 * @param list [in] the list from where the titles are going to be printed from
 * @return PtList returns the created list
 */
PtList DIRECTORS(PtList list, bool print);

/**
 * @brief Creates a file with all data from netflix titles, sorted by rating and year. And a file with all the movies sorted by director
 * @param titlesList [in] the list from where the titles are going to be printed from
 */
void SEGMENT(PtList mainList);