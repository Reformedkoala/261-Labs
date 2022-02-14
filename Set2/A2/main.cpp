/* CSCI 261 A2: PPM Image Editor
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
#include "ppm_functions.h"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;


int main() {
  print_file_options();
  int userImage = get_user_input(1,3);
  print_operation_options();
  int userApply = get_user_input(1,2);
  
}
