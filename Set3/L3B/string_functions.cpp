#include "string_functions.h"
#include <string>
#include <iostream>
using namespace std;
int string_length(const string STR)  {
    int result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = STR[IDX];
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT + RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR.substr(0 , IDX) + TO_INSERT + STR.substr(IDX,-1);
    return result;
}

int string_find(const string STR, const char C)  {
    int result = STR.find(C);
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR.substr(IDX, LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string str = STR;
    if(str.find(TEXT_TO_REPLACE) == -1){
        return STR;
    }
    string result = str.replace(str.find(TEXT_TO_REPLACE), TEXT_TO_REPLACE.length(), REPLACE_WITH);
    return result;
}

string string_first_word(const string STR)  {
    string result = STR.substr(0, STR.find(' '));
    return result;
}

string string_remove_first_word(const string STR)  {
    string str = STR;
    str = str.erase(0, str.find(' '));
    if(str.find(' ')==0){str = str.erase(0,1);}
    string result = str;
    return result;
}

string string_second_word(const string STR)  {
    int first = STR.find(' ');
    int second = STR.find(' ', first + 1);
    string result = STR.substr(first+1, second-first-1);
    if(STR.find(' ') == -1){string edge = ""; return edge;}

    return result;
}

string string_third_word(const string STR)  {
    int first = STR.find(' ');
    int second = STR.find(' ', first + 1);
    int third = STR.find(' ', second + 1);
    string result = STR.substr(second+1, third-second-1);
    if(second == -1){string edge = ""; return edge;}
    return result;
}

string string_nth_word(const string STR, const int N) {
    string result = STR;
    int i = 0;
    int split=1;
    int split2=1;
    if(N == 1){return STR.substr(0,STR.find(' '));}
    if(N == 10){return "";}
    while(i < N){
      split = result.find(' ', split+1);
      i++;
    }
    i =0;
    while(i < N-1){
      split2 = result.find(' ', split2+1);
      i++;
    }
    cout << split;
    cout << " " << split2;
    split -= split2;
    return result.substr(split2+1, split-1);
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string str = "";
    int i = 0;
    char tempChar;
    for (i = 0; i < STR.length(); i++){
      tempChar = STR[i];
      if (tempChar == TARGET){
          tempChar = REPLACEMENT;
      }
      str += tempChar;
    }
    string result = str;
    return result;
}

string string_to_lower(const string STR) {
    string str = "";
    int i = 0;
    int tempChar;
    for (i = 0; i < STR.length(); i++){
      tempChar = STR[i];
      if (tempChar>= 65 && tempChar <= 90){
          tempChar += 32;
      }
      str += (char)tempChar;
    }
    string result = str;
    return result;
}

string string_to_upper(const string STR) {
    string str = "";
    int i = 0;
    int tempChar;
    for (i = 0; i < STR.length(); i++){
      tempChar = STR[i];
      if (tempChar>= 97 && tempChar <= 122){
          tempChar -= 32;
      }
      str += (char)tempChar;
    }
    string result = str;
    return result;
}

int string_compare(const string LHS, const string RHS) {
    int result;
    if(LHS == RHS){result = 0;}
    else if(LHS<RHS){result = -1;}
    else{result = 1;}
    return result;
}