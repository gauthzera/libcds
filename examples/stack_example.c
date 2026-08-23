#include "libcds.h"
#include <stdio.h>

int main() {
    CDSStack *stack = cds_stack_create();
    
    if(stack == NULL){
        return 1;
    }
    
    cds_stack_push(stack,2);
    cds_stack_push(stack,6);
    cds_stack_push(stack,10);

    int top;
    if(cds_stack_top(stack,&top)){
        printf("%d\n",top); //10
    }
    
    cds_stack_push(stack,20);

    int removed;
    if(cds_stack_pop(stack,&removed)){
        printf("%d\n",removed); //20
    }
    
    cds_stack_pop(stack, NULL);

    size_t n=cds_stack_size(stack);
    printf("%zu\n",n); //2

    cds_stack_destroy(stack);

    return 0;
}
