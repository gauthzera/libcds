#include "cds_trie.h"
#include  <stdlib.h>

typedef struct CDSTrieNode{
    struct CDSTrieNode *children[26];
    bool end;
}CDSTrieNode;

static CDSTrieNode *cds_trie_node_create(){
    CDSTrieNode *n = malloc(sizeof(CDSTrieNode));
    
    if(n == NULL)return NULL;
    
    for(int i=0; i<26 ;i++){
        n->children[i]=NULL;
    }

    n->end = false;

    return n;
}

struct CDSTrie{
    CDSTrieNode *root;
    size_t size;
};

CDSTrie *cds_trie_create(void){
    CDSTrie *trie = malloc(sizeof(CDSTrie));
    
    if(trie == NULL)return NULL;
    
    trie->root=cds_trie_node_create();
    if(trie->root == NULL){
        free(trie);
        return NULL;
    }
    
    trie->size=0;
    return trie;
}

static void cds_trie_destroy_node(CDSTrieNode *node){
    if(node == NULL)return;

    for(int i=0;i<26;i++){
        if(node->children[i] != NULL){
            cds_trie_destroy_node(node->children[i]);
        }
    }
     
    free(node);
}

void cds_trie_destroy(CDSTrie *trie){
    if(trie == NULL)return;

    cds_trie_destroy_node(trie->root);
    free(trie);
}

size_t cds_trie_size(const CDSTrie *trie){
    if(trie == NULL)return 0;

    return trie->size;
}

bool cds_trie_empty(const CDSTrie *trie){
    if(trie == NULL)return true;
    
    return trie->size == 0;
}

static bool trie_valid_string(const char *str){
    if(str == NULL || str[0] == '\0')return false; 

    for(size_t i=0; str[i]!='\0'; i++){
        if(str[i] < 'a' || str[i]>'z'){
                return false;
        }
    }
    return true;
}

bool cds_trie_contains(const CDSTrie *trie, const char *word){
    if(trie == NULL || !trie_valid_string(word))return false;
    
    CDSTrieNode *cur = trie->root;

    for(size_t i=0; word[i] != '\0'; i++){
        int indx=word[i] - 'a';

        if(cur->children[indx]==NULL)return false;

        cur=cur->children[indx];
    } 
    
    return cur->end;
}

bool cds_trie_starts_with(const CDSTrie *trie, const char *prefix){
    if(trie == NULL || !trie_valid_string(prefix))return false;

    CDSTrieNode *cur = trie->root;

    for(size_t i=0; prefix[i]!='\0'; i++){
        int indx=prefix[i] - 'a';

        if(cur->children[indx] == NULL)return false;
        
        cur=cur->children[indx];
    }

    return true;
}

bool cds_trie_insert(CDSTrie *trie, const char *word){
    if(trie == NULL || !trie_valid_string(word))return false;

    CDSTrieNode *cur = trie->root;
    
    for(size_t i=0; word[i] != '\0'; i++){
        int indx=word[i] - 'a';

        if(cur->children[indx] == NULL){
            cur->children[indx] = cds_trie_node_create();
            
            if(cur->children[indx] == NULL)return false;

        }
        
        cur = cur->children[indx];
    }
    
    if(cur->end){
        return false;
    }
        
    cur->end = true;
    trie->size++;
    return true;
}

static bool node_has_children(CDSTrieNode *node){
    for(int i=0; i<26; i++){
        if(node->children[i] != NULL)return true;
    }

    return false;
}

static bool trie_remove(CDSTrieNode *node, const char *word, size_t pos){
    if(word[pos] == '\0'){
        node->end=false;
        
        return !node_has_children(node);
    }
 
    int indx = word[pos] - 'a';
    
    CDSTrieNode *child = node->children[indx];
    
    bool remove_child = trie_remove(child, word, pos+1);
    
    if(remove_child){
        free(child);
        node->children[indx] = NULL;
    }
    
    return !node->end && !node_has_children(node);
}

bool cds_trie_remove(CDSTrie *trie, const char *word){
    if(trie == NULL || !trie_valid_string(word))return false;
    
    if(!cds_trie_contains(trie, word))return false;
    
    trie_remove(trie->root, word, 0);

    trie->size--;
    
    return true;
}

void cds_trie_clear(CDSTrie *trie){
    if(trie == NULL)return;
    
    for(int i=0; i<26; i++){
        cds_trie_destroy_node(trie->root->children[i]);
        trie->root->children[i] = NULL;
    }
    
    trie->root->end = false;
    trie->size=0;
}
