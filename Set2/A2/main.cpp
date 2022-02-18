/* CSCI 261 A2: PPM Image Editor
 *
 * Author: Garrett Thompson
 *
 * This program takes in a PPM file as an input and based on user input changes the file to be inverted or gray scaled.  This is done by reading in the file the user wants
 * and changing each pixel based on the change desired.  This program has a total of 7 functions and uses them to abstract a lot of the mess out of the main funciton.
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math
#include <cstdlib> // for random
#include <ctime> // for time
#include <iomanip> // for formatting
#include <fstream> // for files
#include "ppm_functions.h"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;


int main() {
  int width;
  int height;
  int maxRgb;
  print_file_options();
  int userImage = get_user_input(1,3);
  print_operation_options();
  int userApply = get_user_input(1,2);
  ifstream inputFile;
  ofstream outputFile;
  open_files(inputFile, outputFile, userImage, userApply);
  read_header_information(inputFile, width, height, maxRgb);
  write_header_information(outputFile, width, height, maxRgb);
  read_and_write_modified_pixels(inputFile, outputFile, userApply, width, height, maxRgb);
}
