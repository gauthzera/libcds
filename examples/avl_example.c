#include "libcds.h"
#include <stdio.h>

void print_node(int value){
    printf("%d ",value);
}

int main() {
    CDSAVL *avl = cds_avl_create();

    if(avl == NULL){
        return 1;
    }
    
    cds_avl_insert(avl, 1);
    cds_avl_insert(avl, 2);
    cds_avl_insert(avl, 3);
    cds_avl_insert(avl, 4);
    cds_avl_insert(avl, 5);
    cds_avl_insert(avl, 6);
    cds_avl_insert(avl, 7);

    cds_avl_inorder(avl, print_node); //1 2 3 4 5 6 7
    printf("\n");

    int height;
    if(cds_avl_height(avl, &height)){
        printf("height: %d\n",height); //2
    }

    cds_avl_remove(avl, 3);
    
    int max, min;
    
    if(cds_avl_max(avl, &max)){
        printf("max: %d\n",max); //7
    }

    if(cds_avl_min(avl, &min)){
        printf("min: %d\n",min); //1
    }

    cds_avl_postorder(avl, print_node); //1 2 5 7 6 4
    printf("\n");

    cds_avl_destroy(avl);

    return 0;
}
