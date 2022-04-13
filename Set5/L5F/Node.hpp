#ifndef NODE_H
#define NODE_H
/* CSCI 261: Lab 5F - A Needle in the Haystack
 *
 * Author: Garrett Thompson
 *
 * LinkedList file for Lab 5F in which we assign random values to a linked list, sort it, then perform a binary search based on user specified values
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