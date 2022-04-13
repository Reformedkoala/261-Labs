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
#include "array_functions.cpp"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

void insertion_sort_array(int* pArray, const int SIZE){
  // Looping over the array to keep track of the elements I've changed and sorting the elements that need to be sorted
  for (int i=1; i < SIZE; i++){
    int x, j;
    x = pArray[i];
    j = i-1;
    while (j >= 0 && pArray[j] > x){
      pArray[j+1] = pArray[j];
      j--;
    }
    pArray[j+1] = x;
  }
}

int main(){
  // Initializing the array
  int *pArray = nullptr;
  int currArraySize = 9;
  // Dynamically allocating the array
  array_allocate(pArray, currArraySize);
  // Setting all the elements in the array
  array_set_element_at(pArray, currArraySize, 0, 4);
  array_set_element_at(pArray, currArraySize, 1, 3);
  array_set_element_at(pArray, currArraySize, 2, 8);
  array_set_element_at(pArray, currArraySize, 3, 1);
  array_set_element_at(pArray, currArraySize, 4, 5);
  array_set_element_at(pArray, currArraySize, 5, 9);
  array_set_element_at(pArray, currArraySize, 6, 7);
  array_set_element_at(pArray, currArraySize, 7, 2);
  array_set_element_at(pArray, currArraySize, 8, 6);
  // Printing out the original array
  for (int i =0; i < currArraySize; i++){
    cout << array_get_element_at(pArray, currArraySize, i) << " ";
  }
  cout << endl;
  // Calling the sort function for the array
  insertion_sort_array(pArray, currArraySize);
  for (int i =0; i < currArraySize; i++){
    cout << array_get_element_at(pArray, currArraySize, i) << " ";
  }
  cout << endl;
}