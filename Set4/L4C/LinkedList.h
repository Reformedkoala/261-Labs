#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
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