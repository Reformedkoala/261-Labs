#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
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
  int userIn;
  int values;
  int search;
  cout << "How many integers would you like to make?" << endl;
  cin >> userIn;
  srand(time(0));
  rand();
  LinkedList<int> list1;
  for(int i = 0; i < userIn; i++){
    int x = rand() % (100-0+1) +0;
    list1.pushBack(x);
  }
  list1.print(list1);
  list1.merge_sort(list1);
  list1.print(list1);
  cout << "How many values would you like to search?" << endl;
  cin >> values;
  for(int i = 0; i < values; i++){
    cout << "what value would you like to search for?" << endl;
    cin >> search;
    cout << list1.search(list1, search) << endl;
  }
  return 0;

}
