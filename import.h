#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "netflix.h"
#include "input.h"
#include "list.h"
#include "map.h"
#include "date.h"
#include "stringWrap.h"
#include <ctype.h>

/**
 * @brief Populates the list with netflix titles from a specific given file
 * @param titlesList [in] the list to be populated
 * @return PtList returns the created list
 */
PtList LOADF(PtList titlesList);

/**
 * @brief Populates the list with netflix titles from a default file
 * @param titlesList [in] the list to be populated
 * @return PtList returns the created list
 */
PtList LOADD(PtList titlesList);

/**
 * @brief Deletes a specific given title from the netflix list
 * @param list [in] the list from where the title is going to be removed
 * @return PtList returns the updated list
 */
PtList DEL(PtList list);

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