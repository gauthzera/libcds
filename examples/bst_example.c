#include "libcds.h"
#include <stdio.h>

void print_node(int value){
    printf("%d ",value);
}

int main() {
    CDSBST *bst = cds_bst_create();

    if(bst == NULL){
        return 1;
    }
    
    cds_bst_insert(bst, 1);
    cds_bst_insert(bst, 2);
    cds_bst_insert(bst, 3);
    cds_bst_insert(bst, 4);
    cds_bst_insert(bst, 5);
    cds_bst_insert(bst, 6);
    cds_bst_insert(bst, 7);


    cds_bst_inorder(bst, print_node); //1 2 3 4 5 6 7
    printf("\n");

    int height;
    if(cds_bst_height(bst, &height)){
        printf("height: %d\n",height); //6
    }

    cds_bst_remove(bst, 3);
    
    int max, min;
    
    if(cds_bst_max(bst, &max)){
        printf("max: %d\n",max); //7
    }

    if(cds_bst_min(bst, &min)){
        printf("min: %d\n",min); //1
    }
    
    cds_bst_postorder(bst, print_node); // 7 6 5 4 2 1
    printf("\n");

    cds_bst_destroy(bst);

    return 0;
}
