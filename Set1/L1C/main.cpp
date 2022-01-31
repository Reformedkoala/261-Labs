/* CSCI 261 Lab 1B: Generate & Classify a Random Value
 *
 * Author: Garrett Thompson
 *
 * The goal of this lab was to create a random float value between two values the user gives
 * that could then be classified within the four quartiles of the given range.
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
  // Seeding the random function in order to make sure our random values are somewhat truly random
  srand(time(0));
  rand();
  // Initializing variables to be using within our function
  float min;
  float max;
  cout << "Enter the minimum value: ";
  cin >> min;
  cout << "Enter the maximum value: ";
  cin >> max;
  // Generates the random value using math we learned in class
  float rand_float = rand() / (float)RAND_MAX * (max - min) + min;
  cout << "A random value is: " << rand_float << endl;
  // Determines what quartile the random value is in
  if (rand_float >= min && rand_float < (float)((max - min) / 4) + min) {
    cout << "This is in the first quartile" << endl;
  }
  else if ((rand_float >= (float)(((max - min) / 4) + min) && (rand_float < (float)((((max - min) / 4) * 2) + min)))) {
    cout << "This is in the second quartile" << endl;
  }
  else if((rand_float >= (float)((((max - min) / 4)  * 2) + min)) && (rand_float < (float)((((max - min) / 4) * 3) + min))) {
    cout << "This is in the third quartile" << endl;
  }
  else{
    cout << "This is in the fourth quartile" << endl;
  }
  return 0; // signals the operating system that our program ended OK.
}
