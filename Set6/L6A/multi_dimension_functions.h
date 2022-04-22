#ifndef MULTI_DIMENSION_FUNCTIONS_H
#define MULTI_DIMENSION_FUNCTIONS_H
#include <string>
#include <fstream>
#include <vector>
using namespace std;
/* CSCI 261: Lab 6A - Multidimensional Data
 *
 * Author: Garrett Thompson
 * 
 * This program prints out the multi dimensional array stored in a data file by taking in the integers and iterating over it through vectors
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
 * @brief Creates the 2D array of integers
 * 
 * @param inputFile inputfile passed by reference in order to use it and set it for the rest of the program
 * @param arrayBound array bounds to keep track of
 * 
 */
vector<vector<int>> read_file(ifstream &inputFile, int arrayBound);

#endif