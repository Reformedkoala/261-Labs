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
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;
#include "LinkedList.hpp"
#include "Node.hpp"

int main(){
  // Copy and paste from previous lab but this time with type specification
  LinkedList<int> list1;
  cout << list1.size() << endl;
  list1.pushFront(1);
  list1.pushBack(2);
  list1.pushFront(3);
  list1.pushBack(4);
  list1.pushFront(5);
  list1.pushBack(6);
  cout << list1.size() << endl;
  int counter = 0;
  while(counter < list1.size()){
    cout << list1.at(counter) << " ";
    counter++; 
  }
  LinkedList<int> list2;
  cout << endl << list2.size() << endl;
  list2 = list1;
  cout << list1.size() << " " << list2.size() << endl;
  list1.pushFront(7);
  list1.pushBack(8);
  cout << list1.size() << " " << list2.size() << endl;
  LinkedList<int> list3 = LinkedList<int>(list1);
  cout << list1.size() << " " << list2.size() << " " << list3.size() << endl;
  list1.pushFront(9);
  list1.pushBack(10);
  cout << list1.size() << " " << list2.size() << " " << list3.size() << endl;
  list1.print(list1);
  list2.print(list2);
  list3.print(list3);
  list1.~LinkedList<int>();
  list2.~LinkedList<int>();
  list3.~LinkedList<int>();
  // Trying out the new template on the string data type
  LinkedList<string> list4;
  list4.pushFront("is");
  list4.pushBack("working");
  list4.pushFront("This");
  list4.pushBack("now.");
  list4.print(list4);
  list4.~LinkedList<string>();
}