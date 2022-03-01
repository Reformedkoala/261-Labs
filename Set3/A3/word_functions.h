#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H
#include <fstream>
#include <vector>
using namespace std;

string prompt_user_for_filename();
 
bool open_file(ifstream &inputFile, string filename);

vector<string> read_words_from_file(ifstream &inputFile);

void remove_punctuation(vector<string> &allWords, string punctuation);

void capitalize_words(vector<string> &allWords);

vector<string> filter_unique_words(vector<string> &allWords);

void count_letters(unsigned int letters[], const vector<string> &ALL_WORDS);

void print_letter_counts(unsigned int letters[]);

void print_max_min_letter(unsigned int letters[]);


#endif