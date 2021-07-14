#include "netflix.h"
#include "list.h"

/**
 * @brief Populates array with students.
 * 
 * The function returns how many students were actually populated.
 * This is important if 'howMany' is greater than available students.
 * 
 * Should use the return value to iterate the array afterwards.
 * 
 * @param arr [out] array of netflix titles to populate. Must have necessary space.
 * @param howMany [in] number of netflix titles to load
 * @return int actually number of populated netflix titles.
 */
PtList LOADF(PtList list);

/**
 * @brief Populates array with students.
 * 
 * The function returns how many students were actually populated.
 * This is important if 'howMany' is greater than available students.
 * 
 * Should use the return value to iterate the array afterwards.
 * 
 * @param arr [out] array of netflix titles to populate. Must have necessary space.
 * @param howMany [in] number of netflix titles to load
 * @return int actually number of populated netflix titles.
 */
PtList LOADD(PtList list);

void CLEAR(PtList list);

void QUIT(PtList list);

void DEL(PtList list);

void GET(PtList list);

void LIST(PtList list);

/**
 * @brief Prints all netflix titles.
 * 
 * The function prints all data from every netflix show
 * 
 * @param pNetflix [in] pointer from Netflix struct
 */
void netflixPrint(Netflix *pNetflix);

void printList(PtList list);
