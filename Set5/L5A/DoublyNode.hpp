#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H
/* CSCI 261: L4A: Lab 4F - A Templated Linked List
 *
 * Author: Garrett Thompson
 *
 * Implementation of the Linked List Class but now able to funciton with any data type
 * 
 */

/**
 * @brief A single element of a linked list
 * 
 */
template<typename T>
struct DoublyNode {
    /**
     * @brief the value of this Node
     * 
     */
    T value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    DoublyNode<T> *pNext;
    DoublyNode<T> *pPrev;
};

#endif