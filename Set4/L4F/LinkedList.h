#include "Node.hpp"
class LinkedList {
  private:
    Node* mpHead;
    Node* mpTail;
    unsigned int mSize;
    Node* makeNodeForValue(const int VALUE);
  public:
    void print(LinkedList& OTHER) const;
    int at(const int POS) const;
    int Front() const;
    int Back() const;
    unsigned int size() const;
    void pushFront(const int VALUE);
    void pushBack(const int VALUE);
    int popFront();
    LinkedList();
    LinkedList(const LinkedList& OTHER);
    LinkedList& operator=(const LinkedList& OTHER);
    ~LinkedList();
};