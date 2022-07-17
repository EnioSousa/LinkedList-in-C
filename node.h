#ifndef NODE
#define NODE

#include <stdlib.h>

/**
 * @brief Structure holds info about a node
 * 
 */
typedef struct Node {
    void* value; // The value contained in the node
    struct Node* next; // The next node
    struct Node* prev; // The previous node
}Node;

/**
 * @brief Creates a new node with a memory address
 * 
 * @param value Memory address of the object to save
 * @return Node* Address for a new node
 */
Node* newNode(void* value);

/**
 * @brief Free the memory allocated for the node and for the object
 * contained in the node
 * 
 * @param node The node the delete
 * @param freeFunc Function to free the object contained in the node
 */
void delNode(Node* node, void (*freeFunc)(void*));

/**
 * @brief Delete the node without deleting the value contained.
 * Careful with this function, don't forget to free the value, or 
 * else a memory leak will happen
 * 
 * @param node The node to delete
 * @return void* The address of the object contained in the node
 */
void* simpleDelNode(Node *node);

/**
 * @brief Get the Next Node object
 *
 * @param node The current Node object
 * @return Node* The next node
 */
Node* getNextNode(Node* node);

/**
 * @brief Get the Prev Node object
 *
 * @param node The current Node object
 * @return Node* The prev node
 */
Node* getPrevNode(Node* node);

/**
 * @brief Get the address of the Value/object contained in the node
 *
 * @param node The current node
 * @return void* The address of the value/object
 */
void* getValue(Node* node);

/**
 * @brief Set the Next object
 * 
 * @param node The current Node
 * @param next The next node
 */
void setNextNode(Node* node, Node* next);

/**
 * @brief Set the Prev object
 * 
 * @param node The current node
 * @param prev The previous node
 */
void setPrevNode(Node* node, Node* prev);

/**
 * @brief Prints the content of a node
 * 
 * @param node The to print
 * @param printFunc The print function that know how to print the value
 */
void printNode(Node *node, void (*printFunc)(void *));

#endif