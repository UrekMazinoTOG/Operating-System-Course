
#ifndef QUEUE_H
#define QUEUE_H

#include "structs.h"
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

/* Initialize the process queue */
void initialize_queue(pqueue_t * q);

/* Get a process from a queue */
struct pcb_t * de_queue(pqueue_t * q);

/* Put a process into a queue */
void en_queue(pqueue_t * q, pcb_t * proc);

/* Check queue is empty or not */
int empty(pqueue_t * q);

#endif


