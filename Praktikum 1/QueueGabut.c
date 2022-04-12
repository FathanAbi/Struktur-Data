#include <stdio.h>
#include <stdlib.h>

/* Struktur ADT QueueArray */

typedef struct queuearr_t {
    int *_element;
    int _front, 
        _rear;
    unsigned _size, _capacity;
} QueueArray;

/* Function prototype */

void queueArray_init(QueueArray *queue, unsigned queueSize);
int queueArray_isEmpty(QueueArray *queue);
void queueArray_push(QueueArray *queue, int value);
void queueArray_pop(QueueArray *queue);
int  queueArray_front(QueueArray *queue);
unsigned queueArray_size(QueueArray *queue);

/* Function definition below */

void queueArray_init(QueueArray *queue, unsigned queueSize)
{
    queue->_element = (int*) malloc(sizeof(int) * queueSize);
    queue->_front = -1;
    queue->_rear  = -1;
    queue->_size  = 0;
    queue->_capacity = queueSize;
}

int queueArray_isEmpty(QueueArray *queue) {
    return (queue->_front == -1);
}

void queueArray_push(QueueArray *queue, int value)
{
    if (queue->_size + 1 <= queue->_capacity) {
        if (queue->_front == -1)
            queue->_front = 0;
        queue->_rear = (queue->_rear + 1) % queue->_capacity;
        queue->_element[queue->_rear] = value;
        queue->_size++; 
    }
}

void queueArray_pop(QueueArray *queue)
{
    if (!queueArray_isEmpty(queue)) {
        if (queue->_front == queue->_rear)
            queue->_front = queue->_rear = -1;
        else
            queue->_front = (queue->_front + 1) % queue->_capacity;
        queue->_size--;
    }
}

int queueArray_front(QueueArray *queue) 
{
    if (!queueArray_isEmpty(queue)) {
        return queue->_element[queue->_front];
    }
    return 0;
}

unsigned queueArray_size(QueueArray *queue) {
    return (queue->_size);
}

int main()
{
    int x, y, n, e, i;
    scanf("%d%d%d", &x, &y, &n);
    
    QueueArray queue;
    queueArray_init(&queue, x);
    
    for(i=0;i<x;i++){
        scanf("%d", &e);
        queueArray_push(&queue, e);
    }

  

    i=0;
    int j=0;
    int temp;
    while(queue._size != 0 && i<n){
        queueArray_pop(&queue);
        if(queue._size != 0){
            for(j=0;j<y%queue._size;j++){
                temp = queueArray_front(&queue);
                queueArray_push(&queue, temp);
                queueArray_pop(&queue);
            }
        }
        i++;

    }

    

    if((!queueArray_isEmpty(&queue))) printf("%d", queueArray_front(&queue));
    else printf("Kok sepi\n");

    
}