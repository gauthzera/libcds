#ifndef CDS_LIST_H
#define CDS_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSList CDSList;

/**
 * Creates an empty list.
 *
 * @return Pointer to the created list, or NULL if memory allocation fails.
 */
CDSList *cds_list_create(void);

/**
 * Destroys the list and frees all allocated memory.
 *
 * If list is NULL, the function does nothing.
 *
 * @param list List to destroy.
 */
void cds_list_destroy(CDSList *list);

/**
 * Returns the number of elements in the list.
 *
 * @param list List to inspect.
 * @return Number of elements in the list, or 0 if list is NULL.
 */
size_t cds_list_size(const CDSList *list);

/**
 * Checks whether the list is empty.
 *
 * @param list List to inspect.
 * @return true if the list is empty or NULL, false otherwise.
 */
bool cds_list_empty(const CDSList *list);

/**
 * Retrieves the value at the specified index.
 *
 * @param list List to inspect.
 * @param index Index of the element to retrieve.
 * @param value Pointer where the retrieved value will be stored.
 * @return true on success, false if list or value is NULL,
 *         or if index is out of bounds.
 */
bool cds_list_at(const CDSList *list, size_t index, int *value);

/**
 * Checks whether the list contains the specified value.
 *
 * @param list List to inspect.
 * @param value Value to search for.
 * @return true if the value is found, false otherwise.
 */
bool cds_list_contains(const CDSList *list, int value);

/**
 * Adds an element to the beginning of the list.
 *
 * @param list List to modify.
 * @param value Value to add.
 * @return true if the element was added successfully, false if list is NULL
 *         or memory allocation fails.
 */
bool cds_list_push_front(CDSList *list, int value);

/**
 * Adds an element to the end of the list.
 *
 * @param list List to modify.
 * @param value Value to add.
 * @return true if the element was added successfully, false if list is NULL
 *         or memory allocation fails.
 */
bool cds_list_push_back(CDSList *list, int value);

/**
 * Inserts an element at the specified index.
 *
 * @param list List to modify.
 * @param index Index where the element will be inserted.
 * @param value Value to insert.
 * @return true if the element was inserted successfully, false if list is NULL,
 *         index is out of bounds, or memory allocation fails.
 */
bool cds_list_insert(CDSList *list, size_t index, int value);

/**
 * Removes the first element from the list.
 *
 * @param list List to modify.
 * @param value Optional pointer where the removed value will be stored.
 * @return true if an element was removed, false if list is NULL
 *         or the list is empty.
 */
bool cds_list_pop_front(CDSList *list, int *value);

/**
 * Removes the last element from the list.
 *
 * @param list List to modify.
 * @param value Optional pointer where the removed value will be stored.
 * @return true if an element was removed, false if list is NULL
 *         or the list is empty.
 */
bool cds_list_pop_back(CDSList *list, int *value);

/**
 * Removes the element at the specified index.
 *
 * @param list List to modify.
 * @param index Index of the element to remove.
 * @param value Optional pointer where the removed value will be stored.
 * @return true if the element was removed, false if list is NULL
 *         or index is out of bounds.
 */
bool cds_list_erase(CDSList *list, size_t index, int *value);

/**
 * Removes the first occurrence of the specified value.
 *
 * @param list List to modify.
 * @param value Value to remove.
 * @return true if the value was found and removed, false otherwise.
 */
bool cds_list_remove(CDSList *list, int value);

/**
 * Removes all elements from the list.
 *
 * @param list List to clear.
 */
void cds_list_clear(CDSList *list);

#endif