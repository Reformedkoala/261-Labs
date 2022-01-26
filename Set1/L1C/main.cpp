/* CSCI 261 Lab 1B: Generate & Classify a Random Value
 *
 * Author: Garrett Thompson
 *
 * More complete description here...
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math
#include <cstdlib> // for random
#include <ctime> // for time
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
  srand(time(0));
  rand();
  float min;
  float max;
  cout << "Enter the minimum value: ";
  cin >> min;
  cout << "Enter the maximum value: ";
  cin >> max;
  float rand_float = rand() / (float)RAND_MAX + (max - min);
  cout << "A random value is: " << rand_float << endl;
  if(rand_float >= 0 && rand_float < max / 4) {
    cout << "This is in the first quartile" << endl;
  }
  else if(rand_float >= max / 4 && rand_float < max / 4 * 2) {
    cout << "This is in the second quartile" << endl;
  }
  else if(rand_float >= max / 4 * 2 && rand_float < max / 4 * 3) {
    cout << "This is in the third quartile" << endl;
  }
  else{
    cout << "This is in the fourth quartile" << endl;
  }
  return 0; // signals the operating system that our program ended OK.
}
