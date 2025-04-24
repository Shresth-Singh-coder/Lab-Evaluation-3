//write a program to convert numbers from 1 to n into bnary numbers with the help of the queue.

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear;
    int size;
    char** arr;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->arr = (char**)malloc(sizeof(char*) * size);
    return queue;
}

int isFull(struct Queue* queue) {
    return queue->rear == queue->size - 1;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, char* value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = value;
}

char* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    char* value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

void generateBinaryNumbers(int n) {
    struct Queue* queue = createQueue(n);
    enqueue(queue, "1");
    for (int i = 1; i <= n; i++) {
        char* binary = dequeue(queue);
        printf("%s\n", binary);
        char* left = (char*)malloc(sizeof(char) * (strlen(binary) + 2));
        char* right = (char*)malloc(sizeof(char) * (strlen(binary) + 2))
        strcpy(left, binary);
        strcat(left, "0");
        strcpy(right, binary);
        strcat(right, "1");
        enqueue(queue, left);
        enqueue(queue, right);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Binary numbers from 1 to %d are:\n", n);
    generateBinaryNumbers(n);
    return 0;
}
