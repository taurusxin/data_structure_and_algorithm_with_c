#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct LinkedNode {
    E element;
    struct LinkedNode * next;
};

typedef struct LinkedNode * Node;

struct Queue {
    Node front, rear;
};

typedef struct Queue * LinkedQueue;

bool initQueue(LinkedQueue queue) {
    Node node = malloc(sizeof(struct LinkedNode));
    if (node == NULL) return false;
    queue->rear = queue->front = node;
    return true;
}

bool offerQueue(LinkedQueue queue, E element) {
    Node node = malloc(sizeof(struct LinkedNode));
    if (node == NULL) return false;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return true;
}

bool isEmpty(LinkedQueue queue) {
    return queue->front == queue->rear;
}

E poolQueue(LinkedQueue queue) {
    Node temp = queue->front->next;
    E e = temp->element;
    queue->front->next = queue->front->next->next;
    if (queue->rear == temp) queue->rear = queue->front;
    free(temp);
    return e;
}

void printQueue(LinkedQueue queue) {
    printf("<<< ");
    Node node = queue->front->next;
    while (node) {
        printf("%d ", node->element);
        node = node->next;
    }
    printf("<<<\n");

}

int main() {
    struct Queue queue;
    initQueue(&queue);

    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue, i * 100);
    }

    printQueue(&queue);

    while (!isEmpty(&queue)) {
        printf("%d ", poolQueue(&queue));
    }
}