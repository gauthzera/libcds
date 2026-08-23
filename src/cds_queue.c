#include "cds_queue.h"
#include <stdlib.h>

typedef struct CDSQueueNode{
    int value;
    struct CDSQueueNode *next;
}CDSQueueNode;

static CDSQueueNode *cds_queue_node_create(int value){
    CDSQueueNode *n=malloc(sizeof(CDSQueueNode));

    if(n == NULL)return NULL;

    n->value=value;
    n->next=NULL;

    return n;
}

struct CDSQueue{
    CDSQueueNode *front,*back;
    size_t size;
};

CDSQueue *cds_queue_create(void){
    CDSQueue *queue=malloc(sizeof(CDSQueue));

    if(queue == NULL)return NULL;
    
    queue->front=NULL;
    queue->back=NULL;
    queue->size=0;

    return queue;
}

void cds_queue_destroy(CDSQueue *queue){
    if(queue == NULL) return;

    for(CDSQueueNode *n=queue->front; n!=NULL;){
        CDSQueueNode *cur=n;
        n=n->next;
        
        free(cur);
    }

    free(queue);
}

size_t cds_queue_size(const CDSQueue *queue){
    if(queue == NULL)return 0;
    return queue->size;
}

bool cds_queue_empty(const CDSQueue *queue){
    if(queue == NULL) return true;

    return queue->size == 0;
}

bool cds_queue_front(const CDSQueue *queue, int *value){
    if(queue == NULL || value == NULL || queue->size == 0)return false;

    *value=queue->front->value;
    return true;
}

bool cds_queue_back(const CDSQueue *queue, int *value){
    if(queue == NULL || value == NULL || queue->size == 0)return false;

    *value=queue->back->value;
    return true;
}

bool cds_queue_push(CDSQueue *queue, int value){
    if(queue == NULL)return false;
    
    CDSQueueNode *new_node=cds_queue_node_create(value);
    
    if(new_node == NULL)return false;

    if(queue->size == 0){
        queue->front=new_node;
        queue->back=new_node;

        queue->size++;
        return true;
    }

    queue->back->next=new_node;
    queue->back=new_node;
    
    queue->size++;

    return true;
}

bool cds_queue_pop(CDSQueue *queue, int *value){
    if(queue == NULL || queue->size == 0)return false;
    
    CDSQueueNode *removed = queue->front;
    queue->front = removed->next;
    
    if(queue->front == NULL){
        queue->back = NULL;
    }
    
    if(value != NULL){
        *value=removed->value;
    }

    queue->size--;

    free(removed);
    return true;
}

void cds_queue_clear(CDSQueue *queue){
    if(queue == NULL)return;
    
    for(CDSQueueNode *n=queue->front; n!=NULL;){
        CDSQueueNode *cur=n;
        n=n->next;
        
        free(cur);
    }
    
    queue->front=NULL;
    queue->back=NULL;

    queue->size = 0;
}
