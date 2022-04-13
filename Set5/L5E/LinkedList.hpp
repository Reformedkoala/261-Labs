#include "Node.hpp"
#include <iostream>
using namespace std;

/* CSCI 261: Lab 5E - Procedural and Object-Oriented
 *
 * Author: Garrett Thompson
 *
 * Class implementation of the singular linked list in order to act as a container for our objects we create
 * 
 */
/**
 * @brief LinkedList object
 * 
 */
template<typename T>
class LinkedList {
  private:
    /**
     * @brief The head of the linkedlist
     * 
     */
    Node<T>* mpHead;
    /**
     * @brief The tail of the linkedlist
     * 
     */
    Node<T>* mpTail;
    /**
     * @brief The size of the linkedlist
     * 
     */
    unsigned int mSize;
    /**
     * @brief A method to make a node for the linked list
     * 
     * @param VALUE what to store in the node you make
     * 
     */
    Node<T>* makeNodeForValue(const T VALUE);
  public:
    /**
     * @brief A method to print out the entire list for ease of use and debugging
     * 
     * @param OTHER The linked list object to print
     */
    void print(LinkedList& OTHER) const;
    /**
     * @brief A method to get the value at a certain position
     * 
     * @param POS the position to get the value at
     */
    T at(const int POS) const;
    /**
     * @brief A method to get the front of the linked list or head
     * 
     * 
     */
    T Front() const;
    /**
     * @brief A method to get the back of the linked list or tail
     * 
     * 
     */
    T Back() const;
    /**
     * @brief A method to get the size of the linked list
     * 
     * 
     */
    unsigned int size() const;
    /**
     * @brief A method to push a node to the front of the linked list
     * 
     * @param value what to store in the node you make
     * 
     */
    void pushFront(const T VALUE);
    /**
     * @brief A method to push a node to the back of the linked list
     * 
     * @param value what to store in the node you make
     * 
     */
    void pushBack(const T VALUE);
    /**
     * @brief A method to pop a node from the front of the list and return the value
     * 
     * 
     */
    T popFront();
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
    /**
     * @brief Splits the given list on the left
     * 
     * @param pList Linked List object passed to the function to split
     * 
     */
    LinkedList<T> split_left(LinkedList<T> &pList);
    /**
     * @brief Splits the given list on the right
     * 
     * @param pList Linked List object passed to the function to split
     * 
     */
    LinkedList<T> split_right(LinkedList<T> &pList);
    /**
     * @brief Performed the merge sort recursion 
     * 
     * @param pList Linked List object passed to the function to sort recursively
     * 
     */
    void merge_sort(LinkedList<T> &pList, const int WAY);
};

template<typename T>
LinkedList<T>::LinkedList(){
    mpHead = nullptr;
    mpTail = nullptr;
    mSize = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& OTHER){
  mSize = OTHER.mSize;
  Node<T>* pCurrent;
  Node<T>* pNext;
  if(OTHER.mpHead == nullptr){
    mpHead = nullptr;
  }
  else{
    mpHead = new Node<T>;
    mpTail = new Node<T>;
    mpHead->pNext = OTHER.mpHead->pNext;
    mpHead->value = OTHER.mpHead->value;
    mpTail->pNext = OTHER.mpTail->pNext;
    mpTail->value = OTHER.mpTail->value;
    pCurrent = mpHead;
    pNext = mpHead->pNext;
  }
  while(pNext->pNext != nullptr){
    pCurrent->pNext = new Node<T>;
    pCurrent = pCurrent->pNext;
    pCurrent->pNext = pNext->pNext;
    pCurrent->value = pNext->value;
    pNext = pNext->pNext;
  }
  pCurrent->pNext = nullptr;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& OTHER){
  if(this == &OTHER)
    return *this;
  this->mSize = OTHER.mSize;
  Node<T>* pCurrent;
  Node<T>* pNext;
  if(OTHER.mpHead == nullptr){
    this->mpHead = nullptr;
  }
  else{
    this->mpHead = new Node<T>;
    this->mpTail = new Node<T>;
    this->mpHead->pNext = OTHER.mpHead->pNext;
    this->mpHead->value = OTHER.mpHead->value;
    this->mpTail->pNext = OTHER.mpTail->pNext;
    this->mpTail->value = OTHER.mpTail->value;
    pCurrent = this->mpHead;
    pNext = this->mpHead->pNext;
  }
  while(pNext->pNext != nullptr){
    pCurrent->pNext = new Node<T>;
    pCurrent = pCurrent->pNext;
    pCurrent->pNext = pNext->pNext;
    pCurrent->value = pNext->value;
    pNext = pNext->pNext;
  }
  pCurrent->pNext = nullptr;
  return *this;
}

