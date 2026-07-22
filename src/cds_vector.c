#include "cds_vector.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 8

struct CDSVector{
    int *data;
    size_t capacity;
    size_t size;
};

CDSVector *cds_vector_create(void){
    CDSVector* v=malloc(sizeof(CDSVector));
    
    if(v == NULL)return NULL;

    v->data=malloc(sizeof(int) * INITIAL_CAPACITY);

    if(v->data == NULL){
        free(v);
        return  NULL;
    }

    v->capacity=INITIAL_CAPACITY;
    v->size=0;

    return v;
}

void cds_vector_destroy(CDSVector *v){
    if(v == NULL) return;
    free(v->data);
    free(v);
}

size_t cds_vector_size(const CDSVector *v){
    if(v == NULL)return 0;
    return v->size;
}

size_t cds_vector_capacity(const CDSVector *v){
    if(v == NULL)return 0;
    return v->capacity;
}

bool cds_vector_at(const CDSVector *v, size_t index, int *value){
    if(v == NULL || value == NULL || index >= v->size) return false;

    *value=v->data[index];

    return true;
}

bool cds_vector_empty(const CDSVector *v){
    if(v == NULL)return true;

    return v->size == 0;
}

bool cds_vector_push_back(CDSVector *v,int value){
    if(v == NULL)return false;

    if(v->size == v->capacity ){
        int *new_data=realloc(v->data, v->capacity*2 * sizeof(int));
                 
        if(new_data == NULL)return false;

        v->data=new_data;
        v->capacity*=2;
    }
    
    v->data[v->size]=value;
    v->size++;

    return true;
}

bool cds_vector_pop_back(CDSVector *v,int *value){
    if(v == NULL || value == NULL || v->size == 0) return false;

    *value=v->data[v->size - 1];
    v->size--;

    return true;
}

bool cds_vector_insert(CDSVector *v, size_t index, int value){
    if(v == NULL || index > v->size) return false;

    if(v->size == v->capacity){
        int *new_data=realloc(v->data, v->capacity*2 * sizeof(int));
                 
        if(new_data == NULL)return false;

        v->data=new_data;
        v->capacity*=2;
    }
    
    for(size_t i=v->size; i>index; i--){
        v->data[i]=v->data[i-1];
    }
    
    v->data[index]=value;
    v->size++;

    return true;
}

bool cds_vector_erase(CDSVector *v, size_t index){
    if(v == NULL || index >= v->size)return false;

    for(size_t i=index; i< v->size-1; i++){
        v->data[i]=v->data[i+1];
    }
    
    v->size--;
    
    return true;
}

bool cds_vector_remove(CDSVector *v, int value){
    if(v == NULL ) return false;
    
    for(size_t i=0; i< v->size; i++){
        if(v->data[i] == value){
            return cds_vector_erase(v, i);
        }
    }

    return false;
}

void cds_vector_clear(CDSVector *v){
    if(v == NULL)return;
    v->size=0;
}

static void quicksort(int *v, int l, int r){
    int i=l,j=r;
    int pivot=v[l + (r-l)/2];

    while(i<=j){
        while(v[i]<pivot)i++;
        while(v[j]>pivot)j--;

        if(i<=j){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;

            i++;
            j--;
        }
    }

    if(i<r)quicksort(v,i,r);
    if(j>l)quicksort(v,l,j);
}

void cds_vector_sort(CDSVector *v){
    if(v == NULL || v->size < 2)return;

    quicksort(v->data, 0, (int)v->size-1);
}
