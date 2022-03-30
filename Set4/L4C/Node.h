#ifndef NODE_H
#define NODE_H
/* CSCI 261: L4C: The Class Shell
 *
 * Author: Garrett Thompson
 *
 * Making a shell to later implement a class for our Linked List and Node
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
