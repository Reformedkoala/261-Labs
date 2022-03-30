#include "Node.h"
/* CSCI 261: L4D: Construct/Destruct a List
 *
 * Author: Garrett Thompson
 *
 * Refactoring our linked list class to fit public and private denotions as well as implementing the big three.
 *
 */
/**
 * @brief LinkedList object
 * 
 */
class LinkedList {
  private:
    /**
     * @brief The head of the linkedlist
     * 
     */
    Node* mpHead;
    /**
     * @brief The tail of the linkedlist
     * 
     */
    Node* mpTail;
    /**
     * @brief The size of the linkedlist
     * 
     */
    unsigned int mSize;
    /**
     * @brief A method to make a node for the linked list
     * 
     * @param value what to store in the node you make
     * 
     */
    Node* makeNodeForValue(int value);
  public:
    /**
     * @brief A method to get the front of the linked list or head
     * 
     * 
     */
    int Front();
    /**
     * @brief A method to get the back of the linked list or tail
     * 
     * 
     */
    int Back();
    /**
     * @brief A method to get the size of the linked list
     * 
     * 
     */
    unsigned int size();
    /**
     * @brief A method to push a node to the front of the linked list
     * 
     * @param value what to store in the node you make
     * 
     */
    void pushFront(int value);
    /**
     * @brief A method to push a node to the back of the linked list
     * 
     * @param value what to store in the node you make
     * 
     */
    void pushBack(int value);
    /**
     * @brief A method to pop a node from the front of the list and return the value
     * 
     * 
     */
    int popFront();
    /**
     * @brief The constructor of the class object
     * 
     * 
     */
    LinkedList();
    /**
     * @brief The destructor of the class object
     * 
     * 
     */
    ~LinkedList();
};
