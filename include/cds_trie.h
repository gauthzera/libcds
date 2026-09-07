#ifndef CDS_TRIE_H
#define CDS_TRIE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSTrie CDSTrie;

/**
 * Creates an empty trie.
 *
 * @return Pointer to the created trie, or NULL if memory allocation fails.
 */
CDSTrie *cds_trie_create(void);

/**
 * Destroys the trie and frees all allocated memory.
 *
 * If trie is NULL, the function does nothing.
 *
 * @param trie Trie to destroy.
 */
void cds_trie_destroy(CDSTrie *trie);

/**
 * Returns the number of words stored in the trie.
 *
 * @param trie Trie to inspect.
 * @return Number of words in the trie, or 0 if trie is NULL.
 */
size_t cds_trie_size(const CDSTrie *trie);

/**
 * Checks whether the trie is empty.
 *
 * @param trie Trie to inspect.
 * @return true if the trie is empty or NULL, false otherwise.
 */
bool cds_trie_empty(const CDSTrie *trie);

/**
 * Checks whether the trie contains the specified word.
 *
 * Only non-empty strings containing lowercase letters from 'a' to 'z'
 * are accepted.
 *
 * @param trie Trie to inspect.
 * @param word Word to search for.
 * @return true if the word is found, false if the word is not found
 *         or the arguments are invalid.
 */
bool cds_trie_contains(const CDSTrie *trie, const char *word);

/**
 * Checks whether the trie contains a word with the specified prefix.
 *
 * Only non-empty strings containing lowercase letters from 'a' to 'z'
 * are accepted.
 *
 * @param trie Trie to inspect.
 * @param prefix Prefix to search for.
 * @return true if the prefix exists, false if the prefix is not found
 *         or the arguments are invalid.
 */
bool cds_trie_starts_with(const CDSTrie *trie, const char *prefix);

/**
 * Inserts a word into the trie.
 *
 * Only non-empty strings containing lowercase letters from 'a' to 'z'
 * are accepted. Duplicate words are not allowed.
 *
 * @param trie Trie to modify.
 * @param word Word to insert.
 * @return true if the word was inserted successfully, false if the arguments
 *         are invalid, the word already exists, or memory allocation fails.
 */
bool cds_trie_insert(CDSTrie *trie, const char *word);

/**
 * Removes a word from the trie.
 *
 * Only non-empty strings containing lowercase letters from 'a' to 'z'
 * are accepted.
 *
 * @param trie Trie to modify.
 * @param word Word to remove.
 * @return true if the word was found and removed, false if the word is not
 *         found or the arguments are invalid.
 */
bool cds_trie_remove(CDSTrie *trie, const char *word);

/**
 * Removes all words from the trie.
 *
 * @param trie Trie to clear.
 */
void cds_trie_clear(CDSTrie *trie);

#endif