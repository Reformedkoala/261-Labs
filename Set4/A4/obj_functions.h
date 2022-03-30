#ifndef OBJ_FUNCTIONS_H
#define OBJ_FUNCTIONS_H
#include <string>
#include <fstream>
#include "LinkedList.hpp"
using namespace std;
/* CSCI 261: A4: Wavefront OBJ File Format
 *
 * Author: Garrett Thompson
 *
 * Reading in a wavefront OBJ File Format and verifying certain properties of the file as well as printing out based on user specification.
 * 
 */


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


 /**
 * @brief Reads the file
 * 
 * @param stringList list of strings which are our comments
 * @param floatList list of floats which are the vertices
 * @param intList list of ints which are the faces and the vertex indices
 * @param inputFile input file that we must read from
 * 
 */
void read_file(LinkedList<string> &stringList, LinkedList<float> &floatList, LinkedList<int> &intList, ifstream &inputfile);

 /**
 * @brief Print what we read in
 * 
 * @param stringList list of strings which are our comments
 * @param floatList list of floats which are the vertices
 * @param intList list of ints which are the faces and the vertex indices
 * 
 */
void print_read(LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList);

/**
 * @brief Validates what we read in and returns a check variable
 * 
 * @param stringList list of strings which are our comments
 * @param floatList list of floats which are the vertices
 * @param intList list of ints which are the faces and the vertex indices
 * 
 */
int validate_faces(LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList);

/**
 * @brief Gets the user input and returns a variable for their choice as well as validating the input
 * 
*/
int get_user_input();

/**
 * @brief Performs different functions based on the user input
 * 
*/
void user_functions(int choice, LinkedList<string>& stringList, LinkedList<float>& floatList, LinkedList<int>& intList);

#endif