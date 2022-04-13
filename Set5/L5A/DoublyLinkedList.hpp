#include "DoublyNode.hpp"
#include <iostream>
using namespace std;
/* CSCI 261: L4A: Lab 4F - A Templated Linked List
 *
 * Author: Garrett Thompson
 *
 * Implementation of the Linked List Class but now able to funciton with any data type
 * 
 */
/**
 * @brief DoublyLinkedList object
 * 
 */
template<typename T>
class DoublyLinkedList {
  private:
    /**
     * @brief The head of the DoublyLinkedList
     * 
     */
    DoublyNode<T>* mpHead;
    /**
     * @brief The tail of the DoublyLinkedList
     * 
     */
    DoublyNode<T>* mpTail;
    /**
     * @brief The size of the DoublyLinkedList
     * 
     */
    int mSize;
  public:
    /**
     * @brief A method to get the size of the linked list
     * 
     * 
     */
    int size() const;
    /**
     * @brief The constructor of the class object
     * 
     * 
     */
    DoublyLinkedList();
    /**
     * @brief The copy constructor of the class
     * 
     * @param OTHER linked list object to copy to a new one
     * 
     */
    DoublyLinkedList(const DoublyLinkedList& OTHER);
    /**
     * @brief The copy operator of the class
     * 
     * @param OTHER linked list object to copy to a new one
     * 
     */
    DoublyLinkedList& operator=(const DoublyLinkedList& OTHER);
    /**
     * @brief The destructor of the class object
     * 
     * 
     */
    ~DoublyLinkedList();
    /**
     * @brief Returns the value at the given position
     * 
     * @param POS determines what position to get the value at
     * 
     */
    T get(const int POS) const;
    /**
     * @brief Set's the value at the given position
     * 
     * @param POS determines what position to get the value at
     * @param VAL determines the value we set at the position
     * 
     */
    void set(const int POS, const T VAL);
    /**
     * @brief Inserts the value at the specified position
     * 
     * @param POS determines what position to get the value at
     * @param VAL determines the value we set at the position
     * 
     */
    void insert(const int POS, const T VAL);
    /**
     * @brief Removes the value at the specified position
     * 
     * @param POS determines what position to get the value at
     * 
     */
    void remove(const int POS);
    /**
     * @brief Prints the entire linked list(not needed just a nice thing for testing)
     * 
     * 
     */
    void print() const;
    /**
     * @brief Prints the entire linked list in reverse(not needed just a nice thing for testing)
     * 
     * 
     */
    void printReverse() const;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
  // Default constructor for the first node in the list
    mpHead = nullptr;
    mpTail = nullptr;
    mSize = 0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& OTHER){
  // Performing a deep copy of the object passed to the copy constructor
  mSize = OTHER.mSize;
  DoublyNode<T>* pCurrent;
  DoublyNode<T>* pNext;
  // Checking if the head is nullptr
  if(OTHER.mpHead == nullptr){
    mpHead = nullptr;
  }
  else{
    // Creating the tail and head to store the current values and copy them over
    mpHead = new DoublyNode<T>;
    mpTail = new DoublyNode<T>;
    mpHead->pNext = OTHER.mpHead->pNext;
    mpHead->value = OTHER.mpHead->value;
    mpHead->pPrev = OTHER.mpHead->pPrev;
    mpTail->pNext = OTHER.mpTail->pNext;
    mpTail->value = OTHER.mpTail->value;
    mpTail->pPrev = OTHER.mpTail->pPrev;
    pCurrent = mpHead;
    pNext = mpHead->pNext;
  }
  while(pNext->pNext != nullptr){
    // Performing a copy of the entire linked list
    pCurrent->pNext = new DoublyNode<T>;
    pCurrent = pCurrent->pNext;
    pCurrent->pNext = pNext->pNext;
    pCurrent->value = pNext->value;
    pCurrent->pPrev = pNext->pPrev;
    pNext = pNext->pNext;
  }
  pCurrent->pNext = nullptr;
  pCurrent->pPrev = pNext->pPrev;
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& OTHER){
  // Overloading the equality operator to perform a deep copy
  // Same process as above essentially
  if(this == &OTHER)
    return *this;
  this->mSize = OTHER.mSize;
  DoublyNode<T>* pCurrent;
  DoublyNode<T>* pNext;
  if(OTHER.mpHead == nullptr){
    this->mpHead = nullptr;
  }
  else{
    this->mpHead = new DoublyNode<T>;
    this->mpTail = new DoublyNode<T>;
    this->mpHead->pNext = OTHER.mpHead->pNext;
    this->mpHead->value = OTHER.mpHead->value;
    this->mpHead->pPrev = OTHER.mpHead->pPrev;
    this->mpTail->pNext = OTHER.mpTail->pNext;
    this->mpTail->value = OTHER.mpTail->value;
    this->mpTail->pPrev = OTHER.mpTail->pPrev;
    pCurrent = this->mpHead;
    pNext = this->mpHead->pNext;
  }
  while(pNext->pNext != nullptr){
    pCurrent->pNext = new DoublyNode<T>;
    pCurrent = pCurrent->pNext;
    pCurrent->pNext = pNext->pNext;
    pCurrent->value = pNext->value;
    pCurrent->pPrev = pNext->pPrev;
    pNext = pNext->pNext;
  }
  pCurrent->pNext = nullptr;
  pCurrent->pPrev = pNext->pPrev;
  return *this;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  // Deleting all of the allocated memory from the linked list
    DoublyNode<T> *temp = mpHead, *next;
    while(temp != nullptr){
        next = temp->pNext;
        delete temp;
        temp = next;
    }
    delete mpHead;
    mpTail = nullptr;
    mpHead = nullptr;
    mSize = 0;
}


