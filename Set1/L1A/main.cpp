/* CSCI 261 Lab 1A: Compiling Hello World, Ohm's law, and Pythagorean's theorem
 *
 * Author: Garrett Thompson
 * 
 * Prints out Hello World.  Takes a user value in for both voltage and resistance to calculate current.  
 * It then takes in a value for 2 legs of a triangle to calculate the hypotenuse using pythagoreans theorem.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/
  cout << "Hello world!" << endl; // print Hello world! to the screen
  // Initializing variables used within program
  double voltage;
  double resistance;
  double current;
  double x;
  double y;
  double hypotenuse;
  // Asking for user input to calculate the current from voltage and resistance using Ohm's Law
  cout << "Enter the voltage: ";
  cin >> voltage;
  cout << "Enter the resistance: ";
  cin >> resistance;
  current = voltage / resistance;
  cout << "The current is: " << current << " Amps" << endl;
  // Asking for user input to calculate distance based on pythagoreans theorem
  cout << "Enter the first side: ";
  cin >> x;
  cout << "Enter the second side: ";
  cin >> y;
  x = x * x;
  y = y * y;
  hypotenuse = sqrt(x + y);
  cout << "The distance is: " << hypotenuse << endl;
  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}
