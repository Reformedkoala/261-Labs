/* CSCI 261: Lab 1D: Batman Loops 
 *
 * Author: Garrett Thompson
 *
 * This lab gave practice with loop syntax and explains the functionality of including loops to shorten repetitive code.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
  // Initialized an iteration variable
  int i = 0;
  // The while loop increments inside of itself and prints out Na
  while (i < 16) {
      cout << "Na";
      i++;
  }
  cout << " Batman!" << endl;
  // Reset the iteration variable
  i = 0;
  // Same conditional it will just always run at least once
  do {
      cout << "Na";
      i++;
  } while (i < 16);
  cout << " Batman!" << endl;
  // Do not have to reset variable outside of loop conditional and syntax
  for (i = 0; i < 16; i++) {
      cout << "Na";
  }
  cout << " Batman!" << endl;
}
