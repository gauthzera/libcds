#ifndef CDS_QUEUE_H
#define CDS_QUEUE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSQueue CDSQueue;

//Create and destroy
CDSQueue *cds_queue_create(void);
void cds_queue_destroy(CDSQueue *queue);

//Information
size_t cds_queue_size(const CDSQueue *queue);
bool cds_queue_empty(const CDSQueue *queue);
bool cds_queue_front(const CDSQueue *queue, int *value);
bool cds_queue_back(const CDSQueue *queue, int *value);

//Modification
bool cds_queue_push(CDSQueue *queue,int value);
bool cds_queue_pop(CDSQueue *queue,int *value);
void cds_queue_clear(CDSQueue *queue);

#endif
