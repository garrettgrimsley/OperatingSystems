#include "cpu.h"
#include "queue.h"

Queue maQ; // ayyyyy globals
int PRIORITY_DEC = 1;
int PRIORITY_INC = -1;
int PRIORITY_BASE = 1;

void cpu_init() {
    initQueue(&maQ);
}

void dispatch() {
    if (PTBR != NULL && PTBR->pcb->status == running) {
        if (Int_Vector.cause != timeint) {
            PTBR->pcb->last_dispatch = get_clock();
            return;
        }
        else if (Int_Vector.cause == timeint) {
            insert_ready(PTBR->pcb);
            PTBR = NULL;
        }
    }
    PCB *nextPCB = deQueue(&maQ);
    if (nextPCB == NULL) {
        PTBR = NULL;
        return;
    }
    else {
        PTBR = nextPCB->page_tbl;
        prepage(nextPCB); // External routine.
        nextPCB->status = running;
        nextPCB->last_dispatch = get_clock();
        set_timer(Quantum); // Same. Must be implemented in OSP.
    }
}

int compareTo(PCB *pcb1, PCB *pcb2) {
    return pcb1->priority - pcb2->priority;
}

void insert_ready(PCB *pcb) {
    if (pcb->accumulated_cpu == 0) {
        pcb->priority = PRIORITY_BASE;
    }
    else if (pcb->status == running && Int_Vector.cause == timeint) {
        pcb->priority += PRIORITY_DEC;
    }
    else if (pcb->status == waiting) {
        pcb->priority += PRIORITY_INC;
    }
    pcb->status = ready;
    enQueueSorted(&maQ, pcb, compareTo); // Passing function as argument. Neat.
}