template<typename T>
LinkedList<T>::~LinkedList(){
    Node<T> *temp = mpHead, *next;
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
Node<T>* LinkedList<T>::makeNodeForValue(const T VALUE){
  Node<T>* pCurrent = new Node<T>;
  pCurrent->value = VALUE;
  pCurrent->pNext = nullptr;
  return pCurrent;
} 

template<typename T>
void LinkedList<T>::pushFront(const T VALUE){
  Node<T>* newNode = new Node<T>;
  newNode->value = VALUE;
  if(mpHead == nullptr){
    newNode->pNext = nullptr;
    mpTail = newNode;
    mpHead = newNode;
  }
  else{
    newNode->pNext = mpHead;
    mpHead = newNode;
  }
  mSize+=1;
}

template<typename T>
void LinkedList<T>::pushBack(const T VALUE){
  Node<T> *newNode = new Node<T>;
  newNode->value = VALUE;
  if(mpHead == nullptr){
    newNode->pNext = nullptr;
    mpTail = newNode;
    mpHead = newNode;
  }
  else{
    newNode->pNext = nullptr;
    mpTail->pNext = newNode;
    mpTail = newNode;
  }
  mSize+=1;
} 

template<typename T>
T LinkedList<T>::popFront(){
  if(mSize <=0){
    return T();
  }
  T value = mpHead->value;
  Node<T> *delHead = new Node<T>;
  delHead = mpHead;
  mpHead = mpHead->pNext;
  delete delHead;
  mSize -= 1;
  return value;
}

template<typename T>
T LinkedList<T>::Front() const {
    if(mpHead == nullptr){return T();}
    else{return mpHead->value;}
}

template<typename T>
T LinkedList<T>::Back() const {
    if(mpHead == nullptr){return T();}
    else{return mpTail->value;}
} 

template<typename T>
unsigned int LinkedList<T>::size() const {
    return mSize;
} 

template<typename T>
T LinkedList<T>::at(const int POS) const {
  Node<T> *currentNode = new Node<T>;
  currentNode = mpHead;
  int counter = 0;
  while(currentNode != nullptr){
    if(counter == POS){return currentNode->value;}
    currentNode = currentNode->pNext;
    counter++;
  }
  return T();
}

template<typename T>
void LinkedList<T>::print(LinkedList& OTHER) const {
  Node<T> *currentNode = new Node<T>;
  currentNode = this->mpHead;

  while (currentNode != nullptr){
	  cout << currentNode->value << " ";
    currentNode = currentNode->pNext;
  }
  cout << endl;
}

template<typename T>
LinkedList<T> LinkedList<T>::split_left(LinkedList<T> &pList){
  LinkedList<T> pLeft;
  int n = pList.size();
  for(int i=0; i < n; i++){
    if(i < n/2){pLeft.pushBack(pList.popFront());}
  }
  return pLeft;
} 


template<typename T>
LinkedList<T> LinkedList<T>::split_right(LinkedList<T> &pList){
  LinkedList<T> pRight;
  int n = pList.size();
  for(int i=0; i < n; i++){
    pRight.pushBack(pList.popFront());
  }
  return pRight;
} 


template<typename T>
void LinkedList<T>::merge_sort(LinkedList<T> &pList, const int WAY){
  // base case
  if(pList.size() <= 1) {return;} // already sorted
  // divide & split
  LinkedList<T> pLeft = pList.split_left(pList);
  LinkedList<T> pRight = pList.split_right(pList);
  // recurse
  pLeft.merge_sort(pLeft, WAY);
  pRight.merge_sort(pRight, WAY);
  // conquer & merge
  if(WAY == 1){
  while(pLeft.size() != 0 && pRight.size() != 0){
    if(pLeft.Front() < pRight.Front()){
      pList.pushBack(pLeft.popFront());
      }
    else{ 
      pList.pushBack(pRight.popFront());
      }
  }
  while(pLeft.size()!=0){pList.pushBack(pLeft.popFront());}
  while(pRight.size()!=0){pList.pushBack(pRight.popFront());}
  }
  else{
    while(pLeft.size() != 0 && pRight.size() != 0){
      if(pLeft.Front() > pRight.Front()){
        pList.pushBack(pLeft.popFront());
        }
      else{ 
        pList.pushBack(pRight.popFront());
        }
    }
    while(pLeft.size()!=0){pList.pushBack(pLeft.popFront());}
    while(pRight.size()!=0){pList.pushBack(pRight.popFront());}
    }
}
