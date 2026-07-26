#ifndef CDS_STACK_H
#define CDS_STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSStack CDSStack;

//Create and destroy
CDSStack *cds_stack_create(void);
void cds_stack_destroy(CDSStack *stack);

//Information
size_t cds_stack_size(const CDSStack *stack);
bool cds_stack_empty(const CDSStack *stack);
bool cds_stack_top(const CDSStack *stack, int *value);

//Modification
bool cds_stack_push(CDSStack *stack,int value);
bool cds_stack_pop(CDSStack *stack,int *value);
void cds_stack_clear(CDSStack *stack);

#endif
