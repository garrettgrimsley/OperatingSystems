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


void enQueue(Queue* theQueue, data_t *data) {
    QueueNode *letsTryMalloc;
    letsTryMalloc = (QueueNode *) malloc(sizeof(QueueNode));
    QueueNode putInMalloc = {NULL, NULL, data};
    *letsTryMalloc = putInMalloc;
    printf("Key: %i \t Value: %i\n", letsTryMalloc->data->key, letsTryMalloc->data->value);
    if (theQueue->head == NULL) {
        theQueue->head = letsTryMalloc;
        printf("WE NULL STILL");
    }
}


QueueNode *frontNode(Queue *theQueue) {
    return theQueue->head;
}


data_t *frontValue(Queue *theQueue) {
    return theQueue->head->data;
}


data_t *deQueue(Queue *theQueue) {
    data_t *data_tPointer = theQueue->head->data;
    theQueue->head = theQueue->head->prev;
    theQueue->head->next = NULL;
    return data_tPointer;
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
    if (&theQueue->head != NULL) {
        printf("ye");
    }
    QueueNode *nextNode;
    nextNode = theQueue->head;
    while (&nextNode != NULL) {
        printf("%s", label);
        printf(toString((theQueue->head->prev->data)));
        nextNode = nextNode->next;
    }
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
    printf("That's why I\n");
    printQ(&myQueue, "MyQueue:");
    return 0;

}
