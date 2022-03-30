#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
/* CSCI 261: L4D: Construct/Destruct a List
 *
 * Author: Garrett Thompson
 *
 * Refactoring our linked list class to fit public and private denotions as well as implementing the big three.
 *
 */
/**
 * @brief LinkedList object
 * 
 */
class LinkedList {
public:
    /**
     * @brief The head of the linkedlist
     * 
     */
    Node* pHead;
    /**
     * @brief The tail of the linkedlist
     * 
     */
    Node* pTail;
    /**
     * @brief The size of the linkedlist
     * 
     */
    unsigned int size;
    /**
     * @brief A method to make a node for the linked list
     * 
     * @param value what to store in the node you make
     * 
     */
    Node* makeNodeForValue(int value);
    /**
     * @brief A method to push a node to the front of the linked list
     * 
     * @param value what to store in the node you make
     * 
     */
    void pushFront(int value);
    /**
     * @brief A method to push a node to the back of the linked list
     * 
     * @param value what to store in the node you make
     * 
     */
    void pushBack(int value);
    /**
     * @brief A method to pop a node from the front of the list and return the value
     * 
     * 
     */
    int popFront();

}

#endif
