/****************************************************************************/
/* File: queue.c
 */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*              Simple Queue ADT                                            */
/*                                                                          */
/*              Implementation                                              */
/*                                                                          */
/****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void initQueue(Queue *theQueue) {
    theQueue->head = NULL;
    theQueue->tail = NULL;
}


void enQueue(Queue *theQueue, data_t *data) {
    struct queueNode newQueueNode = {NULL, NULL, data};
    newQueueNode.data->value = data->value;
    newQueueNode.data->key = data->key;
    newQueueNode.prev = theQueue->tail;
    theQueue->tail = &newQueueNode;
    if (theQueue->head != NULL) {
        theQueue->head = &newQueueNode;
    }
}


QueueNode *frontNode(Queue *theQueue) {
    return theQueue->head;
}


data_t *frontValue(Queue *theQueue) {
    return theQueue->head->data;
}


data_t *deQueue(Queue *theQueue) {

}


void removeNode(Queue *theQueue, QueueNode *p) {
}


QueueNode *findNode(Queue *theQueue, data_t *data) {
}


data_t *findValue(Queue *theQueue, data_t *data) {
}


void purge(Queue *theQueue, data_t *data) {
}


void printQ(Queue *theQueue, char label[]) {
    printf("aye");
}


char *toString(data_t *d) {
    static char result[BUFSIZ];

    if (d == NULL)
        sprintf(result, "NULL");
    else
        sprintf(result, "key=%d(data=%d) ", d->key, d->value);
    return result;
}

int main() {
    printf("That's why I\n");
    Queue myQueue;
    QueueNode *p;
    data_t data[10], d2;
    int i;

    initQueue(&myQueue);

    for (i = 0; i < 10; i++) {

        data[i].key = i;
        data[i].value = 10 * i;

        enQueue(&myQueue, &data[i]);
    }
    printQ(&myQueue, "MyQueue:");
    return 0;

}
