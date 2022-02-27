/* CSCI 261 L3C: Pointers
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


int main() {
  int iNum = 9;
  double dNum = 14.25;
  int* pINum1;
  int* pINum2;
  double* pDNum;
  pINum1 = &iNum;
  cout << pINum1 << " " << &iNum << endl;
  cout << *pINum1 << endl;
  // pINum2 = &dNum; error: cannot convert 'double*' to 'int*' in assignment
  pDNum = &dNum;
  cout << pDNum << " " << *pDNum << endl;
  iNum = 7;
  cout << *pINum1 << endl;
  pINum2 = pINum1;
  cout << pINum2 << " " << *pINum2 << endl;
  *pINum2 = 12;
  cout << iNum << " "<< *pINum1 << " " << *pINum2 << endl;
  
}
