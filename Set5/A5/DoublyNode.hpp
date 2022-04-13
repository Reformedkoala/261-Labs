#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H
/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Garrett Thompson
 * 
 *  Doubly Node implementation not really any different then any other node
 * 
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
    /**
     * @brief pointer to the previous element of the linked list
     * 
     */
    DoublyNode<T> *pPrev;
};

#endif