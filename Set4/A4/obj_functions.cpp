/* CSCI 261 L3D: Array Functions 
 *
 * Author: Garrett Thompson
 * 
 * This cpp file implements functions to complete a test set in order to verify each function implementation works properly.  This requires a strong understanding of pointers
 * and arrays in c++ and requires the creator to implement each function properly accounting for all cases.
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
#include <string>
#include "obj_functions.h"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

string prompt_user_for_filename(){
  // Prompting the user for the file they want to open
  cout << "Please enter the name for your file here: " << endl;
  string filename;
  getline(cin, filename);
  return filename;
}

bool open_file(ifstream &inputFile, string filename){
  // Opens the input file for the program to read from 
  cout << "Opening file \"" << filename << "\"" << endl;
  inputFile.open(filename);
  if (inputFile.fail()) {
    return false;
  }
  cout << "File successfully opened!" << endl;
  return true;
}