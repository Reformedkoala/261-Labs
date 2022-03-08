#include "Node.h"
class LinkedList {
private:
    Node* mpHead;
    Node* mpTail;
    unsigned int msize;
    Node* makeNodeForValue(int value);
public:
    int Front();
    int Back();
    unsigned int mize();
    void pushFront(int value);
    void pushBack(int value);
    int popFront();
    LinkedList();
    ~LinkedList();
}