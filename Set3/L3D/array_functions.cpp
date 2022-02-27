/* CSCI 261 L3D: Array Functions 
 *
 * Author: Garrett Thompson
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
  pArray = new signed int[INIT_SIZE];
}

int array_get_element_at(const int* pARRAY, const int SIZE, const int POS){
   if (POS == -1 || POS > SIZE){return 0;}
   return pARRAY[POS];
}

void array_set_element_at(int* pArray, const int SIZE, const int POS, const int VALUE){
  pArray[POS] = VALUE;
}

void array_deallocate(int* &pArray, int &size){
  delete pArray;
  pArray = nullptr;
  size = 0;
}

void array_insert_at_position(int* &pArray, int &size, const int POS, const int VALUE){
  int* pArrayNew = new signed int[size+1];
  int i;
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
  delete pArray;
  pArray = pArrayNew;
  delete pArrayNew;
  size +=1;
  
}

int array_min(const int* pARRAY, const int SIZE){
  int i;
  int min = pARRAY[0];
  for (i=0; i < SIZE; i++){
    if(pARRAY[i] < min){
        min = pARRAY[i];
    }
  }
  return min;
}

int array_max(const int* pARRAY, const int SIZE){
  int i;
  int max = pARRAY[0];
  for (i=0; i < SIZE; i++){
    if(pARRAY[i] > max){
        max = pARRAY[i];
    }
  }
  return max;
}

int array_find(const int* pARRAY, const int SIZE, const int TARGET){
  return 0;
}

void array_remove_from_position(int* &pArray, int &size, const int POS){
  int *pArrayNew = new signed int[size-1];
  int i;
  if(POS > size){
    for (i=0; i < size; i++){
      if(i == size-1){
        continue;
      }
      else{
        pArrayNew[i] = pArray[i];
      }
      }
  }
  else if(POS < 0){
    for (i=0; i < size; i++){
      if(i == 0){
        continue;
      }
      else{
        pArrayNew[i-1] = pArray[i];
      }
      }
  }
  else{
    for (i=0; i < size; i++){
      if(i==POS){
        continue;
      }
      else if(i < size){
        pArrayNew[i] = pArray[i];
      }
      else{
        pArrayNew[i-1] = pArray[i];
      }
      }
  }
  delete pArray;
  pArray = pArrayNew;
  delete pArrayNew;
  size -=1;
}
