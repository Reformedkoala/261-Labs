#include "linked_list_functions.h"
#include <iostream>
using namespace std;

Node* linked_list_make_node(const int VALUE) {
    // TODO #1
    Node* newNode = new Node;
    newNode->value = VALUE;
    newNode->pNext = nullptr; 
    return newNode;
}

int linked_list_get_size(Node* pHead) {
    Node *currentNode = new Node;
    int counter = 0;
    currentNode = pHead;
    while(currentNode != nullptr){
      counter++;
      currentNode = currentNode->pNext;
    }
    return counter;
}

Node* linked_list_add_value_to_front(Node* pHead, const int VALUE) {
    Node* newNode = new Node;
    newNode->value = VALUE;
    newNode->pNext = pHead;
    pHead = newNode;
    return pHead;
}

int linked_list_get_value_at_position(Node* pHead, const int POS) {
    Node *currentNode = new Node;
    int counter = 0;
    currentNode = pHead;
    while(currentNode != nullptr){
      if(counter == POS){return currentNode->value;}
      counter++;
      currentNode = currentNode->pNext;
    }
    return -1;
}

int linked_list_min(Node* pHead) {
    if (pHead == nullptr){return -1;}
    Node *currentNode = new Node;
    int min = pHead->value;
    currentNode = pHead;
    while(currentNode != nullptr){
      if(currentNode->value < min){min = currentNode->value;}
      currentNode = currentNode->pNext;
    }
    return min;
}

int linked_list_max(Node* pHead) {
    if (pHead == nullptr){return -1;}
    Node *currentNode = new Node;
    int max = pHead->value;
    currentNode = pHead;
    while(currentNode != nullptr){
      if(currentNode->value > max){max = currentNode->value;}
      currentNode = currentNode->pNext;
    }
    return max;
}

int linked_list_find(Node* pHead, const int TARGET) {
    Node *currentNode = new Node;
    currentNode = pHead;
    int counter = 0;
    while(currentNode != nullptr){
      if(currentNode->value == TARGET){return counter;}
      currentNode = currentNode->pNext;
      counter++;
    }
    return -1;
}

Node* linked_list_remove_node_from_front(Node* pHead) {
    Node *nodeToDelete = new Node;
    if(pHead == nullptr){return pHead;}
    nodeToDelete = pHead;
    pHead = pHead->pNext;
    delete nodeToDelete;
    return pHead;
}

Node* linked_list_set_value_at_position(Node* pHead, const int POS, const int VALUE) {
    Node *currentNode = new Node;
    currentNode = pHead;
    int counter = 0;
    while(currentNode != nullptr){
      if(counter == POS){currentNode->value = VALUE; return pHead;}
      currentNode = currentNode->pNext;
      counter++;
    }
    return pHead;
}