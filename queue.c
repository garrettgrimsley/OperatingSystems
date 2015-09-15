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
    if (theQueue->head == NULL) {
        theQueue->head = letsTryMalloc;
        theQueue->tail = letsTryMalloc;
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
    return NULL;
}


data_t *frontValue(Queue *theQueue) {
    if (theQueue->head != NULL) {
        return theQueue->head->data;
    }
}


data_t *deQueue(Queue *theQueue) {
    if (theQueue->head != NULL) {
        data_t *data_tPointer;
        data_tPointer = theQueue->head->data;
        if (theQueue->head->prev != NULL) {
            theQueue->head = theQueue->head->prev;
            theQueue->head->next = NULL;
        } else if (theQueue->head->prev == NULL) {
            theQueue->head = NULL;
        }
        else if (theQueue->head->next != NULL) {
            theQueue->head->next = NULL;
        }
        return data_tPointer;
    }
}


data_t *findValue(Queue *theQueue, data_t *data) {
    if (findNode(theQueue, data) != NULL) {
        return findNode(theQueue, data)->data;
    }
}


QueueNode *findNode(Queue *theQueue, data_t *data) {
    QueueNode *tempNode;
    tempNode = theQueue->head;

    if (theQueue->head == NULL) {
        return NULL;
    }

    if (tempNode->data->key == data->key) {
        return tempNode;
    }
    while (tempNode->prev != NULL) {
        if (tempNode->data->key == data->key) {
            return tempNode;
        }
        tempNode = tempNode->prev;
    }
    if (tempNode->data->key == data->key) {
        return tempNode;
    }
    return NULL;
}


void removeNode(Queue *theQueue, QueueNode *p) {
    QueueNode pPrevious;
    QueueNode pNext;

    if (p->prev != NULL && p->next != NULL) {
        pPrevious = *p->prev;
        pNext = *p->next;
        pPrevious.next = p->next;
        pNext.prev = p->prev;
        goto TheEnd;
    } else if (p->prev != NULL && p->next == NULL) {
        theQueue->head = p->prev;
        theQueue->head->next = NULL;
        goto TheEnd;
    } else if (p->prev == NULL && p->next != NULL) { // Deal
        theQueue->tail = p->next;
        theQueue->tail->prev = NULL;
        goto TheEnd;
    } else if (p->next == NULL && p->prev == NULL) {
        initQueue(theQueue);
        goto TheEnd;
    }
    TheEnd:
    free(p);
    p = NULL;
    return;
}

void purge(Queue *theQueue, data_t *data) {
    QueueNode *foundNode;
    QueueNode *theNextNode;
    QueueNode *anotherNode;
    theNextNode = theQueue->head;
    while (theNextNode != NULL) {
        foundNode = findNode(theQueue, data);
        anotherNode = foundNode;
        removeNode(theQueue, foundNode);
        theNextNode = anotherNode;

    }
}



void printQ(Queue *theQueue, char label[]) {
    printf("%s", label);
    if (theQueue->head == NULL) {
        return;
    }
    QueueNode *nextNode;
    nextNode = theQueue->head;
    printf("\t");
    while (nextNode != NULL) {
        printf("");
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


/*int main() {
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
    // Terrible "testing"
    printQ(&myQueue, "MyQueue: ");
    printf("\n");
    printf("The front node is at memory address %p\n", frontNode(&myQueue));
    printf("The value returned by frontValue is: %s\n", toString(frontValue(&myQueue)));
    printf("First dequeue removes: %s\n", toString(deQueue(&myQueue)));
    printf("Second dequeue removes: %s\n", toString(deQueue(&myQueue)));
    printf("The front node is at memory address %p\n", frontNode(&myQueue));
    printf("The node with Key ==  %i is at memory location %p\n", myQueue.tail->data->key,
           findNode(&myQueue, &data[2]));
    printf("Value for node where Key == %i is: %s\n", 6, toString(findValue(&myQueue, &data[6])));
    p = myQueue.head->prev->prev;
    printQ(&myQueue, "Queue is now: ");
    printf("\n");
    printf("Pointer p, address: %p points to item with data: %s\n", p, toString(p->data));
    printf("Calling to remove node p\n");
    removeNode(&myQueue, p);
    printQ(&myQueue, "Queue after removeNode() call: ");
    printf("\n");
    printf("Going to purge the nodes with key of %i\n", data[5]);
    purge(&myQueue, &data[5]);
    printQ(&myQueue, "Queue after purge() call: ");
    return 0;
}*/
