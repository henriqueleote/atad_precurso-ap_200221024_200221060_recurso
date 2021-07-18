#include "netflix.h"
#include "list.h"
#include "map.h"

/**
 * @brief Check if a list is empty or null
 * @param list [in] the list to check
 * @return bool with the result of the check
 */
bool listEmpty(PtList list);

/**
 * @brief Turns any string into lowercase
 * @param *str [in] the string to change
 * @return char with the lowercased string
 */
char *convertToLower(char *str);

/**
 * @brief Removes blank spaces from strings
 * @param *str [in] the string to change
 * @return char with the trimmed string
 */
char *trimWhiteSpace(char *str);

/**
 * @brief Sorts a given list by rating
 * @param titlesList [in] the list to sort
 */
void sortRating(PtList titlesList);

/**
 * @brief Sorts a given list by title
 * @param titlesList [in] the list to sort
 */
void sortAlpha(PtList titlesList);

/**
 * @brief Sorts a given list by category
 * @param titlesList [in] the list to sort
 */
void sortCategory(PtList titlesList);

/**
 * @brief Sorts a given list by director
 * @param titlesList [in] the list to sort
 */
void sortDirector(PtList titlesList);

/**
 * @brief Sorts a given list by duration
 * @param titlesList [in] the list to sort
 */
void sortDuration(PtList titlesList);

/**
 * @brief Sorts a given list by year
 * @param titlesList [in] the list to sort
 */
void sortYear(PtList titlesList);

/**
 * @brief Sorts a given list by date
 * @param titlesList [in] the list to sort
 */
void sortDate(PtList titlesList);

/**
 * @brief Checks if a string exists in a given list
 * @param ratingsList [in] the list from where the titles are going to be printed from
 * @param str [in] the string array to check if exists in the list
 */
bool ratingExists(PtList ratingsList, char *str);

/**
 * @brief Prints all netflix titles.
 * @param pNetflix [in] pointer from Netflix struct
 */
void netflixPrint(Netflix *pNetflix);