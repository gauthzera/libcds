#ifndef CDS_LIST_H
#define CDS_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSList CDSList;

//Create and destroy
CDSList *cds_list_create(void);
void cds_list_destroy(CDSList *list);

//Information
size_t cds_list_size(const CDSList *list);
bool cds_list_empty(const CDSList *list);
bool cds_list_at(const CDSList *list, size_t index, int *value);
bool cds_list_contains(const CDSList *list, int value);

//Modification
bool cds_list_push_front(CDSList *list,int value);
bool cds_list_push_back(CDSList *list,int value);
bool cds_list_insert(CDSList *list, size_t index,int value);

bool cds_list_pop_front(CDSList *list, int *value);
bool cds_list_pop_back(CDSList *list, int *value);
bool cds_list_erase(CDSList *list, size_t index, int *value);
bool cds_list_remove(CDSList *list, int value);

void cds_list_clear(CDSList *list);

#endif
