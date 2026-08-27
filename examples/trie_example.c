#include "libcds.h"
#include <stdio.h>

int main() {
    CDSTrie *trie = cds_trie_create();

    if(trie == NULL){
        return 1;
    }
    
    cds_trie_insert(trie, "casa");
    cds_trie_insert(trie, "carro");
    cds_trie_insert(trie, "cachorro");

    if(!cds_trie_insert(trie, "carro")){
        printf("this word already exists\n");
    }
    
    if(cds_trie_contains(trie, "cachorro")){
        printf("found word\n");
    }

    if(cds_trie_starts_with(trie, "ca")){
        printf("found prefix\n");
    }

    size_t size = cds_trie_size(trie);

    printf("size: %zu\n", size); //3

    char *word = "casa";

    if(cds_trie_remove(trie, word)){
        printf("removed %s\n", word);
    }

    cds_trie_destroy(trie);
    
    return 0;
}
