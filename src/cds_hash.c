#include "cds_hash.h"
#include <stdlib.h>

typedef struct CDSHashNode{
    int value;
    struct CDSHashNode *next;
}CDSHashNode;

static CDSHashNode *cds_hash_node_create(int value){
    CDSHashNode *n=malloc(sizeof(CDSHashNode));
    
    if(n == NULL)return NULL;
    
    n->value=value;
    n->next=NULL;

    return n;
}

struct CDSHash{
    CDSHashNode **table;
    size_t capacity;
    size_t size;
};

CDSHash *cds_hash_create(size_t capacity){
    if(capacity == 0)return NULL;

    CDSHash *hash=malloc(sizeof(CDSHash));

    if(hash == NULL)return NULL;
    
    hash->table=malloc(sizeof(CDSHashNode*) * capacity);
    
    if(hash->table == NULL){
        free(hash);
        return NULL;
    }

    for(size_t i=0; i<capacity; i++){
        hash->table[i]=NULL;
    }
    
    hash->size=0;
    hash->capacity=capacity;
    
    return hash;
}

void cds_hash_destroy(CDSHash *hash){
    if(hash == NULL)return;
    
    for(size_t i=0; i<hash->capacity; i++){

        CDSHashNode *cur=hash->table[i];

        while(cur != NULL){
            CDSHashNode *removed=cur;
            cur=removed->next;

            free(removed);
        }
    }
    
    free(hash->table);
    free(hash);
}

static size_t hash_function(const CDSHash *hash, int value){
    return (size_t)(unsigned int)value % hash->capacity;
}

size_t cds_hash_size(const CDSHash *hash){
    if(hash == NULL)return 0;
    return hash->size;
}

size_t cds_hash_capacity(const CDSHash *hash){
    if(hash == NULL)return 0;
    return hash->capacity;
}

bool cds_hash_empty(const CDSHash *hash){
    if(hash == NULL)return true;
    return hash->size == 0;
}

bool cds_hash_contains(const CDSHash *hash, int value){
    if(hash == NULL)return false;
    
    size_t pos = hash_function(hash, value);

    CDSHashNode *cur=hash->table[pos];
    
    while(cur != NULL){
        if(cur->value == value)return true;
        cur=cur->next;
    }
    
    return false;
}

bool cds_hash_insert(CDSHash *hash, int value){
    if(hash == NULL)return false;
    if(cds_hash_contains(hash, value))return false;

    size_t pos = hash_function(hash, value);
    
    CDSHashNode *new_node=cds_hash_node_create(value);
    if(new_node == NULL)return false;

    new_node->next=hash->table[pos];
    hash->table[pos]=new_node;

    hash->size++;
    
    return true;
}

bool cds_hash_remove(CDSHash *hash, int value){
    if(hash == NULL || hash->size == 0)return false;
    
    size_t pos=hash_function(hash, value);
    
    if(hash->table[pos] == NULL)return false;

    if(hash->table[pos]->value == value){
        CDSHashNode *removed=hash->table[pos];
        hash->table[pos] = removed->next;
        
        free(removed);
        hash->size--;
        return true;
    }
    
    CDSHashNode *prev=hash->table[pos];

    while(prev->next !=NULL && prev->next->value != value){
        prev=prev->next;
    }
    
    if(prev->next == NULL)return false;

    CDSHashNode *removed = prev->next;
    prev->next=removed->next;

    free(removed);
    hash->size--;
    return true;
}

void cds_hash_clear(CDSHash *hash){
    if(hash == NULL)return;
    
    for(size_t i=0; i<hash->capacity; i++){

        CDSHashNode *cur=hash->table[i];

        while(cur != NULL){
            CDSHashNode *removed=cur;
            cur=removed->next;

            free(removed);
        }
        hash->table[i]=NULL;
    }
    
    hash->size=0;
}
