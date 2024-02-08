#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initialize(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        exit(1);
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        exit(1);
    }
    int removedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return removedItem;
}

// Function to peek at the front element of the queue
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->items[queue->front];
}

int main() {
    Queue queue;
    initialize(&queue);

    // Enqueue elements into the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Dequeue and print elements from the queue
    printf("Front element: %d\n", peek(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", peek(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}
