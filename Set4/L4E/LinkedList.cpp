#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    mpHead = nullptr;
    mpTail = nullptr;
    mSize = 0;
}

LinkedList::LinkedList(const LinkedList& OTHER){
  mSize = OTHER.mSize;
  Node* pCurrent;
  Node* pNext;
  if(OTHER.mpHead == nullptr){
    mpHead = 0;
  }
  else{
    mpHead = new Node;
    mpTail = new Node;
    mpHead->pNext = OTHER.mpHead->pNext;
    mpHead->value = OTHER.mpHead->value;
    mpTail->pNext = OTHER.mpTail->pNext;
    mpTail->value = OTHER.mpTail->value;
    pCurrent = mpHead;
    pNext = mpHead->pNext;
  }
  while(pNext->pNext != nullptr){
    pCurrent->pNext = new Node;
    pCurrent = pCurrent->pNext;
    pCurrent->pNext = pNext->pNext;
    pCurrent->value = pNext->value;
    pNext = pNext->pNext;
  }
  pCurrent->pNext = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& OTHER){
  if(this == &OTHER)
    return *this;
  this->mSize = OTHER.mSize;
  Node* pCurrent;
  Node* pNext;
  if(OTHER.mpHead == nullptr){
    this->mpHead = 0;
  }
  else{
    this->mpHead = new Node;
    this->mpTail = new Node;
    this->mpHead->pNext = OTHER.mpHead->pNext;
    this->mpHead->value = OTHER.mpHead->value;
    this->mpTail->pNext = OTHER.mpTail->pNext;
    this->mpTail->value = OTHER.mpTail->value;
    pCurrent = this->mpHead;
    pNext = this->mpHead->pNext;
  }
  while(pNext->pNext != nullptr){
    pCurrent->pNext = new Node;
    pCurrent = pCurrent->pNext;
    pCurrent->pNext = pNext->pNext;
    pCurrent->value = pNext->value;
    pNext = pNext->pNext;
  }
  pCurrent->pNext = nullptr;
  return *this;
}

LinkedList::~LinkedList(){
    Node *temp = mpHead, *next;
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

Node* LinkedList::makeNodeForValue(int value){
  Node* pCurrent = new Node;
  pCurrent->value = value;
  pCurrent->pNext = nullptr;
  return pCurrent;
} 

void LinkedList::pushFront(int value){
  Node* newNode = new Node;
  newNode->value = value;
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


void LinkedList::pushBack(int value){
  Node *newNode = new Node;
  newNode->value = value;
  newNode->pNext = nullptr;
  mpTail->pNext = newNode;
  mpTail = newNode;
  mSize+=1;
} 

int LinkedList::popFront(){
  if(mpHead->pNext == nullptr){return -1;}
  int value;
  Node *newHead;
  value = mpHead->value;
  newHead = mpHead->pNext;
  delete mpHead;
  mpHead = newHead;
  mSize -= 1;
  return value;
}

int LinkedList::Front(){
    if(mpHead == nullptr){return -1;}
    else{return mpHead->value;}
}

int LinkedList::Back(){
    if(mpHead == nullptr){return -1;}
    else{return mpTail->value;}
} 

unsigned int LinkedList::size(){
    return mSize;
} 

int LinkedList::at(const int POS){
  Node *currentNode = new Node;
  currentNode = mpHead;
  int counter = 0;
  while(currentNode != nullptr){
    if(counter == POS){return currentNode->value;}
    currentNode = currentNode->pNext;
    counter++;
  }
  return -1;
}

void LinkedList::print(LinkedList& OTHER){
  Node * currentNode = new Node;
  currentNode = this->mpHead;

  while (currentNode != nullptr){
	  cout << currentNode->value << " ";
    currentNode = currentNode->pNext;
  }
  cout << endl;
}