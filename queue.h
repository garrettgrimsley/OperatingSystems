#include <stdio.h>


extern int ______trace_switch;


typedef struct {
    int key;
    int value;
} data_t;

typedef struct queueNode {
    struct queueNode *next, *prev;
    data_t *data;
} QueueNode;

typedef struct queueType {
    QueueNode *head;
    QueueNode *tail;
} Queue;


void initQueue(Queue *theQueue);

void enQueue(Queue *theQueue, data_t *data);

data_t *frontValue(Queue *theQueue);

QueueNode *frontNode(Queue *theQueue);

data_t *deQueue(Queue *theQueue);

void removeNode(Queue *theQueue, QueueNode *p);

QueueNode *findNode(Queue *theQueue, data_t *data);

data_t *findValue(Queue *theQueue, data_t *data);

void purge(Queue *theQueue, data_t *data);

void printQ(Queue *theQueue, char label[]);

char *toString(data_t *d);




