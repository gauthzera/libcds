#include "libcds.h"
#include <stdio.h>

int main() {
    CDSList *list=cds_list_create();
    
    if(list == NULL){
        return 1;
    }
        
    cds_list_push_back(list,10);
    cds_list_push_back(list,20);
    cds_list_push_front(list,30);

    if(cds_list_contains(list,10)){
        printf("YES\n"); //YES
    }
    
    cds_list_insert(list,1,5);
    
    int value;
    if(cds_list_at(list, 1, &value)){
        printf("%d\n",value); //5
    }
    
    int removed;
    if(cds_list_pop_front(list, &removed)){
        printf("%d\n",removed); //30
    }
    
    cds_list_erase(list, 1, NULL);
   
    size_t n = cds_list_size(list);
    printf("%zu\n", n); //2

    cds_list_destroy(list);
    
    return 0;
}

