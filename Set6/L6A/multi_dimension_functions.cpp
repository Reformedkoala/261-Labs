/* CSCI 261: A4: Wavefront OBJ File Format
 *
 * Author: Garrett Thompson
 *
 * Reading in a wavefront OBJ File Format and verifying certain properties of the file as well as printing out based on user specification.
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <vector>
#include <fstream> // for files
#include <string>
#include "multi_dimension_functions.h"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

string prompt_user_for_filename(){
  // Prompting the user for the file they want to open
  cout << "What file do you wish to open:  " << endl;
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
  cout << "File successfully opened!" << endl << endl;
  return true;
}