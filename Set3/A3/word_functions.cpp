/* CSCI 261 A3: Green Eggs and Ham 
 *
 * Author: Garrett Thompson
 *
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math
#include <cstdlib> // for random
#include <ctime> // for time
#include <iomanip> // for formatting
#include <fstream> // for files
#include <vector> // for dynamic arrays
#include "word_functions.h"
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

string prompt_user_for_filename(){
  cout << "Please enter the name for your file here: " << endl;
  string filename;
  getline(cin, filename);
  return filename;
}
 
bool open_file(ifstream &inputFile, string filename){
  inputFile.open(filename);
  if (inputFile.fail()) {
    cerr << "Error opening input file";
    return false;
  }
  return true;
}

vector<string> read_words_from_file(ifstream &inputFile){
  string tempString;
  vector<string> allWords;
  while (inputFile >> tempString){
    allWords.push_back(tempString);
    tempString.clear();
  }
  return allWords;
}

void remove_punctuation(vector<string> &allWords, string punctuation){
  for(int i=0; i < allWords.size(); i++){
    string tempString;
    tempString = allWords.at(i);
    for(int j=0; j < sizeof(punctuation); j++){
      while(tempString.find(punctuation[j]) != -1){
        tempString = tempString.replace(tempString.find(punctuation[j]), 1,"");
      }
    }
    allWords.at(i) = tempString;
  }
}

void capitalize_words(vector<string> &allWords){
  for(int i=0; i < allWords.size(); i++){
    string tempString;
    string tempString2 = "";
    tempString = allWords.at(i);
    for(int j=0; j < tempString.length(); j++){
      if ((int)tempString[j] >= 97 && (int)tempString[j] <= 122){
        tempString2 += (int)tempString.at(j) - 32; 
      } else{
        tempString2 += tempString.at(j);
      }
    }
    allWords.at(i) = tempString2;
    tempString2 = "";
  }
  
}

vector<string> filter_unique_words(vector<string> &allWords){
  vector<string> uniqueWords;
  int check;
  for(int i=0; i < allWords.size(); i++){
    check = 1;
    for(int j=0; j < uniqueWords.size(); j++){
        if(allWords.at(i) == uniqueWords.at(j)){
            check = 0;
            break;
        }
    }
    if(check != 0){
      uniqueWords.push_back(allWords.at(i));
    }
  }
  
  return uniqueWords;
}

void count_letters(unsigned int letters[], const vector<string> &ALL_WORDS){
  int curLetter;
  for(int i=0; i < ALL_WORDS.size(); i++){
    for(int j=0; j < ALL_WORDS.at(i).size(); j++){
      curLetter = ALL_WORDS.at(i).at(j) - 65;
      letters[curLetter] += 1;
    }
  }
}

void print_letter_counts(unsigned int letters[]){
  int maxLength = to_string(letters[0]).length();
  for(int i=0; i < 26; i++){
    if (maxLength < to_string(letters[i]).length()){
      maxLength = to_string(letters[i]).length();
    }
  }
  for(int i=0; i < 26; i++){
    cout << (char)(i+65);
    cout << setw(maxLength + 1) << letters[i] << "\n";
  }
}

void print_max_min_letter(unsigned int letters[]){
  int maxLength = to_string(letters[0]).length();
  int maxPercentSize;
  char maxLetter;
  int maxLetterValue = letters[0];
  char minLetter;
  int minLetterValue = letters[0];
  double maxPercent;
  double minPercent;
  int sum = 0;
  for(int i=0; i < 26; i++){
    sum += (int)letters[i];
    if (maxLength < to_string(letters[i]).length()){
      maxLength = to_string(letters[i]).length();
    }
    if (maxLetterValue < letters[i]){
      maxLetterValue = letters[i];
      maxLetter = (char)(i + 65);
    }
    if (minLetterValue > letters[i]){
      minLetterValue = letters[i];
      minLetter = (char)(i + 65);
    }
  }
  maxPercent = ((double)maxLetterValue / sum)*100;
  minPercent = ((double)minLetterValue / sum)*100;
  maxPercentSize = to_string(((double)maxLetterValue / sum)*100.000).length() - 3;
  cout << fixed << right << "Least Frequent Letter: " << minLetter << setw(maxLength+1) << minLetterValue << " ( " << setw(maxPercentSize) << setprecision(3) << ((double)minLetterValue/sum)*100.000 << "%)\n";
  cout << fixed << right << " Most Frequent Letter: " << maxLetter << setw(maxLength+1) << maxLetterValue << " ( " << setw(maxPercentSize) << setprecision(3) << ((double)maxLetterValue/sum)*100.000 << "%)\n";

}
