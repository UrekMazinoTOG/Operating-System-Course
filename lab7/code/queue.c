
#include "queue.h"

/* Remember to initilize the queue before using it */
void initialize_queue(pqueue_t * q) {
	assert(q != NULL);
	q->head = q->tail = NULL;
	pthread_mutex_init(&q->lock, NULL);
}

/* Return non-zero if the queue is empty */
int empty(pqueue_t * q) {
	assert(q != NULL);
	return (q->head == NULL);
}

/* Get PCB of a process from the queue (q).
 * Return NULL if the queue is empty */
pcb_t * de_queue(pqueue_t * q) {
	assert(q != NULL);
	pcb_t *proc = NULL;

	pthread_mutex_lock(&q->lock);

	if(!empty(q)) {
		// 1 Save the head pointer
		qitem_t *dltItem = q->head;
		proc = dltItem->data;
		// 2 Change the head pointer to the next node
		q->head = dltItem->next;
		if(empty(q)) q->tail = NULL;
		// 3 Deallocate storage space of node
		free(dltItem); 
	}
	
	pthread_mutex_unlock(&q->lock);

	// 4 Return item
	return proc;
}

/* Put PCB of a process to the queue. */
void en_queue(struct pqueue_t * q, struct pcb_t * proc) {
	assert(q != NULL && proc != NULL);
	
	// 1 Create the new node
    qitem_t *newItem = (qitem_t*) malloc(sizeof(qitem_t));
	newItem->data = proc; 
	newItem->next = NULL;
	
	pthread_mutex_lock(&q->lock);
	// 2 Link the rear node to the new node
	if(!empty(q)) q->tail->next = newItem;
	// 3 Change the rear pointer to the new node
    //   If the new node is the first node, update head pointer
    q->tail = newItem;
    if(empty(q)) q->head = newItem;
	pthread_mutex_unlock(&q->lock);
}


