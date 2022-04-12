#include <stdio.h>
#include <stdlib.h>

/* Struktur Node */

typedef struct dnode_t {
    long long data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(long long value);
void deq_init(Deque *deque);
int deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, long long value);
void deq_pushBack(Deque *deque, long long value);
long long deq_front(Deque *deque);
long long  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

/* Definisi Fungsi */

DListNode* __dlist_createNode(long long value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

int deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, long long value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, long long value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

long long deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

long long deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

int main()
{
    int n, q;
    long long i;
    long long a;
    long long A, B;
    scanf("%d%d", &n, &q);

    Deque deque;
    deq_init(&deque);

    for(i=0;i<n;i++){
        scanf("%lld", &a);
        deq_pushBack(&deque, a);
    }
    
    

    

    long long AB[5*n][2];
    AB[1][0] = deq_front(&deque);
    deq_popFront(&deque);
    AB[1][1] = deq_front(&deque);
    deq_pushBack(&deque, AB[1][0]);
    

    
    for(long long j=0;j<5*n-2;j++){
        
        A = deq_front(&deque);
        deq_popFront(&deque);
        B = deq_front(&deque);
        deq_popFront(&deque);

        if(A>B){
            deq_pushFront(&deque, A);
            deq_pushBack(&deque, B);
        } else {
            deq_pushFront(&deque, B);
            deq_pushBack(&deque, A);
        }

        AB[j+2][0] = A;
        AB[j+2][1] = B;
    }
    
    long long temp;
    long long query[q];
    for(long long j=0;j<q;j++){
        scanf("%lld", &temp);
        
        if(temp>2*n) temp = (temp%(n-1)) + 2*n -2;
        
        query[j] = temp;
    }
    
    


    
    
    
    for(i=0;i<q;i++){
        printf("%lld %lld\n", AB[query[i]][0], AB[query[i]][1]);
    }


    


    
}