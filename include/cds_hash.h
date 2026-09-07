#ifndef CDS_HASH_H
#define CDS_HASH_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSHash CDSHash;

/**
 * Creates an empty hash table with the specified capacity.
 *
 * @param capacity Number of buckets in the hash table.
 * @return Pointer to the created hash table, or NULL if capacity is 0
 *         or memory allocation fails.
 */
CDSHash *cds_hash_create(size_t capacity);

/**
 * Destroys the hash table and frees all allocated memory.
 *
 * If hash is NULL, the function does nothing.
 *
 * @param hash Hash table to destroy.
 */
void cds_hash_destroy(CDSHash *hash);

/**
 * Returns the number of elements in the hash table.
 *
 * @param hash Hash table to inspect.
 * @return Number of elements in the hash table, or 0 if hash is NULL.
 */
size_t cds_hash_size(const CDSHash *hash);

/**
 * Returns the capacity of the hash table.
 *
 * @param hash Hash table to inspect.
 * @return Number of buckets in the hash table, or 0 if hash is NULL.
 */
size_t cds_hash_capacity(const CDSHash *hash);

/**
 * Checks whether the hash table is empty.
 *
 * @param hash Hash table to inspect.
 * @return true if the hash table is empty or NULL, false otherwise.
 */
bool cds_hash_empty(const CDSHash *hash);

/**
 * Checks whether the hash table contains the specified value.
 *
 * @param hash Hash table to inspect.
 * @param value Value to search for.
 * @return true if the value is found, false otherwise.
 */
bool cds_hash_contains(const CDSHash *hash, int value);

/**
 * Inserts a value into the hash table.
 *
 * Duplicate values are not allowed.
 *
 * @param hash Hash table to modify.
 * @param value Value to insert.
 * @return true if the value was inserted successfully, false if hash is NULL,
 *         the value already exists, or memory allocation fails.
 */
bool cds_hash_insert(CDSHash *hash, int value);

/**
 * Removes a value from the hash table.
 *
 * @param hash Hash table to modify.
 * @param value Value to remove.
 * @return true if the value was found and removed, false otherwise.
 */
bool cds_hash_remove(CDSHash *hash, int value);

/**
 * Removes all elements from the hash table.
 *
 * The hash table capacity remains unchanged.
 *
 * @param hash Hash table to clear.
 */
void cds_hash_clear(CDSHash *hash);

#endif