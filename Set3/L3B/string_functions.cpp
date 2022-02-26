#include "string_functions.h"

int string_length(const string STR)  {
    int result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = '\0';
    // TODO 01: set result to the character of a string at a given index
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    // TODO 02: set result to the concatenation of strings LEFT and RIGHT
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;
    // TODO 03: set result to the result of inserting a string into another
    return result;
}

int string_find(const string STR, const char C)  {
    int result = -1;
    // TODO 04: set result to the index of the first occurrence of the character
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR;
    // TODO 05: set result to be a substring starting at index of given length
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    // TODO 06: set result to be the string with the given text replaced
    return result;
}

string string_first_word(const string STR)  {
    string result = STR;
    // TODO 07: set result to the first word from the string
    return result;
}

string string_remove_first_word(const string STR)  {
    string result = STR;
    // TODO 08: set result to be the string with the first word removed
    return result;
}

string string_second_word(const string STR)  {
    string result = STR;
    // TODO 09: set result to be the second word from the string
    return result;
}

string string_third_word(const string STR)  {
    string result = STR;
    // TODO 10: set result to be the third word from the string
    return result;
}

string string_nth_word(const string STR, const int N)  {
    string result = STR;
    // TODO 11: set result to be the nth word from the string
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    // TODO 12: set result to be the string with all instances of TARGET replaced
    return result;
}

string string_to_lower(const string STR) {
    string result = STR;
    // TODO 13: convert all characters to lower case
    return result;
}

string string_to_upper(const string STR) {
    string result = STR;
    // TODO 14: convert all characters to upper case
    return result;
}

int string_compare(const string LHS, const string RHS) {
    int result = 0;
    // TODO 15: compare LHS and RHS
    return result;
}