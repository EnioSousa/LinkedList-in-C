#ifndef LINKEDLIST
#define LINKEDLIST

#include "node.h"
#include <stdio.h>

typedef struct List {
    Node* first;
    Node* last;
    int size;
} List;

/**
 * @brief Creates a new list
 * 
 * @return List* The address to a new list
 */
List* newList();

/**
 * @brief Deletes the list, including all the values contained
 * 
 * @param list The list to delete
 * @param freeFunc The function that know how to delete the values
 */
void delList(List *list, void (*freeFunc)(void*));

/**
 * @brief Get the Fist object
 * 
 * @param list The list
 * @return void* The first value
 */
void* getFist(List* list);

/**
 * @brief Get the Last object
 * 
 * @param list The list
 * @return void* The last element
 */
void* getLast(List* list);

/**
 * @brief Get the First Node object
 * 
 * @param list The list
 * @return Node* The first node
 */
Node* getFirstNode(List* list);

/**
 * @brief Get the Last Node object
 * 
 * @param list The list 
 * @return Node* The last node
 */
Node* getLastNode(List* list);

/**
 * @brief Adds a value to the front of the list
 * 
 * @param list The list
 * @param value The address of the value to add
 */
void addFirst(List* list, void* value);

/**
 * @brief Add a value to the end of the lsit
 * 
 * @param list The list
 * @param value The address of the value to add
 */
void addLast(List* list, void* value);

/**
 * @brief Add value to the front of the list
 * 
 * @param list The list
 * @param value The value to add
 */
void push(List* list, void* value);

/**
 * @brief Get the First object
 * 
 * @param list the list
 * @return void* the address of the object if it exist
 */
void* getFirst(List *list);

/**
 * @brief Get the Last object
 * 
 * @param list the list
 * @return void* the address of the object if it exist
 */
void* getLast(List *list);

/**
 * @brief Remove the first node and removes the value contained
 * 
 * @param list The list
 * @param freeFunc The function that knows how to delete the object
 */
void delFirst(List* list, void (*freeFunc)(void *));

/**
 * @brief Remove the last node and removes the value contained
 * 
 * @param list The list
 * @param freeFunc The function that knows how to delete the object
 */
void delLast(List *list, void (*freeFunc)(void *));

/**
 * @brief Remove the first node and removes the value contained
 * 
 * @param list The list
 * @param freeFunc The function that knows how to delete the object
 */
void pop(List* list, void (*freeFunc)(void *));

/**
 * @brief Print the list
 * 
 * @param list The list to print
 * @param printFunc The print function that know how to print the value 
 */
void printList(List *list, void (*printFunc)(void*));

#endif