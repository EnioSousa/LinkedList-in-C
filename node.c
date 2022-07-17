#include "node.h"

Node* newNode(void* value) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->value = value;

    return node;
}

void delNode(Node* node, void (*freeFunc)(void*)) {
    if (freeFunc != NULL && getValue(node) != NULL) {
        freeFunc(getValue(node));
    }

    free(node);
}

void* simpleDelNode(Node* node) {
    void* obj = NULL;

    if (node != NULL) {
        obj = getValue(node);
    }

    free(node);

    return obj;
}

Node* getPrevNode(Node* node) {
    return node == NULL ? NULL : node->prev;
}

Node* getNextNode(Node* node) {
    return node == NULL ? NULL : node->prev;
}

void* getValue(Node* node) {
    return node == NULL ? NULL : node->value;
}

void setNextNode(Node* node, Node* next) {
    if (node != NULL) {
        node->next = next;
    }
}

void setPrevNode(Node* node, Node* prev) {
    if (node != NULL) {
        node->prev = prev;
    }
}

void printNode(Node *node, void (*printFunc)(void*)) {
    printFunc(getValue(node));
}