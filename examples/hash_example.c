#include "libcds.h"
#include <stdio.h>

int main() {
    CDSHash *hash = cds_hash_create(8);
    
    if(hash == NULL){
        return 1;
    }

    cds_hash_insert(hash, 10);
    cds_hash_insert(hash, 5);
    cds_hash_insert(hash, 9);
    cds_hash_insert(hash, 20);
    
    if(!cds_hash_insert(hash,10)){
        printf("10 already exists!\n");
    }

    printf("size: %zu\n", cds_hash_size(hash)); //4
    printf("capacity: %zu\n", cds_hash_capacity(hash)); //8
    
    if(cds_hash_contains(hash, 9)){
        printf("9 found\n");
    }

    if(!cds_hash_contains(hash, 30)){
        printf("30 not found\n");     //30 not found
    }

    if(cds_hash_remove(hash, 10)){
        printf("removed 10\n");     //removed 10
    }
    
    cds_hash_clear(hash);

    printf("size after clear: %zu\n", cds_hash_size(hash));

    cds_hash_destroy(hash);
    
    return 0;
}
