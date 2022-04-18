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
    int arrayBound;
    fileIn >> arrayBound;
    vector<vector<int>> multiList = read_file(fileIn, arrayBound);
    int min = multiList.at(0).at(0);
    int max = multiList.at(0).at(0);
    for(int i = 0; i < arrayBound; i++){
      for(int j = 0; j < arrayBound; j++){
        cout << multiList.at(i).at(j) << " ";
        if(min > multiList.at(i).at(j)){min = multiList.at(i).at(j);}
        if(max < multiList.at(i).at(j)){max = multiList.at(i).at(j);}
      }
      cout << endl;
    }
    cout << "The min is: " << min << endl;
    cout << "The max is: " << max << endl;
}