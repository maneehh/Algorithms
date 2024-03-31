#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *collection;
    bool empty;
} Stack;

Stack *create_stack();
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool top(Stack *stack, int *item);

int main(void) {
    Stack *stack = create_stack();
    if (stack == NULL) {
        printf("Error\n");
        return 1;
    }

    push(stack, 5);
    int top_val;
    if (top(stack, &top_val)) {
        printf("Top element: %d\n", top_val);
    } else {
        printf("Empty.\n");
    }

    pop(stack, &top_val);
    printf("Popped element: %d\n", top_val);

    if (top(stack, &top_val)) {
        printf("Top element: %d\n", top_val);
    } else {
        printf("Stack is empty.\n");
    }

    free(stack);

    return 0;
}

Stack *create_stack() {
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) return NULL;
    stack->collection = NULL;
    stack->empty = true;
    return stack;
}

bool push(Stack *stack, int item) {
    if (!stack->empty) return false;
    stack->collection = malloc(sizeof(int));
    if (stack->collection == NULL) return false;
    *(stack->collection) = item;
    stack->empty = false;
    return true;
}

bool top(Stack *stack, int *item) {
    if (stack->empty) return false;
    *item = *(stack->collection);
    return true;
}

bool pop(Stack *stack, int *item) {
    if (stack->empty) return false;
    *item = *(stack->collection);
    free(stack->collection);
    stack->empty = true;
    return true;
}
