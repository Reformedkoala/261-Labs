#include "obj_functions.h"
#include <fstream>
#include <iostream>
#include <string>
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
    // Created the Linked Lists we will be storing our data in
    LinkedList<string> stringList;
    LinkedList<float> floatList;
    LinkedList<int> intList; 
    // Read the file
    read_file(stringList, floatList, intList, fileIn);
    // Print what we read in
    print_read(stringList, floatList, intList);
    // Checking if the file is valid
    int check = validate_faces(stringList, floatList, intList);
    if(check == 0){return -1;}
    // Allowing the user to choose what to print
    int choice = get_user_input();
    while(choice != 4){
        user_functions(choice, stringList, floatList, intList);
        choice = get_user_input();
    }
    // Exiting and cleaning up the program on the backend
    cout << endl << "Goodbye!" << endl;
    stringList.~LinkedList();
    floatList.~LinkedList();
    intList.~LinkedList();
    return 0;
}