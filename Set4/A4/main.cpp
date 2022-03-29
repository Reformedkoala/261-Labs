#include "obj_functions.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

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

    LinkedList<string> stringList;
    LinkedList<float> floatList;
    LinkedList<int> intList; 
    read_file(stringList, floatList, intList, fileIn);
    print_read(stringList, floatList, intList);
    int check = validate_faces(stringList, floatList, intList);
    if(check == 0){return -1;}
    int choice = get_user_input();
    while(choice != 4){
        user_functions(choice, stringList, floatList, intList);
        choice = get_user_input();
    }
    cout << endl << "Goodbye!" << endl;
    stringList.~LinkedList();
    floatList.~LinkedList();
    intList.~LinkedList();
    return 0;
}