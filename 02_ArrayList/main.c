#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct List {
    E* array;
    int capacity;
    int size;
};

typedef struct List* ArrayList;

_Bool initList(ArrayList list) {
    list->capacity = 10;
    list->array = malloc(sizeof(E) * list->capacity);
    if (list->array == NULL) return 0;
    list->size = 0;
    return 1;
}

_Bool insertList(ArrayList list, E element, int index) {
    if (index < 1 || index > list->size + 1) return 0;

    if (list->size == list->capacity) {
        int newCapacity = list->capacity + (list->capacity >> 1);
        E* newArray = realloc(list->array, newCapacity * sizeof(E));
        if (newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }

    for (int i = list->size; i > index - 1; --i)
        list->array[i] = list->array[i - 1];
    list->array[index - 1] = element;
    list->size++;
    return 1;
}

_Bool deleteList(ArrayList list, int index) {
    if (index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];
    list->size--;
    return 1;
}

int sizeList(ArrayList list) {
    return list->size;
}

E* getList(ArrayList list, int index) {
    if (index < 1 || index > list->size) return NULL;
    return &list->array[index - 1];
}

int findList(ArrayList list, E element) {
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) return i + 1;
    }
    return -1;
}

void printList(ArrayList list) {
    for (int i = 0; i < list->size; ++i)
        printf("%d ", list->array[i]);
    printf("\n");
}

int main() {
    struct List list;
    if (initList(&list)) {
        for (int i = 0; i < 30; ++i)
            insertList(&list, i * 5, i + 1);
        printList(&list);
        deleteList(&list, 10);
        deleteList(&list, 10);
        printList(&list);
        printf("%d\n", *getList(&list, 7));
        printf("%d\n", findList(&list, 30));
    } else {
        printf("Initialize LinearTable failed!");
    }
}