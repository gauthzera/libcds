#ifndef CDS_HASH_H
#define CDS_HASH_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSHash CDSHash;

//Create and destroy
CDSHash *cds_hash_create(size_t capacity);
void cds_hash_destroy(CDSHash *hash);

//Information
size_t cds_hash_size(const CDSHash *hash);
size_t cds_hash_capacity(const CDSHash *hash);
bool cds_hash_empty(const CDSHash *hash);
bool cds_hash_contains(const CDSHash *hash, int value);

//Modification
bool cds_hash_insert(CDSHash *hash, int value);
bool cds_hash_remove(CDSHash *hash,int value);
void cds_hash_clear(CDSHash *hash);

#endif
