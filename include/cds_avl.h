#ifndef CDS_AVL_H
#define CDS_AVL_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSAVL CDSAVL;

//Create and destroy
CDSAVL *cds_avl_create(void);
void cds_avl_destroy(CDSAVL *tree);

//Information
size_t cds_avl_size(const CDSAVL *tree);
bool cds_avl_empty(const CDSAVL *tree);
bool cds_avl_contains(const CDSAVL *tree, int value);
bool cds_avl_min(const CDSAVL *tree, int *value);
bool cds_avl_max(const CDSAVL *tree, int *value);
bool cds_avl_height(const CDSAVL *tree, int *value);

void cds_avl_inorder(const CDSAVL *tree, void(*visit)(int));
void cds_avl_preorder(const CDSAVL *tree, void(*visit)(int));
void cds_avl_postorder(const CDSAVL *tree, void(*visit)(int));

//Modification
bool cds_avl_insert(CDSAVL *tree, int value);
bool cds_avl_remove(CDSAVL *tree, int value);
void cds_avl_clear(CDSAVL *tree);

#endif
