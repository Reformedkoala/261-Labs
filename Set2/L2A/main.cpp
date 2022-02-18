/* CSCI 261: Lab 2A: Secret Moosage 
 *
 * Author: Garrett Thompson
 *
 * This program takes in a secret message encoded with a secret code and converts that message into something human readable.
 * 
 */
// The include section adds extra definitions from the C++ standard library.
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  // Creates the ifstream object to read from and checks that it opens correctly
  ifstream secretMessage("secretMessage.txt");
  if (secretMessage.fail()) {
    cerr << "Error opening input file";
    return -1;
  }
  // Creates the ofstream object to read from and checks that it opens correctly
  ofstream decipheredMessage("decipheredMessage.txt");
  if (decipheredMessage.fail()) {
    cerr << "Error opening output file";
    return -2;
  }
  // Reads each character from the file does a conversion if neccesary and writes to the file once converted
  char c;
  while ( secretMessage.get(c) ) {
    if (c == '\n'){
      decipheredMessage << c;
    }
    else if (c == '~') {
      decipheredMessage << ' ';
    }
    else{
      decipheredMessage << (char)(c + 1);
    }
  }
  // Closes both files once successful
  secretMessage.close();
  decipheredMessage.close();
  return 0; 
}
