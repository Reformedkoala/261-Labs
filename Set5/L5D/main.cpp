#include <fstream>
#include <iostream>
#include <string>
#include "LinkedList.hpp"
using namespace std;
/* CSCI 261: A4: Wavefront OBJ File Format
 *
 * Author: Garrett Thompson
 *
 * Reading in a wavefront OBJ File Format and verifying certain properties of the file as well as printing out based on user specification.
 * 
 */

int main() {
  LinkedList<int> list1;
  // 4 3 8 1 5 9 7 2 6
  list1.pushBack(4);
  list1.pushBack(3);
  list1.pushBack(8);
  list1.pushBack(1);
  list1.pushBack(5);
  list1.pushBack(9);
  list1.pushBack(7);
  list1.pushBack(2);
  list1.pushBack(6);
  list1.print(list1);
  list1.merge_sort(list1);
  list1.print(list1);
  list1.~LinkedList();
  return 0;
}