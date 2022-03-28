#include "Node.hpp"
#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
  private:
    Node<T>* mpHead;
    Node<T>* mpTail;
    unsigned int mSize;
    Node<T>* makeNodeForValue(const T VALUE);
  public:
    void print(LinkedList& OTHER) const;
    T at(const int POS) const;
    T Front() const;
    T Back() const;
    unsigned int size() const;
    void pushFront(const T VALUE);
    void pushBack(const T VALUE);
    T popFront();
    LinkedList();
    LinkedList(const LinkedList& OTHER);
    LinkedList& operator=(const LinkedList& OTHER);
    ~LinkedList();
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
  if(mpHead->pNext == nullptr){return T();}
  int value;
  Node<T> *newHead;
  value = mpHead->value;
  newHead = mpHead->pNext;
  delete mpHead;
  mpHead = newHead;
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