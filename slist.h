/**
 * @file slist.h
 * @brief Interface for an ordered (by position, not with respect to any ordering criterion) list of strings.
 *
 */
#include "types.h"

typedef struct _SList SList;

/**
 * @brief Create an empty list of strings.
 *
 * @return SList*, new list of strings.
 */
SList *sl_new();

/**
 * @brief Free the list.
 *
 * @param sl List.
 */
void sl_free(SList *sl);

/**
 * @brief Add a string to the end of the list.
 *
 * @param sl List.
 * @param str String to append; if not NULL, str is assumed to be a NULL-terminated C string.
 * @return Status, OK or ERROR depending on whether the addition was successful.
 */
Status sl_append(SList *sl, char *str);

/**
 * @brief Remove the last string from the list, and return it.
 *
 * @param sl List.
 * @param str String, output argument.
 * @return Status, OK if successful, ERROR otherwise (e.g. if the list is empty).
 */
Status sl_pop(SList *sl, char **str);

/**
 * @brief Get the string in the specified position of the list.
 *
 * @param sl List.
 * @param pos Position.
 * @param str String, output argument.
 * @return Status, OK or ERROR depending on whether the operation was successful.
 */
Status sl_get(SList *sl, int pos, char **str);

/**
 * @brief Check if the list is empty.
 *
 * @param sl List.
 * @return bool, true if the list is empty, false otherwise.
 */
bool sl_is_empty(SList *sl);

/**
 * @brief Print all strings in the list.
 *
 * @param sl List.
 */
void sl_print(SList *sl);

/**
 * @brief Get the number of strings in the list.
 *
 * @param sl List.
 * @return int, number of strings in the list.
 */
int sl_size(SList *sl);