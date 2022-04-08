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
  int *pArray = nullptr;
  int currArraySize = 9;
  array_allocate(pArray, currArraySize);
  array_set_element_at(pArray, currArraySize, 0, 4);
  array_set_element_at(pArray, currArraySize, 1, 3);
  array_set_element_at(pArray, currArraySize, 2, 8);
  array_set_element_at(pArray, currArraySize, 3, 1);
  array_set_element_at(pArray, currArraySize, 4, 5);
  array_set_element_at(pArray, currArraySize, 5, 9);
  array_set_element_at(pArray, currArraySize, 6, 7);
  array_set_element_at(pArray, currArraySize, 7, 2);
  array_set_element_at(pArray, currArraySize, 8, 6);
  for (int i =0; i < currArraySize; i++){
    cout << array_get_element_at(pArray, currArraySize, i) << " ";
  }
  cout << endl;
  insertion_sort_array(pArray, currArraySize);
  for (int i =0; i < currArraySize; i++){
    cout << array_get_element_at(pArray, currArraySize, i) << " ";
  }
  cout << endl;
}