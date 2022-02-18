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

/**
 * @brief Prints the options menu for which file to open.
 * 
 */
void print_file_options() {
  cout << "which image to load?" << endl;
  cout << "1. Brick" << endl;
  cout << "2. Wallpaper" << endl;
  cout << "3. Private" << endl;
}

/**
 * @brief Prints the options menu for which file processing to perform.
 * 
 */
void print_operation_options() {
  cout << "which process to apply?" << endl;
  cout << "1. Grayscale" << endl;
  cout << "2. Inversion" << endl;
}

/**
 * @brief Prompts the user to enter a value. 
 * 
 * @param minIn determines the minimum value a user can enter
 * @param maxIn determines the maximum value a user can enter
 * 
 */
int get_user_input(int minIn, int maxIn) {
  int userImage;
  int userApply;
  // Determines which branch to send us down so we can record the proper user input
  if (maxIn == 3) {
      while(true) {
        cout << "Enter 1, 2, or 3: ";
        cin >> userImage;
        // Checks user input here to ensure that a valid value is entered
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

/**
 * @brief Opens the corresponding files for reading and writing based on the file and operation chosen.
 * 
 * @param inputFile determines which file to open and read from 
 * @param outputFile determines which file to open and write from
 * @param userImage determines which Image to use based on user input
 * @param userApply determines which change to apply to said image based on user input
 * 
 */
bool open_files(ifstream &inputFile, ofstream &outputFile, int userImage, int userApply) {  
  // A bunch of branches to send the program down based on previous user input which helps determine what to do as well as print out the correct message
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
  // Checks if the file opened okay for both reading and writing
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

/**
 * @brief Reads the header block of the file (the first four values).
 * 
 * @param inputFile determines which file to open and read from 
 * @param width returns the width of the file from the function for later user
 * @param height returns the height of the file from the function for later user
 * @param maxRgb returns the maximum rgb value of the file to eventually use
 * 
 */
bool read_header_information(ifstream &inputFile, int &width, int &height, int &maxRgb) {
  // Collects the header information we need from the file
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

/**
 * @brief Writes the header block of the file (the first four values).
 * 
 * @param outputFile determines which file to open and write to
 * @param width determines the width to write to the file
 * @param height determines the height to write to the file
 * @param maxRgb determines the maxRGB to write to the file
 * 
 */
void write_header_information(ofstream &outputFile, int &width, int &height, int &maxRgb) {
  // Uses the header information we just collected and writes it to the new file to ensure proper file format
  outputFile << "P3\n";
  outputFile << width << " ";
  outputFile << height << "\n";
  outputFile << maxRgb << "\n";
}

/**
 * @brief Writes the header block of the file (the first four values).
 * 
 * @param inputFile determines which file to open and read from and modify the pixels
 * @param outputFile determines which file to open and write to
 * @param userApply determines the effect to apply to the file
 * @param width determines the width to write to the file
 * @param height determines the height to write to the file
 * @param maxRgb determines the maxRGB to write to the file
 * 
 */
void read_and_write_modified_pixels(ifstream &inputFile, ofstream &outputFile, int &userApply, int &width, int &height, int &maxRgb){
  int red;
  int green;
  int blue;
  int gray;
  int i = 0;
  int j = 0;
  //Determines which modification we make to the file
  if (userApply == 1){
    while (i < height) {
      while (j < width){
        inputFile >> red;
        inputFile >> green;
        inputFile >> blue;
        // Math to grayscale each pixel
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
        // math to invert the RGB value of each pixel based on our maxRGB value because it could be bigger then 255 hypothetically or smaller.
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