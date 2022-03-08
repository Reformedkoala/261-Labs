/* CSCI 261: L4A: Lab 4A - Array vs Linked List
 *
 * Author: Garrett Thompson
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
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
  int* pArray;
  pArray = new signed int[3];
  cout << "Please enter three values here" << endl;
  for(int i = 0; i < 3; i++){
    cout << "Value " << i + 1 << ": ";
    cin >> pArray[i];
  }
  for(int i = 0; i < 3; i++){
    cout << pArray[i] << " ";
  }
  cout << endl;
  for(int i = 2; i >= 0; i--){
    cout << pArray[i] << " ";
  }
  cout << endl;
  struct Node {
    int value;
    Node *pNext;
  };
  Node *pHead = new Node;
  Node *pNext = new Node;
  Node *pTail = new Node;
  pHead->pNext = pNext;
  pNext->pNext = pTail;
  pTail->pNext = nullptr;
  cout << "Please enter three values here" << endl;
  Node *currentNode = new Node;
  currentNode->pNext = pHead;
  for(int i = 0; i < 3; i++){
    cout << "Value " << i+1 << ": ";
    cin >> currentNode->pNext->value;
    currentNode->pNext = currentNode->pNext->pNext;
  }
  currentNode->pNext = pHead;
  for(int i = 0; i < 3; i++){
    cout << currentNode->pNext->value << " ";
    currentNode->pNext = currentNode->pNext->pNext;
  }
  cout << endl;
  int i = 3;
  while(i > 0){
    currentNode->pNext = pHead;
    for(int j=0; j<i-1; j++){
      currentNode->pNext = currentNode->pNext->pNext;
    }
    cout << currentNode->pNext->value << " ";
    i--;
  }
  
  delete pHead;
  delete pNext;
  delete pTail;
  delete currentNode;
}
