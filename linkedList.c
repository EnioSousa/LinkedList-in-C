#include "linkedList.h"

List* newList() {
    List* list = (List*)malloc(sizeof(List));

    list->first = newNode(NULL);
    list->last = newNode(NULL);

    setNextNode(list->first, list->last);
    setPrevNode(list->last, list->first);

    list->size = 0;

    return list;
}

void delList(List* list, void (*freeFunc)(void*)) {
    while (getFirstNode(list) != NULL) {
        delNode(getFirstNode(list), freeFunc);
    }

    delNode(list->first, NULL);
    delNode(list->last, NULL);

    free(list);
}

void* getFirst(List* list) {
    return getValue(getFirstNode(list));
}
void* getLast(List* list) {
    return getValue(getLastNode(list));
}

Node* getFirstNode(List* list) {
    if (list->first->next == list->last) {
        return NULL;
    }
    else {
        return list->first->next;
    }
}
Node* getLastNode(List* list) {
    if (list->last->prev == list->first) {
        return NULL;
    }
    else {
        return list->last->prev;
    }
}

void addFirst(List* list, void* value) {
    Node* node = newNode(value);

    setPrevNode(node, list->first);
    setNextNode(node, list->first->next);

    setNextNode(node->prev, node);
    setPrevNode(node->next, node);

    list->size++;
}

void addLast(List* list, void* value) {
    Node* node = newNode(value);

    setPrevNode(node, list->last->prev);
    setNextNode(node, list->last);

    setNextNode(node->prev, node);
    setPrevNode(node->next, node);

    list->size++;
}
void push(List* list, void* value) {
    addFirst(list, value);
}

void delFirst(List* list, void (*freeFunc)(void *)) {
    if (list->size) {
        Node* node = list->first->next;

        setNextNode(node->prev, node->next);
        setPrevNode(node->next, node->prev);

        list->size--;

        delNode(node, freeFunc);
    }
}

void delLast(List* list, void (*freeFunc)(void *)) {
    if (list->size) {
        Node* node = list->last->prev;

        setNextNode(node->prev, node->next);
        setPrevNode(node->next, node->prev);

        list->size--;

        delNode(node, freeFunc);
    }
}

void pop(List* list, void (*freeFunc)(void *)) {
    delFirst(list, freeFunc);
}

void printList(List* list, void (*printFunc)(void*)) {
    if ( list->size == 0 ) {
        printf("List is empty\n");
        return;
    }

    int index = 0;

    printf("List size: %d\n", list->size);

    for (Node* node = list->first->next; node != list->last; node = node->next) {
        printf("\nIndex: %d\n", index++);

        printNode(node, printFunc);
    }
}