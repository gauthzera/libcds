#include "cds_avl.h"
#include <stdlib.h>

typedef struct CDSAVLNode{
    int value;
    int height;
    struct CDSAVLNode *left,*right;
}CDSAVLNode;

static CDSAVLNode *cds_avl_node_create(int value){
    CDSAVLNode *n=malloc(sizeof(CDSAVLNode));

    if(n == NULL)return NULL;

    n->value=value;
    n->height=0;
    n->left=NULL;
    n->right=NULL;
    
    return n;
}

struct CDSAVL{
    CDSAVLNode *root;
    size_t size;
};

CDSAVL *cds_avl_create(void){
    CDSAVL *tree=malloc(sizeof(CDSAVL));

    if(tree == NULL)return NULL;

    tree->root=NULL;
    tree->size=0;
    
    return tree;
}

static void cds_avl_destroy_subtree(CDSAVLNode *root){
    if(root!=NULL){
        cds_avl_destroy_subtree(root->left);
        cds_avl_destroy_subtree(root->right);
        free(root);
    }
}

void cds_avl_destroy(CDSAVL *tree){
    if(tree == NULL)return;

    cds_avl_destroy_subtree(tree->root);
    free(tree);
}

size_t cds_avl_size(const CDSAVL *tree){
    if(tree==NULL)return 0;

    return tree->size;
}

bool cds_avl_empty(const CDSAVL *tree){
    if(tree == NULL)return true;
    
    return tree->size==0;
}

static bool avl_search(const CDSAVLNode *root, int value){
    if(root == NULL)return false;

    if(value > root->value){
        return avl_search(root->right, value);
    }else if(value < root->value){
        return avl_search(root->left, value);
    }
    
    return true;
}

bool cds_avl_contains(const CDSAVL *tree, int value){
    if(tree == NULL || tree->size == 0)return false;

    return avl_search(tree->root, value);
}


bool cds_avl_min(const CDSAVL *tree, int *value){
    if(tree == NULL || tree->size == 0 || value==NULL)return false;

    const CDSAVLNode *min_node=tree->root;

    while(min_node->left != NULL){
        min_node=min_node->left;
    }
    
    *value=min_node->value;
    return true;
}


bool cds_avl_max(const CDSAVL *tree, int *value){
    if(tree == NULL || tree->size == 0 || value == NULL)return false;

    const CDSAVLNode *max_node=tree->root;
    
    while(max_node->right != NULL){
        max_node = max_node->right;
    }

    *value=max_node->value;
    return true;
}

static int avl_node_height(const CDSAVLNode *node){
    return (node == NULL) ? -1 : node->height;
}

bool cds_avl_height(const CDSAVL *tree, int *value){
    if(tree == NULL || value == NULL)return false;
        
    *value= avl_node_height(tree->root);

    return true;
}

static int avl_max(int a,int b){
    return (a > b) ? a : b;
}

static int avl_balance_factor(const CDSAVLNode *node){
    if(node == NULL)return 0;

    return avl_node_height(node->right) - avl_node_height(node->left);
}

static int avl_calculate_height(const CDSAVLNode *node){
    return avl_max(avl_node_height(node->right), avl_node_height(node->left)) + 1;
}

static CDSAVLNode *avl_rotate_left(CDSAVLNode *node){
    CDSAVLNode *right_node=node->right;
    CDSAVLNode *r_left_node=right_node->left;
    
    right_node->left=node;
    node->right=r_left_node;
    
    node->height = avl_calculate_height(node);
    right_node->height = avl_calculate_height(right_node); 
    
    return right_node;
}

static CDSAVLNode *avl_rotate_right(CDSAVLNode *node){
    CDSAVLNode *left_node=node->left;
    CDSAVLNode *l_right_node=left_node->right;

    left_node->right=node;
    node->left=l_right_node;
   
    node->height = avl_calculate_height(node);
    left_node->height = avl_calculate_height(left_node); 

    return left_node;
}

static CDSAVLNode *avl_rebalance(CDSAVLNode *node){
    int bf = avl_balance_factor(node);

    if(bf > 1){
        if(avl_balance_factor(node->right) < 0){
            node->right = avl_rotate_right(node->right);
        }
        node = avl_rotate_left(node);
    
    }else if(bf < -1){
        if(avl_balance_factor(node->left) > 0){
            node->left = avl_rotate_left(node->left);
        }
        node = avl_rotate_right(node);
    }
    
    return node;
}

static CDSAVLNode *avl_insert(CDSAVLNode *root, int value, bool *inserted){
    if(root == NULL){
        CDSAVLNode *new_node = cds_avl_node_create(value);
            
        *inserted = new_node!=NULL;
        
        return new_node;
    }

    if(value > root->value){
        root->right = avl_insert(root->right, value, inserted);
    }else if(value < root->value){
        root->left = avl_insert(root->left, value, inserted);
    }else{
        *inserted = false;
        return root;
    }
    
    root->height = avl_calculate_height(root);
    
    return avl_rebalance(root);
}

bool cds_avl_insert(CDSAVL *tree, int value){
    if(tree == NULL)return false;

    bool inserted=false;
    tree->root=avl_insert(tree->root, value, &inserted);
    
    if(inserted)tree->size++;

    return inserted;
}

static CDSAVLNode *avl_remove(CDSAVLNode *root, int value, bool *removed){
    if(root == NULL){
        *removed=false;
        return root;
    }

    if(value > root->value){
        root->right = avl_remove(root->right, value, removed);    
    }else if(value < root->value){
        root->left = avl_remove(root->left, value, removed);
    }else{
        *removed = true;

        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;

        }else if(root->left == NULL){
            CDSAVLNode *right_node = root->right;
            free(root);
            return right_node;

        }else if(root->right == NULL){
            CDSAVLNode *left_node = root->left;
            free(root);
            return left_node;
        }else{
            CDSAVLNode *successor = root->right;
                
            while(successor->left != NULL){
                successor = successor->left;
            }

            root->value=successor->value;
            bool suc_removed=false;

            root->right = avl_remove(root->right, successor->value, &suc_removed);
        }
    }
    
    root->height = avl_calculate_height(root);
    
    return avl_rebalance(root);
}

bool cds_avl_remove(CDSAVL *tree, int value){
    if(tree == NULL || tree->size == 0)return false;
    
    bool removed=false;
    tree->root = avl_remove(tree->root, value, &removed);
    
    if(removed)tree->size--;

    return removed;
}

void cds_avl_clear(CDSAVL *tree){
    if(tree == NULL)return;

    cds_avl_destroy_subtree(tree->root);
    tree->root = NULL;
    tree->size=0;
}
