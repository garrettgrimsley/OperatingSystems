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
    QueueNode *letsTryMalloc;
    letsTryMalloc = (QueueNode *) malloc(sizeof(QueueNode));
    QueueNode putInMalloc = {NULL, NULL, data};
    *letsTryMalloc = putInMalloc;
    printf("Key: %i \t Value: %i\n", letsTryMalloc->data->key, letsTryMalloc->data->value);
    if (theQueue->head == NULL) {
        theQueue->head = letsTryMalloc;
        theQueue->tail = letsTryMalloc;
        printf("NULL STILL\n");
    } else {
        theQueue->tail->prev = letsTryMalloc;
        letsTryMalloc->next = theQueue->tail;
        theQueue->tail = letsTryMalloc;
    }
}


QueueNode *frontNode(Queue *theQueue) {
    if (theQueue->head) {
        return theQueue->head;
    }
}


data_t *frontValue(Queue *theQueue) {
    if (theQueue->head->data) {
    return theQueue->head->data;
    }
}


data_t *deQueue(Queue *theQueue) {
    data_t *data_tPointer = theQueue->head->data;
    theQueue->head = theQueue->head->prev;
    theQueue->head->next = NULL;
    return data_tPointer;
}


void removeNode(Queue *theQueue, QueueNode *p) {
    // Start at the head, search through the tail.
    if (theQueue->head) { // Check to make sure there is a head.
        QueueNode *checkNode;
        checkNode = theQueue->head;


    }
}


QueueNode *findNode(Queue *theQueue, data_t *data) {
    if (theQueue->head == NULL) {
        // Do something here?
    } else if (theQueue->head->data->key == data->key) {
        return theQueue->head;
    }
}


data_t *findValue(Queue *theQueue, data_t *data) {
}


void purge(Queue *theQueue, data_t *data) {
}


void printQ(Queue *theQueue, char label[]) {
    printf("%s", label);
    if (theQueue->head == NULL) {
        printf("Empty queue.\n");
        return;
    }
    QueueNode *nextNode;
    nextNode = theQueue->head;
    while (nextNode != NULL) {
        printf("\n");
        printf(toString((nextNode->data)));
        nextNode = nextNode->prev;
    }
    return;
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
    printf("\nThe front node is at memory address %p\n", frontNode(&myQueue));
    printf("First dequeue removes: %s\n", toString(deQueue(&myQueue)));
    printf("Second dequeue removes: %s\n", toString(deQueue(&myQueue)));
    printf("\nThe front node is at memory address %p\n", frontNode(&myQueue));
    findNode(&myQueue, myQueue.head->data);
    return 0;

}
