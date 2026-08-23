#include "libcds.h"
#include <stdio.h>

int main() {
    CDSQueue *queue = cds_queue_create();

    if(queue == NULL){
        return 1;
    }
    
    cds_queue_push(queue,10);
    cds_queue_push(queue,15);
    cds_queue_push(queue,20);
        
    int front;
    if(cds_queue_front(queue,&front)){
        printf("%d\n",front); //10
    }

    int back;
    if(cds_queue_back(queue,&back)){
        printf("%d\n",back); //20
    }
    
    int removed;
    if(cds_queue_pop(queue,&removed)){
        printf("%d\n",removed); //10
    }
    
    cds_queue_pop(queue, NULL);

    size_t n=cds_queue_size(queue);
    printf("%zu\n",n); //1

    cds_queue_destroy(queue);
    
    return 0;
}
