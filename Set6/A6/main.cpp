#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "multi_dimension_functions.h"
using namespace std;
/* CSCI 261: A4: Wavefront OBJ File Format
 *
 * Author: Garrett Thompson
 *
 * Reading in a wavefront OBJ File Format and verifying certain properties of the file as well as printing out based on user specification.
 * 
 */
int main(int argc, char* argv[]) {
    // get filename to open
    string filename;
    if(argc == 1) {
        filename = prompt_user_for_filename();
    } else if(argc == 2) {
        filename = argv[1];
        cout << "Opening file '" << filename << "'" << endl;
    } else {
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "  filename   - optional file to open upon start" << endl;
        return -2;
    }
    // open file for parsing
    ifstream fileIn;
    if( !open_file(fileIn, filename) ) {
        cerr << "Could not open file \"" << filename << "\"" << endl;
        cerr << "Shutting down" << endl;
        return -1;
    }
    cout << "Enter 1 to search via BFS." << endl;
    cout << "Enter 2 to search via DFS." << endl;
    int arrayRow;
    fileIn >> arrayRow;
    int arrayCol;
    fileIn >> arrayCol;
    vector<vector<char>> multiList = read_file(fileIn, arrayRow, arrayCol);
    /*
    for(int i = 0; i < arrayRow; i++){
      for(int j = 0; j < arrayCol; j++){
        cout << multiList.at(i).at(j) << " ";
      }
      cout << endl;
    }
    */
    int choice = get_user_input();
    bool result;
    if(choice == 1){result = BFS(multiList, arrayRow, arrayCol);}
    else{return -1;}
    if(result == true){
      cout << "End was reached" << endl;
    } else{
      cout << "End cannot be reached" << endl;
    }
    for(int i = 0; i < arrayRow; i++){
      for(int j = 0; j < arrayCol; j++){
        cout << multiList.at(i).at(j) << " ";
      }
      cout << endl;
    }
}