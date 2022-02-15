/* CSCI 261 A2: PPM Image Editor
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
using namespace std;
#include "ppm_functions.h"
// We will (most of the time) use the standard library namespace in our programs.


void print_file_options() {
  cout << "which image to load?" << endl;
  cout << "1. Brick" << endl;
  cout << "2. Wallpaper" << endl;
  cout << "3. Private" << endl;
}

void print_operation_options() {
  cout << "which process to apply?" << endl;
  cout << "1. Grayscale" << endl;
  cout << "2. Inversion" << endl;
}

int get_user_input(int minIn, int maxIn) {
  int userImage;
  int userApply;
  if (maxIn == 3) {
      while(true) {
        cout << "Enter 1, 2, or 3: ";
        cin >> userImage;
        if (!cin.fail() && userImage >= minIn && userImage <= maxIn) break;
        cerr << "Invalid input" << endl;
        cin.clear();
        char badChar; 
        do { badChar = cin.get(); } while( badChar != '\n' );
      }
      return userImage;
  }
  else {
      while(true) {
        cout << "Enter 1 or 2: ";
        cin >> userApply;
        if (!cin.fail() && userApply >= minIn && userApply <= maxIn) break;
        cerr << "Invalid input" << endl;
        cin.clear();
        char badChar; 
        do { badChar = cin.get(); } while( badChar != '\n' );
      }
      return userApply;
  }
}

bool open_files(ifstream &inputFile, ofstream &outputFile, int userImage, int userApply) {  
    if (userImage == 1 && userApply == 1) {
      inputFile.open("brick.ppm");
      outputFile.open("brick_grayscaled.ppm");
      cout << "Opening brick.ppm file" << endl;
      cout << "Opening brick_greyscale.ppm file" << endl;
  } else if (userImage == 2 && userApply == 1){
      inputFile.open("wallpaper.ppm");
      outputFile.open("wallpaper_grayscale.ppm");
      cout << "Opening wallpaper.ppm file" << endl;
      cout << "Opening wallpaper_greyscale.ppm file" << endl;
  } else if (userImage == 1 && userApply == 2){
      inputFile.open("brick.ppm");
      outputFile.open("brick_inversion.ppm");
      cout << "Opening brick.ppm file" << endl;
      cout << "Opening brick_inversion.ppm file" << endl;
  } else if (userImage == 2 && userApply == 2){
      inputFile.open("wallpaper.ppm");
      outputFile.open("wallpaper_inversion.ppm");
      cout << "Opening wallpaper.ppm file" << endl;
      cout << "Opening wallpaper_inversion.ppm file" << endl;
  } else if (userImage == 3 && userApply == 1){
      inputFile.open("private.ppm");
      outputFile.open("private_grayscale.ppm");
      cout << "Opening private.ppm file" << endl;
      cout << "Opening private_greyscale.ppm file" << endl;
  }else {
      inputFile.open("private.ppm");
      outputFile.open("private_inversion.ppm");
      cout << "Opening private.ppm file" << endl;
      cout << "Opening private_inversion.ppm file" << endl;
  }
  if (inputFile.fail()) {
    cerr << "Error opening input file";
    return false;
  }
  if (outputFile.fail()) {
    cerr << "Error opening output file";
    return false;
  }
  return true;
}

bool read_header_information(ifstream &inputFile, int &width, int &height, int &maxRgb) {
  string fileType;
  getline(inputFile, fileType);
  if (fileType != "P3") {
    return false;
  }
  inputFile >> width;
  inputFile >> height;
  inputFile >> maxRgb;
  return true;
}

void write_header_information(ofstream &outputFile, int &width, int &height, int &maxRgb) {
  outputFile << "P3\n";
  outputFile << width << " ";
  outputFile << height << "\n";
  outputFile << maxRgb << "\n";
}

void read_and_write_modified_pixels(ifstream &inputFile, ofstream &outputFile, int &userApply, int &width, int &height, int &maxRgb){
  int red;
  int green;
  int blue;
  int gray;
  int i = 0;
  int j = 0;
  if (userApply == 1){
    while (i < height) {
      while (j < width){
        inputFile >> red;
        inputFile >> green;
        inputFile >> blue;
        gray = red * .2989 + green * .5870 + blue * .1140;
        outputFile << gray << " ";
        outputFile << gray << " ";
        outputFile << gray << " ";
        j++;
      }
      outputFile << "\n";
      j = 0;
      i++;
    }  
  } else {
    while (i < height) {
      while (j < width){
        inputFile >> red;
        inputFile >> green;
        inputFile >> blue;
        red = maxRgb - red;
        green = maxRgb - green;
        blue = maxRgb - blue;
        outputFile << red << " ";
        outputFile << green << " ";
        outputFile << blue << " ";
        j++;
      }
      outputFile << "\n";
      j = 0;
      i++;
    }  
  }
}