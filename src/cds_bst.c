#include "cds_bst.h"
#include <stdlib.h>

typedef struct CDSBSTNode{
    int value;
    struct CDSBSTNode *right, *left;
}CDSBSTNode;

static CDSBSTNode *cds_bst_node_create(int value){
    CDSBSTNode *n = malloc(sizeof(CDSBSTNode));
    if(n == NULL) return NULL;

    n->value=value;
    n->right=NULL;
    n->left=NULL;
    
    return n;
}

struct CDSBST{
    CDSBSTNode *root;
    size_t size;
};

CDSBST *cds_bst_create(void){
    CDSBST *tree = malloc(sizeof(CDSBST));
    
    if(tree == NULL)return NULL;
    
    tree->root=NULL;
    tree->size=0;
    
    return tree;
}

static void cds_bst_destroy_subtree(CDSBSTNode *root){
    if(root != NULL){
        cds_bst_destroy_subtree(root->left);
        cds_bst_destroy_subtree(root->right);
        free(root);
    }
}

void cds_bst_destroy(CDSBST *tree){
    if(tree == NULL)return;
    cds_bst_destroy_subtree(tree->root);

    free(tree);
}

size_t cds_bst_size(const CDSBST *tree){
    if(tree == NULL)return 0;
    
    return tree->size;
}

bool cds_bst_empty(const CDSBST *tree){
    if(tree == NULL)return true;

    return tree->size == 0;
}

static bool bst_search(const CDSBSTNode *root, int value){
    if(root == NULL)return false;

    if(value > root->value){
        return bst_search(root->right, value);
    }else if(value < root->value){
        return bst_search(root->left, value);
    }

    return true;
}

bool cds_bst_contains(const CDSBST *tree, int value){
    if(tree == NULL || tree->size == 0)return false;

    return bst_search(tree->root, value);
}

bool cds_bst_min(const CDSBST *tree, int *value){
    if(tree == NULL || tree->size == 0 || value == NULL)return false;

   const CDSBSTNode *min_node=tree->root;
    
    while(min_node->left != NULL){
        min_node = min_node->left;
    }
    
    *value=min_node->value;
    return true;
}

bool cds_bst_max(const CDSBST *tree, int *value){
    if(tree == NULL || tree->size == 0 || value == NULL)return false;
    
    const CDSBSTNode *max_node=tree->root;

    while(max_node->right != NULL){
        max_node = max_node->right;
    }
    
    *value=max_node->value;
    return true;
}

static int bst_height(const CDSBSTNode *root){
    if(root == NULL)return -1;

    int left_height=bst_height(root->left);
    int right_height=bst_height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1; 
}

bool cds_bst_height(const CDSBST *tree, int *value){
    if(tree == NULL || value == NULL)return false;
    
    *value = bst_height(tree->root);
    return true;
}

static bool bst_insert(CDSBSTNode **root, int value){
    if(*root == NULL){
        *root = cds_bst_node_create(value);
        return *root != NULL;
    }

    if(value > (*root)->value){

        return bst_insert(&(*root)->right, value);
    }else if(value < (*root)->value){

        return bst_insert(&(*root)->left, value);
    }
    
    return false;
}

bool cds_bst_insert(CDSBST *tree, int value){
    if(tree == NULL)return false;
    
    if(!bst_insert(&tree->root, value))return false;
    
    tree->size++;
    return true;
}

static CDSBSTNode *bst_remove(CDSBSTNode *root, int value, bool *removed){
    if(root == NULL){
        return  NULL; 
    }

    if(value > root->value){
        root->right = bst_remove(root->right, value,removed);
    }else if(value < root->value){
        root->left = bst_remove(root->left, value, removed);
    }else{
        *removed = true;

        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;

        }else if(root->left == NULL){
            CDSBSTNode *right_node= root->right;
            free(root);
            return right_node;

        }else if(root->right == NULL){
            CDSBSTNode *left_node= root->left;
            free(root);
            return left_node;
        }else{
            CDSBSTNode *successor=root->right;

            while(successor->left != NULL){
                successor = successor->left;
            }
            
            root->value = successor->value;
            bool suc_removed=false;

            root->right = bst_remove(root->right, successor->value, &suc_removed);

        }    
    }
     
    return root;
}

bool cds_bst_remove(CDSBST *tree, int value){
    if(tree == NULL || tree->size == 0)return false;
    
    bool removed = false;
    tree->root = bst_remove(tree->root,value, &removed);
    
    if(removed)tree->size--;

    return removed;
}

void cds_bst_clear(CDSBST *tree){
    if(tree == NULL)return;
    
    cds_bst_destroy_subtree(tree->root);
    tree->root = NULL;

    tree->size=0;
}
