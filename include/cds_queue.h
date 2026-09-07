#ifndef CDS_QUEUE_H
#define CDS_QUEUE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSQueue CDSQueue;

/**
 * Creates an empty queue.
 *
 * @return Pointer to the created queue, or NULL if memory allocation fails.
 */
CDSQueue *cds_queue_create(void);

/**
 * Destroys the queue and frees all allocated memory.
 *
 * If queue is NULL, the function does nothing.
 *
 * @param queue Queue to destroy.
 */
void cds_queue_destroy(CDSQueue *queue);

/**
 * Returns the number of elements in the queue.
 *
 * @param queue Queue to inspect.
 * @return Number of elements in the queue, or 0 if queue is NULL.
 */
size_t cds_queue_size(const CDSQueue *queue);

/**
 * Checks whether the queue is empty.
 *
 * @param queue Queue to inspect.
 * @return true if the queue is empty or NULL, false otherwise.
 */
bool cds_queue_empty(const CDSQueue *queue);

/**
 * Retrieves the value at the front of the queue without removing it.
 *
 * @param queue Queue to inspect.
 * @param value Pointer where the front value will be stored.
 * @return true on success, false if queue or value is NULL,
 *         or if the queue is empty.
 */
bool cds_queue_front(const CDSQueue *queue, int *value);

/**
 * Retrieves the value at the back of the queue without removing it.
 *
 * @param queue Queue to inspect.
 * @param value Pointer where the back value will be stored.
 * @return true on success, false if queue or value is NULL,
 *         or if the queue is empty.
 */
bool cds_queue_back(const CDSQueue *queue, int *value);

/**
 * Adds an element to the back of the queue.
 *
 * @param queue Queue to modify.
 * @param value Value to add.
 * @return true if the element was added successfully, false if queue is NULL
 *         or memory allocation fails.
 */
bool cds_queue_push(CDSQueue *queue, int value);

/**
 * Removes the element at the front of the queue.
 *
 * @param queue Queue to modify.
 * @param value Optional pointer where the removed value will be stored.
 * @return true if an element was removed, false if queue is NULL
 *         or the queue is empty.
 */
bool cds_queue_pop(CDSQueue *queue, int *value);

/**
 * Removes all elements from the queue.
 *
 * @param queue Queue to clear.
 */
void cds_queue_clear(CDSQueue *queue);

#endif