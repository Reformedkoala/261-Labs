#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H
#include <fstream>
#include <vector>
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


/**
 * @brief Reads in all the words from the input file and ensures everything is read in properly
 * 
 * @param inputFile the file we use to read in all words
 * 
 */
vector<string> read_words_from_file(ifstream &inputFile);


/**
 * @brief Removes all punctuation from the vector containing all strings from the file(one improvement is to combine the punctuation and capitilization)
 * 
 * @param allwords The vector of strings we created from the read words function
 * @param punctuation The punctuation to remove from the vector of strings we have
 * 
 */
void remove_punctuation(vector<string> &allWords, string punctuation);


/**
 * @brief Removes all lowercase characters from the vector of strings
 * 
 * @param allwords The vector of strings we created from the read words function
 * 
 */
void capitalize_words(vector<string> &allWords);


/**
 * @brief Filters all unique words and turns it into a new string that we count the size of
 * 
 * @param allwords The vector of strings we created from the read words function
 * 
 */
vector<string> filter_unique_words(vector<string> &allWords);


/**
 * @brief Counts all the letters within the file given
 * 
 * @param letters The array of empty zeroes to keep track of characters within the entire file
 * @param ALL_WORDS The vector of strings we created from the read words function
 * 
 */
void count_letters(unsigned int letters[], const vector<string> &ALL_WORDS);


/**
 * @brief Prints out all the counts of our letters
 * 
 * @param letters The array of empty zeroes to keep track of characters within the entire file
 * 
 */
void print_letter_counts(unsigned int letters[]);


/**
 * @brief Prints out the min and max letter as well as other statistics
 * 
 * @param letters The array of empty zeroes to keep track of characters within the entire file
 * 
 */
void print_max_min_letter(unsigned int letters[]);


#endif