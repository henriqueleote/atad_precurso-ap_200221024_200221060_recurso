#include "netflix.h"
#include "list.h"

/**
 * @brief Populates the list with netflix titles from a specific given file
 *
 * The function returns the list with the populated netflix titles
 *
 * @param list [in] the list to be populated
 * @return PtList The list with all netflix titles.
 */
PtList LOADF(PtList list);

/**
 * @brief Populates the list with netflix titles from a default file
 *
 * The function returns the list with the populated netflix titles
 *
 * @param list [in] the list to be populated
 * @return PtList The list with all netflix titles.
 */
PtList LOADD(PtList list);

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
 * @brief Deletes a specific given title from the netflix list
 * @param list [in] the list from where the title is going to be removed
 */
void DEL(PtList list);

/**
 * @brief Returns a specific given title from the netflix list
 * @param list [in] the list from where the title is going to be returned from
 */
void GET(PtList list);

/**
 * @brief Print to screen all the netflix titles in the list
 * @param list [in] the list from where the titles are going to be printed from
 */
void LIST(PtList list, int min, int max, int type);

void MTIME(PtList list);

PtList sort(PtList list, int type, int sort);

/**
 * @brief Prints all netflix titles.
 * @param pNetflix [in] pointer from Netflix struct
 */
void netflixPrint(Netflix *pNetflix);

void printList(PtList list);

void STATS(PtList list);

void SEARCHC(PtList list);

void RATINGS(PtList list);