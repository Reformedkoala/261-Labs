#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList(){
    mpHead = nullptr;
    mpTail = nullptr;
    msize = 0;
}

LinkedList::~LinkedList(){
    Node *temp = head, *next;
    while(temp != nullptr){
        next = temp->next;
        delete temp;
        temp = next;
    }
    delete mpHead;
    mpTail = nullptr;
    mpHead = nullptr;
    mSize = 0;
}

Node LinkedList::mMakeNodeForValue(int value){
  Node *pCurrent;
  pCurrent->value = value;
  pCurrent->pNext = nullptr;
  return pCurrent;
} 

void LinkedList::pushFront(int value){
  Node *newNode;
  newNode->value = value;
  newNode->pNext = mpHead;
  mpHead = newNode;
}


void LinkedList::pushBack(int value){
  Node *newNode;
  newNode->value = value;
  newNode->pNext = nullptr;
  mpTail->pNext = newNode;
  mpTail = newNode;
} 

int LinkedList::popFront(){
  if(mpHead->pNext == nullptr){return -1}
  int value;
  Node *newHead;
  value = mpHead->value;
  newHead = mpHead->pNext;
  delete mpHead;
  mpHead = newHead;
  mSize -= 1;
  return value;
}

int LinkedList::front(){
    if(mpHead == nullptr){return -1;}
    else{return mpHead->value;}
}

int LinkedList::back(){
    if(mpHead == nullptr){return -1;}
    else{return mpTail->value;}
} 

int LinkedList::size(){
    return mSize;
} 
