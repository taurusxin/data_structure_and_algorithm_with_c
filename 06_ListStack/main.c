#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListStackNode {
    E element;
    struct ListStackNode* next;
};

typedef struct ListStackNode * Node;

void initStack(Node head) {
    head->next = NULL;
}

_Bool pushStack(Node head, E element) {
    Node node = malloc(sizeof(struct ListStackNode));
    if (node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

_Bool isEmpty(Node head) {
    return head->next == NULL;
}

E popStack(Node head) {
    Node temp = head->next;
    E e = temp->element;
    head->next = head->next->next;
    free(temp);
    return e;
}

void printStack(Node head) {
    head = head->next;
    while (head) {
        printf("%d, ", head->element);
        head = head->next;
    }
    printf("|\n");
}

int main() {
    struct ListStackNode head;
    initStack(&head);

    for (int i = 0; i < 3; ++i) {
        pushStack(&head, i * 100);
    }

    printStack(&head);

    while (!isEmpty(&head)) {
        printf("%d\n", popStack(&head));
    }
}