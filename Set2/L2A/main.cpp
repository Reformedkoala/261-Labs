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

  ifstream secretMessage("secretMessage.txt");
  if (secretMessage.fail()) {
    cerr << "Error opening input file";
    return -1;
  }
  ofstream decipheredMessage("decipheredMessage.txt");
  if (decipheredMessage.fail()) {
    cerr << "Error opening output file";
    return -2;
  }
  
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
    // c is now assigned the next character from the file
  }
  secretMessage.close();
  decipheredMessage.close();
  return 0; 
}
