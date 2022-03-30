#include "Node.h"

/* CSCI 261: L4A: Lab 4E - A Linked List Class Part III: Test, Copy, Print
 *
 * Author: Garrett Thompson
 *
 * Implementation of each class operation
 * 
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
     * @brief A method to print out the entire list for ease of use and debugging
     * 
     * @param OTHER The linked list object to print
     */
    void print(LinkedList& OTHER);
    /**
     * @brief A method to get the value at a certain position
     * 
     * @param POS the position to get the value at
     */
    int at(const int POS);
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
     * @brief The copy constructor of the class
     * 
     * @param OTHER linked list object to copy to a new one
     * 
     */
    LinkedList(const LinkedList& OTHER);
    /**
     * @brief The copy operator of the class
     * 
     * @param OTHER linked list object to copy to a new one
     * 
     */
    LinkedList& operator=(const LinkedList& OTHER);
    /**
     * @brief The destructor of the class object
     * 
     * 
     */
    ~LinkedList();
};