#ifndef PPM_FUNCTIONS_H
#define PPM_FUNCTIONS_H
#include <fstream>
using namespace std;

void print_file_options();
void print_operation_options();
int get_user_input(int minIn, int maxIn);
bool open_files(ifstream &inputFile, ofstream &outputFile, int userImage, int userApply);
bool read_header_information(ifstream &inputFile, int &width, int &height, int &maxRgb);
void write_header_information(ofstream &outputFile, int &width, int &height, int &maxRgb);
void read_and_write_modified_pixels(ifstream &inputFile, ofstream &outputFile, int &userApply, int &width, int &height, int &maxRgb);

#endif