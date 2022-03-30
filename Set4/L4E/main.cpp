/* CSCI 261: L4A: Lab 4E - A Linked List Class Part III: Test, Copy, Print
 *
 * Author: Garrett Thompson
 *
 * Implementation of each class operation
 * 
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
#include "LinkedList.h"

int main(){
  // Step 1
  LinkedList list1;
  // Step 2
  cout << list1.size() << endl;
  // Step 3
  list1.pushFront(1);
  list1.pushBack(2);
  list1.pushFront(3);
  list1.pushBack(4);
  list1.pushFront(5);
  list1.pushBack(6);
  // Step 4
  cout << list1.size() << endl;
  // Step 5
  int counter = 0;
  while(counter < list1.size()){
    cout << list1.at(counter) << " ";
    counter++; 
  }
  // Step 6
  LinkedList list2;
  // Step 7
  cout << endl << list2.size() << endl;
  // Step 8
  list2 = list1;
  // Step 9
  cout << list1.size() << " " << list2.size() << endl;
  // Step 10
  list1.pushFront(7);
  list1.pushBack(8);
  // Step 11
  cout << list1.size() << " " << list2.size() << endl;
  // Step 12
  LinkedList list3 = LinkedList(list1);
  // Step 13
  cout << list1.size() << " " << list2.size() << " " << list3.size() << endl;
  // Step 14
  list1.pushFront(9);
  list1.pushBack(10);
  // Step 15
  cout << list1.size() << " " << list2.size() << " " << list3.size() << endl;
  // Step 16 (implemented a print function)
  list1.print(list1);
  list2.print(list2);
  list3.print(list3);
  // Step 17
  list1.~LinkedList();
  list2.~LinkedList();
  list3.~LinkedList();
}