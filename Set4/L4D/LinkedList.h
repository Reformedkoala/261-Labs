#include "Node.h"
/* CSCI 261: L4D: Construct/Destruct a List
 *
 * Author: Garrett Thompson
 *
 * Refactoring our linked list class to fit public and private denotions as well as implementing the big three.
 *
 */
class LinkedList {
  private:
    Node* mpHead;
    Node* mpTail;
    unsigned int mSize;
    Node* makeNodeForValue(int value);
  public:
    int Front();
    int Back();
    unsigned int size();
    void pushFront(int value);
    void pushBack(int value);
    int popFront();
    LinkedList();
    ~LinkedList();
};
