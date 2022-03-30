/* CSCI 261: L4A: Lab 4A - Array vs Linked List
 *
 * Author: Garrett Thompson
 *
 * Testing and implementing the differences between an array and linked-list
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math
#include <cstdlib> // for random
#include <ctime> // for time
#include <iomanip> // for formatting
#include <fstream> // for files
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main(){
  // Initializing a pointer to an array on the free store
  int* pArray;
  pArray = new signed int[3];
  cout << "Please enter three values here" << endl;
  // Taking in user values
  for(int i = 0; i < 3; i++){
    cout << "Value " << i + 1 << ": ";
    cin >> pArray[i];
  }
  // Printing out user values
  for(int i = 0; i < 3; i++){
    cout << pArray[i] << " ";
  }
  cout << endl;
  for(int i = 2; i >= 0; i--){
    cout << pArray[i] << " ";
  }
  cout << endl;
  // Creating a struct for a Node in our linked list
  struct Node {
    int value;
    Node *pNext;
  };
  // Initializing 3 Nodes as part of our linked list
  Node *pHead = new Node;
  Node *pNext = new Node;
  Node *pTail = new Node;
  pHead->pNext = pNext;
  pNext->pNext = pTail;
  pTail->pNext = nullptr;
  cout << "Please enter three values here" << endl;
  Node *currentNode = new Node;
  currentNode->pNext = pHead;
  // Storing user values in the linked list
  for(int i = 0; i < 3; i++){
    cout << "Value " << i+1 << ": ";
    cin >> currentNode->pNext->value;
    currentNode->pNext = currentNode->pNext->pNext;
  }
  currentNode->pNext = pHead;
  // Printing out the values in the linked list
  for(int i = 0; i < 3; i++){
    cout << currentNode->pNext->value << " ";
    currentNode->pNext = currentNode->pNext->pNext;
  }
  cout << endl;
  int i = 3;
  // Printing out the values backwards
  while(i > 0){
    currentNode->pNext = pHead;
    for(int j=0; j<i-1; j++){
      currentNode->pNext = currentNode->pNext->pNext;
    }
    cout << currentNode->pNext->value << " ";
    i--;
  }
  // Removing the nodes off the free store
  delete pHead;
  delete pNext;
  delete pTail;
  delete currentNode;
}
