/* CSCI 261: L5A: Double The Fun
 *
 * Author: Garrett Thompson
 *
 * Main file to test my implementation of the Doubly Linked List class implementation
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include "DoublyLinkedList.hpp"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main(){
  // Creating a doubly linked list
  DoublyLinkedList<int> list1;
  // Inserting our test values into the linked list
  list1.insert(0, 6);
  list1.insert(0, 5);
  list1.insert(5, 7);
  list1.insert(-3, 1);
  list1.insert(1, 2);
  list1.insert(2, 9);
  list1.insert(2, 3);
  // Printing the linked list
  list1.print();
  list1.printReverse();
  // Testing the set funciton
  list1.set(3, 4);
  // Printing the linked list
  list1.print();
  // Testing the remove function by removing values from the list
  list1.remove(-2);
  list1.remove(9);
  list1.remove(2);
  // Testing the size and get function
  cout << list1.get(2) << endl;
  cout << list1.size() << endl;
  // Printing the list again
  list1.print();
  // Cleaning up and deconstructing the linked list
  list1.~DoublyLinkedList();

}