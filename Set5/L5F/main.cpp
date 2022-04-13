#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.hpp"
using namespace std;
/* CSCI 261: Lab 5F - A Needle in the Haystack
 *
 * Author: Garrett Thompson
 *
 * Main file for Lab 5F in which we assign random values to a linked list, sort it, then perform a binary search based on user specified values
 * 
 */

int main() {
  // Initializing values we need to take user input and perform the search
  int userIn;
  int values;
  int search;
  // Asking the user for how many values to add to the list
  cout << "How many integers would you like to make?" << endl;
  cin >> userIn;
  // Seeding random time
  srand(time(0));
  rand();
  // Initializing the list to hold the values
  LinkedList<int> list1;
  for(int i = 0; i < userIn; i++){
    // Storing the random values in the list
    int x = rand() % (100-0+1) +0;
    list1.pushBack(x);
  }
  // Printing the original list
  list1.print(list1);
  // Performing a mege sort on the list
  list1.merge_sort(list1);
  // Printing the merge sort
  list1.print(list1);
  // Asking the user how many values they want to search for
  cout << "How many values would you like to search?" << endl;
  cin >> values;
  // Looping until all of the searches are used up
  for(int i = 0; i < values; i++){
    cout << "what value would you like to search for?" << endl;
    cin >> search;
    // Function call for the binary search
    cout << list1.search(list1, search) << endl;
  }
  return 0;

}
