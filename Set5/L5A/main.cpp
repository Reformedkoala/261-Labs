/* CSCI 261: L4A: Lab 4F - A Templated Linked List
 *
 * Author: Garrett Thompson
 *
 * Implementation of the Linked List Class but now able to funciton with any data type
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math
#include <cstdlib> // for random
#include <ctime> // for time
#include <iomanip> // for formatting
#include <fstream> // for files
#include "DoublyLinkedList.hpp"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main(){
  DoublyLinkedList<int> list1;
  list1.insert(0, 6);
  list1.insert(0, 5);
  list1.insert(5, 7);
  list1.insert(-3, 1);
  list1.insert(1, 2);
  list1.insert(2, 9);
  list1.insert(2, 3);
  list1.print();
  list1.printReverse();
  list1.set(3, 4);
  list1.print();
  list1.remove(-2);
  list1.remove(9);
  list1.remove(2);
  cout << list1.get(2) << endl;
  cout << list1.size() << endl;
  list1.print();
  list1.~DoublyLinkedList();

}