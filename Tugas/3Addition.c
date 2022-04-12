#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);
int  slist_getAt(SinglyList *list, int index);


void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, int index, int value)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;    
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        
        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;    
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }
        
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index)
{
    if(index > list->_size) return 0;
    else {
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }


        return temp->data;
    }
    return 0;
    }
}

void printList(SinglyList* list)
{
    int i;
    for(i=0;i<list->_size;i++){
        printf("%d", slist_getAt(list, i));
    }
}

int main(int argc, char const *argv[])
{
    int a, b;
    int* aptr = &a;
    int* bptr = &b;
    scanf("%d %d", &a, &b);

    SinglyList Add(int*, int*);
    SinglyList total = Add(aptr, bptr);
    
    for(int i=0;i<total._size;i++){
        printf("%d", slist_getAt(&total, i));
    }

    return 0;
}

SinglyList Add(int *ap, int*bp)
{
    SinglyList listA;      //buat linked list 
    slist_init(&listA);    //untuk menyimpan int a

    SinglyList listB;      //buat linked list 
    slist_init(&listB);    //untuk menyimpan int B

    int a = *ap;           //var untuk value int a
    int b = *bp;           //var untuk value int b
    int temp;

    while(a>0){
        temp = a - ((a/10)*10);     //mengambil digit paling belakang int a
        a = a/10;               

        slist_pushBack(&listA, temp);   //meletakkan digit paling belakan int a ke linked list
    }

    while(b>0){
        temp = b - ((b/10)*10);      //mengambil digit paling belakang int a
        b = b/10;                    

        slist_pushBack(&listB, temp);  //meletakkan digit paling belakan int b ke linked list
    }

    SinglyList sum;               // buat linked list untuk sum
    slist_init(&sum);
    
    // penjumlahan tiap digit
    int keep = 0, result;
    for(int i=0;i<listA._size || i<listB._size;i++){
        temp = slist_getAt(&listA, i) + slist_getAt(&listB, i) + keep;
        if(temp > 19){
            result = temp - 20;
            slist_pushBack(&sum, result);
            keep = 2;
        } else if(temp>9){
            result = temp - 10;
            slist_pushBack(&sum, result);
            keep = 1;
        } else {
            result = temp;
            slist_pushBack(&sum, result);
            keep = 0;
        }
    }
    if(keep != 0) slist_pushBack(&sum, keep);
    

    
    return sum;
}