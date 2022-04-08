/* CSCI 261 L3D: Array Functions 
 *
 * Author: Garrett Thompson
 * 
 * This cpp file implements functions to complete a test set in order to verify each function implementation works properly.  This requires a strong understanding of pointers
 * and arrays in c++ and requires the creator to implement each function properly accounting for all cases.
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
#include <vector> // for dynamic arrays
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

#include "array_functions.h"



void array_allocate(int* &pArray, const int INIT_SIZE){
  // Declaring a new array
  pArray = new signed int[INIT_SIZE];
}

int array_get_element_at(const int* pARRAY, const int SIZE, const int POS){
  // Getting an element at a new array
   if (POS == -1 || POS > SIZE){return 0;}
   return pARRAY[POS];
}

void array_set_element_at(int* pArray, const int SIZE, const int POS, const int VALUE){
  // Setting a value at a certain index
  pArray[POS] = VALUE;
}

void array_deallocate(int* &pArray, int &size){
  // Deleting the previous array
  delete pArray;
  pArray = nullptr;
  size = 0;
}

void array_insert_at_position(int* &pArray, int &size, const int POS, const int VALUE){
  // Initiating a new array
  int* pArrayNew = new signed int[size+1];
  int i;
  // Checking if it needs to be put at the front
  if(POS > size){
    for (i=0; i < size+1; i++){
      if(i == size){
        pArrayNew[i] = VALUE;
      }
      else{
        pArrayNew[i] = pArray[i];
      }
      }
  }
  // Checking if the position is less then 0
  else if(POS < 0){
    for (i=0; i < size+1; i++){
      if(i == 0){
        pArrayNew[i] = VALUE;
      }
      else{
        pArrayNew[i] = pArray[i-1];
      }
      }
  }
  // Default insert into the array
  else{
    for (i=0; i < size+1; i++){
      if(i==POS){
        pArrayNew[i] = VALUE;
      }
      else if(i < POS){
        pArrayNew[i] = pArray[i];
      }
      else{
        pArrayNew[i] = pArray[i-1];
      }
      }
  }
  pArray = pArrayNew;
  size +=1;
  
}

int array_min(const int* pARRAY, const int SIZE){
  // Checks if the size is 0 and breaks if so
  if(SIZE == 0){
    return 0;
  }
  // Default checking through the min of the array
  else{
    int i=0;
    int min = pARRAY[i];
    for (i=0; i < SIZE; i++){
      if(pARRAY[i] < min){
        min = pARRAY[i];
      }
    }
    return min;
  }
}

int array_max(const int* pARRAY, const int SIZE){
  // Checks if the size is 0 and exits if so
  if(SIZE == 0){
    return 0;
  }
  // Default searching for the minimum in the array
  else{
    int i;
    int max = pARRAY[0];
    for (i=0; i < SIZE; i++){
      if(pARRAY[i] > max){
          max = pARRAY[i];
      }
    }
    return max;
  }
}

int array_find(const int* pARRAY, const int SIZE, const int TARGET){
  // Searches the entire array for the required value
  for (int i=0; i < SIZE; i++){
    if(pARRAY[i] == TARGET){
      return i;
    }
  }
  return -1;
}

void array_remove_from_position(int* &pArray, int &size, const int POS){
  // Checks if the size is equal to 0 or not
  if(size!=0){
    int *pArrayNew = new signed int[size-1];
    int i;
    // Checks if the position is greater then the size and removes it from the front if so 
    if(POS > size){
      for (i=0; i < size; i++){
        if(i == size){
          continue;
        }
        else{
          pArrayNew[i] = pArray[i];
        }
        }
    }
    // Checks if the position is less then 0 and removes it from the back if so 
    else if(POS <= 0){
      for (i=0; i < size; i++){
        if(i == 0){
          continue;
        }
        else{
          pArrayNew[i-1] = pArray[i];
        }
        }
    }
    // Default code to remove from inside the array
    else{
      for (i=0; i < size; i++){
        if(i==POS){
          continue;
        }
        else if(i < POS){
          pArrayNew[i] = pArray[i];
        }
        else{
          pArrayNew[i-1] = pArray[i];
        }
        }
    }
    pArray = pArrayNew;
    size -=1;
  }
  
}
