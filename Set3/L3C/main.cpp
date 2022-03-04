/* CSCI 261 L3C: Pointers
 *
 * Author: Garrett Thompson
 *
 * This lab was meamt to introduce us to pointers and allow us to familiarize ourselves with the implementation of pointers.  Similar to pass by reference pointers work through
 * memory addresses and help us reference things and allocate memory at runtime rather then at compiling.
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


int main() {
  // Initializing starting variables
  int iNum = 9;
  double dNum = 14.25;
  // Initializing pointers to play with
  int* pINum1;
  int* pINum2;
  double* pDNum;
  // Setting a pointer equal to the memory address of our base variable
  pINum1 = &iNum;
  cout << pINum1 << " " << &iNum << endl;
  cout << *pINum1 << endl;
  // pINum2 = &dNum; error: cannot convert 'double*' to 'int*' in assignment
  pDNum = &dNum;
  // Doing a sanity check each time we implement a pointer to ensure it is to what we want
  cout << pDNum << " " << *pDNum << endl;
  iNum = 7;
  cout << *pINum1 << endl;
  pINum2 = pINum1;
  cout << pINum2 << " " << *pINum2 << endl;
  *pINum2 = 12;
  cout << iNum << " "<< *pINum1 << " " << *pINum2 << endl;
  
}