template<typename T>
T DoublyLinkedList<T>::get(const int POS) const {
  // Getting the current value at the position provided by iterating through the list
  DoublyNode<T> *currentNode = new DoublyNode<T>;
  currentNode = mpHead;
  int counter = 0;
  while(currentNode != nullptr){
    if(counter == POS){return currentNode->value;}
    currentNode = currentNode->pNext;
    counter++;
  }
  return T(-1);
}


template<typename T>
void DoublyLinkedList<T>::set(const int POS, const T VAL){
  // Setting the value at a specific position by iterating through and setting the current node's value
  DoublyNode<T> *currentNode = new DoublyNode<T>;
  currentNode = mpHead;
  int counter = 0;
  while(currentNode != nullptr){
    if(counter == POS){currentNode->value = VAL;}
    currentNode = currentNode->pNext;
    counter++;
  }
}


template<typename T>
void DoublyLinkedList<T>::insert(const int POS, const T VAL){
  DoublyNode<T> *newNode = new DoublyNode<T>;
  DoublyNode<T> *currentNode = new DoublyNode<T>;
  DoublyNode<T> *prevNode = new DoublyNode<T>;
  // Inserting a node anywhere into a list by flipping around pointers to point to the new node
  newNode->value = VAL;
  if(POS <= 0){
    if(mpHead == nullptr){
      newNode->pNext = nullptr;
      newNode->pPrev = nullptr;
      mpTail = newNode;
      mpHead = newNode;
    }
    else{
      newNode->pNext = mpHead;
      mpHead->pPrev = newNode;
      newNode->pPrev = nullptr;
      mpHead = newNode;
    }
  } else if(POS > mSize){
    newNode->pPrev = mpTail;
    newNode->pNext = nullptr;
    mpTail->pNext = newNode;
    mpTail = newNode;
  } else {
    int counter = 0;
    currentNode = mpHead;
    while(counter != POS){
      currentNode = currentNode->pNext;
      counter++; 
    }
    prevNode = currentNode->pPrev;
    newNode->pNext = currentNode;
    newNode->pPrev = prevNode;
    prevNode->pNext = newNode;
    currentNode->pPrev = newNode;
  }
  mSize++;
}


template<typename T>
void DoublyLinkedList<T>::remove(const int POS){
  // Removing a node form anywhere in the list by flipping around pointers and removing it from the link and deleting it
  DoublyNode<T> *newNode = new DoublyNode<T>;
  DoublyNode<T> *currentNode = new DoublyNode<T>;
  if(POS < 0){
    newNode = mpHead->pNext;
    newNode->pPrev = nullptr;
    delete mpHead;
    mpHead = newNode;
  } else if(POS > mSize){
    newNode = mpTail->pPrev;
    newNode->pNext = nullptr;
    delete mpTail;
    mpTail = newNode;
  } else {
    int counter = 0;
    currentNode = mpHead;
    while(counter != POS){
      currentNode = currentNode->pNext;
      counter++; 
    }
    newNode = currentNode->pPrev;
    newNode->pNext = currentNode->pNext;
  }
  mSize--;
}


template<typename T>
int DoublyLinkedList<T>::size() const{
  // Returns size
  return mSize;
}


template<typename T>
void DoublyLinkedList<T>::print() const {
  // Prints out the list so I don't have to write code for it everytime
  DoublyNode<T> *currentDoublyNode = new DoublyNode<T>;
  currentDoublyNode = mpHead;

  while (currentDoublyNode != nullptr){
	  cout << currentDoublyNode->value << " ";
    currentDoublyNode = currentDoublyNode->pNext;
  }
  cout << endl;
}


template<typename T>
void DoublyLinkedList<T>::printReverse() const{
  // Prints out the list in reverse so I don't have to
  DoublyNode<T> *currentDoublyNode = new DoublyNode<T>;
  currentDoublyNode = mpTail;

  while (currentDoublyNode != nullptr){
	  cout << currentDoublyNode->value << " ";
    currentDoublyNode = currentDoublyNode->pPrev;
  }
  cout << endl;
}
