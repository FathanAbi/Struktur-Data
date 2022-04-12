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
long long  deq_front(Deque *deque);
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

void printKMax(long long arr[], int n, int k)
{
     
    // Create a Double Ended Queue,
    // Qi that will store indexes
    // of array elements
    // The queue will store indexes
    // of useful elements in every
    // window and it will
    // maintain decreasing order of
    // values from front to rear in Qi, i.e.,
    // arr[Qi.front[]] to arr[Qi.rear()]
    // are sorted in decreasing order
    Deque deque;
    deq_init(&deque);

 
    /* Process first k (or first window)
     elements of array */
    int i;
    for (i = 0; i < k; ++i)
    {
     
        // For every element, the previous
        // smaller elements are useless so
        // remove them from Qi
        while ((!deq_isEmpty(&deque)) && arr[i] >=
                            arr[deq_back(&deque)])
           
             // Remove from rear
            deq_popBack(&deque);
 
        // Add new element at rear of queue
       deq_pushBack(&deque, i);
    }
 
    // Process rest of the elements,
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i)
    {
     
        // The element at the front of
        // the queue is the largest element of
        // previous window, so print it

        //cout << arr[Qi.front()] << " ";
        printf("%lld ", arr[deq_front(&deque)]);
 
        // Remove the elements which
        // are out of this window
        while ((!deq_isEmpty(&deque)) && deq_front(&deque) <=
                                           i - k)
           
            // Remove from front of queue
            deq_popFront(&deque);
 
        // Remove all elements
        // smaller than the currently
        // being added element (remove
        // useless elements)
        while ((!deq_isEmpty(&deque)) && arr[i] >=
                             arr[deq_back(&deque)])
            deq_popBack(&deque);
 
        // Add current element at the rear of Qi
        deq_pushBack(&deque, i);
    }
 
    // Print the maximum element
    // of last window
    //cout << arr[Qi.front()];
    printf("%lld", arr[deq_front(&deque)]);
}

int main()
{
    int n, k, i;
    scanf("%d", &n);

    long long arr[n];   
    for(i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    
    scanf("%d", &k);

    printKMax(arr, n, k);

    return 0;

}