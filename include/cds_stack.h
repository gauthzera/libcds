#ifndef CDS_STACK_H
#define CDS_STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSStack CDSStack;

/**
 * Creates an empty stack.
 *
 * @return Pointer to the created stack, or NULL if memory allocation fails.
 */
CDSStack *cds_stack_create(void);

/**
 * Destroys the stack and frees all allocated memory.
 *
 * If stack is NULL, the function does nothing.
 *
 * @param stack Stack to destroy.
 */
void cds_stack_destroy(CDSStack *stack);

/**
 * Returns the number of elements in the stack.
 *
 * @param stack Stack to inspect.
 * @return Number of elements in the stack, or 0 if stack is NULL.
 */
size_t cds_stack_size(const CDSStack *stack);

/**
 * Checks whether the stack is empty.
 *
 * @param stack Stack to inspect.
 * @return true if the stack is empty or NULL, false otherwise.
 */
bool cds_stack_empty(const CDSStack *stack);

/**
 * Retrieves the value at the top of the stack without removing it.
 *
 * @param stack Stack to inspect.
 * @param value Pointer where the top value will be stored.
 * @return true on success, false if stack or value is NULL,
 *         or if the stack is empty.
 */
bool cds_stack_top(const CDSStack *stack, int *value);

/**
 * Adds an element to the top of the stack.
 *
 * @param stack Stack to modify.
 * @param value Value to add.
 * @return true if the element was added successfully, false if stack is NULL
 *         or memory allocation fails.
 */
bool cds_stack_push(CDSStack *stack, int value);

/**
 * Removes the element at the top of the stack.
 *
 * @param stack Stack to modify.
 * @param value Optional pointer where the removed value will be stored.
 * @return true if an element was removed, false if stack is NULL
 *         or the stack is empty.
 */
bool cds_stack_pop(CDSStack *stack, int *value);

/**
 * Removes all elements from the stack.
 *
 * @param stack Stack to clear.
 */
void cds_stack_clear(CDSStack *stack);

#endif