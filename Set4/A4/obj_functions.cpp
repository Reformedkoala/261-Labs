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
  cout << "File successfully opened!" << endl << endl;
  return true;
}

void read_file(LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList, ifstream &inputFile){
  char tempChar;
  int tempInt;
  float tempFloat;
  string tempString;
  while(inputFile >> tempChar){
    if (tempChar == '#'){
      getline(inputFile, tempString);
      stringList.pushBack(tempString);
    }else if(tempChar == 'v'){
      inputFile >> tempFloat;
      floatList.pushBack(tempFloat);
      inputFile >> tempFloat;
      floatList.pushBack(tempFloat);
      inputFile >> tempFloat;
      floatList.pushBack(tempFloat);
    }else{
      inputFile >> tempInt;
      intList.pushBack(tempInt);
      inputFile >> tempInt;
      intList.pushBack(tempInt);
      inputFile >> tempInt;
      intList.pushBack(tempInt);
    }
  }
  inputFile.close();
}

void print_read(LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList){
  cout << "Read in:" << endl;
  cout << stringList.size() << " comments" << endl;
  cout << floatList.size()/3 << " vertices" << endl;
  cout << intList.size()/3 << " faces" << endl << endl;
}

int validate_faces(LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList){
  int check = 1;
  cout << "Validating Faces..." << endl;
  for(int i = 0; i < intList.size()/3; i++){
    if(intList.at(i*3) == intList.at(i*3+1) || intList.at(i*3+1) == intList.at(i*3+2) || intList.at(i*3+2) == intList.at(i*3)){
      cout << "Face " << i+1 << " has duplicate indices" << endl;
      check = 0;
    }
    if((intList.at(i*3)*3) > floatList.size() || (intList.at(i*3)*3) < 0 && (intList.at(i*3+1)*3+1) > floatList.size() || (intList.at(i*3+1)*3+1) < 0 && (intList.at(i*3+2)*3+2) > floatList.size() || (intList.at(i*3+2)*3+2) < 0) {
      cout << "Face " << i+1 << " contains vertices out of range" << endl;
      check = 0;
    }
  }
  if(check == 1){
    cout << "...File is valid!" << endl;
    return check;
  }else{
    cout << "...File is invalid." << endl;
    return check;
  }
  
}

int get_user_input() {
  int choice;
    while(true) {
      cout << "What do you wish to do?" << endl;
      cout << "1) Print comments" << endl;
      cout << "2) Print vertices" << endl;
      cout << "3) Print faces" << endl;
      cout << "4) Quit" << endl;
      cout << "Choice: ";
      cin >> choice;
      // Checks user input here to ensure that a valid value is entered
      if (!cin.fail() && choice >= 1 && choice <= 4) break;
      cerr << "Invalid input please enter a number between 1 and 4" << endl;
      cin.clear();
      char badChar; 
      do { badChar = cin.get(); } while( badChar != '\n' );
    }
    return choice;
  
}

void user_functions(int choice, LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList){
  if(choice == 1){
    for(int i = 0; i < stringList.size(); i++){
      cout << "Comment #" << i+1 << ":" << stringList.at(i) << endl;
    }
  }else if(choice == 2){
    for(int i = 0; i < floatList.size()/3; i++){
      cout << "Vertex #" << i+1 << ": (" << floatList.at(i*3) << ", " << floatList.at(i*3+1) << ", " <<  floatList.at(i*3+2) << ")" << endl;
    }
  }else{
    for(int i = 0; i < intList.size()/3; i++){
      cout << "Face #" << i+1 << ":";
      cout << " (" << floatList.at(((intList.at(i*3)-1)*3)) << ", " << floatList.at(((intList.at(i*3)-1)*3)+1) << ", " <<  floatList.at(((intList.at(i*3)-1)*3)+2) << ") ";
      cout << " (" << floatList.at(((intList.at(i*3+1)-1)*3)) << ", " << floatList.at(((intList.at(i*3+1)-1)*3)+1) << ", " <<  floatList.at(((intList.at(i*3+1)-1)*3)+2) << ") ";
      cout << " (" << floatList.at(((intList.at(i*3+2)-1)*3)) << ", " << floatList.at(((intList.at(i*3+2)-1)*3)+1) << ", " <<  floatList.at(((intList.at(i*3+2)-1)*3)+2) << ") ";
      cout << endl;
    }
  }

}