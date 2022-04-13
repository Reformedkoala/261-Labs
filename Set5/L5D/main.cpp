#include <iostream>
#include "LinkedList.hpp"
using namespace std;
/* CSCI 261: L5D: Sorting II & Recursion II: Merge Sort via the Call Stack
 *
 * Author: Garrett Thompson
 *
 * Performing the recursive merge sort on a list of integers
 * 
 */

int main() {
  // Initializing the list
  LinkedList<int> list1;
  // 4 3 8 1 5 9 7 2 6
  // Pushing the values into the list
  list1.pushBack(4);
  list1.pushBack(3);
  list1.pushBack(8);
  list1.pushBack(1);
  list1.pushBack(5);
  list1.pushBack(9);
  list1.pushBack(7);
  list1.pushBack(2);
  list1.pushBack(6);
  // Printing the original list out
  list1.print(list1);
  // Sorting the list
  list1.merge_sort(list1);
  // Printing the list
  list1.print(list1);
  // Deconstructing the list
  list1.~LinkedList();
  return 0;
}