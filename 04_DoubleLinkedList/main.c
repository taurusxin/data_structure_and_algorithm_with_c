#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode* next;
    struct ListNode* prev;
};

typedef struct ListNode* Node;

void initList(Node node) {
    node->next = node->prev = NULL;
}

_Bool insertList(Node head, E element, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }

    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->element = element;

    if (head->next) {  // 只有新节点不在最后才执行
        node->next = head->next;
        head->next->prev = node;
    } else {
        node->next = NULL;
    }

    head->next = node;
    node->prev = head;

    return 1;
}

_Bool deleteList(Node head, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    if (head->next == NULL) return 0;

    Node tmp = head->next;
    if (head->next->next) {
        head->next->next->prev = head;
        head->next = head->next->next;
    } else {
        head->next = NULL;
    }
    free(tmp);

    return 1;
}

E* getList(Node head, int index) {
    if (index < 1) return 0;
    do {
        head = head->next;
        if (head == NULL) return NULL;
    } while (--index);
    return &head->element;
}

void printList(Node head) {
    while (head->next) {
        head = head->next;
        printf("%d ", head->element);
    }
    printf("\n");
}

int findList(Node head, E element) {
    int i = 1;
    head = head->next; // 先从第一个节点开始
    while (head) {
        if (head->element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}

int sizeList(Node head) {
    int i = -1;
    while (head->next) {
        head = head->next;
        i++;
    }
    return i;
}

int main() {
    struct ListNode head;
    initList(&head);

    for (int i = 1; i <= 5; ++i) {
        insertList(&head, i * 100, i);
    }

    printList(&head);

    printf("%d\n", findList(&head, 200));

    deleteList(&head, 5);

    printList(&head);

    return 0;
}
