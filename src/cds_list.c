#include "cds_list.h"
#include <stdlib.h>

typedef struct CDSListNode{
    int value;
    struct CDSListNode *next;
}CDSListNode;

static CDSListNode *cds_list_node_create(int value){
    CDSListNode *n=malloc(sizeof(CDSListNode));
    
    if(n == NULL)return NULL;

    n->value=value;
    n->next=NULL;

    return n;
}

struct CDSList{
    CDSListNode *first, *last;
    size_t size;
};

CDSList *cds_list_create(void){
    CDSList *list= malloc(sizeof(CDSList));
    
    if(list == NULL)return NULL;

    list->first=NULL;
    list->last=NULL;
    list->size=0;

    return list;
}

void cds_list_destroy(CDSList *list){
    if(list == NULL)return;
     
    for(CDSListNode *n=list->first; n!= NULL;){
        CDSListNode *cur=n;
        n=n->next;
        free(cur);
    }
    
    free(list);
}

size_t cds_list_size(const CDSList *list){
   if(list == NULL)return 0;
   return list->size;
}

bool cds_list_empty(const CDSList *list){
    if(list == NULL)return true;

    return list->size == 0;
}

bool cds_list_at(const CDSList *list, size_t index, int *value){
    if(list == NULL || value == NULL || index>= list->size)return false;
    
    const CDSListNode *n=list->first;
    for(size_t i=0; i<index; i++){
        n=n->next;
    }
    
    *value= n->value;
    return true;
}

bool cds_list_contains(const CDSList *list, int value){
    if(list == NULL)return false;
    
    for(const CDSListNode *n=list->first; n!=NULL; n=n->next){
        if(n->value == value) return true;
    }

    return false;
}

bool cds_list_push_front(CDSList *list, int value){
    if(list == NULL) return false;
    
    CDSListNode *new_node= cds_list_node_create(value);
    if(new_node  ==  NULL)return false;

    new_node->next = list->first;
    list->first=new_node;
    
    if(list->size == 0){
        list->last = list->first;
    }

    list->size++;

    return true;
}

bool cds_list_push_back(CDSList *list, int value){
    if(list == NULL)return false;

    CDSListNode *new_node= cds_list_node_create(value);
    if(new_node == NULL) return false;
    
    if(list->size == 0){
        list->first=new_node;
        list->last=new_node;
    }else{
        list->last->next=new_node;
        list->last=new_node;
    }

    list->size++;

    return true;
}

bool cds_list_insert(CDSList *list, size_t index, int value){
    if(list == NULL || index > list->size)return false;
    
    if(index == 0) return cds_list_push_front(list, value);
    if(index == list->size) return cds_list_push_back(list, value);

    CDSListNode *new_node=cds_list_node_create(value);
    if(new_node == NULL) return false;

    size_t cnt=0;
    CDSListNode *prev=list->first;
    
    while(cnt < index-1){
        prev=prev->next;
        cnt++;
    }
    
    new_node->next=prev->next;
    prev->next=new_node;
    list->size++;    
    
    return true;
}

bool cds_list_pop_front(CDSList *list, int *value){
    if(list == NULL || list->size == 0 || value == NULL)return false;
    
    CDSListNode *removed=list->first;
    list->first=removed->next;
    
    if(list->first == NULL){
        list->last = NULL;
    }    
    
    *value=removed->value;
    free(removed);

    list->size--;
    return true;
}

bool cds_list_pop_back(CDSList *list, int *value){
    if(list == NULL || list->size == 0 || value == NULL) return false;
    
    if(list->size == 1){
        return cds_list_pop_front(list, value);
    }

    CDSListNode *prev=list->first;

    while(prev->next != list->last){
        prev=prev->next;
    }

    CDSListNode *removed=list->last;

    prev->next=NULL;

    *value=removed->value;
    list->last=prev;

    free(removed);

    list->size--;
        
    return true;
}

bool cds_list_erase(CDSList *list, size_t index){
    if(list == NULL || index >= list->size)return false;
    
    if(index == 0){
        int value;
        return cds_list_pop_front(list, &value);
    }

    size_t cnt=0;
    CDSListNode *prev=list->first;

    while(cnt < index-1){
        prev=prev->next;
        cnt++;
    }
    
    CDSListNode *removed=prev->next;
    prev->next = removed->next;
    
    if(removed == list->last){
        list->last=prev;
    }

    free(removed);
    list->size--;    

    return true;
}

bool cds_list_remove(CDSList *list, int value){
    if(list == NULL || list->size == 0)return false;

    if(list->first->value == value){
        int value;
        return cds_list_pop_front(list, &value);
    }
    
    CDSListNode *prev=list->first;

    while(prev->next != NULL && prev->next->value != value){
        prev=prev->next;
    }
    
    if(prev->next == NULL)return false;

    CDSListNode *removed=prev->next;
    prev->next=removed->next;

    if(removed == list->last){
        list->last=prev;
    }
    
    free(removed);
    list->size--;
    return true;
}

void cds_list_clear(CDSList *list){
    if(list == NULL)return;

    for(CDSListNode *n=list->first; n!= NULL;){
        CDSListNode *cur=n;
        n=n->next;
        free(cur);
    }
    list->first=NULL;
    list->last=NULL;

    list->size=0;    
}
