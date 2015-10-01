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
        return data_tPointer;
    }
}


data_t *findValue(Queue *theQueue, data_t *data) {
    QueueNode *found = findNode(theQueue, data);
    if (found != NULL) {
        return found->data;
    }
}


QueueNode *findNode(Queue *theQueue, data_t *data) {
    if (theQueue->head != NULL) {
        QueueNode *tempNode = theQueue->head;
        int i = 1;
        while (i == 1) {
            if (tempNode->data->key == data->key) {
                return tempNode;
            } else if (tempNode != theQueue->tail) {
                tempNode = tempNode->prev;
            } else {
                return NULL;
            }
        }
    }
}


void removeNode(Queue *theQueue, QueueNode *p) {
    QueueNode *pPrevious;
    QueueNode *pNext;
    if (p == NULL) {
        return;
    } else if (theQueue->head == NULL) { // Empty
        return;
    } else if (theQueue->head == theQueue->tail && theQueue->head == p) { // Single
        initQueue(theQueue);
    } else if (p == theQueue->head) { // Head
        pPrevious = p->prev;
        theQueue->head = pPrevious;
        theQueue->head->next = NULL;
    } else if (p == theQueue->tail) { // Tail
        pNext = p->next;
        theQueue->tail = pNext;
        theQueue->tail->prev = NULL;
    } else { // Middle
        pPrevious = p->prev;
        pNext = p->next;
        pPrevious->next = pNext;
        pNext->prev = pPrevious;
    };
    p->prev = p->next = NULL;
    free(p);
}


void purge(Queue *theQueue, data_t *data) {
    QueueNode *foundNode;
    QueueNode *checkNext = theQueue->head;
    if (theQueue->head != NULL) {
        int i = 1;
        while (i == 1) {
            foundNode = findNode(theQueue, data);
            if (foundNode != NULL) {
                removeNode(theQueue, foundNode);
                if (checkNext != NULL) {
                    checkNext = checkNext->prev;
                } else {checkNext = theQueue->head;}
            } else {
                i = 0;
            }
        }
    }
}


void printQ(Queue *theQueue, char label[]) {
    printf("\t \t \t %s", label);
    if (theQueue->head != NULL) {
        QueueNode *printNode = theQueue->head;
        int i = 1;
        while (i == 1) {
            printf(toString(printNode->data));
            if (printNode != theQueue->tail) {
                printNode = printNode->prev;
            } else {
                i = 0;
            }
        }
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

//
//int main() {
//    Queue newQueue = {NULL, NULL};
//    data_t dataZero = {0, 0};
//    data_t dataOne = {1, 1};
//    data_t dataTwo = {2, 2};
//    data_t dataThree = {3, 3};
//    Queue *qP = &newQueue;
//    data_t *dPZero = &dataZero;
//    data_t *dPOne = &dataOne;
//    data_t *dPTwo = &dataTwo;
//    data_t *dPThree = &dataThree;
//    enQueue(qP, dPZero);
//    enQueue(qP, dPOne);
//    enQueue(qP, dPTwo);
//    enQueue(qP, dPThree);
//    QueueNode *removeZero = findNode(qP, dPZero);
//    QueueNode *removeOne = findNode(qP, dPOne);
//    QueueNode *removeTwo = findNode(qP, dPTwo);
//    QueueNode *removeThree = findNode(qP, dPThree);
//    removeNode(qP, removeTwo);
//    removeNode(qP, removeOne);
//    return 0;
//}