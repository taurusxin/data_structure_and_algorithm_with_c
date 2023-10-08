#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Stack {
    E * array;
    int capacity;
    int top;
};

typedef struct Stack * ArrayStack;

_Bool initStack(ArrayStack stack) {
    stack->array = malloc(sizeof(E) * 10);
    if (stack->array == NULL) return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}

_Bool pushStack(ArrayStack stack, E element) {
    if (stack->top + 1 == stack->capacity) {  // The stack is full
        int newCapacity = stack->capacity + (stack->capacity >> 1);  // Expand the stack
        E * newArray = realloc(stack->array, newCapacity * sizeof(E));  // Reallocate the memory
        if (newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }

    stack->array[++stack->top] = element;
    return 1;
}

_Bool isEmpty(ArrayStack stack) {
    return stack->top == -1;
}

E popStack(ArrayStack stack) {
    return stack->array[stack->top--];
}

void printStack(ArrayStack stack) {
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; i < 30; ++i) {
        pushStack(&stack, i * 100);
    }

    printStack(&stack);

    while (!isEmpty(&stack)) {
        printf("%d, ", popStack(&stack));
    }
}
