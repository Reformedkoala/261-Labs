/* CSCI 261 Lab 2B: Procedural Programming with Functions
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
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.
void generate_random_integer(int min_val, int max_val, bool min_in, bool max_in) {
  int i = 0;
  for (i = 0; i < 10; i++) {
    int rand_int = rand() % (int)((max_val - min_val + 1) + min_val);
    cout << rand_int << endl;
  }
}
void generate_random_float(float min_val, float max_val, bool min_in, bool max_in) {
  int i = 0;
  for (i =0; i < 10; i++) {
    float rand_float = rand() / (float)RAND_MAX * (max_val - min_val) + min_val;
    cout << setprecision(4) << rand_float << endl;
  }
}
// Must have a function named "main", which is the starting point of a C++ program.
int main() {
  srand(time(0));
  rand();
  float min_val;
  float max_val;
  bool min_in;
  bool max_in;
  cout << "Enter the minimum value: ";
  cin >> min_val;
  cout << "Enter the maximum value: ";
  cin >> max_val;
  cout << "Enter whether or not the minimum should be inclusive ";
  cin >> min_in;
  cout << "Enter whether or not the maximum should be inclusive ";
  cin >> max_in;
  generate_random_integer(min_val, max_val, min_in, max_in);
  generate_random_float(min_val, max_val, min_in, max_in);
  return 0; // signals the operating system that our program ended OK.
}

