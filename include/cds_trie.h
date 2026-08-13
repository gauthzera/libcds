#ifndef CDS_TRIE_H
#define CDS_TRIE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSTrie CDSTrie;

//Create and destroy
CDSTrie *cds_trie_create(void);
void cds_trie_destroy(CDSTrie *trie);

//Information
size_t cds_trie_size(const CDSTrie *trie);
bool cds_trie_empty(const CDSTrie *trie);
bool cds_trie_contains(const CDSTrie *trie, const char *word);
bool cds_trie_starts_with(const CDSTrie *trie,const char *prefix);

//Modification
bool cds_trie_insert(CDSTrie *trie, const char *word);
bool cds_trie_remove(CDSTrie *trie, const char *word);
void cds_trie_clear(CDSTrie *trie);

#endif
