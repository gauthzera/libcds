#ifndef CDS_VECTOR_H
#define CDS_VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSVector CDSVector;

//Create and destroy
CDSVector *cds_vector_create(void); //initial capacity = 8
void cds_vector_destroy(CDSVector* v);

//Information
size_t cds_vector_size(const CDSVector *v);
size_t cds_vector_capacity(const CDSVector *v);
bool cds_vector_at(const CDSVector *v,size_t index,int *value);
bool cds_vector_empty(const CDSVector *v);

//Modification
bool cds_vector_push_back(CDSVector *v, int value);
bool cds_vector_pop_back(CDSVector *v,int *value);
bool cds_vector_insert(CDSVector *v,size_t index,int value);
bool cds_vector_erase(CDSVector *v,size_t index, int *value);
bool cds_vector_remove(CDSVector *v,int value);
void cds_vector_clear(CDSVector *v);
void cds_vector_sort(CDSVector *v);

#endif
