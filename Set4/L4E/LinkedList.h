#include "Node.h"
class LinkedList {
  private:
    Node* mpHead;
    Node* mpTail;
    unsigned int mSize;
    Node* makeNodeForValue(int value);
  public:
    void print(LinkedList& OTHER);
    int at(const int POS);
    int Front();
    int Back();
    unsigned int size();
    void pushFront(int value);
    void pushBack(int value);
    int popFront();
    LinkedList();
    LinkedList(const LinkedList& OTHER);
    LinkedList& operator=(const LinkedList& OTHER);
    ~LinkedList();
};