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
#include "Queue.hpp"
#include "Stack.hpp"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

string prompt_user_for_filename(){
  // Prompting the user for the file they want to open
  cout << "Please enter the name for your file here: ";
  string filename;
  getline(cin, filename);
  cout << "Opening file '" << filename << "'" << endl;
  return filename;
}
 
bool open_file(ifstream &inputFile, string filename){
  // Opens the input file for the program to read from 
  inputFile.open(filename);
  if (inputFile.fail()) {
    cerr << "Error opening input file";
    return false;
  }
  cout << "File opened successfully" << endl;
  return true;
}

vector<vector<char>> read_file(ifstream &inputFile, const int ARRAYROW, const int ARRAYCOL){
  vector<vector<char>> multiList;
  vector<char> tempList;
  char tempInt;
  for(int i = 0; i < ARRAYROW; i++){
    for(int j = 0; j < ARRAYCOL; j++){
        inputFile >> tempInt;
        tempList.push_back(tempInt);
    }
    multiList.push_back(tempList);
    tempList.clear();
  }
  return multiList;
}


int get_user_input() {
  int choice;
  // Allowing the user to choose what they want to do and validates their input
    while(true) {
      cout << "Choice: ";
      cin >> choice;
      // Checks user input here to ensure that a valid value is entered
      if (!cin.fail() && choice >= 1 && choice <= 2) break;
      cerr << "Invalid input please enter a number between 1 and 4" << endl;
      cin.clear();
      char badChar; 
      do { badChar = cin.get(); } while( badChar != '\n' );
    }
    return choice;
  
}

bool BFS(vector<vector<char>> &ogList, const int ARRAYROW, const int ARRAYCOL){
  struct Point {
    int x;
    int y;
    char value; 
  };
  Queue<Point> bfsQueue;
  for(int i = 0; i < ARRAYROW; i++){
    for(int j = 0; j < ARRAYCOL; j++){
      if(ogList.at(i).at(j) == 'S'){
        Point start;
        start.value = ogList.at(i).at(j);
        start.y = i;
        start.x = j;
        bfsQueue.push(start);
        break;
      }
    }
  }
  while(!bfsQueue.isEmpty()){

    if(bfsQueue.peak().value == 'S'){bfsQueue.pop();}
    else if(bfsQueue.peak().value == '.'){ogList.at(bfsQueue.peak().y).at(bfsQueue.peak().x) = '@'; bfsQueue.pop();}
    else if(bfsQueue.peak().value == 'E'){return true;}

    if(ogList.at(bfsQueue.peak().y+1).at(bfsQueue.peak().x) == '.' || ogList.at(bfsQueue.peak().y+1).at(bfsQueue.peak().x) == 'E'){
      Point next; 
      next.value = ogList.at(bfsQueue.peak().y+1).at(bfsQueue.peak().x); 
      next.y = bfsQueue.peak().y+1; 
      next.x = bfsQueue.peak().x; 
      bfsQueue.push(next);
    } 
    if(ogList.at(bfsQueue.peak().y).at(bfsQueue.peak().x+1) == '.' || ogList.at(bfsQueue.peak().y).at(bfsQueue.peak().x+1) == 'E'){
      Point next; 
      next.value = ogList.at(bfsQueue.peak().y).at(bfsQueue.peak().x+1); 
      next.y = bfsQueue.peak().y; 
      next.x = bfsQueue.peak().x+1; 
      bfsQueue.push(next);
    } 
    if(ogList.at(bfsQueue.peak().y-1).at(bfsQueue.peak().x) == '.' || ogList.at(bfsQueue.peak().y-1).at(bfsQueue.peak().x) == 'E' ){
      Point next; 
      next.value = ogList.at(bfsQueue.peak().y-1).at(bfsQueue.peak().x); 
      next.y = bfsQueue.peak().y-1; 
      next.x = bfsQueue.peak().x; 
      bfsQueue.push(next);
    } 
    if(ogList.at(bfsQueue.peak().y).at(bfsQueue.peak().x-1) == '.' || ogList.at(bfsQueue.peak().y).at(bfsQueue.peak().x-1) == 'E'){
      Point next; 
      next.value = ogList.at(bfsQueue.peak().y).at(bfsQueue.peak().x-1); 
      next.y = bfsQueue.peak().y; 
      next.x = bfsQueue.peak().x-1; 
      bfsQueue.push(next);
    }

  }
  return false;


}