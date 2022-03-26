#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList(){
    mpHead = nullptr;
    mpTail = nullptr;
    mSize = 0;
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
  Node* pCurrent;
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
