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

void print_file_options() {
  cout << "which image to load?" << endl;
  cout << "1. Brick" << endl;
  cout << "2. Wallpaper" << endl;
  cout << "3. Private" << endl;
}

void print_operation_options() {
  cout << "which process to apply?" << endl;
  cout << "1. Grayscale" << endl;
  cout << "2. Inversion" << endl;
}

int get_user_input(int minIn, int maxIn) {
  int userImage;
  int userApply;
  if (maxIn == 3) {
      while(true) {
        cout << "Enter 1, 2, or 3: ";
        cin >> userImage;
        if (!cin.fail() && userImage >= minIn && userImage <= maxIn) break;
        cerr << "Invalid input" << endl;
        cin.clear();
        char badChar; 
        do { badChar = cin.get(); } while( badChar != '\n' );
      }
      return userImage;
  }
  else {
      while(true) {
        cout << "Enter 1 or 2: ";
        cin >> userApply;
        if (!cin.fail() && userApply >= minIn && userApply <= maxIn) break;
        cerr << "Invalid input" << endl;
        cin.clear();
        char badChar; 
        do { badChar = cin.get(); } while( badChar != '\n' );
      }
      return userApply;
  }
}

