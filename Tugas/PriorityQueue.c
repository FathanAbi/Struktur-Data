#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char job[50];
    struct Node* next;
    struct Node* prev;
    int priority;
} Node, *NodePtr;

typedef struct Pqueue{
    NodePtr head;
    NodePtr tail;
    int size;
} PQueue, *PQueuePtr;

PQueuePtr QueueInit(void)
{
    PQueuePtr pqueue;

    pqueue = (PQueuePtr)malloc(sizeof(PQueue));

    pqueue->size = 0;
    pqueue->head = NULL;
    
    return pqueue;
}

void enqueue(PQueuePtr que, char job[], int priority){
    NodePtr np;
    np = (NodePtr)malloc(sizeof(Node));

    np->priority = priority;
    strcpy(np->job, job);
    np->next = NULL;
    np->prev = NULL;

    if(que->head == NULL){
        que->head = np;
        que->tail = np;
        que->size++;
    } else if(np->priority > que->head->priority){
        np->next = que->tail;
        que->head = np;
        que->size++;

    }
    else {
        NodePtr temp = que->head;
        while(temp->next->priority > np->priority){
            temp = temp->next;
        }
        
        np->next = temp->next;
        temp->next = np;

        que->size++;
    }
    
    
}

int main()
{
    PQueuePtr pque;
    pque = QueueInit();

    
    enqueue(pque, "Major", 10);
    enqueue(pque, "president", 1000);
    enqueue(pque, "Governor", 100);
    enqueue(pque, "Vice President", 999);

    printf("size: %d \n", pque->size);

    NodePtr temp = pque->head;
    while(temp != NULL){
        printf("%s\n", temp->job);
        temp = temp->next;
    }



}