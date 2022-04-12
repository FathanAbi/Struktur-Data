#include <stdio.h>
#include <Stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node, *NodePtr;

NodePtr Add(int*, int*);
NodePtr makeNode();
void printList(NodePtr);

int main()
{
    int a, b;
    int* aptr = &a;
    int* bptr = &b;
    scanf("%d %d", &a, &b);

    NodePtr sum = Add(aptr, bptr);

    printList(sum);



}

NodePtr Add(int* ap, int* bp)
{
    NodePtr topA = NULL;
    NodePtr last;
    NodePtr topB = NULL;
    NodePtr np;

    int a = *ap;
    int b = *bp;
    int temp;
    
    printf("a = %d\n", a);
    while(a > 0){
        temp = a - ((a/10)*10);
        a = a/10;

        np = (NodePtr)malloc(sizeof(Node));
        np->data = temp;
        np->next = NULL;

        if(topA == NULL){
            topA = np;
        } else {
            last->next = np;
            last = np;
        }

    }

    

    return topA;

}

void printList(NodePtr top)
{ 
    NodePtr temp = top;
    while(temp->next != NULL){
        printf("%d", temp->data);
    }
}