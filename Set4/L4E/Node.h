#ifndef NODE_H
#define NODE_H

/* CSCI 261: L4A: Lab 4E - A Linked List Class Part III: Test, Copy, Print
 *
 * Author: Garrett Thompson
 *
 * Implementation of each class operation
 * 
 * 
 */

/**
 * @brief A single element of a linked list
 * 
 */
struct Node {
    /**
     * @brief the value of this Node
     * 
     */
    int value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    Node *pNext;
};

#endif