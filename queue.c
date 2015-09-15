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
    else {
        exit(EXIT_FAILURE);
    }
}


data_t *frontValue(Queue *theQueue) {
    if (theQueue->head->data) {
        return theQueue->head->data;
    } else {
        exit(EXIT_FAILURE);
    }
}


data_t *deQueue(Queue *theQueue) {
    if (theQueue->head) {
        data_t *data_tPointer = theQueue->head->data;
        theQueue->head = theQueue->head->prev;
        theQueue->head->next = NULL;
        return data_tPointer;
    } else {
        exit(EXIT_FAILURE);
    }
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
        exit(EXIT_FAILURE);
    } else if (theQueue->head->data->key == data->key) {
        return theQueue->head;
    } else {
        QueueNode *tempNode;
        tempNode = theQueue->head;
        while (tempNode->prev) {
            if (tempNode->data->key == data->key) {
                return tempNode;
            }
            tempNode = tempNode->prev;
        }
    }
    exit(EXIT_FAILURE);
}


data_t *findValue(Queue *theQueue, data_t *data) {
    return findNode(theQueue, data)->data;
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

    if (d == NULL) {
        sprintf(result, "NULL");
    } else {
        sprintf(result, "key=%d(data=%d) ", d->key, d->value);
    }
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
    printf("\n");
    printf("The front node is at memory address %p\n", frontNode(&myQueue));
    printf("The value returned by frontValue is: %s\n", toString(frontValue(&myQueue)));
    printf("First dequeue removes: %s\n", toString(deQueue(&myQueue)));
    printf("Second dequeue removes: %s\n", toString(deQueue(&myQueue)));
    printf("The front node is at memory address %p\n", frontNode(&myQueue));
    printf("The node with Key ==  %i is at memory location %p\n", myQueue.tail->data->key,
           findNode(&myQueue, &data[2]));
    printf("Value for node where Key == %i is: %s\n", 6, toString(findValue(&myQueue, &data[6])));
    return 0;

}
