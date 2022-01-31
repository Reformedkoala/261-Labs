/* CSCI 261: Lab 2A: Secret Moosage 
 *
 * Author: Garrett Thompson
 *
 * 
 */
// The include section adds extra definitions from the C++ standard library.
#include <fstream>
#include <iostream>
using namespace std;

int main() {

  ifstream filein("circle1.txt");
  if (filein.fail()) {
    cerr << "Error opening input file";
    return -1;
  }

  float piVal;
  filein >> piVal;
  float radius;
  filein >> radius;

  filein.close();

  ofstream fileout("area.txt");
  if (fileout.fail()) {
    cerr << "Error opening input file";
    return -2;
  }
  
  fileout << "writing to file..." << endl;
  fileout << piVal << endl;
  fileout << radius << endl;

  return 0; 
}
