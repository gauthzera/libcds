#ifndef CDS_VECTOR_H
#define CDS_VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSVector CDSVector;

/**
 * Creates an empty vector.
 *
 * @return Pointer to the created vector, or NULL if memory allocation fails.
 */
CDSVector *cds_vector_create(void);

/**
 * Destroys the vector and frees all allocated memory.
 *
 * If v is NULL, the function does nothing.
 *
 * @param v Vector to destroy.
 */
void cds_vector_destroy(CDSVector *v);

/**
 * Returns the number of elements in the vector.
 *
 * @param v Vector to inspect.
 * @return Number of elements in the vector, or 0 if v is NULL.
 */
size_t cds_vector_size(const CDSVector *v);

/**
 * Returns the total capacity of the vector.
 *
 * @param v Vector to inspect.
 * @return Total capacity of the vector, or 0 if v is NULL.
 */
size_t cds_vector_capacity(const CDSVector *v);

/**
 * Retrieves the value at the specified index.
 *
 * @param v Vector to inspect.
 * @param index Index of the element to retrieve.
 * @param value Pointer where the retrieved value will be stored.
 * @return true on success, false if v or value is NULL,
 *         or if index is out of bounds.
 */
bool cds_vector_at(const CDSVector *v, size_t index, int *value);

/**
 * Checks whether the vector is empty.
 *
 * @param v Vector to inspect.
 * @return true if the vector is empty or NULL, false otherwise.
 */
bool cds_vector_empty(const CDSVector *v);

/**
 * Adds an element to the end of the vector.
 *
 * @param v Vector to modify.
 * @param value Value to add.
 * @return true if the element was added successfully, false otherwise.
 */
bool cds_vector_push_back(CDSVector *v, int value);

/**
 * Removes the last element from the vector.
 *
 * @param v Vector to modify.
 * @param value Optional pointer where the removed value will be stored.
 * @return true if an element was removed, false if v is NULL
 *         or the vector is empty.
 */
bool cds_vector_pop_back(CDSVector *v, int *value);

/**
 * Inserts an element at the specified index.
 *
 * @param v Vector to modify.
 * @param index Index where the element will be inserted.
 * @param value Value to insert.
 * @return true if the element was inserted successfully, false if v is NULL,
 *         index is out of bounds, or memory allocation fails.
 */
bool cds_vector_insert(CDSVector *v, size_t index, int value);

/**
 * Removes the element at the specified index.
 *
 * @param v Vector to modify.
 * @param index Index of the element to remove.
 * @param value Optional pointer where the removed value will be stored.
 * @return true if the element was removed, false if v is NULL
 *         or index is out of bounds.
 */
bool cds_vector_erase(CDSVector *v, size_t index, int *value);

/**
 * Removes the first occurrence of the specified value.
 *
 * @param v Vector to modify.
 * @param value Value to remove.
 * @return true if the value was found and removed, false otherwise.
 */
bool cds_vector_remove(CDSVector *v, int value);

/**
 * Removes all elements from the vector.
 *
 * The vector capacity remains unchanged.
 *
 * @param v Vector to clear.
 */
void cds_vector_clear(CDSVector *v);

/**
 * Sorts the vector elements in ascending order.
 *
 * @param v Vector to sort.
 */
void cds_vector_sort(CDSVector *v);

#endif