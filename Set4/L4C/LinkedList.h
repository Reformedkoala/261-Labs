#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
/* CSCI 261: L4C: The Class Shell
 *
 * Author: Garrett Thompson
 *
 * Making a shell to later implement a class for our Linked List and Node
 *
 */
class LinkedList {
public:
    Node* pHead;
    Node* pTail;
    unsigned int size;
    Node* makeNodeForValue(int value);
    void pushFront(int value);
    void pushBack(int value);
    int popFront();

}

#endif
