/**
 * @file stack.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/* Aim : To implement the stack functionality */
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

// Structure to represent the stack
typedef struct {
    int *array;     // Pointer to dynamic array to store elements
    int top;        // Index of the top element in the stack
    int capacity;   // Current capacity of the dynamic array
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (stack->array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = -1;  // Stack is initially empty
    stack->capacity = INITIAL_CAPACITY;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    // Check if the stack is full
    if (stack->top == stack->capacity - 1) {
        // If full, resize the array
        stack->capacity *= 2;
        stack->array = (int*)realloc(stack->array, stack->capacity * sizeof(int));
        if (stack->array == NULL) {
            printf("Memory reallocation failed\n");
            exit(1);
        }
    }
    // Increment top and add the new element
    stack->array[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->array[stack->top--];
}

// Function to peek at the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->array[stack->top];
}

// Function to cleanup memory allocated for the stack
void cleanup(Stack *stack) {
    free(stack->array);
}

int main() {
    Stack stack;
    initialize(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    // Print and remove elements from the stack
    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));

    cleanup(&stack);

    return 0;
}
