#include "cds_stack.h"
#include <stdlib.h>

typedef struct CDSStackNode{
    int value;
    struct CDSStackNode *next;
}CDSStackNode;

static CDSStackNode *cds_stack_node_create(int value){
    CDSStackNode *n=malloc(sizeof(CDSStackNode));
    
    if(n == NULL)return NULL;

    n->value=value;
    n->next=NULL;

    return n;
}

struct CDSStack{
    CDSStackNode *top;
    size_t size;
};

CDSStack *cds_stack_create(void){
    CDSStack *stack=malloc(sizeof(CDSStack));
        
    if(stack == NULL)return NULL;
    
    stack->top=NULL;
    stack->size=0;
    
    return stack;
}

void cds_stack_destroy(CDSStack *stack){
    if(stack == NULL) return;
    
    for(CDSStackNode *n=stack->top; n!=NULL;){
        CDSStackNode *cur=n;
        n=n->next;
            
        free(cur);
    }
    
    free(stack);
}

size_t cds_stack_size(const CDSStack *stack){
    if(stack == NULL)return 0;
    return stack->size;
}


bool cds_stack_empty(const CDSStack *stack){
    if(stack == NULL)return true;
    return stack->size==0;
}

bool cds_stack_top(const CDSStack *stack, int *value){
    if(stack == NULL || stack->size==0 || value==NULL)return false;

    *value=stack->top->value;
    return true;
}

bool cds_stack_push(CDSStack *stack,int value){
    if(stack == NULL)return false;

    CDSStackNode *new_node=cds_stack_node_create(value);
    
    if(new_node == NULL)return false;

    new_node->next=stack->top;
    stack->top=new_node;

    stack->size++;
    
    return true;
}

bool cds_stack_pop(CDSStack *stack,int *value){
    if(stack == NULL || stack->size == 0)return false;
    
    CDSStackNode *removed=stack->top;
    stack->top=removed->next;
    
    if(value != NULL){
        *value=removed->value;
    }

    free(removed);

    stack->size--;
    return true;
}

void cds_stack_clear(CDSStack *stack){
     if(stack == NULL) return;
    
    for(CDSStackNode *n=stack->top; n!=NULL;){
        CDSStackNode *cur=n;
        n=n->next;
            
        free(cur);
    }
    
    stack->top=NULL;
    stack->size=0;
}

