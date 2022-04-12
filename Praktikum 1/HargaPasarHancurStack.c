#include <stdio.h>
#include <stdlib.h>

/* Struktur ADT StackArray */

typedef struct stackarr_t {
    int *_element, _topIndex;
    unsigned int _size, _capacity;
} StackArray;

/* Function prototype */

void stackArray_init(StackArray *stack, unsigned stackSize);
int stackArray_isEmpty(StackArray *stack);
void stackArray_push(StackArray *stack, int value);
void stackArray_pop(StackArray *stack);
int  stackArray_top(StackArray *stack);

/* Function definition below */

void stackArray_init(StackArray *stack, unsigned int stackSize) 
{
    stack->_element  = (int*) malloc(sizeof(int) * stackSize);
    stack->_size     = 0;
    stack->_topIndex = -1;
    stack->_capacity = stackSize;
}

int stackArray_isEmpty(StackArray *stack) {
    return (stack->_topIndex == -1);
}

void stackArray_push(StackArray *stack, int value)
{
    if (stack->_size + 1 <= stack->_capacity) {
        stack->_element[++stack->_topIndex] = value;
        stack->_size++;
    }
}

void stackArray_pop(StackArray *stack)
{
    if (!stackArray_isEmpty(stack)) {
        stack->_topIndex--;
        stack->_size--;
    }
}

int stackArray_top(StackArray *stack)
{
    if (!stackArray_isEmpty(stack)) {
        return stack->_element[stack->_topIndex];
    }
    return 0;
}


int main(){
    int t, n, a, i, j, low, h;
    scanf("%d", &t);

    for(i=0;i<t;i++){
        scanf("%d", &n);

        StackArray stack;
        stackArray_init(&stack, n);

        for(j=0;j<n;j++){
            scanf("%d", &a);
            stackArray_push(&stack, a);
        }

        low = stackArray_top(&stack);
        h = 0;

        while(stack._size >= 2){
            stackArray_pop(&stack);
            if(stackArray_top(&stack) < low) low = stackArray_top(&stack);
            else if (stackArray_top(&stack) > low) h++;

        }

        printf("%d\n", h);
    }
}