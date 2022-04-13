#ifndef NODE_H
#define NODE_H
/* CSCI 261: L5D: Sorting II & Recursion II: Merge Sort via the Call Stack
 *
 * Author: Garrett Thompson
 *
 * Node for the linked list
 * 
 */
/**
 * @brief A single element of a linked list
 * 
 */
template<typename T>
struct Node {
    /**
     * @brief the value of this Node
     * 
     */
    T value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    Node *pNext;
};

#endif