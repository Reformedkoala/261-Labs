#ifndef OBJ_FUNCTIONS_H
#define OBJ_FUNCTIONS_H
#include <string>
#include <fstream>
#include "LinkedList.hpp"
using namespace std;

/**
 * @brief Prompts the user to enter the filename and turns it into a string 
 * 
 */
string prompt_user_for_filename();
 

 /**
 * @brief Opens the file
 * 
 * @param inputFile inputfile passed by reference in order to use it and set it for the rest of the program
 * @param filename name of the file to open 
 * 
 */
bool open_file(ifstream &inputFile, string filename);

void read_file(LinkedList<string> &stringList, LinkedList<float> &floatList, LinkedList<int> &intList, ifstream &inputfile);

void print_read(LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList);

void validate_faces(LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList);

#endif