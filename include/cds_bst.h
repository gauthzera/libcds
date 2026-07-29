#ifndef CDS_BST_H
#define CDS_BST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CDSBST CDSBST;

//Create and destroy
CDSBST *cds_bst_create(void);
void cds_bst_destroy(CDSBST *tree);

//Information
size_t cds_bst_size(const CDSBST *tree);
bool cds_bst_empty(const CDSBST *tree);
bool cds_bst_contains(const CDSBST *tree, int value);
bool cds_bst_min(const CDSBST *tree, int *value);
bool cds_bst_max(const CDSBST *tree, int *value);
bool cds_bst_height(const CDSBST *tree, int *value);

//Modification
bool cds_bst_insert(CDSBST *tree, int value);
bool cds_bst_remove(CDSBST *tree, int value);
void cds_bst_clear(CDSBST *tree);

#endif
