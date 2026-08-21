#include "libcds.h"
#include <stdio.h>

int main(){
    CDSVector *v=cds_vector_create();
    
    if(v == NULL){
        return 1;
    }

    cds_vector_push_back(v,15);
    cds_vector_push_back(v,10);
    cds_vector_push_back(v,5);

    size_t n=cds_vector_size(v);

    for(size_t i=0; i<n; i++){
        int x;
        if(cds_vector_at(v,i,&x)){
            printf("%d ",x); //15, 10 , 5
        }
    }

    printf("\n");

    cds_vector_sort(v);
    
    for(int i=0; i<n; i++){
        int x;
        if(cds_vector_at(v,i,&x)){
            printf("%d ",x); //5, 10, 15
        }
    }
    
    printf("\n");

    int removed;
    if(cds_vector_pop_back(v,&removed)){
        printf("%d\n",removed); //15
    }
    
    cds_vector_destroy(v);

    return 0;
}
